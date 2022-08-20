#include <iostream>
#include <thread>
#include <vector>

//공유되는 공간을 mutex로 보호해준다면
//오직 하나의 쓰레드만 접근하면서
//data race 방지한다.

int num=0;
std::mutex mtx;

void plus10000(){
    mtx.lock(); //처음 접근한 쓰레드가 lock을 걸어주고
    for(int i=0;i<10000;i++){
        num++;
    }
    mtx.unlock();//빠져나갈때 해제
//보호받는 동안 다른 쓰레드가 접근할 수 없음. block되서 unlock을 기다림
//보호받는 구역을 critical section이라고 한다.
//주의! critical section은 최소화되야한다. 꼭 보호해야하는 부분만 보호한다.
}

int main(){
    std::vector<std::thread> threads;
    for(int i=0;i<10;i++){
        threads.emplace_back(std::thread(plus10000));    
    }
    for(auto &t : threads){
        t.join();
    }
    std::cout<<num<<std::endl;
}