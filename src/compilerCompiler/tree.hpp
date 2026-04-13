#ifndef TREE
#define TREE
#include "compilercompiler.hpp"

class Tree: public CompilerCompiler{
    std::string str;
public:
    Tree(std::string str); 
    std::string getCode() override; 
};

#endif
