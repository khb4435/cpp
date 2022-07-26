//
//  main.cpp
//  1
//
//  Created by 김현배 on 2022/02/22.
//


//템플릿이란 특별한 타입이 정의되어 있지 않고 런타임때 필요한 타입으로 정의된다
//Function Templete -> funtion overloading이 일어나는 때 가장 필요함

//뼈대만 만들어놓고 본 함수는 런타임에 만들어내자
int add(int a,int b){
    return a+b;
}
float add(float a,float b){
    return a+b;
}
double add(double a,double b){
    return a+b;
}


#include <iostream>
int main(int argc, const char * argv[]) {
    //귀찮아
    int i = add(1,2);
    float f = add(1.2f,4.5f);
    double d = add(1.2,4.5);
    return 0;
}
