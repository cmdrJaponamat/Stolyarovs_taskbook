#include <stdio.h>

class I{
	int x,y;
public:
	I(int x_in, int y_in){x = x_in; y = y_in;}
	int GetX(){return x;}
	int GetY(){return y;}
	void operator() (int i, int j)
	{
		I xy(i,j);
	}
};

class M{
	int **i;
public:
	M()
	{
		i = new int*[2];
		for (int j = 0; j<2; j++) i[j]=new int[2];  
		for (int j = 0; j<=2; j++){
			i[j][j] = 1;
		}
	}
	M operator+(M i){}
	int& operator[](const I& j)
	{
		return i[j.GetX()][2];	
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
