//결론적으로는 remove보다 remove if쓰는게 낫다.
//remove는 코드 하나씩 확인하면서 지우고 나머지 뒤 원소를 다 앞칸씩 "무브"시키는 방법으로한다.
//많은 시간 소요됨.
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<int> nums{0,1,0,1,0,1}; //size 6
    
    auto itr=std::remove(nums.begin(),nums.end(),0);
    //begin부터 end까지 모든 0 엘레멘트 삭제,    //여전히 사이즈는 6 
    //그리고 마지막 엘레멘트+1의 주솟값 리턴

    nums.erase(itr,nums.end()); //itr부터 end까지 사이즈 삭제
    //사이즈3
    
    for(auto& num:nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    return 0;
}

---------------
    
    int main(int argc, const char * argv[]) {
    std::vector<int> nums{0,1,2,3,4,5,6}; //size 6
    
    nums.erase(std::remove_if(nums.begin(),nums.end(),[](int n){
        if(n&2==0)
        {
            return true; //짝수면 remove_if에 대한 true면서 삭제된다.
        }
        return false;
        ),nums.end());

    for(auto& num:nums){
        std::cout<<num<<" "; //1 3 5
    }std::cout<<std::endl;
    return 0;
}
