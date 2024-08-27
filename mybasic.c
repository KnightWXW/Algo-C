#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// 随机数:
int GenerateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

// 布尔值：
void PrintBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

// 随机数组：
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

// 随机二维数组:
int **GenerateRandomVec2D(int low, int high, int row, int col)
{
    int **vec = (int **)malloc(sizeof(int *) * row);
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            vec[i][j] = v;
        }
    }
    return vec;
}

void FreeVec2D(int **vec, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(vec[i]);
    }
    return;
}

void PrintVecElement2D(int **vec, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    return;
}

// 随机字符串:
char *GenerateRandomString(int n, char *arr, int arrLen)
{
    char *str = (char *)malloc((n + 1) * sizeof(char));
    memset(str, '\0', n + 1);
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (arrLen);
        str[i] = arr[index];
    }
    return str;
}

void FreeString(char *str)
{
    free(str);
}

void PrintString(char *str)
{
    printf("%s \n", str);
}

// 随机字符串数组:
//     随机定长字符串数组：
char **GenerateRandomStringVecFixed(int row, int col, char *arr, int arrLen)
{
    char **ans = (char **)malloc(row * sizeof(char *));
    srand((int)time(0));
    for (int i = 0; i < row; i++)
    {
        char *tem = (char *)malloc((col + 1) * sizeof(char));
        memset(tem, '\0', col + 1);
        for (int j = 0; j < col; j++)
        {
            int index = rand() % (arrLen);
            tem[j] = arr[index];
        }
        ans[i] = tem;
    }
    return ans;
}

//     随机不定长字符串数组：
char **GenerateRandomStringVecUnfixed(int l, int low, int high, char *arr, int arrLen)
{
    char **ans = (char **)malloc(l * sizeof(char *));
    srand((int)time(0));
    for (int i = 0; i < l; i++)
    {
        int n = (rand() % (high - low + 1)) + low;
        ans[i] = GenerateRandomString(n, arr, arrLen);
    }
    return ans;
}

void FreeStringVec(char **arr, int l)
{
    for (int i = 0; i < l; i++)
    {
        free(arr[i]);
    }
    return;
}

void PrintStringVec(char **arr, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%s\n", arr[i]);
    }
    return;
}
