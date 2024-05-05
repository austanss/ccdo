#include "exec/args.hh"

using namespace ccdo;

ProgramArguments::ProgramArguments(int argc, char** argv) {
    this->data = new std::vector<std::string>(argc);
    for (int i = 0; i < argc; i++) {
        this->data->at(i) = std::string(argv[i]);
    }
    this->size = argc;
}

ProgramArguments::~ProgramArguments() {
    delete this->data;
}

std::string ProgramArguments::at(unsigned long index) {
    return this->data->at(index);
}

unsigned long ProgramArguments::count() {
    return this->size;
}
