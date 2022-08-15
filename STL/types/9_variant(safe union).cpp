//c++17
//안전한 union임.
#include <iostream>
#include <variant>
struct S{
    int i;
    double d;
};

union U{
    int i;
    double d;
};

int main(int argc, const char * argv[]) {
    std::variant<int,double> v;
    std::cout<<sizeof(v)<<std::endl; //Union같은 메모리구조 
    //하지만 현재 어떤 메모리인지 추적하는 8바이트 추가
    std::cout<<sizeof(S)<<std::endl; //16
    std::cout<<sizeof(U)<<std::endl; //8
    return 0;
}
