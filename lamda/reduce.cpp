//
//  main.cpp
//  reduce
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
int main(int argc, const char * argv[]) {
    std::vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    int sum = std::reduce(nums.begin(),nums.end(),0,[](int a,int b)
    {
        return a+b;
    });
    std::cout<<sum<<std::endl;
    
    int multi = std::reduce(nums.begin(), nums.end(), 1, [] (int a,int b)
    {
        return a*b;
    });
    std::cout<<multi<<std::endl;
    return 0;
}
