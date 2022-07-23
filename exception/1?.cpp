//
//  main.cpp
//  1
//
//  Created by 김현배 on 2022/03/20.
//


//C에는 예외처리가 없고
//C++에는 optional,pair,tuple등 error return하는 방법외에도
//exception(try,catch,throw)가 있음

#include <iostream>
#include <exception>
class Cat{
public:
    Cat(){}
    ~Cat(){}
};

int divide(int a, int b){
    if(b==0){
        //throw::std::exception(); //std::exception이라는 객체를 만들어서 던짐
        
        //throw::std::runtime_error("divide by 0");
        
        throw Cat();
    }
    return a/b;
}
int main(int argc, const char * argv[]) {
    try{
        std::cout<<divide(10,0)<<std::endl;
    }
    /*
    catch(const std::exception(&e)){
        //std::cout<<"std::exception is catched"<<std::endl;
        
        std::cout<<e.what()<<std::endl;
        std::cout<<"std::exception is catched"<<std::endl;
    }
    catch(const Cat& c){
        std::cout<<"cat is catched"<<std::endl;
    }
     */
    catch(...){
        std::cout<<"std::exception is catched"<<std::endl;
        //std::cout<<e.what()<<std::endl;
        std::cout<<"std::exception is catched"<<std::endl;
        std::cout<<"cat is catched"<<std::endl;
    }
    return 0;
}
