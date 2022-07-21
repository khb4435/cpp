//
//  main.cpp
//  4
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <string>
class Cat{
public:
    Cat(std::string name):mName{std::move(name)} {}
private:
    std::string mName;
};

int main(int argc, const char * argv[]) {
    std::vector<Cat> cats;
    cats.emplace_back(Cat{"kitty"}); //move process가 있다
    cats.emplace_back(Cat{"nabi"}); //move process가 있다
    
    //move process없게
    Cat& cat=cats.emplace_back("changmin"); //g++ 4.cpp -std=c++17
    
    Cat nabi{"nabi"};// Lvalue = copy
    cats.emplace_back(std::move(nabi)); //Rvalue = move
    return 0;
}
