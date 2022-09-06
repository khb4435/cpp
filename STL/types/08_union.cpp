#include <iostream>
#include <string>
#include <vector>
 
//메모리를 소멸자/생성자 써주면서 관리하기 불편.
//type tracking
//union-like class, tagged union 검색
//std::variant가 union보다 낫다.
union S
{
    std::string str;
    std::vector<int> vec;
    ~S() {} // needs to know which member is active, only possible in union-like class 
};          // the whole union occupies max(sizeof(string), sizeof(vector<int>))
 
int main()
{
    S s = {"Hello, world"};
    // at this point, reading from s.vec is undefined behavior
    std::cout << "s.str = " << s.str << '\n';
    s.str.~basic_string();
    new (&s.vec) std::vector<int>;
    // now, s.vec is the active member of the union
    s.vec.push_back(10);
    std::cout << s.vec.size() << '\n';
    s.vec.~vector();
}

//동적할당되는 메모리의 경우 메모리 덮어쓰기전에 소멸자 호출!
//새로 만들때 생성자 호출!
