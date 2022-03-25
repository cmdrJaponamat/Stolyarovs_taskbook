#include <stdio.h>

int space_cnt(char *str){
    char *buf;
    buf = str;
    int cnt = 0;
    for(;*buf;buf++){
        if (*buf == 32){
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    int cnt = 0;
    char str[]=" Hello World!";
    cnt = space_cnt(&str[0]);
    printf("%d\n", cnt);
    return 0;
}
