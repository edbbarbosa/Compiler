#include "tree.hpp"

Tree::Tree(std::string str){
    this->str = str;

    while(this->str.find("tree") != std::string::npos)
        this->str.replace(this->str.find("tree"), 4, "float");
}

std::string Tree::getCode(){
   return "\t" + this->str;
}