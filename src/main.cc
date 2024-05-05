#include "exec/args.hh"
#include "opts/base.hh"
#include <iostream>
#include <fstream>
#include <memory>

using namespace ccdo;

int main(int argc, char** argv) {
    std::shared_ptr<ProgramArguments> args = std::make_shared<ProgramArguments>(argc, argv);
    
    if (args->count() < 2) {
        std::cerr << "Usage: " << args->at(0) << " <task>" << std::endl;
        return 1;
    }
    std::unique_ptr<ExecutionOption> task = ExecutionOption::get_by_name(args->at(1));

    task->perform(args).handle();

    return 0;
}
