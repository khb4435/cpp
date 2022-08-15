#include <iostream>
#include <set>

int main(){
    std::set<int> nums{1,2,3,4,5};

    //기본적으로는 red black tree구조로 set이 내부에 저장되지만
    //컴파일러마다 다르기 때문에 여기에서는 BST
    //binary search tree구조로 설명
    //BST란 어떤 노드기준, 왼쪽은 작은것만 오른쪽은 큰것만오는 tree구조임 (sorted!!!!)

    //find->0(logN) : 기준값을 중심으로 왼/오로 찾아간다.
    //삽입/삭제도 0(logN) : 할때마다 tree rebuild, (re coloring필요

    //중복삭제기능
    nums.emplace(3);
    nums.emplace(3);

    for(auto &num : nums){
        std::cout<<num<<std::endl; //1 2 3 4 5
    }
}
