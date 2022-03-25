#include <stdio.h>

int main(){
    char hello[]="Hello!";
    char *str;
    str = &hello[0];
    printf("%3s\n", str);
    printf("%8s\n", str);
    printf("%-8s\n", str);
    printf("%3.4s\n", str);
    printf("%6.4s\n", str);
}
