#include <stdio.h>


int max_size_of_arg(int *max_cnt, char **max_arg, char** argv){
    int letter_cnt=0;
    char *buf;
    while (*++argv){
        buf = *argv;
        while(*buf++){
            letter_cnt++;
        }
        if (*max_cnt<letter_cnt){
            *max_cnt=letter_cnt;
            *max_arg = *argv;
        }
        letter_cnt=0;
    }
    return 0;
}

int no_repeat_letter(char **argv){
    return 0;
}


int main(int argc, char** argv){
    int max_cnt=0;
    char *max_arg;
    max_size_of_arg(&max_cnt, &max_arg, argv);
    while (*++argv){
        while (**argv++){
            int greatest_arg(max_arg, **argv);
            bool repeated_letter(**argv);
            int special_symbol(**argv);
            number_only(**argv);
            word_of_one_symbol(**argv);
        }
    }
    printf("%d, %s\n", max_cnt, max_arg);
    return 0;
}
