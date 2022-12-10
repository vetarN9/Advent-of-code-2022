#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    int output = 0;
    int current = 0;

    char line[BUFF_SIZE];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        if (line[0] != '\n')
        {
            current += strtol(line, NULL, 10);
        }
        else
        {
            if (current > output)
            {
                output = current;
            }

            current = 0;
        }
    }

    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}