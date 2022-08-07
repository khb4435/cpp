//
//  main.cpp
//  1
//
//  Created by 김현배 on 2022/02/20.
//

//vector? 
1.dynamic size array
2.sequence array

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    //스택공간에 배열 선언
    int* numsPtr = new int[5];
    for(int i=0;i<5;i++){
        numsPtr[i]=i;
    }
    delete [] numsPtr;
    
    //힙 공간에 배열 선언 -> 벡터
    std::vector<int> nums(5);
    for(int i=0;i<5;i++){
        nums[i]=i;
    }
    
    //delete 필요없음
    
    //벡터기본(벡터는 힙공간 배열을 가리키는 포인터와, 사이즈, 캐패시티 정보로 구성된다)
    std::vector<int> numss{0,1,2,3,4};
    std::cout<<numss.size()<<std::endl; //5
    numss.emplace_back(5);
    std::cout<<numss.size()<<std::endl; //6
    numss.pop_back();
    std::cout<<numss.size()<<std::endl; //5
    
    //벡터값 추출하는 세가지 방법
    //1.index based ((3이 제일 편하고 빠르지만 벡터 사이즈가 변화할 시 무조건 1번 써야한다))
    for(std::size_t idx=0; idx<numss.size(); idx++){
        std::cout<<numss[idx]<<" ";
    }std::cout<<std::endl;
    
    //2.iterator based
    for(auto itr=numss.begin(); itr!=numss.end(); itr++){
        std::cout<<(*itr)<<" ";
    }std::cout<<std::endl;
    
    //3.range based loop (제일빠름)
    for(const int& num : numss){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
}
