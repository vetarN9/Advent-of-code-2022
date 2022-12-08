#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 256

/* 
rock = 1
paper = 2
scissors = 3

rock - scissor = -2 win
scissor - paper = 1 win
paper - rock = 1 win

rock - paper = -1 loss
scissor - rock = 2 loss
paper - scissor = -1 loss */

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    
    int output = 0;

    int offsetA = 'A' - 1;
    int offsetX = 'X' - 1;

    char line[BUFF_SIZE];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        int opp = line[0] - offsetA;
        int you = line[2] - offsetX;

        output += you;

        int outcome = you - opp;
        if (outcome == 1 || outcome == -2)
        {
            output += 6;
        }
        else if (outcome == 0)
        {
            output += 3;
        }
    }
    
    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}