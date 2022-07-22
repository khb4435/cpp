//
//  main.cpp
//  8
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<int> nums{0,1,0,1,0,1}; //size 6
    
    auto itr=std::remove(nums.begin(),nums.end(),0);
    //begin부터 end까지 모든 0 엘레멘트 삭제 그리고 마지막 엘레멘트 리턴
    //여전히 사이즈는 6
    
    nums.erase(itr,nums.end()); //itr부터 end까지 사이즈 삭제
    //사이즈3
    
    for(auto& num:nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    return 0;
}
