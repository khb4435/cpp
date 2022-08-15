//일반적인 함수 return과 다른 path기 때문에 예외처리가 일어나는걸 미리 알고 코드를 짜지 않으면
//resource leak이 일어날 수있으니 주의

//stack unwinding : 지금 예제에 main안의 f안의 divide에서 excetion 불려지는데,이 과정에서 catch 만날때까지 f, divide 팝 된다.
//이마저도 main내에 catch없으면? std::terminate 만나면서 프로세스 종료된다.

//excetion발생시 약간의 오버헤드가 생기는데 우리 환경에 따라 무시가능한지 아닌지는 우리 환경에 달림
//그렇기에 반복문 같이 계속 exception불려지는 환경에서는 안하는게 좋고

#include <iostream>
#include <exception>
class Cat{
public:
    Cat(int age) : mAge{age} {};
    ~Cat()=default;
private:
    int mAge;
};

int divide(int a, int b){
    if(b==0){
        throw::std::runtime_error("divide by 0");
    }
    return a/b;
}

void f(){
    //1
    std::cout<<divide(10,0)<<std::endl; //exception발생
    
    //2
    Cat *cp = new Cat(5);
    std::cout<<divide(10,0)<<std::endl; //exception발생
    delete cp; //exception이 불려지며 힙공간의 Cat객체를 소멸하지 못함
    
    //3
    //unique pointer는 f()가 소멸되면서 cp의 소멸자도 자동으로 호출됨
    //스마트포인터 사용하면 exception에 더 안전한 코드 사용 가능
    std::unique_ptr<Cat> cp = std::make_unique<Cat>(5);
    std::cout<<divide(10,0)<<std::endl;//exception발생
}

int main(int argc, const char * argv[]) {
    try{
        f();
    }
    catch(const std::exception(&e)){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
