//
//  main.cpp
//  any
//
//  Created by 김현배 on 2022/03/01.
//




//((void*))로 어떤 타입이든간에 접근할 수 있는데 제대로 사용하려면 그 접근된 메모리의 타입을 내가 인식하고 있어야함.
// ((void* + 가르켜지는 메모리타입정보))가 한 세트가 되면 뭔가 편해지지 않을까? -> any
//any 사용 거의 안함. any쓰면 못 짠 코드임

#include <any>
#include <iostream>
#include <vector>
int main()
{
  std::vector<std::any>pythonlike {42,1.42f,"helllo"};
  //python,javascript같이 아무 타입 다 넣을 수는 있음
    std::cout << std::boolalpha;

    // any type
    std::any a = 1;
    std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
    // i : 1
    a = 3.14;
    std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
    //d : 3.14
    a = true;
    std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';
    //b : true

    // bad cast
    try //해보기
    {
        a = 1;
        std::cout << std::any_cast<float>(a) << '\n';
    }
    catch (const std::bad_any_cast& e) //당연히 exception던져지며 이부분실행
    {
        std::cout << e.what() << '\n';
        //bad any_cast
    }

    // has value
    a = 2;
    if (a.has_value())
    {
        std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
        // i
    }

    // reset
    a.reset();
    if (!a.has_value())
    {
        std::cout << "no value\n";
        //no value
    }

    // pointer to contained data
    a = 3;
    int* i = std::any_cast<int>(&a);
    std::cout << *i << "\n";
    //1
}
//g++ main.c -std==c++17
