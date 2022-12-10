#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFF_SIZE 5000
#define WINDOW_LENGTH 4

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    int output;

    char line[BUFF_SIZE];
    fgets(line, BUFF_SIZE, input);
    fclose(input);
    
    bool foundMsg;

    for (int marker = WINDOW_LENGTH-1; marker < strlen(line);)
    {
        foundMsg = true;

        //compare each char in window
        for (int i = marker-WINDOW_LENGTH+1; i < marker; i++)
        {   
            for (int j = i+1; j <= marker; j++)
            {
                if (line[i] == line[j])
                {
                    foundMsg = false;
                    break;
                }
            }
            if (!foundMsg)
            {
                marker = i + WINDOW_LENGTH;
                break;
            }
        }

        if (foundMsg)
        {
            output = marker+1;
            break;
        }
    }
    
    printf("%d\n", output);

    return EXIT_SUCCESS;
}