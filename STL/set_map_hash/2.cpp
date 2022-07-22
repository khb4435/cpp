//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <set>

//c++에서 구조체와 클래스의 차이는 접근제어지시자자 클래스는 무조건 public인 것 밖에 없다.
struct customFn
{
    bool operator() (const int lhs, const int rhs) const{
        //return lhs < rhs;
        //return lhs > rhs;
        return (lhs%10) > (rhs%10);
    }
};

int main(int argc, const char * argv[]) {
    std::set<int,customFn> nums{1,2,3,4,5};
    
    nums.emplace(-1);
    nums.emplace(1); //1
    nums.emplace(11); //1
    nums.emplace(101); //1 -> 똑같은 1임으로 삭제됨
    nums.emplace(111);//1
    nums.emplace(-10);
    nums.emplace(-17);
    nums.emplace(6);
    
    for(const int& num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl; // 6 5 4 3 2 1 -10 -1 -17
    return 0;
}
