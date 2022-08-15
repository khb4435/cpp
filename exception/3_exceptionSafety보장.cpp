
//exception safety : destrucotr, swap, move,defualt constrotor등은 절대 예외처리 throw 하면안됨
//:no except붙여주기

//총3가지의 exception safety garuntee가 있는데, 고려해주지 않으면 메모리 릭 일어난다.
//1.basic exception safety : when exception is executed, no memory leak, but changed state!!
//2.strong exception safety : no memory leak, no changed state!!
//3.no safety garuntee

//위 세가지를 모두 지키지 않는 no safety exception
#include <iostream>
#include <exception>

int divide(int a, int b){
    if(b==0){
        throw std::runtime_error("divided by 0");
    }
    return a/b;
}

void f(){
    Cat *cp = new Cat();
    divide(10,0);
    delete cp;
}

int main(){
    try{
        f();
    }
    catch(const std::exception &e){
        std::cout<<e.what<<std::endl;
    }
}

//basic safety garuntee
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
    g=1; //state changed
    divide(10,0);
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
