//
//  main.cpp
//  various_template
//
//  Created by 김현배 on 2022/02/22.
//




#include <iostream>
#include <vector>
//class template
template <typename T>
class Stack{
public:
    void push(T elem){
        //push특성상 lvalue일때는 카피, Rvalue일땐 move를 일으키기위해 이렇게 했다함
        mVec.emplace_back(std::move(elem));
    }
    bool pop(T& elem){
        if(mVec.size()==0) {
            return false;
        }
        elem = mVec[mVec.size()-1];
        mVec.pop_back();
        return true;
    }
private:
    std::vector<T> mVec;
};

//aliaing template
//c++17이전에는 typedef 이후에는 using쓰자
template<typename T>
using nocopeKeys = std::vector<std::array<T,64>>;

//variable template
template <class T>
constexpr T pi = T(3.141592178231L);

int main(int argc, const char * argv[]) {
    //class template
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    int n; //475248
    while(stack.pop(n)){
        std::cout<<n<<std::endl;
    }
    
    //aliaing template
    //c++17이전에는 typedef 이후에는 using쓰자
    nocopeKeys<float> floatKeys;
    //std::vector<std::array<float,64>>;
    
    //variable template
    int intpi = pi<int>;
    double doublepi = pi<double>;
    return 0;
}
