//
//  main.cpp
//  templete_instantiation
//
//  Created by 김현배 on 2022/02/22.
//



#include <vector>
#include <iostream>
//""multiple type parameters""
//find
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
//array
template<typename T, std::size_t N>
T foo(T a){
    return N*a;
}

//parameter Pack
template<typename ...T>
void foo(T && ... args){
    (std::cout<< ... <<args) << '\n';
}

//템플릿은 코드상으로만 존재하다가 컴파일이 되면서 만들어지는데 오류를 방지하기 위해 템플릿을 헤더파일에 넣을때
//보통 헤더파일엔 선언만 넣고 cpp에 몸체를 넣는다 템플릿은 헤더파일에 그냥 몸체를 다 넣어줘야한다.

//내가 만드는 템플릿
template<typename PT,typename T>
PT findValue(PT first,PT last,T value){
    while(first!=last){
        if((*first)==value){
            return first;
        }
        else first++;
    }
    return last;
}

int main(int argc, const char * argv[]) {
    //non type parameter
    std::cout<<foo<double,4>(2.0)<<std::endl;
    
    //parameter pack
    foo(1,2,3);
    foo("ABC","nocope"); //g++ main.c -std=c++17
    
    //내가 만든 템플릿
    std::vector<int> nums{1,2,3,4,5};
    for(auto& num : nums){
        auto a = findValue(nums.begin(), nums.end(), 3);
        num = *a;
    }
    for(const auto& num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    
    return 0;
}
