#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

//하나의 쓰레드에서 다른 쓰레드로 신호를 보낼 때 사용된다.

//한 쓰레드가 진행과정중에 condition variable의 wait를 받고 블락상태로 있고
//다른 쓰레드가 두 쓰레드 사이에서 공유가 되는 shared variable을 수정하고
//condition variable을 통해 signal을 보내면 block 상태에 있는 쓰레드는
//신호를 받고 바뀐 shared variable을 체크하고 그 조건이 만족되면 
//해당 쓰레드를 계속 진행

std::condition_variable cv;
std::mutex mtx;

void waitFn(){
    std::cout<<"wait"<<std::endl;
    std::unique_lock<std::mutex>lck(mtx);
    cv.wait(lck); //인자로 unique_lock이 필요
    std::cout<<"re run"<<std::endl;
}

void signalFn(){
    std::cout<<"signal"<<std::endl;
    cv.notify_one();
}

int main(){
    std::thread waitT(waitFn);
    std::thread signalT(signalFn);

    waitT.join();
    signalT.join();
}
//이건 틀린코드. 이유는?
//봐봐 만약 notify_one함수가 wait되기 전에 들어가면?!
//wait상태를 끝내줄 시그널이 없음
//그 때문에 shared variable와 
//shared variabled을 보호하기 위한 mutex 필요한 것

////////////////////////////////////////////////////////////////
bool readyFlag = false; //shared variable로 사용됨
//이건 두 쓰레드에서 동시 접근하기 때문에 mutex로 보호해줘야한다.
std::condition_variable cv;
std::mutex mtx;

void waitFn(){
    std::cout<<"wait"<<std::endl;
    std::unique_lock<std::mutex>lck(mtx);
    while(!readyFlag){
        cv.wait(lck); //인자로 unique_lock이 필요
        //wait 즉 block상태에 되면서 mutex는 unlock된다.
        //signal받으면 다시 mutex는 lock이 되면서 스코프
        //빠져나가면서 critical section진행
    }
    //critical section
    std::cout<<"re run"<<std::endl;
}

void signalFn(){
    std::cout<<"signal"<<std::endl;
    {
        std::lock_guard<std::mutex>lck(mtx);
        readyFlag = true;
    }
    cv.notify_one();
}

int main(){
    std::thread waitT(waitFn);
    std::thread signalT(signalFn);

    waitT.join();
    signalT.join();
}


////////////////////////
bool readyFlag = false; //shared variable로 사용됨
//이건 두 쓰레드에서 동시 접근하기 때문에 mutex로 보호해줘야한다.
std::condition_variable cv;
std::mutex mtx;

void waitFn(){
    std::cout<<"wait"<<std::endl;
    std::unique_lock<std::mutex>lck(mtx);
    cv.wait(lck,[]{return readyFlag;}); //true일때만 wait풀린다. 
    //critical section
    std::cout<<"re run"<<std::endl;
}

void signalFn(){
    std::cout<<"signal"<<std::endl;
    std::unique_lock<std::mutex>lck(mtx);
    readyFlag = true;
    lck.unlock();
    cv.notify_one();//notify_all이면 waiting중인
    //모든 쓰레드를 깨운다.
}

int main(){
    std::thread waitT(waitFn);
    std::thread signalT(signalFn);

    waitT.join();
    signalT.join();
}