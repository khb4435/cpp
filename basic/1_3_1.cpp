//
//  main.cpp
//  3-1
//
//  Created by 김현배 on 2022/02/17.
//

#include <iostream>
class Cat{
public:
    void speak(){
        count++;
        std::cout<<count<<" "<<"meow"<<std::endl;
    }
private:
    int mAge;
    static int count; //static 멤버변수
};

int Cat::count =0;//초기화는 여기서

int main(int argc, const char * argv[]) {
    Cat kitty;
    Cat nabi;
    kitty.speak(); //count 1
    nabi.speak(); // count 2
    //count를 두 객체가 공유해서 쓰는 것 처럼 보인다.
    return 0;
}
