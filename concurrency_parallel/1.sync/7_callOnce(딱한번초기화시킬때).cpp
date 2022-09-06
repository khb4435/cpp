#include <iostream>
#include <thread>
#include <mutex>

//call_once : 초기화 딱 하나 시킬때
class Cat{
    public:
    Cat(){
        std::cout<<"init cat"<<std::endl;
    }
    void speak(){
        std::cout<<"meow"<<std::endl;
    }
};

class Zoo{
    public:
    std::unique_ptr<Cat> mCat;
    std::once_flag catInitFlag;
    void speak(){
        std::cout<<"zoo"<<std::endl;
    }
};


void fn(Zoo &z){
    std::call_once(z.catInitFlag,[&](){
        z.mCat=std::make_unique<Cat>();
    });
}

int main(){
    Zoo z;
    std::thread t1(fn,std::ref(z));
    std::thread t2(fn,std::ref(z));
    //초기화가 두번 된 것 처럼 보이지만 Cat객체는 한개가 만들어짐
    
    t1.join();
    t2.join();

    z.speak();
}
