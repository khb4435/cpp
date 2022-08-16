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
    }//exception이 divide함수에서 던져지고 f()함수에서 잡힙니다.
    //그러니까 f()를 부르는 caller, main은 f()가 exception을 던지지 않는다는 것을
    //알고있고 이를 no throw garuntee라고 한다.
    return a/b;
}

void f(){
    try{
        int a = divide(10,0);
        g=a;
    }//main까지 exception이 propagated되지 않음!!!!
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
