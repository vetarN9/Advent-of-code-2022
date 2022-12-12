#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFF_SIZE 256
#define ROWS 6
#define COLS 40
#define NOOP 'n'
#define ADDX 'a'

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    printf("%d\n", 0 % 40);

    int cycle = 0;
    int regX = 1;
    int row = 0;
    char output[ROWS][COLS+1];
    memset(output, '.', ROWS*(COLS+1)*sizeof(char));
    for (int i = 0; i < ROWS; i++)
    {
        output[i][COLS] = '\0';
    }
    
    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, input))
    {
        int pos = cycle % COLS;
        if (pos == 0 && cycle != 0)
        {
            row++;
        }

        if (pos == regX || pos == regX-1 || pos == regX+1)
        {
            output[row][pos] = '#';
        }

        switch (line[0])
        {
            case NOOP: 
                cycle++; 
                break;

            case ADDX: 
                cycle++;
                pos = cycle % COLS;
                if (pos == 0 && cycle != 0)
                {
                    row++;
                }

                if (pos == regX || pos == regX-1 || pos == regX+1)
                {
                    output[row][pos] = '#';
                }
                cycle++;
                char *num = line+4;
                regX += strtol(num, NULL, 10);
                break;
        }
    }
    fclose(input);

    for (int i = 0; i < ROWS; i++)
    {
        printf("%s\n", output[i]);
    }

    return EXIT_SUCCESS;
}