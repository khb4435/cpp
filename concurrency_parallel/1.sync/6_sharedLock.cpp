#include <iostream>
#include <thread>
#include <chrono>
#include <shared_mutex>

//여러개의 쓰레드가 동시에 잡을 수 있는 뮤텍스
//std::shared_lock

//일반적으로 mutex lock이란
//여러 쓰레드중에 접근한 쓰레드가 lock을 걸고 다른 쓰레드들은
//밖에서 block상태로 unlock되기를 기다리는 상황

// 반면에 이거는 기본 기능에 + 여러 쓰레드가 접근할 때 먼저 접근한 놈이 shared_lock을 획득함
// 다른 쓰레드들은 block상태가 아니라 똑같이 critical section안으로 들어가고
// 모든 쓰레드가 다 나가야 그제서야 shared_lock이 풀린다.

//대표적인 예로 write, read가 있음
//write에는 일반적인 mutex lock기능이 필요할거지만
//read에는 다 같이 이 메모리가 접근해도된다. 읽기 연산이 동시에 읽어나면 더 빠르고 효율적이게 된다.

struct MInt{
    std::shared_mutex mtx;
    int num = 0;
};

void setNum(MInt& mi , int num){
    //std::lock_guard<std::mutex>lck(mi.mtx);
    mi.mtx.lock();
    mi.num = num;
    mi.mtx.unlock();
}

void printNum(MInt &mi){
    //std::shared_lock<std::shared_mutex> lck(mi.mtx);
    mi.mtx.lock_shared();
    std::cout<<mi.num<<std::endl;
    mi.mtx.unlock_shared();
}

int main(){
    MInt mi;
    std::thread t1(printNum,std::ref(mi));
    std::thread t2(setNum,std::ref(mi),100);
    std::thread t3(printNum,std::ref(mi));
    std::thread t4(printNum,std::ref(mi));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}