#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

// max size for input
#define MAX_INPUT 32

void diagonal_wave();
void stickman_jump();

int main(int argc, char *argv[]){
    char input[MAX_INPUT];
    int val;

    printf("Hi there! ");

    while(true){
        printf("What animation do you want to see? (Type in a number)\n\n"
               "1 - Diagonal Wave\n"
               "2 - Stickman Jumping\n"
               "\n"
               );

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

            case 2:
                stickman_jump();
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

void stickman_jump(){
    int j;
    int head_line = 3, arms_line = 4, body_line = 5, legs_line = 6;
    // keep track of leftmost part of stickmans position
    int pos = 2;
    int h_off_ground = 0;

    // box starts an index 22
    char animate_str[7][53] = {
        "                                                   \n",
        "                                                   \n",
        "                                                   \n",
        "   O                                               \n",
        "  /|\\                                              \n",
        "   |                  |====|                       \n",
        "__/_\\_________________|____|_______________________\n"
    };

    while(pos<45){
        // moving forward
        if(pos < 17 || (pos >= 20 && pos < 27) || pos >= 30 ){
            animate_str[head_line][pos+1] = ' ';
            animate_str[head_line][pos+2] = 'O';
            animate_str[arms_line][pos] = ' ';
            animate_str[arms_line][pos+1] = '/';
            animate_str[arms_line][pos+2] = '|';
            animate_str[arms_line][pos+3] = '\\';
            animate_str[body_line][pos+1] = ' ';
            animate_str[body_line][pos+2] = '|';
            if(h_off_ground == 0){
                animate_str[legs_line][pos] = '_';
                animate_str[legs_line][pos+2] = '_';
            }
            else{
                animate_str[legs_line][pos] = ' ';
                animate_str[legs_line][pos+2] = ' ';
            }
            animate_str[legs_line][pos+1] = '/';
            animate_str[legs_line][pos+3] = '\\';
        }
        // jumping
        else if(pos >= 17 && pos < 20){
            animate_str[head_line][pos+1] = ' ';
            head_line--;
            animate_str[head_line][pos+2] = 'O';

            animate_str[arms_line][pos] = ' ';
            animate_str[arms_line][pos+1] = ' ';
            animate_str[arms_line][pos+2] = ' ';
            arms_line--;
            animate_str[arms_line][pos+1] = '/';
            animate_str[arms_line][pos+2] = '|';
            animate_str[arms_line][pos+3] = '\\';

            animate_str[body_line][pos+1] = ' ';
            body_line--;
            animate_str[body_line][pos+2] = '|';

            if(h_off_ground == 0){
                animate_str[legs_line][pos] = '_';
                animate_str[legs_line][pos+1] = '_';
                animate_str[legs_line][pos+2] = '_';
            }
            else{
                animate_str[legs_line][pos] = ' ';
                animate_str[legs_line][pos+1] = ' ';
                animate_str[legs_line][pos+2] = ' ';
            }
            legs_line--;
            animate_str[legs_line][pos+1] = '/';
            animate_str[legs_line][pos+2] = ' ';
            animate_str[legs_line][pos+3] = '\\';

            h_off_ground++;
        }
        // falling down
        else if(26 <= pos < 30){
            animate_str[legs_line][pos] = ' ';
            animate_str[legs_line][pos+1] = ' ';
            animate_str[legs_line][pos+2] = ' ';
            legs_line++;
            animate_str[legs_line][pos+1] = '/';
            animate_str[legs_line][pos+2] = ' ';
            animate_str[legs_line][pos+3] = '\\';

            animate_str[body_line][pos+1] = ' ';
            body_line++;
            animate_str[body_line][pos+2] = '|';

            animate_str[arms_line][pos] = ' ';
            animate_str[arms_line][pos+1] = ' ';
            animate_str[arms_line][pos+2] = ' ';
            arms_line++;
            animate_str[arms_line][pos+1] = '/';
            animate_str[arms_line][pos+2] = '|';
            animate_str[arms_line][pos+3] = '\\';

            animate_str[head_line][pos+1] = ' ';
            head_line++;
            animate_str[head_line][pos+2] = 'O';

            h_off_ground--;
        }

        pos++;

        printf("\n");
        for(j=0;j<7;j++){
            printf("%s", animate_str[j]);
        }
        if(pos < 45){
            printf("\n\n\n\n\n\n\n\n\n");
        }
        Sleep(100);
    }

    printf("\n\n");

}
