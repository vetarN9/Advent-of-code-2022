#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFF_SIZE 256
#define OFFSET_0 '0'

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    char line[BUFF_SIZE];

    // Set input width
    fgets(line, BUFF_SIZE, input);
    int n = strlen(line)-1;

    // Set input height
    int m = 1;
    while (fgets(line, BUFF_SIZE, input))
    {
        m++;
    }
    rewind(input);

    int trees[m][n];

    // Initialize 2d-array of trees from input file
    int row = 0;
    while (fgets(line, BUFF_SIZE, input))
    {
        for (int col = 0; col < n; col++)
        {
            trees[row][col] = line[col] - OFFSET_0;
        }

        row++;
    }
    fclose(input);

    int output = 0;

    // loop through each tree
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = 0;
            int down = 0;
            int left = 0;
            int right = 0;

            // look up
            for (int k = i; k > 0; k--)
            {
                up++;

                if (trees[k-1][j] >= trees[i][j])
                {
                    break;
                }
            }
            
            // look down
            for (int k = i; k < m-1; k++)
            {
                down++;

                if (trees[k+1][j] >= trees[i][j])
                {
                    break;
                }
            }

            // look left
            for (int k = j; k > 0; k--)
            {
                left++;

                if (trees[i][k-1] >= trees[i][j])
                {
                    break;
                }
            }

            // look right
            for (int k = j; k < n-1; k++)
            {
                right++;

                if (trees[i][k+1] >= trees[i][j])
                {
                    break;
                }
            }

            int scenic = up*down*left*right;
            if (scenic > output)
            {
                output = scenic;
            }
        }
    }
    
    printf("%d\n", output);

    return EXIT_SUCCESS;
}