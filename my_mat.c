#include <stdio.h>
#include "my_mat.h"

#ifndef Matrix_Size
#define Matrix_Size 10
#endif

void initMatrix(int** matrix) 
{
    int temp;
    for (int i = 0; i < Matrix_Size; i++) 
    {
        for (int j = 0; j < Matrix_Size; j++) 
        {
            scanf("%d", &temp);
            matrix[i][j] = temp;
        }
    }
}

// Recursive function
int isPathAvailable(int** matrix, int i, int j) 
{
    // Stopping condition for the recursion: If a path exists.
    if (matrix[i][j] != -1)
        return 1;
    // Going over the nodes to look for a node that can connect i and j.
    for (int h = 0; h < Matrix_Size; h++)
    {
        // If there is a path between i and h, then we will check if there is a path between h and j
        if (mat[i][h] != -1)
        {
            // Recursive call
            if (isPathAvailable(matrix, h, j) != 0)
                return 1;
        }
    }
    return 0;
}

// Updates all the nodes for their shortest way of getting to the other nodes.
int findShortest(int** matrix, int i, int j) 
{
    // For each path a to c, checks whether there is a shorter path that passes through b.
    for (int b = 0; b < Matrix_Size; b++) 
    {
        for (int a = 0; a < Matrix_Size; a++) 
        {
            for (int c = 0; c < Matrix_Size; c++) 
            {
                if (a != c) 
                {
                    // Choose the shorter path.
                    if ((matrix[a][b] > 0) && (matrix[b][c] > 0)) 
                    {
                        if (matrix[a][c] == -1) 
                            matrix[a][c] = matrix[a][b] + matrix[b][c];
                        else if (matrix[a][c] > (matrix[a][b] + matrix[b][c]))
                            matrix[a][c] = matrix[a][b] + matrix[b][c];
                    }
                }
            }
        }
    }

    return matrix[i][j];
}