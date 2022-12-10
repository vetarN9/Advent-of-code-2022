#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        perror("Error");
        return EXIT_FAILURE;
    }

    int output;

    int current = 0;
    int highest = 0;
    int secondHighest = 0;
    int thirdHighest = 0;

    char line[BUFF_SIZE];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        if (line[0] != '\n')
        {
            current += strtol(line, NULL, 10);
        }
        else
        {
            if (current > highest)
            {
                thirdHighest = secondHighest;
                secondHighest = highest;
                highest = current; 
            }
            else if (current > secondHighest)
            {
                thirdHighest = secondHighest;
                secondHighest = current;
            }
            else if (current > thirdHighest)
            {
                thirdHighest = current;
            }

            current = 0;
        }
    }

    output = highest + secondHighest + thirdHighest;
    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}