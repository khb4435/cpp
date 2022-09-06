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
    
    //벡터기본(벡터는 힙공간 배열을 가리키는 포인터와, 사이즈, 캐패시티 정보로 구성된다)
    std::vector<int> vec{0,1,2,3,4};
    std::cout<<vec.size()<<std::endl; //5
    vec.emplace_back(5); //이렇게 보면 int의 "값"이 들어가는 걸 볼 수 있음
    std::cout<<vec.size()<<std::endl; //6
    vec.pop_back();
    std::cout<<vec.size()<<std::endl; //5
    
    //벡터값 추출하는 세가지 방법
    //1.index based 
    //사이즈 변화하는 벡터의 경우 무조건 이 방법 써야한다.
    for(std::size_t idx=0; idx<vec.size(); idx++){
        std::cout<<vec[idx]<<" ";
    }std::cout<<std::endl;
    
    //2.iterator based
    //여기서 end는 백터마지막공간 다음공간을 포인팅한다.
    for(auto itr=vec.begin(); itr!=vec.end(); itr++){
        std::cout<<(*itr)<<" ";
    }std::cout<<std::endl;
    
    //3.range based loop (제일빠름, 제일 안정적이다.)
    ((3이 제일 편하고 빠르지만 벡터 사이즈가 변화할 시 무조건 1번 써야한다))
    for(const int& num : vec){
        std::cout<<num<<" ";
    }std::cout<<std::endl;
}   
