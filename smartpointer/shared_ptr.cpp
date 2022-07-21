//
//  main.cpp
//  shared_ptr
//
//  Created by 김현배 on 2022/02/20.
//

//shared pointer는 많은 스마트 포인터들에 둘려쌓여질 수 있음
//shared pointer는 count라는 게 있는데 포인팅당하는 갯수를 알려줌
//count가 0일 때 소멸자가 호출된다
#include <iostream>
class Cat{
public:
    Cat() : mAge{0}{}
    ~Cat(){}
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    std::shared_ptr<Cat> catPtr = std::make_shared<Cat>();
    std::cout<<"count: "<<catPtr.use_count()<<std::endl; //1
    
    std::shared_ptr<Cat> catPtr1 = catPtr;
    std::cout<<"count: "<<catPtr.use_count()<<std::endl; //2
    return 0;
}
