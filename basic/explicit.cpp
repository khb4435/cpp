//
//  main.cpp
//  explicit
//
//  Created by 김현배 on 2022/02/18.
//

#include <iostream>
class Cat{
public:
    explicit Cat(int age):mAge{age}{} //무조건 생성자를 이 형식으로 만든다는 것임
    void speak() const{
        std::cout<<mAge<<std::endl;
    }
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    //Cat kitty; //오류
    //const Cat kitty=3; //오류
    const Cat kitty(3); //explicit하게 이거만 성공
    return 0;
}
