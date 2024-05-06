#pragma once
#include "opts/base.hh"
#include "exec/conf.hh"

namespace ccdo {

    class ExecutionContext {

    public:
        ExecutionContext(const ProgramArguments& args);
        ExecutionContext(const ExecutionContext& copy);
        ~ExecutionContext();

        // Performs the execution of the task in context
        inline ExecutionStatus realize() { return option == nullptr ? ExecutionStatus::BAD_CONFIG : option->perform(*configuration); };
        
    private:
        ExecutionContext();
        std::unique_ptr<ExecutionOption> option;
        std::unique_ptr<ExecutionConfiguration> configuration;
    
    };

}