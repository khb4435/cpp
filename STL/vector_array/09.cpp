#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, const char * argv[]) {
    std::vector<int> nums{0,1,2,3,4,5,6}; //size 7
    nums.erase(std::remove_if(nums.begin(),nums.end(),[](int n){
    //std::remove if란
    //begin부터 end까지 모든 짝수 엘레멘트 삭제 그리고 마지막 엘레멘트 리턴
    //그러나 여전히 사이즈는 7
    
    //erase란    
    //리턴받은 마지막 엘레멘트부터 end까지 사이즈 삭제
    //사이즈3
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
