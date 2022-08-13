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
    storeByValue(a); //2copy
    storeByLRef(a); //1copy

    //0 copy
    storeByRRef("abc");
    storeByRRef(std::move(a));
}

-------------------std::move 오너십
//1
void storeByLRef(std::string &s){
    std::string b = std::move(s);
};

int main(){
    std::string a = "abc";
    storeByLRef(a);
    std::cout<<a<<std::endl; //값이 없음 오너십 b에뺏김
}

//2
void storeByLRef(const std::string &s){
    std::string b = std::move(s);
};

int main(){
    std::string a = "abc";
    storeByLRef(a);
    std::cout<<a<<std::endl; //"abc" const , std::move조합은
    //copy일어난다.
}
