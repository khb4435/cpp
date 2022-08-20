#include <iostream>
#include <thread>

//결론 : scoped static을 활용한다면 mutex나 call once 등이 필요없음

void fn(){
    static int i = 0;
}

int main(){
    fn();
    fn();
    fn();
    fn();
}

//암만 불러도 int i 는 static 공간에 딱 하나 만들어진다.

//////////////////////
void fn(){
    static int i = 0;
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
    //쓰레드로 불러도 해당변수는 딱 static공간에 하나만 만들어짐
}

/////////////////////////
class Cat{
    public:
    Cat(){
        std::cout<<"meow"<<std::endl;
    }
};

void fn(){
    static Cat cat;
    //lazy init -> process 실행중 init된다.
}

int main(){
    std::thread t1(fn);
    std::thread t2(fn);

    t1.join();
    t2.join();
    //이 역시 static 공간에 cat이 딱 한개 만들어지고, 초기화는 한번만되는것
}


///////////////////////////
class SingleTon{
    public:
    static SingleTon& getinstance(){
        static SingleTon obj;
        return obj;
    }
    //copy assignment, constructor = delete
};

