#include "analysis/syntax.hpp"
#include "analysis/semantic.hpp"

int main(){
    Lexical lexical; 

    if(lexical.getBool()){
       std::cout << lexical.getCode() << std::endl;
    
       std::string out = "#include <iostream>\n\nint main(){\n" + lexical.getCode() + "}"; 
    
       std::ofstream ofs ("output.cc", std::ofstream::out);
       ofs << out;
    }

    remove("carSymbolTable");
    remove("treeSymbolTable");
    remove("bananaSymbolTable");
}
