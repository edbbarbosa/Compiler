#ifndef INITIALISATION
#define INITIALISATION
#include "compilercompiler.hpp"

class Initialisation: public CompilerCompiler{
    std::string str;
public:
    Initialisation(std::string);
    std::string getCode(); 
};

#endif
