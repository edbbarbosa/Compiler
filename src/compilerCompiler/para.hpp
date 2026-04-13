#ifndef PARA
#define PARA
#include "compilercompiler.hpp"
#include "../analysis/lexical.hpp"

class Para: public CompilerCompiler{
    std::string str;
public:
    Para(std::string); 
    std::string getCode() override;
};

#endif