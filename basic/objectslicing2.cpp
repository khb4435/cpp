//
//  main.cpp
//  object_slicing2
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <iostream>
class Animal{
public:
    Animal()=default;
    virtual void speak() {
        std::cout<<"animal"<<std::endl;
    }
    virtual ~Animal() = default;
public:
    double animalData=0.0f;
};

bool operator== (const Animal& lhs, const Animal& rhs){
    std::cout<<"animal comp"<<std::endl;
    return lhs.animalData == rhs.animalData //같으면 1, 다르면 0 return
}

class Cat : public Animal{
public:
    Cat(double d) : catData{d} {}
    void speak() override {
        std::cout<<"meow"<<std::endl;
    }
public:
    double catData;
};

bool operator== (const Cat& lhs, const Cat& rhs){
    std::cout<<"cat comp"<<std::endl;
    return lhs.catData == rhs.catData //같으면 1, 다르면 0 return
}

int main(int argc, const char * argv[]) {
    Cat kitty{1.0};
    Cat nabi{1.0};
    if(kitty == nabi){
        //==할 때 Cat == 없다면 Animal ==로 연산하게 된다.
        //근데 둘 다 만들자
        std::cout<<"same"<<std::endl;
    }
    else    std::cout<<"not same"<<std::endl;
    return 0;
}
