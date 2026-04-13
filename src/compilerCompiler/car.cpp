#include "car.hpp"

Car::Car(std::string str){
    this->str = str;

    while(this->str.find("car") != std::string::npos)
        this->str.replace(this->str.find("car"), 3, "unsigned int");
}

std::string Car::getCode(){
    return "\t" + this->str;
}
