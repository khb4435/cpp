//
//  main.cpp
//  variant3
//
//  Created by 김현배 on 2022/03/01.
//

#include <iostream>
#include <variant>
#include <vector>

int main(int argc, const char * argv[]) {
    std::variant<std::string,std::vector<int>> sv;
    sv=std::string("abc");
    std::cout<<std::get<std::string>(sv)<<std::endl;
    //union멤버에 값을 바꿔주면 destructor/constructor로 타입을 바꿔야 하지만
    //variant를 사용시 필요없음
    //자동적으로 desctroctor, constructor관리해줌
    sv=std::vector{1,2,3};
    return 0;
}
