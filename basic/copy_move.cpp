//
//  main.cpp
//  5
//
//  Created by 김현배 on 2022/02/17.
//




//소멸자, move constructor/assignment는 noexcpet 예외처리가 일어나지 않게 해줘야함!!!
//이동의 에외발생은 매우 무서운것이라서 그렇다.
//move가 필요할 때 컴파일러가 noexcpt를 보고 확실하게 move를 call 해줄 수 있음, 아니면 그냥 복사생성하게된다.
#include <iostream>
class Cat{
public:
    //1.생성자
    Cat() = default;
    Cat(std::string name, int age) : mName{std::move(name)},mAge{age} {}

    //2.소멸자
    ~Cat() noexcept {} //c++11부터 소멸자는 기본적으로 noexcpt이다.
    //noexcept란 예외를 발생시키지 않는 함수

    //3.copy constructor -> L value
    Cat(const Cat& other) : mName{other.mName},mAge{other.mAge} {}

    //4.move constructor -> R value
    Cat(const Cat&& other) noexcept : mName{std::move(other.mName)},mAge{other.mAge}{}

    //5.copy assignment -> L value
    Cat& operator= (const Cat& other){
        if(&other = this){
            return *this;
        }
        mName=other.mName;
        mAge=other.mAge;
        return *this;
    }

    //6.move assignment -> Rvalue
    Cat& operator= (const Cat&& other) noexcept {
        if(&other = this){
            return *this;
        }
        mName=std::move(other.mName);
        mAge=other.mAge;
        return *this;
    }
private:
    std::string mName;
    int mAge;
};
int main(int argc, const char * argv[]) {
    Cat kitty{"kitty",1}; //1.생성
    Cat kitty2{kitty}; //3 copy constructor
    Cat kitty3=kitty;//3
    //Assignmentc처럼 보이지만 constructor이다. 왜냐면 kitty3객체가 새로 만들어지는 것이기 때문
    Cat kitty4{std::move(kitty)}; //4 move constructor

    Cat nabi{"nabi",2};
    kitty=nabi; //5 copy assignment

    kitty=std::move(nabi); //6 move assignment
    return 0;
}
