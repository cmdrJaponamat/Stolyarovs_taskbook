#include <stdio.h>
#include <stdlib.h>

class A{
	int i[201];
	public:
		A(int argv)
		{
			for (int j = 0; j<=201; j++){
				i[j] = j+argv;
			}
		}
		int *getnum() {return i;}
		int& operator[](int j){return i[j];}		
};

int main (int argc, char **argv)
{
	if (argc > 1){
		A first = atoi(argv[1]);
		A second(atoi(argv[2]));
	
		printf("first: %d %d\n", first[100], first[200]);
		printf("second: %d %d\n", second[100], second[200]);
	}
	return 0;
}
