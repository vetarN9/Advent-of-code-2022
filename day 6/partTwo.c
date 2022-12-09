#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFF_SIZE 5000
#define WINDOW_LENGTH 14

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    int output;

    char line[BUFF_SIZE];
    fgets(line, BUFF_SIZE, input);
    fclose(input);

    char window[WINDOW_LENGTH];
    for (int i = 0; i < WINDOW_LENGTH; i++)
    {
        window[i] = line[i];
    }
    
    bool foundMsg;

    for (int pos = (WINDOW_LENGTH - 1); pos < strlen(line); pos++)
    {
        foundMsg = true;

        //compare each char in window
        for (int i = 0; i < WINDOW_LENGTH; i++)
        {   
            for (int j = 0; j < WINDOW_LENGTH; j++)
            {
                if (window[i] == window[j] && i != j)
                {
                    foundMsg = false;
                }
            } 
        }

        if (foundMsg)
        {
            output = pos+1;
            break;
        }
        
        // shift window
        for (int i = 0; i < (WINDOW_LENGTH - 1); i++)
        {
            window[i] = window[i+1];
        }
        window[WINDOW_LENGTH-1] = line[pos+1];
    }
    
    printf("%d\n", output);

    return EXIT_SUCCESS;
}