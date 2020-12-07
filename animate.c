#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

// max size for input
#define MAX_INPUT 32

void diagonal_wave();
void stickman_jump();
void stickman_falling();

int main(int argc, char *argv[]){
    char input[MAX_INPUT];
    int val;

//    while(true){
//        stickman_falling();
//        Sleep(2000);
//    }

    printf("Hi there! ");

    while(true){
        printf("What animation do you want to see? (Type in a number)\n\n"
               "1 - Diagonal Wave\n"
               "2 - Stickman Jumping\n"
               "3 - Stickman Falling\n"
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

            case 3:
                stickman_falling();
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
    int i;
    int head_line = 3, arms_line = 4, body_line = 5, legs_line = 6;
    // keep track of leftmost part of stickmans position
    int x_pos = 2;
    int y_pos = 0;

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

    while(x_pos<45){
        // moving forward
        if(x_pos < 17 || (x_pos >= 20 && x_pos < 27) || x_pos >= 30 ){
            animate_str[head_line][x_pos+1] = ' ';
            animate_str[head_line][x_pos+2] = 'O';
            animate_str[arms_line][x_pos] = ' ';
            animate_str[arms_line][x_pos+1] = '/';
            animate_str[arms_line][x_pos+2] = '|';
            animate_str[arms_line][x_pos+3] = '\\';
            animate_str[body_line][x_pos+1] = ' ';
            animate_str[body_line][x_pos+2] = '|';
            if(y_pos == 0){
                animate_str[legs_line][x_pos] = '_';
                animate_str[legs_line][x_pos+2] = '_';
            }
            else{
                animate_str[legs_line][x_pos] = ' ';
                animate_str[legs_line][x_pos+2] = ' ';
            }
            animate_str[legs_line][x_pos+1] = '/';
            animate_str[legs_line][x_pos+3] = '\\';
        }
        // jumping
        else if(x_pos >= 17 && x_pos < 20){
            animate_str[head_line][x_pos+1] = ' ';
            head_line--;
            animate_str[head_line][x_pos+2] = 'O';

            animate_str[arms_line][x_pos] = ' ';
            animate_str[arms_line][x_pos+1] = ' ';
            animate_str[arms_line][x_pos+2] = ' ';
            arms_line--;
            animate_str[arms_line][x_pos+1] = '/';
            animate_str[arms_line][x_pos+2] = '|';
            animate_str[arms_line][x_pos+3] = '\\';

            animate_str[body_line][x_pos+1] = ' ';
            body_line--;
            animate_str[body_line][x_pos+2] = '|';

            if(y_pos == 0){
                animate_str[legs_line][x_pos] = '_';
                animate_str[legs_line][x_pos+1] = '_';
                animate_str[legs_line][x_pos+2] = '_';
            }
            else{
                animate_str[legs_line][x_pos] = ' ';
                animate_str[legs_line][x_pos+1] = ' ';
                animate_str[legs_line][x_pos+2] = ' ';
            }
            legs_line--;
            animate_str[legs_line][x_pos+1] = '/';
            animate_str[legs_line][x_pos+2] = ' ';
            animate_str[legs_line][x_pos+3] = '\\';

            y_pos++;
        }
        // falling down
        else if(26 <= x_pos && x_pos < 30){
            animate_str[legs_line][x_pos] = ' ';
            animate_str[legs_line][x_pos+1] = ' ';
            animate_str[legs_line][x_pos+2] = ' ';
            legs_line++;
            animate_str[legs_line][x_pos+1] = '/';
            animate_str[legs_line][x_pos+2] = ' ';
            animate_str[legs_line][x_pos+3] = '\\';

            animate_str[body_line][x_pos+1] = ' ';
            body_line++;
            animate_str[body_line][x_pos+2] = '|';

            animate_str[arms_line][x_pos] = ' ';
            animate_str[arms_line][x_pos+1] = ' ';
            animate_str[arms_line][x_pos+2] = ' ';
            arms_line++;
            animate_str[arms_line][x_pos+1] = '/';
            animate_str[arms_line][x_pos+2] = '|';
            animate_str[arms_line][x_pos+3] = '\\';

            animate_str[head_line][x_pos+1] = ' ';
            head_line++;
            animate_str[head_line][x_pos+2] = 'O';

            y_pos--;
        }

        x_pos++;

        printf("\n");
        for(i=0;i<7;i++){
            printf("%s", animate_str[i]);
        }
        if(x_pos < 45){
            printf("\n\n\n\n\n\n\n\n\n");
        }
        Sleep(100);
    }

    printf("\n\n");

}

void stickman_falling(){
    int i;
    int head_line = 2, arms_line = 3, body_line = 4, legs_line = 5;
    // keep track of leftmost part of stickmans position
    int x_pos = 2;
    int y_pos = 0;
    bool falling = false;

    // cliff starts at x_pos 19
    char animate_str[18][37] = {
        "                                   \n",
        "                                   \n",
        "   O                               \n",
        "  /|\\                              \n",
        "   |                               \n",
        "__/_\\_____________                 \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "                  |                \n",
        "__________________|                \n",
    };

    while(y_pos > -16){
        // moving forward
        if(x_pos < 20){
            animate_str[head_line][x_pos+1] = ' ';
            animate_str[head_line][x_pos+2] = 'O';
            animate_str[arms_line][x_pos] = ' ';
            animate_str[arms_line][x_pos+1] = '/';
            animate_str[arms_line][x_pos+2] = '|';
            animate_str[arms_line][x_pos+3] = '\\';
            animate_str[body_line][x_pos+1] = ' ';
            animate_str[body_line][x_pos+2] = '|';
            if(x_pos < 17){
                animate_str[legs_line][x_pos] = '_';
                animate_str[legs_line][x_pos+2] = '_';
            }
            else if(x_pos >= 17 && x_pos < 18){
                animate_str[legs_line][x_pos] = '_';
                animate_str[legs_line][x_pos+2] = ' ';
            }
            else{
                animate_str[legs_line][x_pos] = ' ';
                animate_str[legs_line][x_pos+2] = ' ';

            }
            animate_str[legs_line][x_pos+1] = '/';
            animate_str[legs_line][x_pos+3] = '\\';

            x_pos++;
        } //end if
        // falling
        else if(x_pos == 20){
            // stickman raises exclamation point
            if(!falling){
                animate_str[head_line-1][x_pos+1] = '.';
                animate_str[head_line-2][x_pos+1] = '|';
                falling = true;

                printf("\n");
                for(i=0;i<18;i++){
                    printf("%s", animate_str[i]);
                }
                Sleep(1000);

                animate_str[head_line-1][x_pos+1] = ' ';
                animate_str[head_line-2][x_pos+1] = ' ';
            }
            else{
                if(legs_line < 17){
                    animate_str[legs_line][x_pos] = ' ';
                    animate_str[legs_line][x_pos+1] = ' ';
                    animate_str[legs_line][x_pos+2] = ' ';
                    legs_line++;
                    animate_str[legs_line][x_pos] = '/';
                    animate_str[legs_line][x_pos+1] = ' ';
                    animate_str[legs_line][x_pos+2] = '\\';
                }
                // remove legs
                else{
                    animate_str[legs_line][x_pos] = ' ';
                    animate_str[legs_line][x_pos+1] = ' ';
                    animate_str[legs_line][x_pos+2] = ' ';
                }

                if(body_line < 17){
                    animate_str[body_line][x_pos] = ' ';
                    body_line++;
                    animate_str[body_line][x_pos+1] = '|';
                }
                // remove body
                else{
                    animate_str[body_line][x_pos] = ' ';
                }

                if(arms_line < 17){
                    animate_str[arms_line][x_pos] = ' ';
                    arms_line++;
                    animate_str[arms_line][x_pos+1] = '|';
                }
                // remove arms
                else{
                    animate_str[arms_line][x_pos] = ' ';
                }

                if(head_line < 17){
                    animate_str[head_line][x_pos] = ' ';
                    animate_str[head_line][x_pos+1] = ' ';
                    animate_str[head_line][x_pos+2] = ' ';
                    head_line++;
                    animate_str[head_line][x_pos] = '\\';
                    animate_str[head_line][x_pos+1] = 'O';
                    animate_str[head_line][x_pos+2] = '/';
                }
                // remove head
                else{
                    animate_str[head_line][x_pos] = ' ';
                    animate_str[head_line][x_pos+1] = ' ';
                    animate_str[head_line][x_pos+2] = ' ';
                }

                y_pos--;
            }// end else

        }//end else if


        printf("\n");
        for(i=0;i<18;i++){
            printf("%s", animate_str[i]);
        }

        Sleep(100);
    }//end while

    printf("\n\n");


}
