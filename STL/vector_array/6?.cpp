//
//  main.cpp
//  6
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
class Cat{
public:
    explicit Cat(std::string name) : mName{std::move(name)} {}
    ~Cat() noexcept {}
    Cat(const Cat &other) : mName{other.mName}{}
    Cat(Cat &&other) noexcept : mName{std::move(other.mName)}{}
private:
    std::string mName;
};

int main(int argc, const char * argv[]) {
    std::vector<Cat> cats;
    
    cats.reserve(2);
    cats.emplace_back("kitty");
    cats.emplace_back("nabi");
    return 0;
}
