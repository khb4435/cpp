//
//  main.cpp
//  8
//
//  Created by 김현배 on 2022/02/21.
//

//set은 내부적으로 tree구조 -> sorting됨 0(logN)
//unordered set은 0(1) 이고 sorting 되지 않는다
#include <iostream>
#include <string>
#include <unordered_set>

int main(int argc, const char * argv[]) {
    std::unordered_set<std::string> uordSet;
    //uordSet.reserve(10000); //rehashing 막기 위해.
    
    uordSet.emplace("abc");
    uordSet.emplace("def");
    uordSet.emplace("ghi");
    uordSet.emplace("jkl");
    
    std::cout<<"abc: "<<std::hash<std::string>{}("abc")<<std::endl; //해시값 출력
    std::cout<<"def: "<<std::hash<std::string>{}("def")<<std::endl;
    std::cout<<"ghi: "<<std::hash<std::string>{}("ghi")<<std::endl;
    std::cout<<"jkl: "<<std::hash<std::string>{}("jkl")<<std::endl;
    //해쉬값이 모두 다른데, 각 문자열이 해쉬평션을 통하면 저 해쉬값들이 나옴
    
    //근데 해쉬값이 너무 큼 -> 버킷 카운트에 해쉬값 담아놈
    std::cout<<uordSet.bucket_count()<<std::endl; //13?
    //해쉬값들이 5개의 버킷중에 몇번째 버킷에 들어갔는지도 알 수 있음
    std::cout<<"abc: "<<uordSet.bucket("abc")<<std::endl; //4번째 bucket
    std::cout<<"def: "<<uordSet.bucket("abc")<<std::endl; //7
    std::cout<<"ghi: "<<uordSet.bucket("abc")<<std::endl; //4
    std::cout<<"jkl: "<<uordSet.bucket("abc")<<std::endl; //8
    
    //키값으로 해쉬값 찾는시간, 해쉬값으로 버킷카운트넘버 구하는 시간, 그 버킷카운트에서 링크드리스트 타면서 추가/삭제 하는 시간은 0(1)
    
    //emplace많아지면 링크드리스트 많아질테고 걸리는시간 0(1)보다 커지게 될 것같으면 버킷 카운트 증가됨
    //그럼 rehashing일어나면서 시간 지연됨. 이를 방지하기 위해 reserve
    return 0;
}
