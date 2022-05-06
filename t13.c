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
    free(str_of_num);
    return str_of_num;
}

int sum_of_arr(char *str_of_num, int *cnt, char *end_str, int *n, int *inacuracy, int *str_cnt){
    int i = -1;
    (*str_cnt)--;
    do{
        i++;
        (*cnt)++;
        if (*cnt >= *n){
            end_str[*str_cnt] = str_of_num[i];
            (*str_cnt)++;
        }
    } while(str_of_num[i]!='\0');
    return 0;
}

int main(int argc, char **argv){
    int cnt = 0, inacuracy = 0, str_cnt = 0;
    long long sqr = 0;
    int n = atoi(*(argv+1)), m = atoi(*(argv+2));
    char *end_str;
    end_str = (char *)malloc(1000000000);
    printf("%d, %d\n", n, m);
    for (int i = 1; cnt <= m; i++){
        sqr = i*i;
        sum_of_arr(get_arr_from_num(sqr), &cnt, end_str, &n, &inacuracy, &str_cnt);
    }
    for (int i = 1; i<m-n; i++){
        printf("%c", end_str[i]);
    }
    printf("\n%s", end_str);
    free(end_str);
    return 0;
}