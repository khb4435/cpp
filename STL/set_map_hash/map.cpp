//
//  main.cpp
//  5
//
//  Created by 김현배 on 2022/02/20.
//


//map은 set + ((key&value))
#include <iostream>
#include <map>
int main(int argc, const char * argv[]) {
    std::map<int,int> numPairs;
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
        std::cout<<numPair.first<<" "<<numPair.second<<std::endl;
    }
    return 0;
}
