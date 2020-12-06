#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

// max size for input
#define MAX_INPUT 32

void diagonal_wave();

int main(int argc, char *argv[]){
    char input[MAX_INPUT];
    int val;

    printf("Hi there!");
    while(true){
        printf("What animation do you want to see? (Type in a number)\n\n"
               "1 - Diagonal Wave\n\n");

        fgets(input, MAX_INPUT, stdin);
        printf("\n");
        val = atoi(input);
        if (val == 0){
            // remove newline before printing
            strtok(input, "\n");
            printf("'%s' is not a valid entry\n\n", input);
            continue;
        }

        switch(val){
            case 1:
                diagonal_wave();
                break;

            default:
                printf("'%d' is not a valid entry.\n\n", val);
        }
    }
}


void diagonal_wave(){
    int i = 0, timeout = 450;
    int max;
    bool going_forward = true;

    printf("What should the max line length be?\n\n");
    scanf("%d", &max);
    while(getchar() != '\n');
    printf("\n");
    char animate_str[max+1];
    memset(animate_str, '\0', sizeof(animate_str));

    while(true){
        if(timeout <= 0 && i == 0){
            printf("\n");
            break;
        }
        if(i == max){
            going_forward ^= true;
        }
        if(i == -1){
            going_forward ^= true;
            i++;
        }


        if (going_forward){
            animate_str[i] = '-';
            i++;
            printf("%s\n", animate_str);
            Sleep(15);
        }
        else{
            animate_str[i] = '\0';
            i--;
            printf("%s\n", animate_str);
            Sleep(15);
        }

        timeout--;
    }
}
