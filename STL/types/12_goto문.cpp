//쓰지말자. 가독성을 해치고, 버그가 들어가기 쉽다
//유용할 때 : 2중, 3중 반복문 탈출할 때
//내부 break만으로는 다 못빠져나와서 추가적인 코딩이 필요함

#include <iostream>

int main(){
    for(int i=0;i<10;i++){
        bool exit = false;
        for(int j=0;j<10;j++){
            if(i*j==25){
                //반복문 완전 탈출
                exit = true;
                break;
            }
        }
        if(exit == true){
            break;
        }
    }
    std::cout<<"after loop"<<std::endl;
}

//---goto문
int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i*j==25){
                //반복문 완전 탈출
                goto afterLoop;
            }
        }
        if(exit == true){
            break;
        }
    }
    afterLoop:
    std::cout<<"after loop"<<std::endl;
}
