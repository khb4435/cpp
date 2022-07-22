//
//  main.cpp
//  6
//
//  Created by 김현배 on 2022/02/18.
//


//함수 오버로딩 = static polymorphism -> 같은 함수 이름 다른 파라미터
//operator 오버로딩 = * / % ...
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Cat{
public:
    Cat(std::string name,int age):mName{std::move(name)},mAge{age} {}
    const std::string& name() const{
    //반환형식이 참조자인것은 복사과정을 없애기 위함임
        return mName;
    }
    int age() const{
    //반환할 때 복사 일어남
        return mAge;
    }
    void print() const{
        std::cout<<mName<<" "<<mAge<<std::endl;
    }
private:
    int mAge;
    std::string mName;
};

//operator overloading은 클래스 안과 밖에서 모두 정의할 수 있는데
//public member만으로 충분하다면 클래스 밖에서 정의를 해주고
//private member에 접근을 해야 한다면 클래스 안에서 정의를 해야 한다.
bool operator == (const Cat& lhs, const Cat& rhs){
    return lhs.age()==rhs.age() && lhs.name()==rhs.name();
}

//없다면 SORT가 되지 않음 그냥 std::vector<int> vec={1,2,3,4,5};였으면 이 오퍼레이터 필요없음
//여러 멤버변수가 있는데 뭐를 기준으로 어떻게 소트할지 알려줘야 하기 때문에 필요한것임
//이거는 소트시 나이로 소트한다는 것
bool operator< (const Cat& lhs, const Cat& rhs){
    if(lhs.age() < rhs.age()){
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    Cat kitty{"kitty",1};
    Cat nabi{"nabi",2};

    if(kitty==nabi){
        std::cout<<"same"<<std::endl;
    }

    else std::cout<<"not same"<<std::endl;

    if(kitty<nabi){
        std::cout<<"nabi is older"<<std::endl;
    }

    else std::cout<<"nabi is not older"<<std::endl;

    std::vector<Cat> cats;
    //add cats..
    std::sort(cats.begin(),cats.end()); //는 operator< 를 이용하여 수행된다.
    return 0;
}
