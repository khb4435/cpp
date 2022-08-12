//std::span -> 연속적인 메모리공간을 메모리 시작점고 길이를 통해 표현하는 추상화된 컨테이너임
//string_view도 마찬가지임

#include <array>
#include <vector>
#include <iostream>
#include <span>
#include <algorithm>

//수정되야함
void printSpan(std::span<int>nums){
    for(auto &num : nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;

    auto ret = std::ranges::find(nums,3); //ranges : c++20
    if(ret!=nums.end()) //3을 찾았다면
    {
        std::cout<<"found 3"<<std::endl;
    }
}

int main(){
    std::vector<int>vec{1,2,3,4,5};
    std::array<int,5>arr{1,2,3,4,5};
    int cNum[6]={1,2,3,4,5,6};

    std::span<int> sp{vec};
    //주의사항. 이짓한후 vec에 emplace_back하지말자
    //span은 할당받는 메모리의 시작주소와 사이즈만 알고있기때문에
    //벡터가 다른공간으로 가면 (( vec.emplace_back() 등 )) 이상한 값을 읽게 되므로 벡터가 이동하지 않도록 주의!
    printSpan(sp);

    std::span<int> sp{arr};
    printSpan(sp);

    std::span<int> sp{cNum};
    printSpan(sp);
}


//span으로 원본을 수정하는것도 가능
void printSpan(std::span<int>nums){
    std::sort(nums.begin(),nums.end());
}

int main(){
    std::vector<int>vec{1,2,3,4,5};
    std::span<int> sp{vec};

    printSpan(sp);
    
    for(auto& num : vec){
        std::cout<<num<<std::endl;
    }
}

//////////const span
int main(){
    const std::vector<int>vec{1,2,3,4,5};
    std::span<const int> sp{vec};
    //내부 element유지하지 위한 const, span은 여기 내부에 붙여준다.
    //스팬 그 자체를 유지하고 싶다면
    const std::span<int> sp{vec};
    //헷갈리면
    const std::span<const int> sp{vec};
}


///////위에는 dynamic span
//여기부턴 static span 즉 컴파일타임에 span의 사이즈를 나타내줄수있음
int main(){
    std::vector<int>vec{1,2,3,4,5};
    std::span<int,5> fixedSpan{vec};
    //컴파일러는 span의 사이즈를 매번 확인하는게 아니라 숫자가 딱 박히니까 더 최적화가 가능

    //subspan은 내가 학습해라
}
