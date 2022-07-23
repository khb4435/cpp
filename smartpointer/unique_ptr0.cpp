//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/20.
//


//기본적으로 객체는 많은 포인터들에 의해 포인팅될 수 있다.
//하지만 unique_ptr은 객채에 대한 유일한 소유권을 갖는다
//즉 이걸 사용하면 이거만 그 객체에 포인팅한다는 말이다.
#include <iostream>
#include <memory>
class Cat{
public:
    Cat():mAge{0}{}
    ~Cat(){}
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    std::unique_ptr<Cat> catPtr = std::make_unique<Cat>();
    //이거로 Cat객체에 catPtr이라는 포인터변수가 포인팅하고있는 상태이고
    
    //std::unique_ptr<Cat> catPtr1 = std::make_unique<Cat>(); //불가
    std::unique_ptr<Cat> catPtr2 = std::move(catPtr); //소유권 이전은 가능
    return 0;
}
