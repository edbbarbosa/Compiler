#ifndef SESENAO
#define SESENAO
#include "compilercompiler.hpp"
#include "../analysis/lexical.hpp"
#include "../analysis/syntax.hpp"
#include <regex>
#include <iostream>

class Sesenao: public CompilerCompiler{
    std::string tmp, x, y, z;
    std::smatch m;
    bool b = true; 
public:
    Sesenao(std::string);   
    std::string getCode() override; 
};

#endif