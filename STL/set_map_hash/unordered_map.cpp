//
//  main.cpp
//  10
//
//  Created by 김현배 on 2022/02/22.
//


//map이 key-value tree구조라면 0(logN)
//unordered map은 key-value hash구조 0(1)
#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, const char * argv[]) {
    std::unordered_map<int, std::string> idNames; //key int, value string
    idNames.emplace(1,"nocope");
    idNames.emplace(2,"kitty");
    idNames.emplace(3,"nabi");
    //중복허용안됌 value는 달라도 핵심인 키가 같자나
    //std::unordered_multimap<int, std::string> idNames; //중복허용
    idNames.emplace(1,"bingo");
    //덮어쓰기
    idNames[1]="bingo";
    
    for(const auto& idname : idNames){
        std::cout<<idname.first<<" "<<idname.second<<std::endl; //순서상관없이 출력됨
    }
    return 0;
}

//Cat 등 사용시, hash와 ==가 정의되어야한다.
