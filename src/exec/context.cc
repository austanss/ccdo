#include "exec/context.hh"

using namespace ccdo;

ExecutionContext::ExecutionContext(const ProgramArguments& args) {
    this->configuration = std::make_unique<ExecutionConfiguration>(args);
    this->configuration->validate().handle();
    this->option = ExecutionOption::get_by_name(this->configuration->task_selection);
}

ExecutionContext::ExecutionContext(const ExecutionContext& copy) {
    this->configuration = std::make_unique<ExecutionConfiguration>(*copy.configuration);
    this->configuration->validate().handle();
    this->option = ExecutionOption::get_by_name(this->configuration->task_selection);
}

ExecutionContext::~ExecutionContext() {
    // Hay nada
}


