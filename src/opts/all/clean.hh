#pragma once
#include "opts/base.hh"

namespace ccdo {

    class CleanupExecutionOption : public ExecutionOption {

    public:
        CleanupExecutionOption();
        virtual ~CleanupExecutionOption() override {}
        virtual ExecutionStatus perform(std::shared_ptr<ProgramArguments> args) override;

    };

}