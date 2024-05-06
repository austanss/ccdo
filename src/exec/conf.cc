#include "exec/conf.hh"

using namespace ccdo;

ExecutionConfiguration::ExecutionConfiguration(const ProgramArguments& args) {
    this->xml_filepath = "ccdo.xml";
    if (args.count() < 2) 
        this->task_selection = "help";
    else
        this->task_selection = args.at(1);
}

ExecutionConfiguration::ExecutionConfiguration(const ExecutionConfiguration& copy) {
    this->xml_filepath = copy.xml_filepath;
    this->task_selection = copy.task_selection;
}

ExecutionConfiguration::~ExecutionConfiguration() {
    // Hay nada
}

ExecutionStatus ExecutionConfiguration::validate() const {
    if (this->xml_filepath == "") {
        return ExecutionStatus::BAD_CONFIG;
    }
    return ExecutionStatus::ALL_OKAY;
}
