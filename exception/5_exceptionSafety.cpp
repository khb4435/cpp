//
//  main.cpp
//  5
//
//  Created by 김현배 on 2022/03/20.
//

//exception safety : destrucotr, swap, move,defualt constrotor등은 절대 예외처리 throw 하면안됨
//:no except붙여주기
//3.no throw garuntee : exception이 던져지지 않은 함수

#include <iostream>
#include <exception>
int g=0;
class Cat{
public:
    Cat(int age) : mAge{age} {};
    ~Cat()=default;
private:
    int mAge;
};

int divide(int a, int b){
    if(b==0){
        throw::std::runtime_error("divide by 0");
    }
    return a/b;
}

void f(){
    try{
        int a = divide(10,0);
        g=a;
    }//main까지 exception이 propagated되지 않음!!!!
    //catch가 불려질때까지 팝되는데, catch가 여기 있어서 f가 팝이 안됬나봄
    catch(const std::exception(&e))
    {
    }
}

int main(int argc, const char * argv[]) {
    std::cout<<"g :"<<g<<std::endl;
    try{
        f();
    }
    catch(const std::exception(&e)){
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"g :"<<g<<std::endl;
    return 0;
}
