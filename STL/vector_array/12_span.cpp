//std::span -> 연속적인 메모리공간이면 그 어떤것이던 인자로 받는다.

#include <array>
#include <vector>
#include <iostream>
#include <span>
#include <algorithm>

//수정되야함
void printSpan(std::span<int>nums){
    for(auto &num : nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;

    auto ret = std::ranges::find(nums,3);
    if(ret!=nums.end()) //3을 찾았다면
    {
        std::cout<<"found 3"<<std::endl;
    }
}

int main(){
    std::vector<int>vec{1,2,3,4,5};
    std::array<int,5>arr{1,2,3,4,5};
    int cNum[6]={1,2,3,4,5,6};

    std::span<int> sp{vec};
    //주의사항. 이짓한후 vec에 emplace_back하지말자
    //span은 처음 받을때의 시작주소와 사이즈만 알고있기때문에
    //벡터가 다른공간으로 가면 이상한 값을 읽게된다.
    printSpan(sp);
}

