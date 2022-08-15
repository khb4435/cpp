//
//  main.cpp
//  union
//
//  Created by 김현배 on 2022/02/27.
//



//union을 사용하는 이유? 메모리 세이빙
#include <iostream>
struct S{ //4 + (4) + 8 = 16
    int i4;
    double d8;
};

union U{ //제일 큰 메모리 공간을 공유 8바이트
    int i4; //4
    double d8; //8
};

int main(int argc, const char * argv[]) {
    std::cout<<sizeof(S)<<std::endl; //16
    std::cout<<sizeof(U)<<std::endl; //8
    
    U u;
    u.i4 = 10;
    std::cout<<u.i4<<std::endl; //10
    
    u.d8=0.3; //0.3으로 덮혀써짐
    std::cout<<u.d8<<std::endl; //0,3
    
    std::cout<<u.i4<<std::endl; //접근은 가능한데,
    //전혀 상관없는 숫자 출력됨
    //즉 0.3이 8바이트내 이진수로 쓰여지는데 여기서 4바이트만 가져오는 꼴 
    //type punning을 하지 않는 이상 union 사용 절대 금지
    return 0;
}
