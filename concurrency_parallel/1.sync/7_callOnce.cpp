#include <iostream>
#include <thread>
#include <mutex>

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

    t1.join();
    t2.join();

    z.speak();
}