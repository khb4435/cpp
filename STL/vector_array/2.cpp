//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
class Cat{
public:
    explicit Cat(int age) : mAge{age} {} //명시적인 생성자 생성방법 explicit
    void speak() const{}
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    std::vector<Cat> cats;
    cats.emplace_back(Cat(1));
    cats.emplace_back(Cat(2));
    cats.emplace_back(Cat(3));
    cats.emplace_back(Cat(4));
    
    for(const auto& cat:cats){
        cat.speak();
    }
    return 0;
}
