//
//  main.cpp
//  3
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int>nums(10000,1); //10000개의 배열에 1을 대입
    
    //시작점과 항상 연속적인 메모리인것이 보장되기 때문에 어떠한 값이라도 읽는데 0(1)
    //마지막원소에 추가/삭제도 0(1)초가 걸림
    nums.emplace_back(2);
    nums.pop_back();
    
    //마지막 원소가 아닌 원소들에 추가/삭제는 0(n)초가 걸림
    nums.emplace_back(nums.begin(),3);//모든 엘레멘트들 뒤로 한칸식 "이동" 하고 첫번째에 삽입
    nums.erase(nums.begin());//첫번째원소 지우고 모든 엘레멘트 한칸 앞칸 앞으로 "이동"
    
    //고로 최대한 0(n)보다 0(1)의 시간할당이 요구되는 작업위주로 해야한다.
    return 0;
}
