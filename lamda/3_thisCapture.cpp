//
//  main.cpp
//  3
//
//  Created by 김현배 on 2022/02/20.
//

//일단 this는 클래스와 관련이 있음

#include <iostream>
class Cat{
public:
    explicit Cat(int age) : mAge{age}{}
    void speak() const{
        std::cout<<"meow"<<std::endl;
    }
    void test() const{
        //auto lambda = [] (){ 이거로 멤버변수/함수 접근하려고하면 에러생김
        
        //멤버함수내에서 그냥 멤버변수,멤버함수 접근은 괜찮은데(this에 연결된것들임) lamda scope에서 접근하려고 하며 오류남
        //그래서
        //auto lambda = [this] (){ //이거나
        auto lambda = [&] (){ //->컴파일러가 알아서 auto this capture
            std::cout<<"lambda function"<<std::endl;
            
            std::cout<<mAge<<std::endl;
            std::cout<<this->mAge<<std::endl;
            
            speak();
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
