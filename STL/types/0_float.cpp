//float에서는 == 나 >= 등 하지말자
//부동소수점의 한계 해결방법
//f1+f2일때 두개의 스케일값이 너무 차이가 나면 결과값이 이상하게 나옴
//double이 float보다 훨씬 정밀하게 숫자 표현해준다.

#include <iostream>
#include <numeric>
//어느정도 맞으면 ==을 출력해주는 함수
bool almostEqual(float x, float y, int ulp){
    const float diff = std::fabs(x-y); //float의 절대값
    return diff <= std::numeric_limits<float>::epsilon() * std::fabs(x+y) *
    ulp || diff < std::numeric_limits<float>::min();
}

int main(int argc, const char * argv[]) {
    const float num1 = 0.3f;
    //0.3000000119
    const float num2 = 0.4f;
    //0.4000000596
    const float sum = num1 + num2;
    //expect 0.7f
    //but 0.7000000xx
    
    if(sum == 0.7f){ //0.6999999xxx
        std::cout<<"correct!"<<std::endl;
    }
    else{
        std::cout<<"not correct!"<<std::endl; //이게 호출됌
    }
    
    //해결방법? almostEqual!
    if(almostEqual(0.7f, sum, 1)){
        std::cout<<"correct!"<<std::endl; //이게 호출됌
    }
    else{
        std::cout<<"not correct!"<<std::endl;
    }
    return 0;
}

