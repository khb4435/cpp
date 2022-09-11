#include <iostream>

//호출이 되기 전까지는 코드로만 존재하고 있다가 컴파일 할 때 함수가 호출이 되고 있으면 그 타입에 맞춰서 컴파일된다.
template<typename T>
T add(T a,T b){
    return a+b;
}

int main(int argc, const char * argv[]) {
    int i = add<int>(4,5);
    //auto i = add(4,5); //templete deduction
    float f = add<double>(4.0f,5.8f);
    //auto f = add(4.0f,5.0f); //templete deduction
    std::cout<<i<<" "<<f<<" "<<std::endl;
    
    //auto a = add<auto>("abc","def"); 컴파일에러
    //std::string에 대한 operator+ 가 정의되어 있지 않아서.
    //std::cout<<a<<std::endl;
    
    return 0;
}
