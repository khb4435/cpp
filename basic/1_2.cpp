//
//  main.cpp
//  2
//
//  Created by 김현배 on 2022/02/17.
//

#include <iostream>
//class Cat{
class alignas(32) Cat{
public:
    void speak();
private:
    int i4a;
    double d8;
    int i4b;
    //16bytes
};

Cat staticCat; //static영역의 Cat object

int main(int argc, const char * argv[]) {
    std::cout<<sizeof(Cat)<<std::endl; //16bytes? No 24bytes(by padding)
    //->32bytes by alignas(32)
    
    Cat stackCat; //stack 영역의 Cat object
    
    //prefer smartPtr
    Cat* heapCatPtr = new Cat(); //Heap영역의 Cat
    delete heapCatPtr;
    
    Cat cats[100]; //24 48 72 .. -> 32 64 ..
    //false sharing이 64bytes마다 일어나므로 alignas32를 하지 않으면 객체가 찢어질 위험이 있었음.
    return 0;
}
