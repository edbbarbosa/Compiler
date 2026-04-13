#ifndef WHILST
#define WHILST
#include "compilercompiler.hpp"
#include "../analysis/lexical.hpp"
#include "../analysis/syntax.hpp"

class Whilst: public CompilerCompiler{
    std::string str, x, y; 
    std::smatch m; 
public:
    Whilst(std::string); 
    std::string getCode() override; 
};

#endif
