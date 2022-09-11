//템플릿 안전하게 쓰기! 템플릿 콘셉!
#include <concepts>
#include <iostream>
#include <string>

template <typename T>
concepts Summable = std::integral<T> || std::floating_point<T>

//정수만 사용해라!
template<typename T> requires Summable<T>
T sum(T a, T b){
    //컨셉사용
    //static_assert(std::integral<T>, "only integer");
    return a+b;
}

int main(int argc, const char * argv[]) {

    std::cout << sum<int>(5,4)<<std::endl;
    std::cout<< sum<float>(5.4f,4.2f)<<std::endl;
    //의도치 않았는데 abcdef로 컴파일됨 이런거 방지
    //std::cout<< sum<std::string>("abc","def")<<std::endl;
    
    return 0;
}
