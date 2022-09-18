#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(int argc, char** argv){
     // Ask contestant to pick a door
    printf("\n");
    printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(" ** Monty Hall Simulator **\n");
    printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");


    // Where is the grand prize?
    srand( time(NULL) );
    int prize = rand()%3; // 0 <= rand() <= 32767
    int notprize1 = (prize+1)%3;
    int notprize2 = (prize+2)%3;

    int guess;
    printf("Pick a door! 1, 2, or 3.\n");
    scanf("%d", &guess);

    if(guess == prize){
        printf("You Win!\n");
    }else if(guess == notprize1){
        printf("Door %d is the wrong door.\n", notprize2);
    }else{
        printf("Door %d is the wrong door.\n", notprize1);
    }

    printf("Pick a door! 1, 2, or 3.\n");
    scanf("%d", &guess);

    if(guess == prize){
        printf("You Win!\n");
    }else{
        printf("You Lose!\n");
    }

    return 0;
}