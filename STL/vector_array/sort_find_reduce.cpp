//
//  main.cpp
//  sort,find,reduce
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main(int argc, const char * argv[]) {
    //1.sort,stable_sort,partial_sort,nth_element
    std::vector<int> numsA{1,3,6,4,7,8,2,5,129,9};
    std::sort(numsA.begin(),numsA.end());
    //std::sort(numsA.begin(),numsA.end(),//람다펑션);
    for(auto& num : numsA){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
    
    //2.find,find_if
    std::vector<int> numsB{0,1,2,3,4};
    const auto resultItr = std::find(numsB.begin(),numsB.end(),2);
    //엘레멘트2인 원소 찾아서 그 주소값이 리턴됨
    if(resultItr!=numsB.end()) { //찾았다면
        std::cout<<"idx: "<<std::distance(numsB.begin(), resultItr);
    }
    else{ //못 찾았다면
        std::cout<<"not 2 element found"<<std::endl;
    }std::cout<<std::endl;
    
    //3.reduce
    std::vector<int>numsC{5,1,2,3,4};
    int sum = std::accumulate(numsC.begin(), numsC.end(), 0);
    int product = std::accumulate(numsC.begin(), numsC.end(), 1 , std::multiplies<int>());
    std::cout<<"sum: "<<sum<<'\n'<<"product: "<<product<<std::endl;
    return 0;
}
