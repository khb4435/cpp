//
//  main.cpp
//  weak_ptr
//
//  Created by 김현배 on 2022/02/20.
//



//weak pointer는 shared pointer처럼 한 객체가 여러개의 포인터에 포인팅 될 수 있지만
//count에 종속되지 않는다
//예를 들어 어떤 객체가 shared pointer 2개, weak pointer 1개로 포인팅되면 count는 2임

#include <iostream>
#include <memory>
class Cat{
public:
    Cat():mAge{1}{}
    virtual ~Cat(){}
    void speak(){
        std::cout<<"meow"<<std::endl;
    }
private:
    int mAge;
};

int main(int argc, const char * argv[]) {
    std::weak_ptr<Cat> wPtr;
    {
        std::shared_ptr<Cat> sPtr = std::make_unique<Cat>();
        wPtr = sPtr;
        std::cout<<"count: "<<sPtr.use_count()<<std::endl;
        //Cat object is2 pointed but 1 count
        
        //to use weak_ptr
        if(const auto& spt = wPtr.lock()){
            //lock returns shared pointer
            std::cout<<"count: "<<sPtr.use_count()<<std::endl; //2
            spt->speak();
        }
    }
    return 0;
}
