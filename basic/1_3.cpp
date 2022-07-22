//
//  main.cpp
//  3
//
//  Created by 김현배 on 2022/02/17.
//

#include <iostream>
class Cat{
public:
    void speak(){ //일반 멤버함수
        std::cout<<"meow"<<std::endl;
    }
    static void staticSpeak(){//객체에 종속되지 않은 static 멤버함수
        std::cout<<"static meow!!"<<std::endl;
        //std::cout<<mAge<<std::endl; //mAge는 멤버변수이고 멤버변수는 객체에 종속됨 즉
        //this->mAge임.
        //일반 멤버함수는 this->speak()같이 객체에 마찬가지로 종속되어 있어 객체에 종속된 멤버변수를 멤버함수내에서 쓸 수 있지만 이건 아님
        //speak();
    }
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    Cat kitty;
    kitty.speak();
    
    Cat::staticSpeak();
    
    kitty.staticSpeak(); //스태틱 멤버함수도 결국 멤버함수라 객체이용하여 쓸 순 있다.
    return 0;
}
