#include <iostream>

class I
{
    int x,y;
public:
    I(int x_in, int y_in){x = x_in; y = y_in;}
    int GetX() const {return x;}
    int GetY() const {return y;}
};

class M
{
    int **i;
public:
    M()
    {
        i = new int*[3];
        for (int j = 0; j <= 3; j++){
            i[j]=new int[3];
        }  
        for (int j = 0; j <= 3; j++){
            i[j][j] = 1;
        }
    }
    M(const M& m)
    {
        i = new int*[3];
        for (int c = 0; c <= 3; c++){
            i[c] = new int[3];
            for (int j = 0; j <= 3; j++){
                i[c][j] = m.i[c][j];
            }
        }
        for (int c = 0; c <= 3; c++){
            for (int j = 0; j <= 3; j++){
                std::cout<<i[c][j]<<std::endl;
            }
        }
    }
    int **Get() const {return i;}

    M operator+(const M& m2) const
    {
        for (int c = 0; c <= 3; c++){
            for (int j = 0; j <= 3; j++)
                m2.i[c][j] += i[c][j];
        }
        return m2;
    }
    int& operator[] (const I& j) 
    {
        int x = j.GetX();
        int y = j.GetY();
        return i[x][y]; 
    }
    ~M()
    {
        for (int c = 0; c <= 3; c++)
            delete [] i[c];
//        delete [] i;
    }
};

int main()
{
    M m1;
    std::cout<<m1[I(1,1)]<<" "<<m1[I(2,2)]<<" "<<m1[I(2,3)]<<std::endl;
    M m2;
    m1[I(2,3)] = 7;
    m2[I(2,3)] = 350;
    M m3 = m2 + m1;
//    M m3(m2);
    std::cout<<m3[I(1,1)]<<" "<<m3[I(2,2)]<<" "<<m3[I(2,3)]<<std::endl;
    return 0;
}
