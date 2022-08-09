#include <iostream>
#include <chrono>
#include <vector>


//사이즈가 변화하는 벡터의 반복문은 무조건 index based!!!!

//index based
int main(){
    std::vector<int> nums{0,1,0,1};
    for(std::size_t idx =0; idx<nums.size();idx++){
        if(nums[idx]==0){
            nums.emplace_back(2); // 
        }
    }
    for(const auto&num : nums){
        std::cout<<num<<" "; // 0 1 0 1 2 2
    }//채워진 공간만나서 이동/복사가 되어도 size에 종속받으니 num은 그냥 이사한 곳의 처음공간을 가리키게됨
    std::cout<<std::endl;
} //그러므로 사이즈가 변경이 되는 벡터면 무조건 1번 방식을 쓰자

//iterator based
int main(){
    std::vector<int> nums{0,1,0,1};
    for(auto itr = nums.begin(); itr!= nums.end(); itr++){
        if(*(itr)==0){
            nums.emplace_back(2);  
        }
    }
    for(const auto&num : nums){
        std::cout<<num<<" "; // 0 1 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
    } //2넣으려고 했는데 바로 공간있어서 새로운공간에 복사or무브하고 다시 2가 집어넣어지는것
//itr은 근데 여전히 처음공간의 그곳을 가리킴 근데 nums.end()는 이사간곳의 마지막을 가리킴
    std::cout<<std::endl;
}

//range based
int main(){
    std::vector<int> nums{0,1,0,1};
    for(auto&num : nums){
        if(num==0){
            nums.emplace_back(2); // 
        }
    }
    for(const auto&num : nums){
        std::cout<<num<<" "; // 0 1 0 1 2 2 2
    }//이는 library implementation마다 다르기 때문에 꼭 찝어서 말씀드리기 어렵습니다. 
    //중요한점은 vector의 capacity가 변하면서 전체복사가 일어날경우 
    //iterator,ranged loop은 잘못된 결과로 이어질수 있다라는 점입니다. 또 궁금한점 있으시면 질문주세요. 감사합니다.
    std::cout<<std::endl;
}
