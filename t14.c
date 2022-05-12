/*func to del space at str without copy with one circle*/

#include <stdio.h>

int space_dltr(char *str){
    printf("%s\n", str);
    if (*str) space_dltr(str+1);
    if (*str == 32){
        while (*(str+1) != 32 && (*(str+1) || *(str+1)=='\0')){
            *str = *(str+1);
            str++;
        }
    }
    return 0;
}

int main(int argc, char **argv){
    space_dltr(argv[1]);
    printf("!%s!\n", argv[1]);
    return 0;
}