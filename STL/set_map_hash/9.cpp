//
//  main.cpp
//  9
//
//  Created by 김현배 on 2022/02/22.
//

#include <iostream>
#include <string>
#include <unordered_set>
class Cat{
public:
    Cat(int age,std::string name):mName{std::move(name)},mAge{age}{}
    int age() const{
        return mAge;
    }
    const std::string& name() const{
        return mName;
    }
    void speak() const{
        std::cout<<"meow"<<std::endl;
    }
private:
    int mAge;
    std::string mName;
};


//이거 없으면 컴파일에러
struct CatHash{
    std::size_t operator() (Cat const& c) const noexcept{
        std::size_t h1=std::hash<int>{}(c.age()); //나이로 해쉬값 만들고
        std::size_t h2=std::hash<std::string>{}(c.name()); //이름으로 해쉬값 만들고
        //return h1^(h2<<1);
        return h1^h2;
    }
};

//==가 있어야 같은 버킷안에 있는 다른 고양이 오브젝트를 구별해 줄 수 있음
bool operator== (const Cat& lhs, const Cat& rhs){
    return (lhs.age()==rhs.age() && lhs.name()==rhs.name());
}

int main(int argc, const char * argv[]) {
    Cat kitty{1,"kitty"};
    Cat nabi{2,"nabi"};
    
    //std::unordered_set<Cat> cats;
    std::unordered_set<Cat,CatHash> cats;
    cats.emplace(kitty);
    cats.emplace(nabi);
    //중복은 제거됨 std::unordered_multiset<Cat,CatHash> cats로 정의하면 중복 허용됨
    cats.emplace(1,"kitty");
    cats.emplace(2,"nabi");
    
    for(const auto& cat: cats){
        cat.speak();
    }
    return 0;
}
