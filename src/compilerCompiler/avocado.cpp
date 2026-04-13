#include "avocado.hpp"

Avocado::Avocado(std::string str){
    this->str = str;
  
  char c0[] = "()";
  for(unsigned i = 0; i < strlen(c0); ++i)
    this->str.erase(std::remove(this->str.begin(), this->str.end(), c0[i]), this->str.end());

  while(this->str.find("avocado") != std::string::npos)
    this->str.replace(this->str.find("avocado"), 7, "std::cout <<");
}

std::string Avocado::getCode(){
  return "\t" + this->str;
}