#ifndef SEMANTIC
#define SEMANTIC
#include "lexical.hpp"
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

class Semantic{
    std::string str;
    std::smatch m; 
    std::vector<std::string> car; 
    std::vector<std::string> tree;
    std::vector<std::string> banana;
    std::vector<bool> b;
public:
    CompilerCompiler* compilerCompiler = nullptr;
    Semantic();
    Semantic(std::string);
    std::string getCode(); 
    void check(std::string); 
    bool getBool(); 
};

#endif
