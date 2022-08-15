

#include <iostream>
#include <queue>
#include <stack>
int main(int argc, const char * argv[]) {
    //stack : last in first out
    std::stack<int> stackNums;
    stackNums.emplace(1);
    stackNums.emplace(3);
    stackNums.emplace(5);

    std::cout<<stackNums.top()<<std::endl; //5
    stackNums.pop();
    std::cout<<stackNums.top()<<std::endl; //3
    stackNums.pop();
    std::cout<<stackNums.top()<<std::endl; //1
    stackNums.pop();

    std::cout<<"size : "<<stackNums.size()<<std::endl; //0

    //Queue : first in first out
    //리스트는 내부구조가 linked list로 구현되어있습니다. 
    //하지만 stack은 더 abstract한 형태로서 그 내부는 끝 부분을 가르킬수있는 vector/deque/list등을 모두 사용해도 됩니다.
    std::queue<int> nums;
    nums.emplace(1);
    nums.emplace(3);
    nums.emplace(5);
    
    std::cout<<nums.front()<<" "<<nums.back()<<std::endl; //1 5
    nums.pop();//1 out
    std::cout<<nums.front()<<" "<<nums.back()<<std::endl; //3 5
    nums.pop();//3 out
    std::cout<<nums.front()<<" "<<nums.back()<<std::endl; //5 5
    nums.pop();//5 out
    
    std::cout<<"size : "<<nums.size()<<std::endl; //0
    return 0;
}
