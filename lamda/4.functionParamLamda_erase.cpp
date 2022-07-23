//
//  main.cpp
//  erase
//
//  Created by 김현배 on 2022/02/20.
//


//higher order function
//하나 혹은 두개의 함수를 파라미터를 받는다.
//함수를 결과로 리턴한다.
#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, const char * argv[]) {
    std::vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    
    //auto filterOdd = [] (int n){
    //    return n%2==1;
    //};
    
    //nums.erase(std::remove_if(nums.begin(),nums.end(), filterOdd {
    nums.erase(std::remove_if(nums.begin(),nums.end(), [] (int n) {
        //이것역시 람다함수가 파라미터로 들어갔으므로 higher order fucntion임
        return n%2 == 1; //홀수면 리턴 -> 홀수면 remove
    }),nums.end());
    
    for(auto& num : nums){
        std::cout<<num<<" ";
    }//2 4 6 8 10
    std::cout<<std::endl;
    return 0;
}
