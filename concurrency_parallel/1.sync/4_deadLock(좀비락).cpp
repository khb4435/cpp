#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//dead_lock? 메모리가 lock되어있고 unlock이 절대 안불려지는 코드
//계속 unlock이 기달려지는 코드

std::mutex mtx;

void deadLockFn(){
    const std::lock_guard<std::mutex> lck(mtx);
    //lck2는 이미 잠겨있는 mutex를 lock시도를 위해 block상태에 빠진다.
    const std::lock_guard<std::mutex> lck2(mtx);
}

int main(){
    std::thread t1(deadLockFn);
    t1.join();

    std::cout<<"bye"<<std::endl;//호출되지 않음
}


////////////////////////////////
//deadlock예시2

std::mutex mtx;

void fn(){
    const std::lock_guard<std::mutex> lck(mtx);
}
void deadLockFn(){
    const std::lock_guard<std::mutex> lck(mtx);
    fn();
}

int main(){
    std::thread t1(deadLockFn);
    t1.join();

    std::cout<<"bye"<<std::endl;//호출되지 않음
}

///////////////////////////
//std::recursive_mutex : lock된 mutex에 block없이 self lock 걸어줄 수 있음

std::recursive_mutex mtx;

void fn(){
    const std::lock_guard<std::mutex> lck(mtx);
}
void deadLockFn(){
    const std::lock_guard<std::mutex> lck(mtx);
    fn();
}

int main(){
    std::thread t1(deadLockFn);
    t1.join();

    std::cout<<"bye"<<std::endl;//호출되며 정상종료
}

////////////////////////////////////
//practical dead lock 상황

std::mutex mtxA;
std::mutex mtxB;

void ab(){
    const std::lock_guard<std::mutex> lckA(mtxA);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    const std::lock_guard<std::mutex> lckB(mtxB);
}

void ba(){
    const std::lock_guard<std::mutex> lckB(mtxB);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    const std::lock_guard<std::mutex> lckA(mtxA);
}
//ab(),ba()에서 mtxA,mtxB에 lock이 된 상태인데 서로가 서로한테 lock을 시도함
//그래서 계속 deadlock발생
//해결방법은 mutex를 언제나 같은 순서대로 걸어준다.
int main(){
    std::thread t1(ab);
    std::thread t2(ba);
    t1.join();
    t2.join();

    std::cout<<"bye"<<std::endl;
}


///////////////////////////////
std::mutex mtxA;
std::mutex mtxB;

void ab(){
    const std::lock_guard<std::mutex> lckA(mtxA);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    const std::lock_guard<std::mutex> lckB(mtxB);
}

void ba(){
    const std::lock_guard<std::mutex> lckA(mtxA);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    const std::lock_guard<std::mutex> lckB(mtxB);
}
//ab(),ba()에서 mtxA,mtxB에 lock이 된 상태인데 서로가 서로한테 lock을 시도함
//그래서 계속 deadlock발생
//해결방법은 mutex를 언제나 같은 순서대로 걸어준다.
//문제는 뮤텍스가 여러개면 그 순서를 기억하면서 코딩하기가 참 어렵다
//해결법:-->std::scoped_lock
int main(){
    std::thread t1(ab);
    std::thread t2(ba);
    t1.join();
    t2.join();

    std::cout<<"bye"<<std::endl;
}
