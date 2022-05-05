#include <stdio.h>
#include <stdlib.h>

char *get_arr_from_num(int num){
    char *str_of_num;
    int cnt = 0;
    str_of_num = (char *)malloc(sizeof(long long));
    while (num > 9){
        str_of_num[cnt++] = (num%10) + '0';
        num = num/10;
    }
    str_of_num[cnt++] = num + '0';
    str_of_num[cnt] = '\0';
    char buf;
    for (int i = 0; i<cnt/2; i++){
        buf = str_of_num[i];
        str_of_num[i] = str_of_num[cnt-i-1];
        str_of_num[cnt-i-1] = buf;
    }
    cnt = 0;
    return str_of_num;
}

char *sum_of_arr(char *str_of_num, int *cnt){
    char *end_str;
    (*cnt)--;
    end_str = (char *)malloc(1024);
    do{
        (*cnt)++;
        end_str[*cnt] = str_of_num[*cnt];
    } while(str_of_num[*cnt]!='\0');
    return end_str;
}

int main(int argc, char **argv){
    int cnt = 0, sqr = 0;
    int n = atoi(*(argv+1)), m = atoi(*(argv+2));
    char *end_str;
    printf("%d, %d\n", n, m);
    for (int i = 1; i<=n; i++){
        sqr = i*i;
        end_str = sum_of_arr(get_arr_from_num(sqr), &cnt);
    }
    // printf("%s", sum_of_arr(get_arr_from_num(n), &cnt));
    printf("%s\n", end_str);
    // (1 4 9 16 25 36 49 64 81 100 121 144 169 196 225 256 289 324 361 400 441 484 529 576 625 676 729 784 841 900 961 1024)
    return 0;
}