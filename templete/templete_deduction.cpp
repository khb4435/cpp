//
//  main.cpp
//  templete_deduction
//
//  Created by 김현배 on 2022/02/22.
//


//g++ main.cpp -Wall
//./a.out | c++filt -t
#include <iostream>
template<typename T>
void printVar(T &&a){ //forward reference (universal reference)
    //Lvalue, Rvalue다 들어갈 수 있음 인자로
    std::cout<<a<<std::endl;
}

void printLref(int &a){
    std::cout<<a<<std::endl;
}

void printRref(int &&a){
    std::cout<<a<<std::endl;
}

int main(int argc, const char * argv[]) {
    int a=1;
    //printRref(a); 에러
    printVar(a); //void printVar<int&>(int&)
    printVar(std::move(a)); //void printVar(int)(int&&)
    
    std::string s="nocope";
    printVar(s);
    printVar(std::move(s));
    return 0;
}
