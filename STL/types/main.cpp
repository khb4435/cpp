//
//  main.cpp
//  type_punning
//
//  Created by 김현배 on 2022/03/20.
//


#include <iostream>
#include <cstring>
#include <bit>
#include <cstdint>
//float으로 쓰고 unsigned int로 읽는 예제코드
bool isNeg(float x){
    //return x < 0.0f; -> 느림
    
    //이런건 되는거 있고 안되는 컴파일러 있고 그럼
    //unsigned char*, char*, std::bite* 만 모든 컴파일러에서 적용됨
    //unsigned int* ui = (unsigned int*)&x;
    //return *ui & 0x80000000;
    
    unsigned int tmp;
    std::memcpy(&tmp, &x, sizeof(x));
    return tmp&0x80000000;
    
    //c++20
    //return std::bit_cast<uint32_t>(x) & 0x80000000;
}

int main(int argc, const char * argv[]) {
    std::cout<<isNeg(-1.0f)<<std::endl;
    std::cout<<isNeg(1.0f)<<std::endl;
    return 0;
}
