//
//  main.cpp
//  5
//
//  Created by 김현배 on 2022/02/17.
//



//일반적으로 소멸자, 복사/이동생성자, 복사/이동 대입연사자는 우리가 직접 구현하지 않는다(멤버변수로 포인터있는상황제외)
//여기서는 어떤식으로 구현될 지 연습개념으로 구현해본다.

//소멸자, move constructor/assignment는 "noexcept"키워드가 필요하다.
//예외상황이 발생하지 않는 상황에서 발생되야하는 것들임

//move가 필요할 때 컴파일러가 noexcpt를 보고 확실하게 move를 call 해줄 수 있음

#include <iostream>
class Cat{
public:
    //1.생성자
    Cat() = default; //컴파일러가 만들어주는 생성자 활용
    Cat(std::string name, int age) : mName{std::move(name)},mAge{age} {}

    //2.소멸자
    ~Cat() noexcept {} //c++11부터 소멸자는 기본적으로 noexcpt이다.
    //noexcept란 예외를 발생시키지 않는 함수

    //3.copy constructor -> 인자로 L value, 기존 객체 활용하여 새로운 오브젝트 만들 때 내부 인자 전부 복사
    Cat(const Cat& other) : mName{other.mName},mAge{other.mAge} {
    //std::memcpy(); 클래스 인자로 포인터변수 있었을 경우
    }
    
    Cat(const Cat& other) = delete;

    //4.move constructor -> 인자로 R value, 기존 객체 활용하여 새로운 오브젝트 만들 때 내부 리소스를 복사하는게아니라 move로.
    Cat(const Cat&& other) noexcept : mName{std::move(other.mName)},mAge{other.mAge}{
    //mPtr = other.ptr;
    //other.ptr = nullptr;
    //클래스 인자로 포인터변수 있었을 경우
    }

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
    Cat kitty{"kitty",1}; //1.생성자 호출
    Cat kitty2{kitty}; //3 copy constructor
    Cat kitty3=kitty;//3 copy constructor
    //Assignmentc처럼 보이지만 constructor이다. 왜냐면 kitty3객체가 새로 만들어지는 것이기 때문

    Cat kitty4{std::move(kitty)}; //4 move constructor

    //5 copy assignment
    Cat nabi{"nabi",2};
    kitty=nabi; 

    kitty=std::move(nabi); //6 move assignment
    return 0;
}
