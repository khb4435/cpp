//
//  main.cpp
//  functionPointer
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
class FunctionObj{
public:
    void operator() (int i){
        std::cout<<i<<std::endl;
    }
};

void freeFunction (int i){
    std::cout<<i<<std::endl;
};

//void runFunction(int i, void(*fnPtr)(int)) //타입이 한정됨
void runFunction(int i, const std::function<void(int)>&fn){
    //어떤 타입도 들어가게됨
    //(*fnptr)(i);
    fn(i);
};

void runFunctions(const std::vector<std::function<void(int)>>&functions){
    int i=0;
    for(const auto& fn : functions){
        fn(++i);
    }
};

int main(int argc, const char * argv[]) {
    freeFunction(10);
    
    //함수 포인터
    void (*fnPtr) (int);
    fnPtr = freeFunction;
    (*fnPtr)(20);
    //
    
    runFunction(10, fnPtr);
    
    FunctionObj functionObj;
    functionObj(10); //객체의 함수화
    runFunction(10, functionObj);
    
    auto lambdaFn = [] (int i){
        std::cout<<"lambdaFunction"<<i<<std::endl;
    };
    lambdaFn(10);
    runFunction(10, lambdaFn);
    
    std::vector<std::function<void(int)>> functions;
    functions.emplace_back(freeFunction);
    functions.emplace_back(functionObj);
    functions.emplace_back(lambdaFn);
    
    runFunctions(functions);
    return 0;
}
