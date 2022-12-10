#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFF_SIZE 256
#define OFFSET_0 '0'

typedef struct tree
{
    int height;
    bool seen;
} tree_t;

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

    tree_t trees[m][n];

    // Initialize 2d-array of trees from input file
    int row = 0;
    while (fgets(line, BUFF_SIZE, input))
    {
        for (int col = 0; col < n; col++)
        {
            tree_t tree;
            tree.seen = false;
            tree.height = line[col] - OFFSET_0;
            trees[row][col] = tree;
        }

        row++;
    }
    fclose(input);

    int output = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Edge case
            if (i == 0 || i == m-1 || j == 0 || j == n-1)
            {
                trees[i][j].seen = true;
                output++;
            }
            else
            {
                trees[i][j].seen = true;

                // look up
                for (int k = i; k > 0; k--)
                {
                    if (trees[k-1][j].height >= trees[i][j].height)
                    {
                        trees[i][j].seen = false;
                        break;
                    }
                }

                if (trees[i][j].seen)
                {
                    output++;
                    continue;
                }

                trees[i][j].seen = true;
                
                // look down
                for (int k = i; k < m-1; k++)
                {
                    if (trees[k+1][j].height >= trees[i][j].height)
                    {
                        trees[i][j].seen = false;
                        break;
                    }
                }

                if (trees[i][j].seen)
                {
                    output++;
                    continue;
                }

                trees[i][j].seen = true;

                // look left
                for (int k = j; k > 0; k--)
                {
                    if (trees[i][k-1].height >= trees[i][j].height)
                    {
                        trees[i][j].seen = false;
                        break;
                    }
                }

                if (trees[i][j].seen)
                {
                    output++;
                    continue;
                }

                trees[i][j].seen = true;

                // look right
                for (int k = j; k < n-1; k++)
                {
                    if (trees[i][k+1].height >= trees[i][j].height)
                    {
                        trees[i][j].seen = false;
                        break;
                    }
                }

                if (trees[i][j].seen)
                {
                    output++;
                    continue;
                }
            }
        }
    }
    
    printf("%d\n", output);

    return EXIT_SUCCESS;
}