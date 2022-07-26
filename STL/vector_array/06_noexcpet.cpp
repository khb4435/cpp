//move cons/assignment 나 destructor처럼 절대 exception이 일어나면 안되는 곳에 수행되야하는 놈들은 noexcept를 붙여줘야 optimization이 됩니다.
//emplace_back시 다른공간있으면 다른공간에 할당되는데 copy보다 move로 해결하기 위해
//move생성자 정의
//다시한번 애초에 이런일 안 일어나도록 큰 공간 reserve해주자

#include <iostream>
#include <vector>
class Cat{
public:
    explicit Cat(std::string name) : mName{std::move(name)} {}
    ~Cat() noexcept {}
    Cat(const Cat &other) : mName{other.mName}{}
    Cat(Cat &&other) noexcept : mName{std::move(other.mName)}{}
private:
    std::string mName;
};

int main(int argc, const char * argv[]) {
    std::vector<Cat> cats;
    
    cats.reserve(2);
    cats.emplace_back("kitty"); //여기서 복사생성자가 불러지는게아님
    cats.emplace_back("nabi");
    return 0;
}
