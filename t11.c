#include <stdio.h>


int greatest_arg(int *letter_cnt,int *position,int *max_cnt,int *max_arg_link, int old_position){
    if (*position == old_position){
        (*letter_cnt)++;
    }
    else {
        if (*max_cnt<*letter_cnt){
            *max_cnt = *letter_cnt;
            *max_arg_link = old_position;
        }
        *letter_cnt=0;
    old_position = *position;
    }
    return 0;
}
int no_repeat_letter(char **argv){
    return 0;
}


int main(int argc, char** argv){
    int old_position=1;
    int position = 0, letter_cnt = 0;
    int max_cnt=0, max_arg_link = 0;
    char *max_arg, *buf;

    while (*++argv){
        position++;
        buf = *argv;
        while (*buf++){
            greatest_arg(&letter_cnt, &position, &max_cnt, &max_arg_link,old_position);
//            bool repeated_letter(**argv);
//            int special_symbol(**argv);
//            number_only(**argv);
//            word_of_one_symbol(**argv);
        }
    }
    printf("%d, %d\n", max_cnt, max_arg_link);
    return 0;
}
