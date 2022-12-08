#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    
    int output = 0;

    int offsetLowercase = 'a' - 1;
    int offsetUppercase = 'A' - 27;

    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, input) != NULL)
    {
        int compartmentSize = strlen(line) / 2;
        char compartment2[compartmentSize];
        strcpy(compartment2, line + compartmentSize);

        for (size_t i = 0; i < compartmentSize; i++)
        {
            if (strchr(compartment2, line[i]) != NULL)
            {
                // this character is also in the second compartment
                if (line[i] > 'Z')
                { 
                    output += (line[i] - offsetLowercase);
                }
                else
                {
                    output += (line[i] - offsetUppercase);
                }
                
                break;
            }
        }
    }
    
    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}