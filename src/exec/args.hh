#pragma once
#include <string>
#include <vector>

namespace ccdo {

    class ProgramArguments {

    public:
        ProgramArguments(int argc, char** argv);
        ProgramArguments(ProgramArguments& copy);
        ~ProgramArguments();
        std::string at(unsigned long index) const;
        inline std::string operator[](unsigned long index) { return this->at(index); };
        inline std::string operator[](int index) { return this->at((unsigned long) index); }
        unsigned long count() const;

    private:
        ProgramArguments();
        void operator=(ProgramArguments& rvalue);
        std::vector<std::string>* data;
        unsigned long size;

    };
    
}