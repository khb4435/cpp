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
    
    //union문제1
    //타입에 맞지 않으면 접근하지 않는 varinat !!
    //expection던져지면서 프로그램멈춤
    //excetion싫으면
    if(auto pVal = std::get_if<double>(&v)){
        std::cout<<*pVal<<std::endl;
    }
    else{
        std::cout<<"v is not double type"<<std::endl; //출력됨
    }
    return 0;
}
