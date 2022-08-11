//deque(double ended queue)
//앞뒤로 데이터 push가 가능한 queue
//백터처럼 뒤의 데이터 인 아웃은 0(1)의 시간소요
//백터와는 달리 데이터 맨 앞도 인 아웃 0(1)의 시간소요
//중간에 데이터 넣고 빼는것만 0(n)

//벡터와는 달리 넣으려고하는데 어떤 메모리있다해도 전체가 다 이동하고 그런게 없음
//사진참고
//단점1.두번의 포인터
//단점2.연속되어있지 않은 메모리로 하드웨어적으로 캐시 미스가 날 수 있음

//vector가 더 낫다.

#include <iostream>
#include <deque>

int main(){
    std::deque<int>d={7,5,16,8};

    d.emplace_front(13); //0(1)
    d.emplace_back(25); //0(1)

    for(int n : d){
        std::cout<<n<<'\n'; // 13 7 5 16 8 25
    }
}
