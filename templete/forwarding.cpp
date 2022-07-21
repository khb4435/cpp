//
//  main.cpp
//  templete_deduction2
//
//  Created by 김현배 on 2022/02/22.
//



//g++ main.cpp -Wall
//./a.out | c++filt -t
#include <iostream>
template<typename T>
void printVar(T &&a){ //forward reference (universal reference)
    //Lvalue, Rvalue다 들어갈 수 있음 인자로
    
    //Rvalue가 넘어오는걸 위해서 이런식으로 해주면
    //std::string localVar(std::move(a)); //그림확인
    //꼬이게되는건 그림으로확인
    
    
    std::string localVar(std::forward(a)); //이게 더 맞음
    //std::forward를 쓰면 Lvalue로 넘어오면 copy시키고
    //Rvalue로 넘어오면 move시킨다
    std::cout<<localVar<<std::endl;
}

int main(int argc, const char * argv[]) {
    std::string s="nocope";
    printVar(s);
    //T=string& (string&)
    printVar(std::move(s));
    //T=string (string&&)
    return 0;
}
