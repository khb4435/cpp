//
//  main.cpp
//  variant4
//
//  Created by 김현배 on 2022/03/01.
//



//optional, pair, tuple

//int와 Enum class가 메모리를 공유함에도 불구하고 pair, tuple과 아무 차이없이 이용가능하다
//std::variant<int,Error_code> double(int a,int b){
//    if(b==0){
//        return Error_code::divide0
//    }
//    return a/b;
//};

#include <iostream>
#include <variant>
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
