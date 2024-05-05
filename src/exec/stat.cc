#include "exec/stat.hh"
#include <iostream>

using namespace ccdo;

const ExecutionStatus ExecutionStatus::ALL_OKAY         { ExecutionState::ALL_OKAY };
const ExecutionStatus ExecutionStatus::INVALID_TASK     { ExecutionState::INVALID_TASK };
const ExecutionStatus ExecutionStatus::BAD_ARGUMENTS    { ExecutionState::BAD_ARGUMENTS };
const ExecutionStatus ExecutionStatus::BAD_CONFIG       { ExecutionState::BAD_CONFIG };
const ExecutionStatus ExecutionStatus::FILE_ERROR       { ExecutionState::FILE_ERROR };
const ExecutionStatus ExecutionStatus::MEMORY_ERROR     { ExecutionState::MEMORY_ERROR };
const ExecutionStatus ExecutionStatus::MISC_ERROR       { ExecutionState::MISC_ERROR };

void ExecutionStatus::handle() const {
    switch (this->state) {
        case ExecutionState::ALL_OKAY:
            return;
        case ExecutionState::INVALID_TASK:
            std::cerr << "FATAL: Invalid task" << std::endl;
            break;
        case ExecutionState::BAD_ARGUMENTS:
            std::cerr << "FATAL: Bad arguments" << std::endl;
            break;
        case ExecutionState::BAD_CONFIG:
            std::cerr << "FATAL: Bad configuration" << std::endl;
            break;
        case ExecutionState::FILE_ERROR:
            std::cerr << "FATAL: File error" << std::endl;
            break;
        case ExecutionState::MEMORY_ERROR:
            std::cerr << "FATAL: Memory error" << std::endl;
            break;
        case ExecutionState::MISC_ERROR:
            std::cerr << "FATAL: Unidentified error" << std::endl;
            break;
        default:
            std::cerr << "FATAL: Unknown error" << std::endl;
            break;
    }
    throw new std::runtime_error("Fatal error encountered");
}
