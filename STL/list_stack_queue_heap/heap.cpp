//
//  main.cpp
//  heap
//
//  Created by 김현배 on 2022/02/22.
//


//priortity queue진화
#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
void print(std::string_view text, std::vector<int> const& v = {}) {
    std::cout << text << ": ";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}
 
int main()
{
    print("Max heap");
 
    std::vector<int> v {1,3,5,7,9,11};
    print("initially, v", v);
    for(auto& i : v){
        std::cout<<i<<" "; //1,3,5,7,9,11 벡터
    }std::cout<<std::endl;
 
    //벡터를 힙으로 바꾼다. 0(N) -> prioirity queue tree같음
    std::make_heap(v.begin(), v.end());
    print("after make_heap, v", v);
    for(auto& i : v){
        std::cout<<i<<" "; //11,9,5,7,3,1 힙
    }std::cout<<std::endl;

    //pop_heap -> 0(logN)
    std::pop_heap(v.begin(), v.end());
    print("after pop_heap, v", v);
    for(auto& i : v){
        std::cout<<i<<" "; //9,7,5,1,3,11 pop heap
    }std::cout<<std::endl;
//    auto top = v.back();

    //pop_back(마지막 엘레멘트 삭제)
    v.pop_back();
    //print("former top element", {top});
    print("after removing the former top element, v", v); //9 7 5 1 3
    
    //마지막에 엘레멘트 추가
    v.emplace_back(10);
    for(const auto& i : v){
        std::cout<<i<<" "; //9 7 5 1 3 10
    }std::cout<<std::endl;
    
    //마지막에 들어온 엘레멘트 다시 정렬 push heap -> 0(logN)
    std::push_heap(v.begin(), v.end());
    for(const auto& i : v){
        std::cout<<i<<" "; //10 7 9 1 3 5
    }std::cout<<std::endl;
 }

    
