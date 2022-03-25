#include <stdio.h>

int put_sum(int *a, int *b, int *c){
    int sum = *a+*b+*c;
    *a = *b = *c = sum;
    return sum;

}

int main(void){
    int a = 0,b = 0,c = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("%d\n", put_sum(&a,&b,&c));
    printf("%d, %d, %d\n", a,b,c);
}
