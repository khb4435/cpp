//
//  main.cpp
//  10
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
class Cat{
public:
    explicit Cat(std::string name,int age):mName{std::move(name)},mAge{age}{}
    void speak() const {}
    int age() const {
        return mAge;
    }
private:
    std::string mName;
    int mAge;
};

int main(int argc, const char * argv[]) {
    std::vector<Cat>cats;
    cats.reserve(4);
    cats.emplace_back("cat1",1);
    cats.emplace_back("cat2",2);
    cats.emplace_back("cat3",3);
    cats.emplace_back("cat4",4);
    
    cats.erase(std::remove_if(cats.begin(),cats.end(),[](const Cat& cat){
        if(cat.age()%2==0){//짝수
            return true;
        }
        return false;
    }),cats.end());
    
    for(const auto& cat : cats){
        cat.speak();
    }
    return 0;
}
