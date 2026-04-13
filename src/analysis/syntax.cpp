#include "syntax.hpp"

void Syntax::check(std::string str){
    if (std::regex_search(str, m, std::regex ("car\\s+[A-Za-z]+\\s+=\\s+[0-9]+\\;|car\\s+[A-Za-z]+\\;"))){
        //
    } else if (std::regex_search(str, m, std::regex("tree\\s+[A-Za-z]\\s+=\\s+[0-9]*\\.[0-9]+;|tree\\s+[A-Za-z];|tree\\s+[A-Za-z]\\s+=\\s+[0-9]+;"))){
        //
    } else if (std::regex_search(str, m, std::regex("banana\\s+[A-Za-z]+;|banana\\s+[A-Za-z]+\\s+=\\s+\"[^\"]*\";"))){
        //
    } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}"))){
        //
    } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){
        //
    } else if (std::regex_search(str, m, std::regex("whilst\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){
        //
    } else if (std::regex_search(str, m, std::regex("^para\\s+\\(car\\s+[A-Za-z]+\\s+=\\s+[0-9]+;\\s+[A-Za-z]+\\s+<\\s+[0-9]+;\\s+[A-Za-z]+\\+\\+\\)\\s+\\{[^}]*\\}$"))){
        //
    } else if (std::regex_search(str, m, std::regex("grape\\s+\\([A-Za-z0-9]+\\)\\;"))){
        //
    } else if (std::regex_search(str, m, std::regex("avocado\\s+\\([^)]*\\)\\;"))){
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
       std::cerr << "\nSyntax error" << std::endl;
    }
}

Syntax::Syntax(){
    std::ifstream file("input.txt");
  
    std::string line;
  
    while(getline(file, line)){
       check(line);
    }

    if(!count(b.begin(), b.end(), false)){
       semantic = new Semantic();
    }
}

Syntax::Syntax(std::string str){
  check(str);

  if(!count(b.begin(), b.end(), false)){
    semantic = new Semantic(str);
  }
}

std::string Syntax::getCode(){
  return semantic->getCode();
}

bool Syntax::getBool(){
  if(count(b.begin(), b.end(), false)){
    return false;
  } else {
    return semantic->getBool();
  }
}