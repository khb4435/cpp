//버그 원천 차단
enum class는 실무에서 매우 많이 사용이 됩니다. 
가장 간단한 예제로 function argument중 하나를 월요일 부터 금요일, 혹은 월요일 부터 일요일을 받는다 라고 가정을 해볼께요.
이때 사용할수있는 방법은 define을 사용해서 int를 0부터 4나 6까지 정의를 하는방법, 혹은 string을 사용해서 "monday","Tuesday"로 사용하는 방법이있습니다.
두가지 경우 모두 버그가 들어가기 쉬운 환경입니다. 개발자가 monday를 쓰지 않고 'munday" 라고 넘겨줄수도 있기때문입니다.
이런경우 enum class를 사용해서 객관식으로 선택해서 argument를 넘겨주게 되면, 버그가 들어갈 가능성 없이 개발을 할 수 있습니다.
 
#include <iostream>

enum class Clothing_size{
    small,
    medium,
    large,
};

enum class Clothing_color{
    red,
    blue,
    yellow
};

//enum class도 클래스이기때문에 operator 사용가능함
Clothing_size& operator++ (Clothing_size& s){
    if(s==Clothing_size::large){
        return  s;
    }
    s=static_cast<Clothing_size>(static_cast<int>(s)+1);
    return s;
}

void buy_shirt(Clothing_size size, Clothing_color color){
    std::cout<<" "<<std::endl;
}

int main(int argc, const char * argv[]) {
    buy_shirt(Clothing_size::medium,Clothing_color::red); //버그차단
    return 0;
}
