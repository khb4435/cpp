//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/22.
//



//forward list : 싱글 리스트, 0(1) for 삽입/삭제 , 벡터와는 다르게 0(1)의 랜덤엑세스는 불가
#include <iostream>
#include <forward_list>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::forward_list<int> nums {1,2,3,4,5};
    nums.emplace_front(0);
    for(const auto& num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    return 0;
}
