#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 256

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

#define LOSE 1
#define DRAW 2
#define WIN 3

int lose(int opp)
{
    switch (opp)
    {
        case ROCK:     return SCISSORS;
        case PAPER:    return ROCK;
        case SCISSORS: return PAPER;
    }
}

int win(int opp)
{
    switch (opp)
    {
        case ROCK:     return PAPER;
        case PAPER:    return SCISSORS;
        case SCISSORS: return ROCK;
    }
}
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
        int outcome = line[2] - offsetX;

        switch (outcome)
        {
            case LOSE:
                output += lose(opp);
                break;
            
            case DRAW: 
                output += (3 + opp);
                break;

            case WIN:
                output += (6 + win(opp));
                break;
        }
    }
    
    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}