#include <stdio.h>

int main(){
    int begin=0, i=0, c, letter_cnt = 0, printed=0;
    char str[]="ii";
    while((c=getchar())!=EOF){
        if (c!=10 && c!=32){
            letter_cnt++;
        }
        if ((c==32 || c==10) && i==2 && letter_cnt==2){
            printf("%s", &str[0]);
            putchar(c);
            printed = 1;
            i=0;
        }
        if (letter_cnt>2 && (c==10 || c==32)){
            putchar(c);
        }
        if (c==32 || c==10){
            letter_cnt=0;
            i=0;
        }
        if (c!=10 && c!=32 && i<2){
            str[i]=c;
            i++;
        }
    }
}
