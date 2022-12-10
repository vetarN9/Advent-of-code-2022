#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    char line[BUFF_SIZE];
    fgets(line, BUFF_SIZE, input);

    int m = strlen(line)/4;
    int n = 0;
    while (line[1] != '1')
    {
        n++;
        fgets(line, BUFF_SIZE, input);
    }
    rewind(input);

    int stacks[m][m*n]; // Represents the stacks of creates
    memset(stacks, 0, m*m*n*sizeof(int));

    int stackHeight[m]; // Current height of eachs stack
    memset(stackHeight, 0, m*sizeof(int));
    
    int height = n-1;

    // Read in the starting state
    while (height >= 0)
    {
        fgets(line, BUFF_SIZE, input);

        for (int i = 0; i < m; i++)
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
    do
    {
        fgets(line, BUFF_SIZE, input);
    } while (line[0] == ' ');

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
    
    char output[m+1];
    int pos = -1;
    for (int stack = 0; stack < m; stack++)
    {
        if (stackHeight[stack] != -1)
        {
            pos++;
            output[pos] = stacks[stack][stackHeight[stack]];
        }
    }
    output[pos+1] = '\0';
    
    printf("%s\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}