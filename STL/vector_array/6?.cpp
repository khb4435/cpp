//
//  main.cpp
//  6
//
//  Created by 김현배 on 2022/02/20.
//

//move cons/assignment 나 destructor처럼 절대  exception이 나지 않는 곳에는 noexcept를 붙여줘야 optimization이 됩니다.
    
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
