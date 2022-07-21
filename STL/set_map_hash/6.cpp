//
//  main.cpp
//  6
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <map>
#include <string>

int main(int argc, const char * argv[]) {
    std::map<int,std::string> nameList;
    nameList.emplace(1,"kitty"); // key value
    nameList.emplace(2,"nabi");
    nameList.emplace(3,"changmin");
    nameList.emplace(4,"jingyu");
    
    for(const auto& idPair : nameList){
        std::cout<<idPair.first<<" "<<idPair.second<<std::endl;
    }
    return 0;
}
