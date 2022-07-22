//
//  main.cpp
//  6-1
//
//  Created by 김현배 on 2022/02/18.
//

#include <iostream>
#include <string>
class Cat{
public:
    Cat(std::string name,int age):mName{std::move(name)},mAge{age} {};
    const std::string& name() const{
        return mName;
    }
    int age() const{
        return mAge;
    }
    void print(std::ostream& os) const{
        os<<mName<<" "<<mAge<<std::endl;
    }
private:
    int mAge;
    std::string mName;
};

//std::cout과 os가 같은 이름을 공유하게된다.
std::ostream& operator<< (std::ostream& os, const Cat& c){
    return os<<c.name()<<" "<<c.age();
}

int main(int argc, const char * argv[]) {
    Cat kitty{"kitty",1};
    Cat nabi{"nabi",2};
    kitty.print(std::cout);
    nabi.print(std::cout);
    std::cout<<kitty<<std::endl; //cout은 ostream의 일종이다.
    return 0;
}
