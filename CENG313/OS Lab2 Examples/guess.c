#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int tries = 0;
    char compAns, userGuess;

    srand(time(NULL)); //randomize the number generator

    compAns = (rand() % 26) + 65; //generate a random letter (using ASCII code)

    printf("I am thinking of a letter..");

    do
    {   
        printf("What is your guess? ");
        scanf(" %c", &userGuess);
        tries++;

        if (userGuess > compAns)
        {
            printf("Your guess was too high \n");
            printf("\n Try again!");
        }
        if (userGuess < compAns)
        {
            printf("Your guess was too low \n");
            printf("\n Try again!");
        }

    } while (userGuess != compAns); //quit when match is found

    printf("Congratulations, you got it right!");
    printf("It took you only %d tries to guess", tries);

    return 0;
}
