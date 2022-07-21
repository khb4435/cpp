//
//  main.cpp
//  1
//
//  Created by 김현배 on 2022/02/20.
//


//RAII
#include <iostream>
#include <memory> //smart pointer
#include <vector>

class Cat{
public:
    Cat() = default; //안 넣어주니까 new Cat[5]에서 오류생겼었다
    Cat(int age) : mAge{age} {}
    ~Cat() noexcept {
        std::cout<<"destructor"<<std::endl;
    };
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    Cat kitty{3};//stack
    Cat* catPtr = new Cat{3}; //heap
    delete catPtr;
    
    Cat* cats = new Cat[5];
    delete [] cats;
    
    //스마트 포인터
    std::unique_ptr<Cat> catPtr1//catPtr1 in stack which pointing Cat type in heap
    = std::make_unique<Cat>(3);
    //이건 delete를 자동적으로 해준다
    
    //""배열을"" 스마트 포인팅 즉 자동 소멸기능 있게 하는방법? 벡터
    std::vector<Cat> catss(5); //5개
    //std::vector<Cat> catssss[5]; //1개
    return 0;
}
