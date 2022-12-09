#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 256
#define WIDTH 9
#define HEIGHT 100

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    int stacks[WIDTH][HEIGHT] = { }; // Represents the stacks of creates
    int stackHeight[WIDTH] = { }; // Current height of eachs stack
    int height = 7; // Highest starting create

    char line[BUFF_SIZE];

    // Read in the starting state
    while (height >= 0)
    {
        fgets(line, BUFF_SIZE, input);

        char *pos;
        while ((pos = strchr(line, '[')) != NULL)
        {
            line[pos-line] = ' ';
        }

        while ((pos = strchr(line, ']')) != NULL)
        {
            line[pos-line] = ' ';
        }

        for (int i = 0; i < 9; i++)
        {
            int pos = 4*i + 1;
            if (line[pos] != ' ')
            {
                stacks[i][height] = line[pos];

                if (height > stackHeight[i])
                {
                    stackHeight[i] = height;
                }
            }
        }
        
        height--;
    }

    // Move to instructions
    fgets(line, BUFF_SIZE, input);
    fgets(line, BUFF_SIZE, input);

    char discard[BUFF_SIZE];
    int num;
    int from;
    int to;

    // Perform each instruction to the stacks
    while (fgets(line, BUFF_SIZE, input))
    {
        sscanf(line, "%s %d %s %d %s %d", discard, &num, discard, &from, discard, &to);
        from--;
        to--;

        for (int i = 0; i < num; i++)
        {
            int move = stacks[from][stackHeight[from]];
            stacks[from][stackHeight[from]] = 0;
            stackHeight[from]--;

            stackHeight[to]++;
            stacks[to][stackHeight[to]] = move;
        }
    }
    
    char output[WIDTH+1];
    for (int stack = 0; stack < WIDTH; stack++)
    {
        output[stack] = stacks[stack][stackHeight[stack]];
    }
    
    printf("%s\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}