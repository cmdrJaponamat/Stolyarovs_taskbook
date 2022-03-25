#include <stdio.h>

int get_and_zero(int *numb){
    int buf = *numb;
    printf("%d\n",buf);
    *numb = 0;
    return buf;
}

int main(){
    int numb=0;
    scanf("%d",&numb);
    printf("%d\n", get_and_zero(&numb));
    printf("%d\n",numb );
    return 0;
}
