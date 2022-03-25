#include <stdio.h>

int main(){
    int c=0, end=0, begin = 1;
    while ((c=getchar())!=EOF){
        if (c=='\n'){
            if (end==0){
                putchar(c);
                begin =1;
                end=0;
            }
            else{
                putchar(')');
                putchar(c);
                begin =1;
                end=0;
            }
        }
        else if (c == ' ' && end ==0){
            putchar(c);
            begin=1;
            end=0;
        }
        else if (c==' ' && end==1){
            putchar(')');
            putchar(c);
            begin=1;
            end=0;
        }
        else{
            if(begin){
                putchar('(');
                putchar(c);
                begin = 0;
                end=1;
            }
            else{
                putchar(c);
                begin = 0;
                end=1;
            }
        }
        
    }
}
