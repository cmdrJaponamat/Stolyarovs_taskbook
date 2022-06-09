#include <stdio.h>
#include <stdlib.h>

class B{
	int i;
public:
	B(int j)
	{
		i = j;
	}
	int Get() const {return i;}
	B operator+(int j)
	{
		B res(i += j);
		return res;
	}
	B operator+=(int j)
	{
		B res(i += j);
		return res;
	}
};

int main()
{
	B first(1), second = 2;
	first = first + 10; second += 1000;
	printf("%d %d\n", first.Get(), second.Get());
	return 0;
}
