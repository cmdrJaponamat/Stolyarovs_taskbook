#include <stdio.h>

char *occurrences(char *first_arg, char *second_arg){
    int first_arg_length = 0;
    char *position = first_arg, *buf = second_arg;
    do{
        if (*buf == *position){
            while(*position++){
                first_arg_length++;
                buf++;
                if (*buf == *position){
                    if (!*position+1){
                        return buf-first_arg_length;
                    }
                }
                else break;
            }
        }
    } while (*++buf);
    return NULL;
}

int main(int argc, char **argv){
    char *first_arg = *(argv + 1), *buf;
    int occurences = 1;
    argv = argv+1;
    while (*++argv){
        if (occurrences(first_arg, *argv)){
            buf = occurrences(first_arg, *argv);
            while (occurrences(first_arg, buf+1)){
                occurences++;
                buf=occurrences(first_arg, buf+1);
            }
            printf("%s, %d\n", *argv, occurences);
        }
        occurences = 1;
    }
    return 0;
}