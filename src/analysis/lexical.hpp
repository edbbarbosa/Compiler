#ifndef LEXICAL
#define LEXICAL
#include "syntax.hpp"
#include "../compilerCompiler/compilercompiler.hpp"
#include "../compilerCompiler/car.hpp"
#include "../compilerCompiler/tree.hpp"
#include "../compilerCompiler/sesenao.hpp"
#include "../compilerCompiler/whilst.hpp"
#include "../compilerCompiler/grape.hpp"
#include "../compilerCompiler/avocado.hpp"
#include "../compilerCompiler/initialisation.hpp"
#include "../compilerCompiler/banana.hpp"
#include "../compilerCompiler/para.hpp"
#include <cstring>
#include <fstream>
#include <string> 

class Syntax; 

class Lexical{
    std::smatch m; 
    std::vector<bool> b; 
public:
    Syntax* syntax = nullptr; 
    Lexical(); 
    Lexical(std::string); 
    std::string getCode(); 
    void check(std::string); 
    bool getBool(); 
};

#endif
