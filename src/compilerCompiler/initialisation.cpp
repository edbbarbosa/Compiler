#include "initialisation.hpp"

Initialisation::Initialisation(std::string str){
    this->str = str; 
}

std::string Initialisation::getCode(){
    return "\t" + this->str;
}
