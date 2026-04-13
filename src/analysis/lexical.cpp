#include "lexical.hpp"

void Lexical::check(std::string str){
    if (std::regex_search(str, m, std::regex ("car\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("tree\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("banana\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("se\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("whilst\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("para\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("grape\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("avocado\\s+"))){
       //
    } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]+;"))){
       //
    } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]*\\.[0-9]+;"))){
       //
    } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+\"[^\"]*\""))){
       //
    } else if (str == ""){
       //
    } else {
       this->b.push_back(false);
       std::cerr << "\nLexical error" << std::endl;
    } 
}

Lexical::Lexical(){
  std::ifstream file("input.txt");
  std::string line;

  while(getline(file, line)){
    check(line);
  }

  if(!count(b.begin(), b.end(), false)){
    syntax = new Syntax();
  }
}

Lexical::Lexical(std::string str){
  check(str);

  if(!count(b.begin(), b.end(), false)){
    syntax = new Syntax(str);
  }
}


std::string Lexical::getCode(){
  return syntax->getCode();
}

bool Lexical::getBool(){
  if(count(b.begin(), b.end(), false)){
    return false;
  } else {
    return syntax->getBool();
  }
}

