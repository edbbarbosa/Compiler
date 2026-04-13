#ifndef BANANA
#define BANANA
#include "compilercompiler.hpp"

class Banana: public CompilerCompiler{
    std::string str;
public:
    Banana(std::string); 
    std::string getCode() override; 
};

#endif
