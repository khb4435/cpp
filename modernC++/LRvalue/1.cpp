#include <string>

void storeByValue(std::string s){
    std::string b = s;
};

void storeByLRef(std::string &s){
    std::string b = s;
};

void storeByRRef(std::string &&s){
    //std::string b = s; //wrong!
    std::string b = std::move(s); 
    //RRef를 받은 s는 여기서 LValue기 때문에 
    //std::move를 통해 RValue화 시키자
};

int main(){
    std::string a="abc";
    storeByValue(a);
    storeByLRef(a);

    storeByRRef("abc");
    storeByRRef(std::move(a));
}
