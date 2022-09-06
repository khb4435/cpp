#include <iostream>
#include <optional>
class Cat{
public:
    void print(){
        std::cout<<n<<std::endl;
    }
private:
    int n=10;
};

int main(int argc, const char * argv[]) {
    //std::optional<Cat> cat;
    //아직 고양이는 없는 상태
    
    //고양이 만드려면
    //cat=Cat();
    //std::optional<Cat> cat{Cat()}; //tmp Cat 생성과 move constructor를 하기 때문에 효율적인 방법은 아님
    std::optional<Cat> cat{std::in_place}; //optional공간안에 고양이를 바로 만든다
    
    if(!cat){
        std::cout<<"no cat"<<std::endl;
    }
    else{
        std::cout<<"yes cat"<<std::endl;
        cat->print();
    }
    
    return 0; //g++ main.c -std=c++17
}
