#include "cpplib.h"
#include "limits"

// Question 2

// Question 3
void CPPLib::mergeArray(std::vector<int>& input1, std::vector<int>& input2){

}

// Question 4
Car_shallow::Car_shallow(){

}

Car_shallow::Car_shallow(int a, int b, int c, int d){

}

void Car_shallow::print(){
    for (auto& i: (*tires))
        std::cout << i << " ";
    std::cout << std::endl; 
}

Car_deep::Car_deep(){
}

Car_deep::~Car_deep(){

}

Car_deep::Car_deep(int a, int b, int c, int d){

}

Car_deep::Car_deep(const Car_deep& c){

}

Car_deep& Car_deep::operator=(const Car_deep& c){

}

void Car_deep::print(){
    for (auto& i: (*tires))
        std::cout << i << " ";
    std::cout << std::endl; 
}

// Question 5
bool CPPLib::CheckValidExpression(const std::string& a){
    
}
