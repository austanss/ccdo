#include "opts/all/clean.hh"
#include <iostream>

using namespace ccdo;

CleanupExecutionOption::CleanupExecutionOption() {
    // Necessitated by compiler nature of abstract class
}

ExecutionStatus CleanupExecutionOption::perform(const ExecutionConfiguration& conf) {
    conf.validate().handle();
    
    std::cout << "\tCleaning" << std::endl;
    
    return ExecutionStatus::ALL_OKAY;
}
