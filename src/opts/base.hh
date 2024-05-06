#pragma once
#include "exec/stat.hh"
#include "exec/args.hh"
#include "exec/conf.hh"
#include <memory>

namespace ccdo {
		
	class ExecutionOption {

	public:
		virtual ~ExecutionOption() {}
		virtual ExecutionStatus perform(const ExecutionConfiguration& conf) = 0;
		static std::unique_ptr<ExecutionOption> get_by_name(std::string name);
		inline ExecutionStatus operator()(const ExecutionConfiguration& config) { return this->perform(config); }

	protected:
		ExecutionOption();
	};

}
