#ifndef CAR
#define CAR
#include "compilercompiler.hpp"

class Car: public CompilerCompiler{
    std::string str;
public:
    Car(std::string);
    std::string getCode() override;
};

#endif