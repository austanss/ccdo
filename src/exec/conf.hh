#pragma once
#include "exec/args.hh"
#include "exec/stat.hh"
#include <memory>

namespace ccdo {

    class ExecutionConfiguration {

    public:
        ExecutionConfiguration(const ProgramArguments& args);
        ExecutionConfiguration(const ExecutionConfiguration& copy);
        ~ExecutionConfiguration();

        ExecutionStatus validate() const;

        std::string task_selection;
        std::string xml_filepath;

    private:
        ExecutionConfiguration();

    };

}