#ifndef SYNTAX
#define SYNTAX
#include "lexical.hpp"
#include "semantic.hpp"
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

class Semantic; 

class Syntax{
    std::smatch m; 
    std::vector<bool> b;
public:
    Semantic* semantic = nullptr; 
    Syntax();
    Syntax(std::string); 
    std::string getCode();
    void check(std::string); 
    bool getBool(); 
};

#endif 
