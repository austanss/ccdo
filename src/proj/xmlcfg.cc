#include "proj/xmlcfg.hh"
#include "exec/stat.hh"
#include <memory>
#include <vector>

using namespace ccdo;

ProjectXmlFile::~ProjectXmlFile() {
	xmlFreeDoc(this->document);
}

ProjectXmlFile::ProjectXmlFile(const std::string filename) : filepath(filename) {
	this->document = xmlParseFile(this->filepath.c_str());
	if (this->document == nullptr) {
		ExecutionStatus::XML_ERROR.handle();
	}
	this->root = xmlDocGetRootElement(this->document);
	if (this->root == nullptr) {
		ExecutionStatus::XML_ERROR.handle();
	}
	if (xmlStrcmp(this->root->name, (const xmlChar *)"project") != 0) {
		ExecutionStatus::BAD_CONFIG.handle();
	}
}

static xmlNodePtr get_child_node_safely(xmlNodePtr parent, const std::string name) {
	xmlNodePtr node = parent->children;
	while (node != nullptr) {
		if (xmlStrcmp(node->name, (const xmlChar *)name.c_str()) == 0) {
			return node;
		}
		node = node->next;
	}
	ExecutionStatus::XML_ERROR.handle();
	return nullptr; // Unreachable, compiler purposes
}

static std::unique_ptr<std::vector<std::string>> split_identifier(const std::string identifier) {
	// Split the identifier into constituent parts
	constexpr char delimiter = '.';
	std::unique_ptr<std::vector<std::string>> tokens = std::make_unique<std::vector<std::string>>(0);
	unsigned long position = 0;
	std::string identifier_rw = std::string(identifier);
	std::string draft;

	while ((position = identifier_rw.find(delimiter)) != std::string::npos) {
		draft = identifier_rw.substr(0, position);
		tokens->push_back(draft);
		identifier_rw.erase(0, position + 1);
	}
	if (identifier_rw.length() > 0)
		tokens->push_back(identifier_rw);
	
	if (tokens->size() == 0) {
		ExecutionStatus::XML_ERROR.handle();
	}

	return tokens;
}

std::string ProjectXmlFile::get_data(const std::string identifier) {
	std::string data = "";

	std::unique_ptr<std::vector<std::string>> directions = split_identifier(identifier);

	// Traverse the XML tree
	xmlNodePtr node = this->root;
	for (std::string identity : *directions) {
		node = get_child_node_safely(node, identity);
	}
	if (xmlStrcmp(node->name, (const xmlChar *)directions->back().c_str()) != 0) {
		ExecutionStatus::XML_ERROR.handle();
	}

	xmlChar* node_content = xmlNodeListGetString(this->document, node->children, 1);
	data = std::string((const char *)node_content);
	xmlFree(node_content);

	return data;
}
