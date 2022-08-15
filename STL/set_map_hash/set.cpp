//
//  main.cpp
//  1
//
//  Created by 김현배 on 2022/02/20.
//


//set -> 내부적 tree구조(BSTorRed black tree), find,삽입,삭제 모두 0(logN)
//map(set+(key,value)) -> 내부적 tree구조(BSTorRed black tree), find,삽입,삭제 모두 0(logN)

//unordered set/map -> hash구조, find,삽입,삭제 모두 0(1), operator=, no sorting
//set/unordered set -> key
//map/unordered map -> key and value

//중복이고 싶으면 multi 붙여주면됌
#include <iostream>
#include <set>

int main(int argc, const char * argv[]) {
    //BST binary search tree
    std::set<int> nums{1,2,3,4,5};
    
    //중복된 것은 삭제된다.
    nums.emplace(3);
    nums.emplace(3);
    //3은 이미 있으니 3을 추가해도 없는것임
    
    for(const int& num : nums){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    return 0;
}
