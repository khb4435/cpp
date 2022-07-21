//
//  main.cpp
//  4
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <set>

int main(int argc, const char * argv[]) {
    std::multiset<int> nums {1,2,3,3,3,4,5}; //중복도 지원
    for(const auto& num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl; // 1 2 3 3 3 4 5
    return 0;
}
