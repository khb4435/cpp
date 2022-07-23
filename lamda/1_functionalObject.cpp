//
//  main.cpp
//  1
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
    Plus plus3{3};
    Plus plus5{5};
    
    std::cout<<plus3(10)<<std::endl; //객체를 함수마냥 쓴다고 해서
    std::cout<<plus5(10)<<std::endl; //함수형 객체 functional object
    return 0;
}
