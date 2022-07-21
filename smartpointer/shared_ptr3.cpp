//
//  main.cpp
//  shared_ptr3
//
//  Created by 김현배 on 2022/02/20.
//



//shared_ptr이 멤버변수로 있을 때
#include <iostream>
#include <memory>
class Cat{
public:
    explicit Cat(int n) : mVar{std::make_shared<int>()} {}
    ~Cat() noexcept {}
    
    Cat clone() const{
        Cat tmp{*mVar};
        return tmp;
    }
private:
    std::shared_ptr<int> mVar;
};

int main(int argc, const char * argv[]) {
    Cat kitty{2};
    Cat nabi{kitty}; //copy constructor
    //같은 int가 kitty.mVar과 nabi.mVar에 포인팅됨
    //즉 멤버변수에 shared_ptr있다면 어떠한 같은 녀석을 포인팅하게됨
    
    //근데 다른 int를 포인팅하게 하고 싶다면?
    Cat nabi2{kitty.clone()};
    return 0;
}
