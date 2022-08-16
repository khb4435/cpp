#include <string>
//value,lvalue rvalue 셋 다 받으면서 
//lvalue넘어갈땐 1copy
//rvalue넘어갈땐 0copy
//가 목표

//결론 값으로 받고 std::move

//일단 함수의 인자는 lref,rref를 해버리면 둘 중 하나만 
//받을 수 있어서 한정됨

class Cat{
    public:
        void setName(std::string name){
            mName = std::move(name);
        }
    private:
        std::string mName;
}

int main(){
    Cat kitty;
    std::string s = "kitty";

    kitty.setName(s);//1copy
    kitty.setName("kitty"); //0copy
    //r value인 kitty를 임시공간을 만들고 value에 복사해서 넘겨주는게 아니라
    //복사생략을 통해 name이 "kitty"가리킨다.
