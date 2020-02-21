#include <stdio.h> 
#include <stdlib.h>

int main()
{
    int * points;
    points = (int *) malloc(5 * sizeof(int));
    points& = 3;
    printf("%d\n", *points);
    free(points);
    printf("%d\n", *points);
}