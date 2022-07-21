//
//  main.cpp
//  function_templete
//
//  Created by 김현배 on 2022/02/22.
//


//호출이 되기 전까지는 코드로만 존재하고 있다가 컴파일 할 때 함수가 호출이 되고 있으면 그 타입에 맞춰서 컴파일된다.
#include <iostream>
template<typename T>
T add(T a,T b){
    return a+b;
}

int main(int argc, const char * argv[]) {
    int i = add<int>(4,5);
    //auto i = add(4,5);
    float f = add<double>(4.0f,5.8f);
    //auto f = add(4.0f,5.0f);
    std::cout<<i<<" "<<f<<" "<<std::endl;
    
    //auto a = add<auto>("abc","def"); 컴파일에러
    //operator+ 가 정의되어 있지 않아서.
    //std::cout<<a<<std::endl;
    
    return 0;
}
