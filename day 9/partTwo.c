#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFF_SIZE 256
#define NUM_KNOTS 10
#define TAIL (NUM_KNOTS-1)
#define HEAD 0
#define U 'U'
#define D 'D'
#define L 'L'
#define R 'R'

typedef struct pos
{
    int x;
    int y;
} pos_t;

int sign(int x)
{
    if(x > 0) return 1;
    if(x < 0)  return -1;
    return 0;
}

void moveKnot(pos_t *tail, const pos_t head)
{
    pos_t dist;
    dist.x = head.x - tail->x;
    dist.y = head.y - tail->y;

    if ((abs(dist.x) == 2 && abs(dist.y) == 1) || (abs(dist.y) == 2 && abs(dist.x) == 1))
    {
        tail->x += sign(dist.x);
        tail->y += sign(dist.y);
    }
    else if (abs(dist.x) == 2 || abs(dist.y) == 2)
    {
        tail->x += dist.x/2;
        tail->y += dist.y/2;
    }
}

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");

    pos_t curr = {};
    pos_t max = {};
    pos_t min = {};

    char line[BUFF_SIZE];

    // First pass
    while (fgets(line, BUFF_SIZE, input))
    {
        char *num = line+1;
        int moves = strtol(num, NULL, 10);

        switch (line[0])
        {
            case U:
                curr.y -= moves;
                if (curr.y < min.y) min.y = curr.y;
                break;

            case D:
                curr.y += moves;
                if (curr.y > max.y) max.y = curr.y;
                break;

            case L:
                curr.x -= moves;
                if (curr.x < min.x) min.x = curr.x;
                break;

            case R:
                curr.x += moves;
                if (curr.x > max.x) max.x = curr.x;
                break;
        }
    }
    rewind(input);

    int height = max.y - min.y + 1;
    int width  = max.x - min.x + 1;

    bool visited[height][width];
    memset(visited, 0, height*width*sizeof(bool));

    pos_t start;
    start.x = -1*min.x;
    start.y = -1*min.y;

    pos_t knots[NUM_KNOTS];
    for (int knot = 0; knot < NUM_KNOTS; knot++)
    {
        knots[knot] = start;
    }

    visited[knots[TAIL].y][knots[TAIL].x] = true;
    int output = 1;

    while (fgets(line, BUFF_SIZE, input))
    {
        char *num = line+1;
        int moves = strtol(num, NULL, 10);

        for (int i = 0; i < moves; i++)
        {
            switch (line[0])
            {
                case U: knots[HEAD].y--; break;
                case D: knots[HEAD].y++; break;
                case L: knots[HEAD].x--; break;
                case R: knots[HEAD].x++; break;
            }

            for (int knot = 0; knot < TAIL; knot++)
            {
                moveKnot(&knots[knot+1], knots[knot]);
            }
            
            if (!visited[knots[TAIL].y][knots[TAIL].x])
            {
                visited[knots[TAIL].y][knots[TAIL].x] = true;
                output++;
            } 
        }
    }
    fclose(input);

    printf("%d\n", output);

    return EXIT_SUCCESS;
}