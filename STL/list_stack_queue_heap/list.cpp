//
//  main.cpp
//  1
//
//  Created by 김현배 on 2022/02/22.
//



//일단 실무에서 거의 쓰이지 않음
//find 0(N) : 처음부터 뒤져가니까
//삽입/삭제 0(1) 공간하나 만들고 포인터만 옮겨주면됌
//더블링크드리스트
#include <iostream>
#include <list>

int main(int argc, const char * argv[]) {
    std::list<int> nums{1,2,3,4,5};
    
    //0(1)
    nums.emplace_back(6);
    nums.emplace_front(0);
    
    //3 엘레멘트 찾아 그 지점 주솟값 반환
    auto it=std::find(nums.begin(), nums.end(), 3);
    //3찾으면
    if(it!=nums.end()){
        nums.emplace(it, 100); //그곳에 100 삽입. 하면 그곳이후는 한칸씩 무브됨
    }
    
    for(const auto& num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    return 0;
}