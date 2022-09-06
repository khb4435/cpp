#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//결론: 1개 mutex lock? std::lock_guard
//2개 이상의 mutex lock? std::scoped_lock
//둘다 스코프단위로 lock, unlock

std::mutex mtxA;
std::mutex mtxB;

void ab(){
    const std::scoped_lock lckA(mtxA,mtxB);
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ba(){
    const std::scoped_lock lckA(mtxB,mtxA);
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
//pass해주는 mtx의 순서에 상관없이 알아서 내부적으로 정한
//mtx순서로 알아서 lock을 한다.

int main(){
    std::thread t1(ab);
    std::thread t2(ba);
    t1.join();
    t2.join();

    std::cout<<"bye"<<std::endl;//deadlock상황없이 잘 출력됨
}

