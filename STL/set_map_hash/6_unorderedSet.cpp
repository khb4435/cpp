//
//  main.cpp
//  7
//
//  Created by 김현배 on 2022/02/21.
//



//set은 내부적으로 BST or red block tree구조 -> sorting됨 0(logN)
//unordered set은 hash구조(키)로 0(1) 이고 sorting 되지 않는다
#include <iostream>
#include <string>
#include <unordered_set>

int main(int argc, const char * argv[]) {
    std::unordered_set<std::string> uordSet;
    uordSet.emplace("abc");
    uordSet.emplace("def");
    uordSet.emplace("ghi");
    uordSet.emplace("jkl");
    
    for(const std::string& str : uordSet){
        std::cout<<str<<std::endl; //순서없이 출력되네?
    }
    
    uordSet.find("abc"); // 0(1)
    uordSet.erase("jkl"); // 0(1)가 될 수 있는 이유는 hash function덕분임
    return 0;
}
