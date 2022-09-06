//C에는 예외처리가 없어서 모든 에러를 리턴으로 해결
//C++에는 optional,pair,tuple등 error return하는 방법외에도
//exception(try,catch,throw)가 있음
//throw는 r value, catch는 lvalue ref
#include <iostream>
#include <exception>
class Cat{
public:
    Cat(){}
    ~Cat(){}
};

int divide(int a, int b){
    if(b==0){
        //catch1
        throw::std::exception(); //std::exception이라는 객체를 만들어서 던짐
        //std::exception의 자식클래스
        throw::std::runtime_error("divide by 0");
        
        //catch2
        //excetion등이 객체라고 했는데, 객체 던지기 가능
        throw Cat();
    }
    return a/b;
}
int main(int argc, const char * argv[]) {
    try{
        std::cout<<divide(10,0)<<std::endl;
    }
    //catch 1
    catch(const std::exception &e){
        std::cout<<e.what()<<std::endl;
        std::cout<<"std::exception is catched"<<std::endl;
    }
    //catch 2
    catch(const Cat& c){
        std::cout<<"cat is catched"<<std::endl;
    }
    
    //어떤 throw된 객체 다 받는다.
    catch(...){
        std::cout<<"std::exception is catched"<<std::endl;
        std::cout<<"cat is catched"<<std::endl;
    }
    return 0;
}
