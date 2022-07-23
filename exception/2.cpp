//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/03/20.
//



//예외처리는 일단 객체가 만들어져서 throw되므로 for문에서의 예외처리는 지양한다
//일반적인 함수 return과 다른 path기 때문에 예외처리가 일어나는걸 미리 알고 코드를 짜지 않으면
//resource leak이 일어날 수있으니 주의
#include <iostream>
#include <exception>
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
    /*
    Cat *cp = new Cat(5);
    std::cout<<divide(10,0)<<std::endl; //exception발생
    delete cp; //exception이 불려지며 힙공간의 Cat객체를 소멸하지 못함
     */
    
    //unique pointer는 f()가 소멸되면서 cp의 소멸자도 자동으로 호출됨
    //스마트포인터 사용하면 exception에 더 안전한 코드 사용 가능
    std::unique_ptr<Cat> cp = std::make_unique<Cat>(5);
    std::cout<<divide(10,0)<<std::endl;
}

int main(int argc, const char * argv[]) {
    try{
        f();
    }
    catch(const std::exception(&e)){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
