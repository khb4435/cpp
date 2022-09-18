//job Queue(shared memory)에 집어넣는 producer 쓰레드
//job Queue에 값 빼는 consumer 쓰레드
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

//스택구조
class StrStack{
public:
    //producer
    void addStr(std::string s){
        {
            std::lock_guard<std::mutex> lck(mtx);
            mStrs.emplace_back(std::move(s));
        }
        mCv.notify_one();
    }
    //consumer
    std::string getStr(){
        {
            std::unique_lock<std::mutex> lck(mtx);
            while(mStrs.empty()){
                mCv.wait(lck);
            }
            std::string s = std::move(mStrs.back());
            mStrs.pop();
            lck.unlock(); //해당함수가 종료되면 자동으로 풀리므로 꼭 필요하진 않은 부분
            return s;
    }
private:
    //이거 까지만 하면 싱글스레드
    std::vector<std::string> mStrs;
    
    //이거 추가되면 멀티쓰레드
    std::mutex mtx;
    std::condition_variable mCv;
}
int main(){
    StrStack strStack;
    std::thread t1([&](){
        strStack.addStr("nocope");
    });
    std::thread t2([&](){
        strStack.addStr("meow");
    });
    std::thread t3([&](){
        std::cout<<strStack.getgStr()<<std::endl;
    });
    std::thread t4([&](){
        std::cout<<strStack.getgStr()<<std::endl;
    });
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
