#include <iostream>
#include <thread>
#include <mutex>

void print(){
    std::cout<<"printed"<<std::endl;
}

void fn(){
    print();
}

int main(){
    std::thread t1(fn);
    std::thread t2(fn);
    std::thread t3(fn);
    std::thread t4(fn);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

//printed x4 출력되는데 쓰레드가 아무리 많아도 오직 한번만 함수 호출을 시키고 싶으면??
//std::call_once 사용하자

///////////////////////////////////////////////

std::once_flag flag;

void print(){
    std::cout<<"printed"<<std::endl;
}

void fn(){
    std::call_once(flag,print);
}

int main(){
    std::thread t1(fn);
    std::thread t2(fn);
    std::thread t3(fn);
    std::thread t4(fn);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
} //printed 하나 호출

//mutex + boolean 조합으로 동일 기능 만들 수 있지만
//전체 프로세스에서 쓰레드로 한 한번만 함수콜 하고 싶다면
//이게 훨씬 더 효율적

//결론 call once는 오브젝트 이니셜라이제이션에 사용한다.

////////////////////////////
class Cat{
    public:
    Cat(){
        std::cout<<"init cat"<<std::endl;
    }
    void speak(){
        std::cout<<"meow"<<std::endl;
    }
};

std::once_flag flag;
std::unique_ptr<Cat> cp = nullptr;

void fn(){
    std::call_once(flag,[](){
        cp=std::make_unique<Cat>();
    });
}

int main(){
    std::thread t1(fn);
    std::thread t2(fn);
    std::thread t3(fn);
    std::thread t4(fn);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cp->speak();
}


///////////////////////////////
//좀 더 practical하게 글로벌 cp가 아닌, 멤버 오브젝트안에 cp를 이닛하는데 쓰일 수 있음
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
    std::call_once(z.catInitFlag,[](){
        z.mCat=std::make_unique<Cat>();
    });
}

int main(){
    Zoo z;
    std::thread t1(fn,z);
    std::thread t2(fn,z);

    t1.join();
    t2.join();

    z.speak();
}