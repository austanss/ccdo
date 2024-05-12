#include "exec/stat.hh"
#include <iostream>

using namespace ccdo;

const ExecutionStatus ExecutionStatus::ALL_OKAY         { ExecutionState::ALL_OKAY };
const ExecutionStatus ExecutionStatus::INVALID_TASK     { ExecutionState::INVALID_TASK };
const ExecutionStatus ExecutionStatus::BAD_ARGUMENTS    { ExecutionState::BAD_ARGUMENTS };
const ExecutionStatus ExecutionStatus::BAD_CONFIG       { ExecutionState::BAD_CONFIG };
const ExecutionStatus ExecutionStatus::FILE_ERROR       { ExecutionState::FILE_ERROR };
const ExecutionStatus ExecutionStatus::XML_ERROR        { ExecutionState::XML_ERROR };
const ExecutionStatus ExecutionStatus::MEMORY_ERROR     { ExecutionState::MEMORY_ERROR };
const ExecutionStatus ExecutionStatus::MISC_ERROR       { ExecutionState::MISC_ERROR };

void ExecutionStatus::handle() const {
    switch (this->state) {
        case ExecutionState::ALL_OKAY:
            return;
        case ExecutionState::INVALID_TASK:
            std::cerr << "FATAL: Invalid task, see help\n" << std::endl;
            break;
        case ExecutionState::BAD_ARGUMENTS:
            std::cerr << "FATAL: Bad arguments, see help\n" << std::endl;
            break;
        case ExecutionState::BAD_CONFIG:
            std::cerr << "FATAL: Bad configuration file data\n" << std::endl;
            break;
        case ExecutionState::FILE_ERROR:
            std::cerr << "FATAL: File processing error\n" << std::endl;
            break;
        case ExecutionState::XML_ERROR:
            std::cerr << "FATAL: XML processing error\n" << std::endl;
            break;
        case ExecutionState::MEMORY_ERROR:
            std::cerr << "FATAL: Memory failure error\n" << std::endl;
            break;
        case ExecutionState::MISC_ERROR:
            std::cerr << "FATAL: Unclassified error\n" << std::endl;
            break;
        default:
            std::cerr << "FATAL: Unidentifiable error\n" << std::endl;
            break;
    }
    throw new std::runtime_error("Fatal error encountered");
}
