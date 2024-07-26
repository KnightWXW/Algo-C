#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GenerateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

[]int generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void PrintVecElement(int* vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}