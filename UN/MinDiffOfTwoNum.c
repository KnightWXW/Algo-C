#include "../Mybasic/mybasic.h"

//      Huawei: 差值的绝对值最小的两个数

//      给定一个无序数组 arr, 可能 有正, 有负, 有0,
//      只能挑选两个数字,想尽量让两个数字加起来的绝对值尽量小
//      返回可能的最小的值

int MinDiffOfTwoNum(int* arr, int l);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(-100, 100, n);
    PrintVecElement(vec, n);
    int ans = CountSmaller(vec, n);
    printf("差值的绝对值最小的两个数 为: %d\n", ans);
    FreeVec(vec);
}

int MinDiffOfTwoNum(int* arr, int l)
{
    
}