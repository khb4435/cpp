//
//  main.cpp
//  shared_ptr2
//
//  Created by 김현배 on 2022/02/20.
//


//shared ptr에서 메모리 릭이 발생하는 경우
#include <iostream>
#includd <memory>
class Cat{
public:
    Cat():mAge{0} {}
    ~Cat(){}
    std::shared_ptr<Cat> mVar; //Cat.mVar is in Heap
};

int main(int argc, const char * argv[]) {
    std::shared_ptr<Cat> mPtr //mPtr is in Stack
    = std::make_shared<Cat>();
    mPtr->mVar = mPtr;
    std::cout<<"count: "<<mPtr.use_count()<<std::endl; //2
    
    //memory leak happens
    //메인 함수가 종료되는데(mPtr해제) count가 남아있어서 1
    return 0;
}
