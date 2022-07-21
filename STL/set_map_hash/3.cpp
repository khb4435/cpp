//
//  main.cpp
//  3
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <set>
class Cat{
public:
    Cat(int age, std::string name) : mName{std::move(name)},mAge{age} {}
    void speak() const{}
    int age() const{
        return mAge;
    }
    const std::string& name() const{
        return mName;
    }
private:
    std::string mName;
    int mAge;
};


//이거 없으면 컴파일에러 왜?
//set은 이 operator와 함께 동작하는 ordered function임
bool operator< (const Cat& lhs, const Cat& rhs){
    return lhs.age() > rhs.age(); //나이로 비교
    //return lhs.name() > rhs.name(); //이름으로 비교
}
//

int main(int argc, const char * argv[]) {
    std::set<Cat> cats;
    cats.emplace(1,"nabi");
    cats.emplace(2,"kitty");
    
    for(const auto& cat:cats){
        cat.speak();
    }
    return 0;
}
