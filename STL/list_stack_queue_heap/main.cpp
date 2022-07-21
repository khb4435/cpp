//
//  main.cpp
//  queue
//
//  Created by 김현배 on 2022/02/22.
//


//Queue : first in first out
#include <iostream>
#include <queue>
#include <stack>
int main(int argc, const char * argv[]) {
    //deque or list로 구성됨
    std::queue<int> nums;
    nums.emplace(1);
    nums.emplace(3);
    nums.emplace(5);
    
    std::cout<<nums.front()<<" "<<nums.back()<<std::endl; //1 5
    nums.pop();
    std::cout<<nums.front()<<" "<<nums.back()<<std::endl; //3 5
    nums.pop();
    std::cout<<nums.front()<<" "<<nums.back()<<std::endl; //5 5
    nums.pop();
    
    return 0;
}
