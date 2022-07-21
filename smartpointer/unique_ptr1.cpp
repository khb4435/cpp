//
//  main.cpp
//  unique_ptr
//
//  Created by 김현배 on 2022/02/20.
//


//유니크 포인터는 주로 멤버변수가 포인터일때 사용된다
//런 금지
#include <iostream>
#include <memory>
class Cat : public Animal {
public:
    Cat():mAge{0}{}
    ~Cat(){}
private:
    int mAge;
};
class Dog : public Animal {} ;
class Zoo : public Animal {
public:
    //prefer enum class
    Zoo(int n){
        if(n==1){
            mAnimal = std::make_unique<Cat>(); //upcast
        }
        else{
            mAnimal = std::make_unique<Dog>(); //upcast
        }
    }
private:
    std::unique_ptr<Animal*> mAnimal;
};

int main(int argc, const char * argv[]) {
    Zoo zo(1);
    std::cout<<zo.mAnimal<<std::endl;
    return 0;
}
