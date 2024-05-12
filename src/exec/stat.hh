#pragma once
#include <stdexcept>

namespace ccdo {

	enum ExecutionState : long {
		ALL_OKAY,
		INVALID_TASK,
		BAD_ARGUMENTS,
		BAD_CONFIG,
		FILE_ERROR,
		XML_ERROR,
		MEMORY_ERROR,
		MISC_ERROR,
	};


	struct ExecutionStatus {
		ExecutionState state;
		// If status is okay, does nothing and returns gracefully
		void handle() const;
		// Static instances of ExecutionStatus
		static const ExecutionStatus ALL_OKAY;
		static const ExecutionStatus INVALID_TASK;
		static const ExecutionStatus BAD_ARGUMENTS;
		static const ExecutionStatus BAD_CONFIG;
		static const ExecutionStatus FILE_ERROR;
		static const ExecutionStatus XML_ERROR;
		static const ExecutionStatus MEMORY_ERROR;
		static const ExecutionStatus MISC_ERROR;
	};
}