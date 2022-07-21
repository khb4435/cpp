//
//  main.cpp
//  enum
//
//  Created by 김현배 on 2022/02/27.
//


//버그 원천 차단
#include <iostream>

enum class Clothing_size{
    small,
    medium,
    large,
};

enum class Clothing_color{
    red,
    blue,
    yellow
};

//enum class도 클래스이기때문에 operator 사용가능함
Clothing_size& operator++ (Clothing_size& s){
    if(s==Clothing_size::large){
        return  s;
    }
    s=static_cast<Clothing_size>(static_cast<int>(s)+1);
    return s;
}

void buy_shirt(Clothing_size size, Clothing_color color){
    std::cout<<" "<<std::endl;
}

int main(int argc, const char * argv[]) {
    buy_shirt(Clothing_size::medium,Clothing_color::red);
    return 0;
}
