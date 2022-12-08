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

    char line1[BUFF_SIZE];
    char line2[BUFF_SIZE];
    char line3[BUFF_SIZE];

    while (fgets(line1, BUFF_SIZE, input) != NULL)
    {
        fgets(line2, BUFF_SIZE, input);
        fgets(line3, BUFF_SIZE, input);

        int len = strlen(line1);

        for (size_t i = 0; i < len; i++)
        {
            if (strchr(line2, line1[i]) != NULL && strchr(line3, line1[i]) != NULL)
            {
                // this character is in both of the other strings
                if (line1[i] > 'Z')
                { 
                    output += (line1[i] - offsetLowercase);
                }
                else
                {
                    output += (line1[i] - offsetUppercase);
                }

                break;
            }
        }
    }
    
    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}