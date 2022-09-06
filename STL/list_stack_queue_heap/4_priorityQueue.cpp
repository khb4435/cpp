//priority queue : pop이 되는 엘레멘트에 우선순위가 있음
//MAX값이 무조건 top으로 가는 "트리구조"!!!!!!!!!!!!!!
//삽입되면 가장 오른쪽 끝에 삽입되고 트리구조의 룰을 지키기위해
//부모자식간 스왑과정을 거치게된다.
//insertion/pop : 0(logN) -> tree구조를 갖는다.
// MIN/MAX : 0(1)
//top을 찍기만 하면 그게 max
//tree구조로 부모가 항상 자식보다 크고, 
//왼쪽부터 차 나간다.

#include <iostream>
#include <queue>
int main(int argc, const char * argv[]) {
    //vector로 이용됨??
    //tree 구조라며? tree element에 0번째 1번째 2번째 등 인덱스가 있을거아냐 그거임
    std::priority_queue<int> nums;
    nums.emplace(1);
    nums.emplace(3);
    nums.emplace(5);
    nums.emplace(7);
    nums.emplace(9);
    
    std::cout<<nums.top()<<std::endl; //9
    
    //0(logN) 새로운 element(10)가 top까지 도달해야 하기 때문
    nums.emplace(10);
    
    //0(1) : top만 찍으면됌
    std::cout<<nums.top()<<std::endl; //10
    
    nums.pop();
    nums.pop();
    nums.pop();
    //가장 큰 숫자 3개가 빠지고
    std::cout<<nums.top()<<std::endl; //5
    
    return 0;
}
