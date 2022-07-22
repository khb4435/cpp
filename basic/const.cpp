//
//  main.cpp
//  const
//
//  Created by 김현배 on 2022/02/18.
//

#include <iostream>
#include <string>
class Cat{
public:
    Cat(std::string name):mName{std::move(name)}{}
    void speak() const{
        mName="nabi"; //mutable변수는 const함수내에서 바뀔 수 있음
        std::cout<<mName<<std::endl;
    }
private:
    mutable std::string mName;
};

int main(int argc, const char * argv[]) {
    Cat kitty{"kitty"};
    kitty.speak(); //nabi
    return 0;
}
