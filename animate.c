#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    int max = 50;
    int i = 0;
    int j;
    char animate_str[max+1];
    memset(animate_str, '\0', sizeof(animate_str));
    bool reverse_dir = false;

    while(true){
        if (i >= max){
            reverse_dir ^= true;
            i = max;
        }
        if (i == -1){
            reverse_dir ^= true;
            i++;
        }
        

        // if going forward
        if (reverse_dir == false){
            for(j=i; j<i+5; j++){
                animate_str[j] = '-';
                i++;
            }
            for(j=0; j<10; j++){
                printf("%s\n", animate_str);
            }
        }
        else{
            for(j=i; j>i-5; j--){
                animate_str[j] = '\0';
                i--;
            }
            for(j=0; j<10; j++){
               printf("%s\n", animate_str);
            }
        }
    }
}
