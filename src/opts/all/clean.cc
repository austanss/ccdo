#include "opts/all/clean.hh"
#include <iostream>

using namespace ccdo;

CleanupExecutionOption::CleanupExecutionOption() {

}

ExecutionStatus CleanupExecutionOption::perform(std::shared_ptr<ProgramArguments> args) {
    this->arguments = args;
    std::cout << "\tCleaning" << std::endl;
    return ExecutionStatus::STAT_OKAY;
}
