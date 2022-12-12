#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFF_SIZE 256
#define NOOP 'n'
#define ADDX 'a'

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    int output = 0;
    int cycle = 0;
    int regX = 1;

    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, input))
    {
        switch (line[0])
        {
            case NOOP: 
                cycle++; 
                if (((cycle - 20) % 40) == 0)
                {
                    output += cycle * regX;
                }
                break;

            case ADDX: 
                cycle++; 
                if (((cycle - 20) % 40) == 0)
                {
                    output += cycle * regX;
                }
                cycle++;
                if (((cycle - 20) % 40) == 0)
                {
                    output += cycle * regX;
                }
                char *num = line+4;
                regX += strtol(num, NULL, 10);
                break;
        }
    }
    fclose(input);

    printf("%d\n", output);

    return EXIT_SUCCESS;
}