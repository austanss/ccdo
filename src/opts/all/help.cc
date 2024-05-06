#include "opts/all/help.hh"
#include <iostream>

using namespace ccdo;

HelpExecutionOption::HelpExecutionOption() {
    // Necessitated by compiler nature of abstract class
}

ExecutionStatus HelpExecutionOption::perform(const ExecutionConfiguration& conf) {
    conf.validate().handle();
    
    std::cout << "Usage: ccdo <task> <arguments>" << std::endl;
    std::cout << "Tasks:" << std::endl;
    std::cout << "\thelp\t\tDisplay this help message" << std::endl;
    std::cout << "\tclean\t\tDelete build output files from this directory" << std::endl;
    
    return ExecutionStatus::ALL_OKAY;
}
