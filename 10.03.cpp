#include <stdio.h>

class D{
	int i;
public:
	D(){i = 0;}
	D(const D& j){i = j.i + 1;}
	int Get() const {return i;}
};


int main ()
{
	D x;
	D y(x);
	D z = y;
	printf("%d %d %d\n", x.Get(), y.Get(), z.Get());
	return 0;
}
