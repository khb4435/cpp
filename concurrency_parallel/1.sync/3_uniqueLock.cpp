#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

//결론적으로는 lock_guard를 일단 쓰고 기능이 더 필요할 때 
//unique_lock을 쓴다.
//이유는 lock_guard가 좀 더 가볍기도하고, 더 제한적인 기능만을 다루기때문에
//쓰기 간단하다.

struct MInt{ //struct, class 비슷
    std::mutex mtx;
    int num = 0;
};

void plus1(MInt &mi){
    std::unique_lock<std::mutex> lock(mi.mtx);
    //std::lock_guard와 마찬가지로 그 아래쪽이 critical section되고
    //스코프 종료되면서 mtx.unlock된다.

    //기능이 똑같아보이는데 이게 사용되는건 unique_lock이 lock_guard보다 더 쓸수있는 기능이 많음
    //그 중에서도 유용한건 move가 가능한것
    mi.num++;
}

int main(){
    MInt mi;
    std::thread t1(plus1,std::ref(mi));
    std::thread t2(plus1,std::ref(mi));

    t1.join();
    t2.join();

    std::cout<<mi.num<<std::endl; //2
}

////////////////////////////////////////////////
//std::unique_lock의 move쓰임새

struct MInt{ //struct, class 비슷
    std::mutex mtx;
    int num = 0;
};

std::unique_lock<std::mutex> unlockTest(std::unique_lock<std::mutex>lck){
    if(true){
        lck.unlock();
    }
    return lck;
} 

void plus1(MInt &mi){
    std::unique_lock<std::mutex> lock(mi.mtx);
    mi.num++;
    
    //오직 rvalue만 가능하기에 move로 rvalue로 바꾼다.
    lock = unlockTest(std::move(lock));
    //결과적으로 plus1의 unique_lock을 다른 함수로 보낼 수 있음
    //개발자가 unique_lock을 resource로 관리할 수 있게 해준다.
}

int main(){
    MInt mi;
    std::thread t1(plus1,std::ref(mi));
    std::thread t2(plus1,std::ref(mi));

    t1.join();
    t2.join();

    std::cout<<mi.num<<std::endl; //2
}

