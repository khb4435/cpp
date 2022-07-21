//
//  main.cpp
//  3
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
class Cat{
public:
    explicit Cat(int age) : mAge{age}{}
    void speak() const{
        std::cout<<"meow"<<std::endl;
    }
    void test() const{
        //auto lambda = [] (){ 이거로 하면 에러생김
        //auto lambda = [this] (){ //이거나
        auto lambda = [&] (){
            std::cout<<"lambda function"<<std::endl;
            
            //std::cout<<mAge<<std::endl;
            std::cout<<this->mAge<<std::endl;
            //speak();
            this->speak();
        };
        lambda();
    }
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    Cat kitty{1};
    kitty.test();
    return 0;
}
