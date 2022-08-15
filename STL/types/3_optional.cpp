//
//  main.cpp
//  optional
//
//  Created by 김현배 on 2022/02/27.
//



//pair사용보다 더 효율적이다. 코드 가독성이 좋다.
#include <iostream>
#include <optional>

//반환으로 int값이 있을 수도 있고 없을 수도 있다.
std::optional<int> divide(int a, int b){
    if(b==0){
        return std::nullopt;
    }
    return a/b;
}

int main(int argc, const char * argv[]) {
    const auto answer = divide(10, 0);
    
    if(answer){
        std::cout<<answer.value()<<std::endl;
    }
    else{
        std::cout<<"no value"<<std::endl;
        //std::cout<<answer.value_or(0)<<std::endl;
        //default value사용할 수도 있다.
    }
    return 0; //g++ main.c -std=c++17
}
