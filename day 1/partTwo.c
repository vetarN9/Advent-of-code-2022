#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct topThree
{
    int one;
    int two;
    int Three;
}topThree_t;


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

topThree_t initTopThree(FILE *input)
{
    topThree_t topThree;

    topThree.one = getOneElfsCalories(input, NULL);

    int calories = getOneElfsCalories(input, NULL);
    if (calories > topThree.one)
    {
        topThree.two = topThree.one;
        topThree.one = calories;
    }
    else
    {
        topThree.two = calories;
    }

    calories = getOneElfsCalories(input, NULL);
    if (calories > topThree.one)
    {
        topThree.Three = topThree.two;
        topThree.two = topThree.one;
        topThree.one = calories;
    }
    else if (calories > topThree.two)
    {
        topThree.Three = topThree.two;
        topThree.two = calories;
    }
    else
    {
        topThree.Three = calories;
    }
    
    return topThree;
}

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        perror("Error");
        return EXIT_FAILURE;
    }
    

    topThree_t topThree = initTopThree(input);

    bool keepReading = true;
    while (keepReading)
    {
        int calories = getOneElfsCalories(input, &keepReading);
        if (calories > topThree.one)
        {
            topThree.Three = topThree.two;
            topThree.two = topThree.one;
            topThree.one = calories; 
        }
        else if (calories > topThree.two)
        {
            topThree.Three = topThree.two;
            topThree.two = calories;
        }
        else if (calories > topThree.Three)
        {
            topThree.Three = calories;
        }
    }
    
    int output = topThree.one + topThree.two + topThree.Three;
    printf("%d\n", output);
    return EXIT_SUCCESS;
}