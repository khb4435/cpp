#include <iostream>
#include <thread>

//data race : 같은 메모리를 두 개 이상의 쓰레드가 동시 접근하고 때 하나 이상의 쓰레드가 writing할 때 문제
//race condition : 쓰레드가 일어나는 시간에 따라 값이 달라지는 것

//사실 이 예제는 둘 다를 포함한다.
//둘은 사실 분리하지말고 같이 간다고 봐야한다
//해결법? mutex!

int num=0;

void plus10000(){
    for(int i=0;i<10000;i++){
        num++;
    }
}

int main(){
    std::thread t1(plus10000);
    std::thread t2(plus10000);

    t1.join();
    t2.join();
    //두개가 전역변수 num에 동시 접근하므로 20000이 나오지 않고 막 16238같은 수가 나온다. 
    //어쩔 땐 20000도 나오지만
    //이런 동시접근하는거 확인하는 방법
    //g++ main.cpp -fsanitize=thread -g
}