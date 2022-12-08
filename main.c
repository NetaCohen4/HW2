/*
Made by Neta Cohen
8/12/2022
*/
#include <stdio.h>
#include "my_mat.h"

#ifndef Matrix_Size
#define Matrix_Size 10
#endif

int main() 
{
    int mat[Matrix_Size][Matrix_Size];
    char action;
    scanf("%c", &action);
    while (action != 'D') 
    {
        if (action == 'A') // Gets in the matrix values
        {
            initMatrix(mat);
        } 
        else if (action == 'B') // Checks wether there is a path between i and j
        {
            int i, j;
            scanf("%d", &i);
            scanf("%d", &j);
            if (isPathAvailable(mat, i, j))
                printf("True");
            else 
                printf("False");
            printf("\n");
        } 
        else if (action == 'C') // Find the shortest way between i and j
        {
            int i, j;
            scanf("%d", &i);
            scanf("%d", &j);
            int shortest = findShortest(mat, i, j);
            printf("%d", shortest);
            printf("\n");
        }
        scanf("%c", &action);
    }
    return 0;
}