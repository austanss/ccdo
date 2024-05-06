#pragma once
#include "opts/base.hh"

namespace ccdo {

    class HelpExecutionOption : public ExecutionOption {

    public:
        HelpExecutionOption();
        virtual ~HelpExecutionOption() override {}
        virtual ExecutionStatus perform(const ExecutionConfiguration& conf) override;

    };

}