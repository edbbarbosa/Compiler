#ifndef COMPILERCOMPILER
#define COMPILERCOMPILER
#include <iostream>
#include <regex>
#include <cstring>

class CompilerCompiler{
public:
    virtual std::string getCode() = 0; 
};

#endif