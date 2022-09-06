//forward list : 싱글드 list, 0(1) for 삽입/삭제 , 벡터와는 다르게 0(1)의 랜덤엑세스는 불가
//벡터가 더 좋다. 

//emplace_front는 있지만
//emplace_back은 제공되지 않는다. !!!!

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

//vector vs list

//vector : random access 0(1) (연속적 메모리공간이라), 중간 삽입/삭제: 0(n) 한칸씩 밀려남, 마지막공간 삽입/삭제: 0(1), find: 0(n): 처음부터 뒤져나감
//list : random access 0(n) (포인터로 다 뒤져야함), 중간 삽입/삭제 0(1): 넣고 포인터만 이동 시켜주면됌, 마지막공간 삽입/삭제: 0(1), find 0(n): 처음부터 뒤져나감

//그럼 벡터가 뭐가 더 좋아?
//컴퓨터 구조 때문에 vector의 find가 훨씬 빠름. 격자적 실제 메모리공간에 연속적인 벡터와(캐시), 포인터를 갖고 띄엄띄엄 메모리(캐시미스)가 저장된 리스트의 차이
//또 병렬프로그래밍도 vector의 경우 코어 갯수만큼 메모리공간 짤라서 할당해줄 수 있는데(연속적인 공간이라) 리스트는 어렵다
