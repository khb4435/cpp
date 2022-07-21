//
//  main.cpp
//  unique_ptr2
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <memory>

class Cat{
public:
    Cat() : mVar{std::make_unique<int>()} {}
    virtual ~Cat(){}
    
    //에러 피하기위해 copy constructor
    Cat(const Cat& other) : mVar{std::make_unique<int>(*other.mVar)} {}
    //*주소 = value
private:
    std::unique_ptr<int> mVar;
};

int main(int argc, const char * argv[]) {
    Cat kitty;
    Cat nabi = kitty; //원랜 컴파일 에러
    //멤버 변수에 포인터있을 경우 copy constructor 등등 직접 정의 해줘야 한댔지?
    return 0;
}
