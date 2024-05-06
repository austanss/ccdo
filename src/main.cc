#include "exec/context.hh"
#include <iostream>
#include <fstream>
#include <memory>

using namespace ccdo;

int main(int argc, char** argv) {
    std::unique_ptr<ExecutionContext> ctx = std::make_unique<ExecutionContext>(ProgramArguments(argc, argv));

    ctx->realize().handle();

    return 0;
}
