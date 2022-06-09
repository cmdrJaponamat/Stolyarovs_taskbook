#include <stdio.h>

class I
{
    int x,y;
public:
    I(int x_in, int y_in){x = x_in; y = y_in;}
    int GetX() const {return x;}
    int GetY() const {return y;}
//    void operator() (int i, int j)
//    {
//        I(i,j);
//    }
};

class M
{
    int **i;
public:
    M()
    {
        i = new int*[3];
        for (int j = 1; j<3; j++)
            i[j]=new int[2];  
        for (int j = 1; j<3; j++){
            i[j][j] = 1;
        }
    }
    M(M& m1)
    {
        for (int j = 1; j < 3; j++){
            for (int c = 1; c < 3; c++)
                i[j][c] = m1.i[j][c];
        }
    }
    M operator+(M m2)
    {
        for (int c = 1; c < 3; c++){
            for (int j = 1; j < 3; j++)
                i[c][j] += m2.i[c][j];
        }
    }
    int& operator[] (const I& j) 
    {
        int x = j.GetX();
        int y = j.GetY();
        return i[x][y]; 
    }
};

int main()
{
    M m1;
    printf("%d %d %d\n", m1[I(1,1)], m1[I(2,2)], m1[I(2,3)]);
    M m2;
    m1[I(2,3)] = 7;
    m2[I(2,3)] = 350;
    M m3(m1 + m2);
    printf("%d %d %d\n", m3[I(1,1)], m3[I(2,2)], m3[I(2,3)]);
    return 0;
}
