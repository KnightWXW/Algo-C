#include "../Mybasic/mybasic.h"

//      给定一个正数数组arr，请把 arr 中所有的 元素 分成两个集合，
//      尽量让两个集合的累加和相近。
//      返回：两个集合的累加和 在最接近的情况下，较小集合的累加和。

int SplitClosestSumWithLimit_A(int *vec, int l);
int DFSSplitClosestSumWithLimit_A(int *vec, int l, int index, int target);
int SplitClosestSumWithLimit_B(int *vec, int l);
int DFSSplitClosestSumWithLimit_B(int *vec, int l, int index, int target, int **mem);
int SplitClosestSumWithLimit_C(int *vec, int l);
int SplitClosestSumWithLimit_D(int *vec, int l);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ansA = SplitClosestSumWithLimit_A(vec, n);
    int ansB = SplitClosestSumWithLimit_B(vec, n);
    int ansC = SplitClosestSumWithLimit_C(vec, n);
    int ansD = SplitClosestSumWithLimit_D(vec, n);
    printf("暴力递归: 最接近的情况下，较小集合的累加和 为 %d\n", ansA);
    printf("记忆化搜索: 最接近的情况下，较小集合的累加和 为 %d\n", ansB);
    printf("动态规划: 最接近的情况下，较小集合的累加和 为 %d\n", ansC);
    printf("动态规划(空间优化): 最接近的情况下，较小集合的累加和 为 %d\n", ansD);
}