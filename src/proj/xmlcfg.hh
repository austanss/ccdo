#pragma once
#include "proj/settings.h"
#include <libxml/parser.h>
#include <string>

namespace ccdo {

    // Members can be modified, but will not reflect on the source file
    class ProjectXmlFile {
        
    public:
        // Reads the file (readonly) and parses it, populating class fields
        ProjectXmlFile(const std::string filename);
        ~ProjectXmlFile();

        // Returns the content of the first node with the requested identifier 
        // identifier format: [ROOT].[NODE].[SUBNODE], e.g. "project.defaults.target"
        std::string get_data(const std::string identifier);

    private:
        const std::string filepath;
        xmlDocPtr document;
        xmlNodePtr root;

    protected:
        ProjectXmlFile();

    };

}