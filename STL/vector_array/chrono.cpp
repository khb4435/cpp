//
//  main.cpp
//  7
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <chrono>
int main(int argc, const char * argv[]) {
    std::cout<<"how many element do you have?"<<std::endl;
    std::size_t n;
    std::cin>>n;
    
    std::vector<int> numsA(n,1);
    std::vector<int> numsB(n,1);
    std::vector<int> numsC(n,1);
    
    //1
    auto start = std::chrono::high_resolution_clock::now(); //지금시간 체크
    for(int i=0; i<1000; i++)
    {
        for(std::size_t idx=0; idx<numsA.size(); idx++){
            numsA[idx]+=2;
        }
    }
    auto end = std::chrono::high_resolution_clock::now(); //지금 시간 체크
    std::chrono::duration<double> diff = end-start;
    std::cout<<"idx loop: "<<diff.count()<<std::endl;
    
    
    //2
    start = std::chrono::high_resolution_clock::now(); //지금시간 체크
    for(int i=0; i<1000; i++)
    {
        for(auto itr=numsB.begin(); itr!=numsB.end(); itr++){
            (*itr)+=2;
        }
    }
    end = std::chrono::high_resolution_clock::now(); //지금시간 체크
    diff=end-start;
    std::cout<<"itr loop: "<<diff.count()<<std::endl;
    
    //3
    start = std::chrono::high_resolution_clock::now(); //지금시간 체크
    for(int i=0; i<1000; i++)
    {
        for(int& num : numsC){
            num+=2;
        }
    }
    end = std::chrono::high_resolution_clock::now(); //지금시간 체크
    diff=end-start;
    std::cout<<"itr loop: "<<diff.count()<<std::endl;
    return 0;
}
    

