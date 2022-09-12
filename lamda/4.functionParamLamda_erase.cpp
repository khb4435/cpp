//higher order function
//하나 혹은 두개의 함수를 파라미터를 받는다.
//함수를 결과로 리턴한다.
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    
    auto lamdaAdd10 = [](int &n){
        n+=10;
    };
    
    //std::for_each는 처음부터 끝까지 모든 원소가 "함수"를 받게함.
    //1
    std::for_each(nums.begin(),nums.end(),lamdaAdd10);
    
    for(auto& num : nums){
        std::cout<<num<<" ";
    }//11~20
    std::cout<<std::endl;
    
    //2
    std::for_each(nums.begin(),nums.end(),[](int &n)
    {
        n+=10;                  
    });
                                            
    for(auto& num : nums){
        std::cout<<num<<" ";
    }//11~20                                        
    
    
    
    //3 higher order function (함수를 아규먼트, 함수를 리턴)
    
    //auto filterOdd = [] (int n){
    //    return n%2==1; //1이면 트루반환
    //};
    
    //remove_if를 통해 먼저 필터 아웃시키고
    //erase로 남은 엘레멘트로만 벡터 사이즈 재구성!
    
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
