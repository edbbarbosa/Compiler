#include "semantic.hpp"

void Semantic::check(std::string str){
    std::string line;

    std::ifstream fileCar("carSymbolTable"); 
    
    while(getline(fileCar, line)){
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); 
        if(!count(car.begin(), car.end(), line)){
            car.push_back(line); 
        }
    }

    std::ifstream fileTree("treeSymbolTable"); 

    while(getline(fileTree, line)){
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); 
        if(!count(tree.begin(), tree.end(), line)){
           tree.push_back(line);
        }
    }

    std::ifstream fileBanana("bananaSymbolTable"); 

    while(getline(fileBanana, line)){
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); 
        if(!count(banana.begin(), banana.end(), line)){
            banana.push_back(line);
        }
    }

    if (std::regex_search(str, m, std::regex("^para\\s+\\(car\\s+[A-Za-z]+\\s+=\\s+[0-9]+;\\s+[A-Za-z]+\\s+<\\s+[0-9]+;\\s+[A-Za-z]+\\+\\+\\)\\s+\\{[^}]*\\}$"))){

        compilerCompiler = new Para(str);

        std::string tmp0 = str;

         while(std::regex_search(str, m, std::regex("car\\s+[A-Za-z]+\\s+=\\s+[0-9]+;"))){
            tmp0 = tmp0 + m.str(0) + "\n";
             str = m.suffix().str();
        }

        tmp0.erase(0, 10);
    
        for(int i = 0; i < tmp0.length(); i++){
         if(tmp0[i] == '='){
	    tmp0.erase(i, tmp0.length());
	    break;
         }
    }
    tmp0.erase(remove_if(tmp0.begin(), tmp0.end(), isspace), tmp0.end()); 

    std::string tmp1;
    
    while(std::regex_search(str, m, std::regex("[A-Za-z]+\\s+<\\s+[0-9]+;"))){
	tmp1 = tmp1 + m.str(0) + "\n";
	str = m.suffix().str();
    }

    for(int i = 0; i < tmp1.length(); i++){
      if(tmp1[i] == '<'){
	tmp1.erase(i, tmp1.length());
	break;
      }
    }
    tmp1.erase(remove_if(tmp1.begin(), tmp1.end(), isspace), tmp1.end());

    std::string tmp2;
    
    while(std::regex_search(str, m, std::regex("[A-Za-z]+\\+\\+"))){
	tmp2 = tmp2 + m.str(0) + "\n";
	str = m.suffix().str();
    }

    for(int i = 0; i < tmp2.length(); i++){
      if(tmp2[i] == '+'){
	tmp2.erase(i, tmp2.length());
	break;
      }
    }
    tmp2.erase(remove_if(tmp2.begin(), tmp2.end(), isspace), tmp2.end());
    
    if(tmp0 == tmp1){
      if(tmp1 == tmp2){
	this->str = this->str + compilerCompiler->getCode() + "\n";
      } else {
	b.push_back(false);
	std::cerr << "Semantic error" << std::endl << "Error in 'para'" << std::endl;
      }
    } else {
      b.push_back(false);
      std::cerr << "Semantic error" << std::endl << "Error in 'para'" << std::endl;
    }
  
  } else if (std::regex_search(str, m, std::regex ("car\\s+[A-Za-z]+\\s+=\\s+[0-9]+\\;|car\\s+[A-Za-z]+\\;"))){

    compilerCompiler = new Car(str);

    str.erase(0, 4);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
      std::cerr << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
      b.push_back(false);
    } else {
      car.push_back(str);
      this->str = this->str + compilerCompiler->getCode() + "\n";
    }
       
  } else if (std::regex_search(str, m, std::regex("tree\\s+[A-Za-z]\\s+=\\s+[0-9]*\\.[0-9]+;|tree\\s+[A-Za-z];|tree\\s+[A-Za-z]\\s+=\\s+[0-9]+;"))){

    compilerCompiler = new Tree(str);

    str.erase(0, 4);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
      std::cerr << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
      b.push_back(false);
    } else {
      tree.push_back(str);
      this->str = this->str + compilerCompiler->getCode() + "\n";
    }

  } else if (std::regex_search(str, m, std::regex("banana\\s+[A-Za-z]+;|banana\\s+[A-Za-z]+\\s+=\\s+\"[^\"]*\";"))){

    compilerCompiler = new Banana(str);

    str.erase(0, 6);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
      std::cerr << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
      b.push_back(false);
    } else {
      banana.push_back(str);
      this->str = this->str + compilerCompiler->getCode() + "\n";
    }

  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}"))){

    compilerCompiler = new Sesenao(str);
    
    for(int i = 0; i < str.length(); i++){
      if(str[i] == '('){
	str.erase(0, i+1);
      } else if (str[i] == ')'){
	str.erase(i);
      }
    }

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<'){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else {
      std::cerr << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
      b.push_back(false);
    }

    
  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){

    compilerCompiler = new Sesenao(str);
        
    for(int i = 0; i < str.length(); i++){
      if(str[i] == '('){
	str.erase(0, i+1);
      } else if (str[i] == ')'){
	str.erase(i);
      }
    }

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<'){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else {
      std::cout << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
      b.push_back(false);
    }   
    
  } else if (std::regex_search(str, m, std::regex("whilst\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){

    compilerCompiler = new Whilst(str);

    int start, end;
    
    for(int i = 0; i < str.length(); i++){
      if(str[i] == '('){
	start = i + 1;
	//str.erase(0, i + 1);
      } else if(str[i] == ')'){
	end = i;
	//str.erase(i, str.length());
	break;
      }
    }

    str.erase(end, str.length());
    str.erase(0, start);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<'){
	str.erase(i, str.length());
      }
    }
    
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else {
      std::cerr << "Semantic error" << std::endl << "The variable has already been declared" << str << std::endl;
      b.push_back(false);
    }

 } else if (std::regex_search(str, m, std::regex("grape\\s+\\([A-Za-z0-9]+\\)\\;"))){

    compilerCompiler = new Grape(str);

      int start, end; 
      for(int i = 0; i < str.length(); i++){
	if(str[i] == '('){
	  start = i+1;
	}
	if (str[i] == ')'){
	  end = i;
	}
      }
      str.erase(end, str.length());
      str.erase(0, start);
      str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
      if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
	this->str = this->str + compilerCompiler->getCode() + "\n";
      } else {
	std::cout << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
	b.push_back(false);
      }   
      
  } else if (std::regex_search(str, m, std::regex("avocado\\s+\\([^)]*\\)\\;"))){

    compilerCompiler = new Avocado(str);

    if(std::regex_search(str, m, std::regex("avocado\\s+\\(\"[^\"]*\"\\)"))){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else {
      int start, end; 
      for(int i = 0; i < str.length(); i++){
	if(str[i] == '('){
	  start = i+1;
	}
	if (str[i] == ')'){
	  end = i;
	}
      }
      str.erase(end, str.length());
      str.erase(0, start);
      str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
      if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str) || count(banana.begin(), banana.end(), str)){
	this->str = this->str + compilerCompiler->getCode() + "\n";
      } else {
	std::cout << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
	b.push_back(false);
      }   
    }
    
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]+;"))){

    compilerCompiler = new Initialisation(str);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    if(count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str)){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else if (count(banana.begin(), banana.end(), str)){
      std::cout << "Semantic error" << std::endl << "The variable is a banana, it should receive a string" << std::endl;
      b.push_back(false);
    } else {
      std::cout << "Semantic error" << std::endl << "The variable has already been declared" << std::endl;
      b.push_back(false);
    }

  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]*\\.[0-9]+;"))){

    compilerCompiler = new Initialisation(str);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    if(count(tree.begin(), tree.end(), str)){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else if (count(car.begin(), car.end(), str)){
      std::cerr << "Semantic error" << std::endl << "The variable is an integer, it cannot receive a decimal number" << std::endl;
      b.push_back(false);
    } else if (count(banana.begin(), banana.end(), str)){
      std::cerr << "Semantic error" << std::endl << "The variable is a banana, it should receive a string" << std::endl;
      b.push_back(false);
    } else {
      std::cerr << "Semantic error" << std::endl << "The variable was not declared" << std::endl;
      b.push_back(false);
    }

  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+\"[^\"]*\""))){

    compilerCompiler = new Initialisation(str);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    if(count(banana.begin(), banana.end(), str)){
      this->str = this->str + compilerCompiler->getCode() + "\n";
    } else if (count(car.begin(), car.end(), str) || count(tree.begin(), tree.end(), str)){
      std::cout << "Semantic error" << std::endl << "The variable does not accept banana (string)" << std::endl;
      b.push_back(false);
    } else { 
      std::cout << "Semantic error" << std::endl << "The variable was not declared" << std::endl;
      b.push_back(false);
    }
    
  } else if (str == ""){
    //
  } else {
    b.push_back(false);
    std::cout << "\nSemantic error" << std::endl;
  }
    
 std::ofstream ofsCar ("carSymbolTable", std::ofstream::out);

  for (int i = 0; i < car.size(); i++){
    ofsCar << car[i] << "\n"; 
  }

  std::ofstream ofsTree ("treeSymbolTable", std::ofstream::out);

  for (int i = 0; i < tree.size(); i++){
    ofsTree << tree[i] << "\n"; 
  }

  std::ofstream ofsBanana ("bananaSymbolTable", std::ofstream::out);

  for (int i = 0; i < banana.size(); i++){
    ofsBanana << banana[i] << "\n"; 
  }

}

Semantic::Semantic(){
  std::ifstream file("input.txt");
  
  std::string line;

  while(getline(file, line)){
    check(line);
  }
  
}

Semantic::Semantic(std::string str){
  check(str);
}

std::string Semantic::getCode(){
  return this->str;
}

bool Semantic::getBool(){
  if(count(b.begin(), b.end(), false)){
    return false;
  } else {
    return true;
  }
}
