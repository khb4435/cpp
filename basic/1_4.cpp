//
//  main.cpp
//  4
//
//  Created by 김현배 on 2022/02/17.
//

#include <iostream>
class Cat{
public:
    Cat() : mAge{1} {}
    Cat(int age) : mAge{age} {}
    ~Cat() {}
private:
    int mAge;
};

class Zoo{
public:
    Zoo(int kitty) : mkitty{kitty} {}
private:
    Cat mkitty;
};

int main(int argc, const char * argv[]) {
    Zoo cppZoo(5);
    //이니셜라이저를 사용함으로 어떠한 과정없이 mkitty의 age가 바로 5가 됨
    return 0;
}
