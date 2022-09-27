/*                                      DSA(THEORY) ASSIGNMENT 1              */
/*NAME = HEMANT*/
/*ROLL = 2105372*/
/*SECTION = CSE-12*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct points
{
    int x;
    int y;
};
struct points pointers_array[10]; // 10 x 10 banane wala array

int symettric_hai_y a_nahi(float **mat, int size) // square mat ko symettric check karne wala
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (mat[i][j] != mat[j][i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    // PART 1 ACCORDING TO SIR
    for (int i = 0; i < 10; i++)
    {
        pointers_array[i].x = rand() % 100; // random 10 elemenst dene wala array
        pointers_array[i].y = rand() % 100;
    }

    // PART 2 ACCORDING TO SIR
    printf("humare points hai  are  \n");
    for (int i = 0; i < 10; i++)
    {
        printf("(%d,%d)\n", pointers_array[i].x, pointers_array[i].y);
    }

    // PART 3 ACCORDING TO SIR

    float **distance_of_mat = (float **)malloc(10 * sizeof(float *)); // mat 10x10 dynamically
    for (int i = 0; i < 10; i++)
    {
        distance_of_mat[i] = (float *)malloc(10 * sizeof(float));
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) // calculate karega each point ka distance
        {
            float distance = sqrt(
                pow((pointers_array[j].x - pointers_array[i].x), 2) + /*(x2-x1)^2*/pow((pointers_array[j].y - pointers_array[i].y), 2));   //(y1-y2)^2
            distance_of_mat[i][j] = distance;
        }
    }
    // PART 4 ACCORDING TO SIR
    // Checking if distance matrix is symettric
    if (symettric_hai_ya_nahi(distance_of_mat, 10))
        printf("yes matrix is symmetric\n");
    else
    {
        printf("nope matrix is not symmetric");
        exit(0);
    }

    for (int i = 0; i < 10; i++) // loop for distance
    {
        for (int j = 0; j < 10; j++)
            printf("%.2f  ", distance_of_mat[i][j]);
        printf("\n");
    }

    struct points x1, x2;
    float minimum_distance = distance_of_mat[1][0];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (distance_of_mat[i][j] < minimum_distance) // check lower diagnoal for smallest number
            {
                minimum_distance = distance_of_mat[i][j];
                x1 = pointers_array[i];
                x2 = pointers_array[j];
            }
        }
    }

    printf("pair of points whi have minimum distance is %d, %d and %d,%d\n", x1.x, x1.y, x2.x, x2.y);
    printf("and the distance between is %.2f \n", minimum_distance);

    return 0;
}
