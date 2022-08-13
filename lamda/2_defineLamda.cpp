//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/20.
//

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
    //lambdaPlus3 정의1
    //[] : 캡쳐모드
    auto lambdaPlus3 = [localVar = 3] (int x){ //[]는 {}안에 들어갈 지역변수느낌, ()는 매개변수
  //auto lambdaPlus3 = [localVar = 3] (int x,int y){ //매개변수 2개
        return localVar + x;
    };
    
    //lambdaPlus3 capture by value
    int three=3;
    auto lambdaPlus3 = [three] (int x){
        return three + x;
    };
    
    //lambdaPlus3 capture by reference
    //매우 큰 오브젝트가 힙에 있고 pointing하는 그림
    veryLargeObj object; //in heap
    auto lambdaPlus3 = [&object] (int x){
        return object + x;
    };
    
    //lambdaPlus3 auto capture by value
    auto lambdaPlus3 = [=] (int x){
        //스스로으로 local value를 캡쳐함(만약 three야? 그럼 지역변수 three 캡처 하는거)
        return localVar + x;
    };
    
    //lambdaPlus3 auto capture by reference
    auto lambdaPlus3 = [&] (int x){
        //스스로으로 reference를 캡쳐함
        return reference + x;
    };
    
    Plus plus3{3};
    std::cout<<plus3(10)<<std::endl;
    std::cout<<lambdaPlus3(10)<<std::endl;
    //둘은 완벽히 같다
    
    return 0;
}
