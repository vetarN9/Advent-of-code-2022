#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    
    int output = 0;

    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, input) != NULL)
    {
        char *pos;
        while ((pos = strchr(line, '-')) != NULL)
        {
            line[pos-line] = ' ';
        }

        while ((pos = strchr(line, ',')) != NULL)
        {
            line[pos-line] = ' ';
        }

        int min1, max1, min2, max2;
        sscanf(line, "%d %d %d %d", &min1, &max1, &min2, &max2);

        if (((min1 >= min2 && min1 <= max2) || (max1 >= min2 && max1 <= max2)) || ((min2 >= min1 && min2 <= max1) || (max2 >= min1 && max2 <= max1)))
        {
            output++;
        }
    }
    
    printf("%d\n", output);

    fclose(input);
    return EXIT_SUCCESS;
}
