//
//  main.cpp
//  sort
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    
    std::sort(nums.begin(),nums.end(),[] (int a, int b)
    {
        //return a<b; //1~10
        //return a>b; //10~1
        
        //5에 가까운 순으로
        return std::abs(a-5) < std::abs(b-5); //5 4 6 3 7 2 8 1 9 10
    });
    
    for(auto& num : nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
