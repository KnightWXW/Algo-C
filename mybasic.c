#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int GenerateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

int *GenerateRandomVec(int low, int high, int len)
{
    int *vec = (int *)malloc(sizeof(int) * len);
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec[i] = v;
    }
    return vec;
}

void FreeVec(int *vec)
{
    free(vec);
    return;
}

void PrintVecElement(int *vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", vec[i]);
    }
    printf("\n");
}