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

char *GenerateRandomString(int n, char *arr)
{
    char *str = (char *)malloc((n + 1) * sizeof(char));
    memset(str, '\0', n + 1);
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str[i] = arr[index];
    }
    return str;
}

// char** GenerateRandomStringVec(int n, int low, int high, char* arr)
// {
//     char** ans = malloc(n * sizeof(char));
//     srand((int)time(0));
//     for (int i = 0; i < n; i++)
//     {
//         int l = (rand() % (high - low + 1)) + low;
//         char* tem = malloc(l * sizeof(char));
//         GenerateRandomString(l, arr);
//         vec.push_back(tem);
//     }
//     return vec;
// }

void FreeString(char *str)
{
    free(str);
}

void PrintString(char *str)
{
    printf("%s \n", str);
}