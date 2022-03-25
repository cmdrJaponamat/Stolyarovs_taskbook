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
int cnt_space(char *str);
int cnt = 0;
int main(void){
    int cnt = 0;
    char str[]=" Hello World ! 1 1 1 1 1 1";
    cnt = cnt_space(&str[0]);
    printf("%d\n", cnt);
    return 0;
}


int cnt_space(char *str){
    if (*str == 32){
        cnt++;
    }
    if (!(*str)){
        return cnt;
    }
    str++;
    cnt_space(str);
    return cnt;
}
