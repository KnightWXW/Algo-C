#include "../Mybasic/mybasic.h"

//      绳子覆盖的节点数

//      给定一个有序数组 arr,代表数轴上从左到右有 n 个点 arr [0]、arr [1]...arr [n−1],
//      给定一个正数 L,代表一根长度为 L 的绳子,求绳子最多能覆盖其中的几个点?

int CompareInt(const void *a, const void *b);
int NumOfNodeCoveredByRope(int* nums, int l);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    int l = GenerateRandomNum(1, 100);
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int ans = NumOfNodeCoveredByRope(vec, n);
    printf("绳子最多能覆盖其中的 %d 个点。\n", ans);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return *tema - *temb;
}

int NumOfNodeCoveredByRope(int* nums, int l)
{

}