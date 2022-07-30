//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/18.
//

//다이아몬드상속
#include <iostream>
class Animal{
public:
    Animal(){}
    virtual void speak(){}
    virtual ~Animal(){}
};

//class Lion : public Animal
class Lion : virtual public Animal{//다이아몬드 상속일 경우 virtual 붙여줘야한다.
public:
    Lion(){}
    virtual ~Lion(){}
    virtual void speak(){}
private:
    double lionData;
};

//class Tiger : public Animal{
class Tiger : virtual public Animal{
public:
    Tiger(){}
    virtual ~Tiger(){}
    virtual void speak(){}
private:
    double tigerData;
};

class Liger : public Lion, public Tiger{
public:
    Liger(){}
    ~Liger(){}
    void speak() override {}
private:
    double ligerData;
};


int main(int argc, const char * argv[]) {
    Liger liger; //animal constructor가 2개 나온다.
    //1개로 만들어주기위해, 다이아몬드 상속시에 virtual 상속이 필요한 것이다.
    return 0;
}