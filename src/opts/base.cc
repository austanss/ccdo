#include "opts/base.hh"
#include "opts/all.hh"
#include <stdexcept>

using namespace ccdo;

std::unique_ptr<ExecutionOption> ExecutionOption::get_by_name(std::string name) {

    if (name == "clean")        return std::make_unique<CleanupExecutionOption>();
    if (name == "help")         return std::make_unique<HelpExecutionOption>();
    // Add more in same format
    
    ExecutionStatus::INVALID_TASK.handle();
    return nullptr;
}

ExecutionOption::ExecutionOption() {}
