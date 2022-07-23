//
//  main.cpp
//  object_slicing1
//
//  Created by 김현배 on 2022/02/19.
//


//&로 받아주면 오브젝트 슬라이싱 일어나지 않지만 value로 받아주면 object 슬라이싱 일어난다
#include <iostream>
class Animal{
public:
    Animal()=default;
    //Animal& operator= (Animal other) = delete;
    virtual void speak() {
        std::cout<<"animal"<<std::endl;
    }
    virtual ~Animal() = default;
private:
    double animalData=0.0f;
    //copy constructor 막기위함
protected:
    Animal(const Animal& other) = default; // copy constructor
};

class Cat : public Animal{
public:
    Cat(double d) : catData{d} {}
    void speak() override {
        std::cout<<"meow"<<std::endl;
    }
private:
    double catData;
};


int main(int argc, const char * argv[]) {
    Cat kitty{1.0};
    
    Animal& animalRef = kitty;
    animalRef.speak(); // meow //노 오브젝트 슬라이싱
    
    //Animal animalObj = kitty; //copy constructor
    //animalObj.speak(); //animal! //오브젝트 슬라이싱
    //오브젝트 슬라이싱 막기위해 copy constructor없애기 -> delete 혹은 protected??
    
    //근데 delete사용하면
    //Cat kitty{0.5};
    //Cat nabi{kitty}; derived클래스가 copy constructor쓸 때 base의 copy constructor도
    //사용하게 되는데 못하게된다
    return 0;
}
