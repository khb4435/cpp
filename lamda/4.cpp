//
//  main.cpp
//  4
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    //std::vector<int> nums(10);
    std::vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    
    //lamdaAdd10 정의
    auto lambdaAdd10 = [] (int &n){
        n+=10;
    };
    
    int n=10;
    lambdaAdd10(n);
    std::cout<<n<<std::endl; //20
    
    //std::for_each(nums.begin(),nums.end(),lambdaAdd10);
    std::for_each(nums.begin(),nums.end(),[](int &n){
        n+=10;
    });
    
    for(auto& num : nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
