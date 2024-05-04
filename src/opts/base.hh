#pragma once
#include "stat.hh"
#include "args.hh"
#include <memory>

namespace ccdo {
		
	class ExecutionOption {

	public:
		virtual ~ExecutionOption() {}
		virtual ExecutionStatus perform(std::shared_ptr<ProgramArguments> args) = 0;
		static std::unique_ptr<ExecutionOption> get_by_name(std::string name);
		inline ExecutionStatus operator()(std::shared_ptr<ProgramArguments> args) { return this->perform(args); }

	protected:
		ExecutionOption();
		std::shared_ptr<ProgramArguments> arguments;
		
	};

}
