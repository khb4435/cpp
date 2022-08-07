int main(){
  std::vector<int>nums{1,2,3,4,5};
  std::cout<<sizeof(nums)<<std::endl; //24?
  //벡터는 3가지의 타입으로 구성된다. 힙공간을 가리키는 포인터, size, capacity
  
  std::cout<<nums.size()<<std::endl; //5
  std::cout<<nums.capacity()<<std::endl; //10
  //즉 사이즈는 5인데 capacity라는 보존된공간?이 있음
  
  nums.emplace_back(6);
  std::cout<<nums.size()<<std::endl; //6
  std::cout<<nums.capacity()<<std::endl; //10
  
  //즉 이렇게 size == capacity되는순간 엘레멘트가 하나 더 들어오면
  //capacity가 늘어난다.
  
  //capacity할다 받은 후 엘레멘트 맨 마지막 백터에 추가하는거 0(1)
  //capacity할당받느 과정은 엑스트라 타임이 소요된다.
  
  //그러므로 확보공간을 미리 많이 해 놓고 하자
  nums.reserve(10000000);
  
  //또 만약 emplace_back해야되는데 그 바로 다음자리에 어떤 메모리가 있다?
//  그대로 복사한 후 스택메모리의 포인터를 또 거기로 move시키고 emplace back 되는 0(n)이 소요되므로
  //  reserve는 필수 사용
}
