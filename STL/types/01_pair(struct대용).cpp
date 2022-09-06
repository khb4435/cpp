//pair를쓰면
//struct a
//{
//  int a,
//  string b
//}; 안써도됌
#include <iostream>
#include <string>
#include <utility>
enum class Error_code{
    error,
    no_error,
};

//answer,error code (prefer enum class)
//예외처리가 되지 않는 환경에서 pair를 이용하여 error code를 던져주는 방식으로.
//std::pair<int,int> divide(int a, int b){ //divide 함수 정의
std::pair<int,Error_code> divide(int a, int b){
    if(b==0){
        //return {0, -1};
        return {0, Error_code::error};
    }
    //return {a/b, 0};
    return {a/b, Error_code::no_error};
}

int main(int argc, const char * argv[]) {
    std::pair<int,std::string> numStr{1,"nocope"};
    std::cout<<numStr.first<<" "<<numStr.second<<std::endl;
    
    //std::pair<int,int> answer = divide(10, 0);
    //std::pair<int,Error_code> answer = divide(10, 0);
    auto answer = divide(10, 0);
    
    //if(answer.second != 0) {//error code
    if(answer.second != Error_code::no_error) {//error code
        std::cout<<"error code"<<std::endl;
    }
    return 0;
}
