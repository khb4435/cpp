//
//  main.cpp
//  templete_instantiation
//
//  Created by 김현배 on 2022/02/22.
//



#include <vector>
#include <iostream>
//""multiple type parameters"" -> typename이 여러개 될 수 있음
//예)std::find
template<typename IT,typename T>
IT find(IT first, IT last, const T& value){
    while(first!=last){
        if(*first==value){
            return first;
        }
        first++;
    }
    return last;
}

//""non type parameter"" : int나 size_t같이 type이 아닌 형태도 파라미터로 들어간다는 말
//예)std::array
template<typename T, std::size_t N>
T foo(T a){
    return N*a;
}

//parameter Pack : 인자 수없이 들어감
template<typename ...T>
void foo(T && ... args){
    (std::cout<< ... <<args) << '\n';
}

//템플릿은 코드상으로만 존재하다가 컴파일이 되면서 만들어지는데 오류를 방지하기 위해 템플릿을 헤더파일에 넣을때
//보통 헤더파일엔 선언만 넣고 cpp에 몸체를 넣는다 
//그러나 템플릿은 헤더파일에 그냥 몸체를 다 넣어줘야한다.


int main(int argc, const char * argv[]) {
    //non type parameter
    std::cout<<foo<double,4>(2.0)<<std::endl;
    
    //parameter pack
    foo(1,2,3);
    foo("ABC","nocope"); //g++ main.c -std=c++17
    
    return 0;
}
