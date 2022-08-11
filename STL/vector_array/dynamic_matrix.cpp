//
//  main.cpp
//  dynamicMatrix
//
//  Created by 김현배 on 2022/02/20.
//

#include <iostream>
#include <array>
#include <vector>

int main(int argc, const char * argv[]) {
    std::array<std::array<int,3>,3> fixedMatrix; //3x3 in Stack in a row!!!
    fixedMatrix[1][1] =5;
    
    
    std::vector<std::vector<int>> dynamicMatrix(3,std::vector<int>(3));
    //스택엔 *,사이즈,캐패시티정보
    //힙위에 세칸을 가진 메모리 공간이 만들어지고 포인터는 여길 가리키고 (3)
    //그 각 세칸은 또 *,사이즈,캐패시티 있는데 또 *는 각각 한개씩 세칸짜리를 가리키게 된다.std::vector<int>(3)
    //연속 메모리 공간읽는데 제약있는 프로그램은 이 방법을 사용해라
    dynamicMatrix[0][2]=10;
    //
    return 0;
}

---------------
templete <typename T>
class Matrix{
    public:
        Matrix(int row, int col):mMatrix(row*col,0){
            mRow = row;
            mCol = col;
        }
        T& operator()(int rowIdx,int colIdx){
                const int idx = rowIdx + mCol * colIdx;
                return mMatrix[idx]
        }
    private:
        std::vector<T>mMatrix;
        int mRow;
        int mCol;
}

int main(){
    Matrix<int> mat(10,10);
    mat(3,3)=3;
    mat(4,3)=mat(3,3)*10;
}

---------------컴파일타임에 사이즈 정해주려면
templete <typename T,int ROW,int COL>
class Matrix{
    public:
        Matrix():mMatrix(ROW*COL,0)
        {
        }
        T& operator()(int rowIdx,int colIdx){
                const int idx = rowIdx + COL * colIdx;
                return mMatrix[idx]
        }
    private:
        std::vector<T,10,10>mMatrix;
        int mRow;
        int mCol;
}

int main(){
    Matrix<int> mat(10,10);
    mat(3,3)=3;
    mat(4,3)=mat(3,3)*10;
}

//-------------다차원배열 루프돌리기
#include <vector>
int main(){
    std::array<std::array<int,10>,10>mat;
    //1
    for(int rowIdx=0;rowIdx<10;rowIdx++){
        for(int colIdx=0;colIdx<10;colIdx++){
            mat[rowIdx][colIdx]+=1;
        }
    }

    //2
    for(int colIdx=0;colIdx<10;colIdx++){
        for(int rowIdx=0;rowIdx<10;rowIdx++){
            mat[rowIdx][colIdx]+=1;
        }
    }

    //방식이 같이 보이지만 "캐시"때문에 속도가 1000배까지 차이가난다.
    //row loop가 안에있으면 캐시 미스가 일어난다.
    //첫줄 한칸읽으면 그 첫줄에 대한 캐시가 생기는데 첫줄 한칸읽고 row로 다음줄 읽으면 캐시 미스가 일어나는것.
}
