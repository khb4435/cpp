//
//  main.cpp
//  arrav_vector
//
//  Created by 김현배 on 2022/02/20.
//

//C스타일이 아닌 std array로 쓰면 iterator를 쓸수있다는건 아는데 다른 장점이 더 있나요?
//vector에서 예시든 nums.begin()이런게 array에서도 가능하다는것
//Array.size()도 하나의 장점이 되겠네요

//array를 굳이 써야할 이유가 있을까요?? vector로 모든경우에 대해서 대체가 가능한것 같아서요. vector선언때 size를 선언하면 메모리 할당시간이 엄청 느릴거 같지도 않고....
//general한 heap memory allocator를 사용한다면 vector에서 heap memory allocation을 받는 순간 많은 시간을 소모하게됩니다. 
//또한 많은 시간 사용하다보면 memory fragmentation에 대해서도 생각을 해보아야 합니다. 
//array는 stack위에 올라가기 때문에 따로 메모리를 할당 받을 필요 없고, stack에 올라가기 때문에 fragmentation도 걱정할 필요없습니다. 
//컴파일 시간에 어레이의 사이즈를 알고, 그 어레이의 사이즈가 작다면 std::array를 사용해서 stack에 올리는 것을 추천드립니다.

//array,vector둘다 random access 지원 nums[i] 시간 0(1)
#include <iostream>
#include <array>
#include <vector>
int main(int argc, const char * argv[]) {
    // insert code here...
    std::array<int,100> nums; //in Stack 연속된 공간, 컴파일타임
    std::vector<int>numss(100); //in Heap 연속되 공간, 런타임
    
    int numsA[100]; //C style
    std::array<int,100> numsB; //C++ style
    return 0;
}
