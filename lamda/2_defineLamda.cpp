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
    auto lambdaPlus3 = [localVar = 3] (int x){ //[]는 {}안에 들어갈 지역변수느낌, ()는 매개변수
        return localVar + x;
    };
    
    //lambdaPlus3 정의2
    int three=3;
    auto lambdaPlus3 = [three] (int x){
        return three + x;
    };
    
    //lambdaPlus3 정의3
    veryLargeObj object; //in heap
    auto lambdaPlus3 = [&object] (int x){
        return object + x;
    };
    
    //lambdaPlus3 정의4
    auto lambdaPlus3 = [=] (int x){
        //스스로으로 value를 캡쳐함
        return localVar + x;
    };
    
    //lambdaPlus3 정의5
    auto lambdaPlus3 = [&] (int x){
        //스스로으로 reference를 캡쳐함
        return localVar + x;
    };
    
    Plus plus3{3};
    std::cout<<plus3(10)<<std::endl;
    std::cout<<lambdaPlus3(10)<<std::endl;
    //둘은 완벽히 같다
    
    return 0;
}
