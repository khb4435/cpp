//
//  main.cpp
//  dynamicMatrix
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <array>
#include <vector>

int main(int argc, const char * argv[]) {
    std::array<std::array<int,3>,3> fixedMatrix; //3x3 in Stack;
    std::vector<std::vector<int>> dynamicMatrix(3,std::vector<int>(3));
    
    fixedMatrix[1][1] =5;
    dynamicMatrix[0][2]=10;
    return 0;
}
