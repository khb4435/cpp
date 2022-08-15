//
//  main.cpp
//  optional3
//
//  Created by 김현배 on 2022/02/27.
//

#include <iostream>
#include <optional>

int main(int argc, const char * argv[]) {
    int num=10;
    std::optional<int> num2{20};//4바이트보다 큼 메모리의 존재 유무 정보도 포함한다.
    return 0;
}
