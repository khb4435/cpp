//
//  main.cpp
//  5
//
//  Created by 김현배 on 2022/02/20.
//


//map은 set(BST구조or red black tree)+(key&value)
//set과 같이 find, insertion, deletion 모두 0(log(n))
#include <iostream>
#include <map>
int main(int argc, const char * argv[]) {
    
    std::map<int,int> numPairs; //int와 int를 엮어주는
    //std::map<int,std::string> numPairs; //가능
    //std::map<std::string,int> numPairs; //다 가능
    //키가 std::string으로 오면 알파벳 순서대로 정렬됨.
    
    //(키,벨류)
    numPairs.emplace(1,101);
    numPairs.emplace(2,102);
    numPairs.emplace(3,103);
    numPairs.emplace(4,104);
    numPairs.emplace(5,105);
    
    //value가 달라도 핵심인 key가 중복되기 때문에 추가되지 않음
    numPairs.emplace(1,201);
    numPairs.emplace(1,301);
    
    //over write
    numPairs[1] = 201;
    
    //defualt value
    std::cout<<numPairs[6]; //6이란 키값이 없으니 마찬가지로 value도 없지만 value가 0으로 default되니
    //주의합시다
    
    for(const auto& numPair : numPairs){
        std::cout<<numPair.first<<" "<<numPair.second<<std::endl; //키,벨류
    }
    return 0;
}
