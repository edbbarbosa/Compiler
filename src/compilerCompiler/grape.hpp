#ifndef GRAPE
#define GRAPE
#include "compilercompiler.hpp"

class Grape: public CompilerCompiler{
    std::string str;
public:
    Grape(std::string);
    std::string getCode() override; 
};

#endif
