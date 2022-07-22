//
//  main.cpp
//  reference
//
//  Created by 김현배 on 2022/02/18.
//

#include <iostream>
class Cat{
public:
    explicit Cat(std::string name):mName{std::move(name)}{} //무조건 생성자를 이 형식으로 만든다는 것임
    const std::string& name() const{
        return mName;
    }
    
    //std::string name(){
    //    return mName;
    //}
private:
    std::string mName;
};

int main(int argc, const char * argv[]) {
    const Cat kitty{"kitty"};
    
    const std::string& name = kitty.name();
    
    //std::string name = kitty.name();
    return 0;
}
