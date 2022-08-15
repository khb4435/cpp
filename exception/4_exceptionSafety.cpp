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
    //즉 strong exception safety를 중시하는 함수란 변경될 사안에 있는 것들을 exception 밑으로 뺀다.
    
    
    divide(10,0);
    g=1;
    //그 결과를 원한다면 로컬 변수로 저장
    int a = divide(10,0);
    int b = divide(10,1);
    int c = divide(10,2);
    
    //exception이 던져졌을대 global variable g에 변화가 없습니다. 
    //또한 divide()의 return value는 설명을 위해 f()안에서 무시하고있습니다. 
    //때문에 return value와 global variable g 와는 관계가 없는 상태입니다. 또 궁금한것 있으시면 질문주세요. 감사합니다.
    int a = divide(10,0);
    g=a;
    
    //g=divide(10,0); 당연히 strong safety garuntee를 원하면 exception이 불려질수도 있는 함수를
    //이렇게 사용해도 안됨
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
