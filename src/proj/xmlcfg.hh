#pragma once
#include "proj/settings.hh"
#include <libxml/parser.h>
#include <string>

namespace ccdo {

	class ProjectXmlFile {
		
	public:
		// Reads the file (readonly) and parses it, populating class fields
		ProjectXmlFile(const std::string filename);
		~ProjectXmlFile();

		// Returns the content of the first node with the requested identifier 
		// "identifier" format: [ROOT].[NODE].[SUBNODE], e.g. "project.defaults.target"
		// If a node and its subnode has the same identifier, there be dragons
		std::string get_data(const std::string identifier);

	private:
		const std::string filepath;
		xmlDocPtr document;
		xmlNodePtr root;

	protected:
		ProjectXmlFile();

	};

}