#ifndef AVOCADO
#define AVOCADO
#include "compilercompiler.hpp"

class Avocado: public CompilerCompiler{
    std::string str;
public:
    Avocado(std::string);
    std::string getCode(); 
};

#endif