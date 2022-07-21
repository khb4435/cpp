//
//  main.cpp
//  4
//
//  Created by 김현배 on 2022/03/20.
//

//exception safety : destrucotr, swap, move,defualt constrotor등은 절대 예외처리 throw 하면안됨
//:no except붙여주기
//2.strong exception safety : when exception is executed, no memory leak, no changed state!!
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
    //g=1; 이걸 밑으로 보내기만 하면됌
    //즉 strong exception safety를 중시하는 함수란 변경될 사안에 있는 것들을 exception 밑으로 빼는등..
    int a = divide(10,0);
    g=a;
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
