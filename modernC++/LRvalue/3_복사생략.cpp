#include <string>
#include <iostream>

//RVO (return value optimization) -> move도 일어나지 않는
//0 move!

std::string getString(){
    std::string s = "nocope"
    //**임시객체 혹은 r value가 복사과정을 거쳐야할 때 복사생성이 일어나는듯함
    return s; //복사생략 일어남
    //임시객체에 복사하는 과정 없애버렸다..?
    //사실 s는 처음부터 존재하지도 않게된다...?
    return std::move(s); //복사생략 일어날지 모르고 짠 코드
    //또 s는 만들어지지도 않은놈이라 소유권의 이동조차도 필요없음
}
int main(){
    std::string a = getString();
    //a가 바로 nocope가리킴
}

//일반적으로 rvo는 거의 모든 케이스에 개입이되는데 -> return시 0 copy만들려고
//std::move return 안해줘도 된다는말
//안되는경우

std::string getString(std::string a,bool b){
    if(b){
        a = "nocope"
    }
    return a;
}
int main(){
    std::string a = getString();
    //컴파일타임에 확정이 안남
}
