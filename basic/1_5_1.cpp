//
//  main.cpp
//  5-1
//
//  Created by 김현배 on 2022/02/18.
//



//꼭 컴파일 후 오류 확인할 것
#include <iostream>
class Cat{
public:
    //1.생성자
    Cat() = default; //보통 static만 있으면 객체 만들 필요없으니까 이렇게
    //객체 만들기 싫으면, 생성자를 delete 시킨다
    //Cat() = delete;
    
    Cat(std::string name, int age) : mName{std::move(name)},mAge{age}{}
    
    //copy constructor, copy assignment 허용하지 않을 때
    Cat(const Cat& other) = delete;
    Cat& operator= (const Cat& other) = delete;
    
    void print() const{
        std::cout<<mName<<" "<<mAge<<std::endl;
    }
private:
    std::string mName;
    int mAge;
    //char* mPtr; 이 있다면 copy move constructor assignment를 직접해줘야하는데
    //없다면 컴파일러가 자동적으로 만들어준다.
    //5에서 한 건 학습이다.
};

int main(int argc, const char * argv[]) {
    Cat kitty{"kitty",1};
    
    Cat kitty2{kitty}; //거부된 copy constructor
    Cat kitty3{std::move(kitty)};
    
    Cat nabi{"nabi",2};
    nabi = kitty; //거부된 copy assignment
    nabi = std::move(kitty);
    
    return 0;
}
