//vector? 
1.dynamic size array
2.sequence array

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    //동적할당 new -> delete필요
    int* numsPtr = new int[5];
    for(int i=0;i<5;i++){
        numsPtr[i]=i;
    }
    delete [] numsPtr;
    
    //동적할당 vector -> delete필요X
    std::vector<int> nums(5);
    for(int i=0;i<5;i++){
        nums[i]=i;
    }
    //delete 필요없음
}   
