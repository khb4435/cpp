//
//  main.cpp
//  variant2
//
//  Created by 김현배 on 2022/03/01.
//

#include <iostream>
#include <variant>
union U{
    int i;
    double d;
    float f;
};

int main(int argc, const char * argv[]) {
    std::variant<int,double,float> v;
    v=10; //int타입
    
    //타입에 맞지 않으면 접근하지 않는 varinat !!
    if(auto pVal = std::get_if<double>(&v)){
        std::cout<<*pVal<<std::endl;
    }
    else{
        std::cout<<"v is not double type"<<std::endl; //출력됨
    }
    
    U u;
    u.i=10;
    std::cout<<u.d<<std::endl; //그냥 유니언을 쓰면 이상한 값 출력됨.
    return 0;
}
