//
//  main.cpp
//  9
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, const char * argv[]) {
    std::vector<int> nums{0,1,2,3,4,5,6};
    nums.erase(std::remove_if(nums.begin(),nums.end(),[](int n){
            if(n%2==0)//짝수
            {
                return true; //짝수인것들 골라서 지우는거
            }
            return false;
            }),nums.end());
    
    for(auto &num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    return 0;
}
