//
//  main.cpp
//  5
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
int main(int argc, const char * argv[]) {
    std::vector<int>nums;
    std::cout<<sizeof(nums)<<std::endl;
    //24bytes( *(8bytes) + size(8) + capacity(8)
    
    std::vector<int>numss{1,2,3,4,5};
    std::cout<<numss.size()<<std::endl; //5
    std::cout<<numss.capacity()<<std::endl; //5
    
    numss.emplace_back(6);
    std::cout<<numss.size()<<std::endl; //6
    std::cout<<numss.capacity()<<std::endl; //10
    //사이즈5, 캐패시터5인 벡터에 엘레멘트 추가하니까 사이즈6되고 캐페시터10됬다
    //엘레멘트 4개 더 추가할때까지 캐페시터는 10으로 유지되고 엘레멘트 5개 추가되면 또 캐패시터는 15가 되겠지
    
    //reserve를 크게 잡지 않고 백터를 해주면 예를들어 배열 4개다 근데 엘레멘트 추가된다. 근데 공간이 없어
    //그러면 5개 공간있는곳에 공간 또 잡히고 엘레멘트 4개가 copy or moved되는 과정이 필요
    //근데 이러면 느려짐 그래서 reserve키워드로 사이즈를 넉넉하게 처음부터 잡아놓는 것 추천
    numss.reserve(10000);
    return 0;
}
