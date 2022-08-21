#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
struct MInt{ //struct, class 비슷
    std::mutex mtx;
    int num = 0;
};

void plus1(MInt &mi){
    mi.mtx.lock();
    mi.num++;
    mi.mtx.unlock();
}

int main(){
    MInt mi;
    std::thread t1(plus1,std::ref(mi));
    std::thread t2(plus1,std::ref(mi));

    t1.join();
    t2.join();

    std::cout<<mi.num<<std::endl; //2
}

//try_lock() ??
//critical section에 접근하는데 성공적으로 들어가서 lock을 걸면 true 리턴
//이미 lock 되어있어서 접근할 수 없으면 block상태아닌 false return

/////////////////////////////
//mutex가 unlock되기 전에 함수가 해제될 수 있는 문제들
struct MInt{ //struct, class 비슷
    std::mutex mtx;
    int num = 0;
};

void plus1(MInt &mi){
    mi.mtx.lock();
    mi.num++;
    if(mi.mum==10){
        return;
    }//라던지
    //throw exception이라든지..
    //mutex가 unlock되기 전에 함수가 해제될 수 있는 문제들이 있다.
    //이를 해결하기 위해 lock_guard사용
    mi.mtx.unlock();
}

int main(){
    MInt mi;
    std::thread t1(plus1,std::ref(mi));
    std::thread t2(plus1,std::ref(mi));

    t1.join();
    t2.join();

    std::cout<<mi.num<<std::endl; //2
}
/////////////////////////////
//lock_guard사용
struct MInt{ //struct, class 비슷
    std::mutex mtx;
    int num = 0;
};

void plus1(MInt &mi){
    {
        const std::lock_guard<std::mutex> lock(mi.mtx);
        //자동적으로 해당아래부분이 critical section으로 지정되면서
        //해당 스코프가 끝나면서 mutex가 해제된다.
        for(int i=0;i<100;i++){
            if(mi.num == 10){
                return;
            }
            mi.num++;
        }
    }
}

int main(){
    MInt mi;
    std::thread t1(plus1,std::ref(mi));
    std::thread t2(plus1,std::ref(mi));

    t1.join();
    t2.join();

    std::cout<<mi.num<<std::endl; //2
}
