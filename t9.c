#include <stdio.h>

int main(){
    char str[254];
    int i = 0, words_cnt = 0, c = 0, letter_cnt = 0, words2 = 0, words = 0;
    int big_words_cnt = 0, small_words_cnt = 0, Az_cnt=0;
    int bigest_word =0, smallest_word=254, space_cnt=0, bigest_space=0;
    int close_paranthesis_cnt=0, enter_paranthesis_cnt=0, equation_cnt=0; 
    letter_cnt = 0;
    while ((c = getchar())!=EOF){
        str[i] = c;
        if (i>0 && (str[i]== 32 || str[i] == 10) && (str[i-1]!=32 && str[i-1]!=10)){
            words_cnt++;
        }
        if (c==40){enter_paranthesis_cnt++;}
        if (c==41){close_paranthesis_cnt++;}
        if (str[i]==41 && str[i-1]==40){equation_cnt++;}
        
        if (space_cnt>bigest_space){
            bigest_space=space_cnt;
        }
        if (c != 32 && c != 10){
            letter_cnt++;
            space_cnt = 0;
        }
        if (c==10){space_cnt=0;}
        if (c==32){space_cnt++;}
        if (c == 32 || c == 10){
            if (letter_cnt>bigest_word){
                bigest_word = letter_cnt;
            }
            if (letter_cnt<smallest_word){
                smallest_word = letter_cnt;
            }
            if (str[i-1]==122 && str[i-letter_cnt]==65){
                Az_cnt++;
            }
            if (letter_cnt > 7){
                big_words_cnt++;
            }
            if (letter_cnt <=2 && letter_cnt>0){
                small_words_cnt++;
            }
            if (letter_cnt>0 && letter_cnt%2 == 0) {
                words2++;
            }
            if (letter_cnt > 0 && letter_cnt%2!=0){
                words++;
            }
            letter_cnt = 0;
        }
        i++;
    }
    if (space_cnt>bigest_space){
        bigest_space=space_cnt;
    }
    if (letter_cnt>0){
        if (letter_cnt%2==0){
            words2++;
        }
        else{words++;}
        words_cnt++;
        if (letter_cnt > 7){
            big_words_cnt++;
        }
        if (letter_cnt <=2){
            small_words_cnt++;
        }
        if (str[i-1]==122 && str[i-letter_cnt]==65){
            Az_cnt++;
        }
    }
    printf ("\n1. Words cnt: %d\n", words_cnt);
    printf ("2. Words: %d,  Words2: %d\n", words, words2);
    printf ("3. big: %d;   small: %d\n", big_words_cnt, small_words_cnt);
    printf ("4. A...z words: %d\n", Az_cnt);
    printf ("5. Words cnt: %d, Bigest word: %d, Smallest word: %d\n", words_cnt, 
            bigest_word, smallest_word);
    printf ("6. Count of spaces: %d\n", bigest_space);
    if (enter_paranthesis_cnt == close_paranthesis_cnt && (enter_paranthesis_cnt>0 && 
                close_paranthesis_cnt>0)){
        printf("7. YES\n");
        }
    else if (enter_paranthesis_cnt>0 || close_paranthesis_cnt>0){
        printf("7. NO\n");
    }
    printf ("8. Equation cnt: %d\n", equation_cnt);
    return 0;
}
