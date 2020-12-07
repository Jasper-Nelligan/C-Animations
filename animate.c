/*
 * A program I made for fun and to practice C.
 * Use this in the command line to see some printed
 * animations!
 *
 * (C) Jasper Nelligan 2020
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_INPUT 32

void diagonal_wave();
void stickman_jump();
void stickman_falling();
void trumpet_playing();

int main(){
    char input[MAX_INPUT];
    int val;

    printf("Hi there! ");

    while(true){
        printf("What animation do you want to see? (Type in a number)\n\n"
               "1 - Diagonal Wave\n"
               "2 - Stickman Jumping\n"
               "3 - Stickman Falling\n"
               "4 - Trumpet Playing\n"
               "\n"
               "5 - Exit Program\n"
               "\n"
               );

        fgets(input, MAX_INPUT, stdin);
        printf("\n");
        val = atoi(input);
        if (val == 0){
            // remove newline before printing
            strtok(input, "\n");
            printf("'%s' is not a valid entry.\n\n", input);
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

            case 4:
                trumpet_playing();
                break;

            case 5:
                exit(0);

            default:
                printf("'%d' is not a valid entry.\n\n", val);
        }
    }
}

void diagonal_wave(){
    int i = 0, timeout = 450;
    int max;
    bool going_forward = true;
    char input[MAX_INPUT];

    printf("What should the max line length be? "
           "(Type in a number greater than 0)\n\n");
    while(true){
        fgets(input, MAX_INPUT, stdin);
        printf("\n");
        max = atoi(input);
        // atoi returns 0 of error, and so user will not be able to
        // put in 0 as a valid answer
        if (max == 0){
            // remove newline before printing
            strtok(input, "\n");
            printf("'%s' is not a valid entry. (Type in a number greater than 0)\n\n", input);
            continue;
        }
        else{
            break;
        }
    }


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
        else{
            printf("\n\n");
        }
        Sleep(100);
    }
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
        "__________________|                \n"
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

void trumpet_playing(){
    int i, j;

    // trumpet ends at 66
    char animate_str[10][100] = {
        "                                                               /|              \n",
        "                    XYX XYX XYX  ,-.                         .' |              \n",
        ",-.__________________H___H___H__(___)_____________________,-'   |              \n",
        "| ||__________________________________________ ___ `._____      |              \n",
        "`-'   / /           | | | | | |               |   `. \\    `-.   |              \n",
        "     | |            | | _ | | |   ,-.         |    | |       `. |              \n",
        "     | |    ________| ,'_)| | |__(___)________|_   | |         \\|              \n",
        "     ' \\  .' ________).`-.|-| |_______________|_\\_.' / |                       \n",
        "      \\ `-`._________)|`-'|-| |____________________.'@/                        \n",
        "       `------------|_| |_| |_|-----------------'J `-'                         \n"
    };

    printf("\n");
    for(i=0;i<10;i++){
        printf("%s", animate_str[i]);
    }
    printf("\n\n\n\n\n\n\n\n\n");
    Sleep(1000);

    for(i=0;i<6;i++){
        if(i == 0 || i == 3){
            // push down left button
            animate_str[1][20] = ' ';
            animate_str[1][21] = ' ';
            animate_str[1][22] = ' ';

            // first half of sixteenth note
            animate_str[2][70] = '|';
            animate_str[3][70] = '|';
            animate_str[4][68] = '(';
            animate_str[4][69] = ')';

            printf("\n");
            for(j=0;j<10;j++){
                printf("%s", animate_str[j]);
            }
            printf("\n\n\n\n\n\n\n\n\n");

            Sleep(200);

            // second
            animate_str[1][71] = '_';
            animate_str[1][72] = '_';
            animate_str[2][71] = '-';
            animate_str[2][72] = '-';
            animate_str[2][73] = '|';
            animate_str[3][73] = '|';
            animate_str[4][72] = '(';
            animate_str[4][73] = ')';
        }
        // animate single note
        else if(i == 1 || i == 4){
            // push down middle button
            animate_str[1][24] = ' ';
            animate_str[1][25] = ' ';
            animate_str[1][26] = ' ';

            animate_str[2][70] = '|';
            animate_str[2][71] = '~';
            animate_str[2][72] = '\'';
            animate_str[3][70] = '|';
            animate_str[4][68] = '(';
            animate_str[4][69] = ')';
        }
        // eighth note
        else if(i == 2 || i == 5){
            // push down left button
            animate_str[1][20] = ' ';
            animate_str[1][21] = ' ';
            animate_str[1][22] = ' ';

            // first half
            animate_str[1][70] = '|';
            animate_str[2][70] = '|';
            animate_str[3][68] = '(';
            animate_str[3][69] = ')';


            printf("\n");
            for(j=0;j<10;j++){
                printf("%s", animate_str[j]);
            }
            printf("\n\n\n\n\n\n\n\n\n");
            Sleep(350);

            // release down left button
            animate_str[1][20] = 'X';
            animate_str[1][21] = 'Y';
            animate_str[1][22] = 'X';

            // push down right button
            animate_str[1][28] = ' ';
            animate_str[1][29] = ' ';
            animate_str[1][30] = ' ';

            // second
            animate_str[1][71] = '\\';
            animate_str[2][72] = '\\';
            animate_str[3][73] = '|';
            animate_str[4][73] = '|';
            animate_str[5][72] = '(';
            animate_str[5][73] = ')';
        }

        printf("\n");
        for(j=0;j<10;j++){
            printf("%s", animate_str[j]);
        }
        printf("\n\n\n\n\n\n\n\n\n");
        Sleep(1000);

        // release buttons
        j = 20;
        while(j<31){
            animate_str[1][j] = 'X';
            animate_str[1][j+1] = 'Y';
            animate_str[1][j+2] = 'X';
            j += 4;
        }

        // clear for next note
        animate_str[1][70] = ' ';
        animate_str[1][71] = ' ';
        animate_str[1][72] = ' ';
        animate_str[2][70] = ' ';
        animate_str[2][71] = ' ';
        animate_str[2][72] = ' ';
        animate_str[2][73] = ' ';
        animate_str[3][68] = ' ';
        animate_str[3][69] = ' ';
        animate_str[3][70] = ' ';
        animate_str[3][73] = ' ';
        animate_str[4][68] = ' ';
        animate_str[4][69] = ' ';
        animate_str[4][72] = ' ';
        animate_str[4][73] = ' ';
        animate_str[5][72] = ' ';
        animate_str[5][73] = ' ';

        printf("\n");
        for(j=0;j<10;j++){
            printf("%s", animate_str[j]);
        }
        if(i < 5){
            printf("\n\n\n\n\n\n\n\n\n");
        }
        else{
            printf("\n\n");
        }

        if(i == 1 || i == 4){
            Sleep(350);
        }
        else{
            Sleep(1000);
        };

    }// end for

    printf("\n\n");
}
