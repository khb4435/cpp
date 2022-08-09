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
    cats.emplace_back(Cat{"kitty"}); //스택위에 Cat객체의 임시객체가 만들어지고 이 값들이 백터의 마지막 공간으로 move됨!
    cats.emplace_back(Cat{"nabi"}); //move process가 있다
    
    //move process없게도 가능.
    //cats.emplace_back("navi"); 이런식으로. 근데 이걸 가리키게 어떻게함? 이렇게 밑에처럼
    //push_back보다 이게 좋은거 이렇게 만들어진 백터공간을 레퍼런스로 받아줄 수 있음
    Cat& cat=cats.emplace_back("changmin"); //g++ 4.cpp -std=c++17
    
    Cat nabi{"nabi"};
    cats.emplace_back(nabi); //Lvalue copy
    cats.emplace_back(std::move(nabi)); //Rvalue = move
    //emplace_back엔 다음과같이 l value r value 모두 들어간다.
    return 0;
}
