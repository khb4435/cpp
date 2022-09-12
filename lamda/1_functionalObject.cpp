//OOP는 대체 가능한 쉬운 다른 언어가 많다
//c++ = OOP + 하이 퍼포먼스(cache hit)

//함수형 프로그래밍(자바 스크립트 등)을 제대로 배우고 싶으면 전문 서적 등을 봐라!
//함수형 프로그래밍? 
//안의 내부변수는 어떠한 방법으로도 접근이 불가
//함수를 변수처럼 다루면서 콜백펑션, 하이어옫 펑션등을 쉽게 다룰 수 있음

//operator()를 해줌으로써 함수형 객체 
#include <iostream>
class Plus{
public:
    explicit Plus(int a) : localVar{a}{}
    int operator() (int x) const{
        return localVar + x;
    }
private:
    int localVar;
};

int main(int argc, const char * argv[]) {
    Plus plus3{3};
    Plus plus5{5};
    
    std::cout<<plus3(10)<<std::endl; //객체를 함수마냥 쓴다고 해서
    std::cout<<plus5(10)<<std::endl; //함수형 객체 functional object
    return 0;
}
