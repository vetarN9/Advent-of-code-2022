#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

int getOneElfsCalories(FILE *input, bool *keepReading)
{
    char line[100];
    int calories = 0;
    
    do
    {
        if (fgets(line, sizeof(line), input) == NULL)
        {
            *keepReading = false;
            return calories;
        }

        calories += atoi(line);
        
    } while (line[0] != '\n');

    return calories;
}

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        perror("Error");
        return EXIT_FAILURE;
    }
    
    int maxCalories = 0;

    bool keepReading = true;
    while (keepReading)
    {
        int calories = getOneElfsCalories(input, &keepReading);
        if (calories > maxCalories)
        {
            maxCalories = calories;
        }
    }
    
    printf("%d\n", maxCalories);
    return EXIT_SUCCESS;
}