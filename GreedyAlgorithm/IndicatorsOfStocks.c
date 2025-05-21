#include "../Mybasic/mybasic.h"

//      神策: 股票的指标

//      给定一个数组 arr, 表示连续 n 天的股价, 数组下标表示第几天
//          指标 X: 任意两天的股价之和 – 此两天间隔的天数
//      比如
//          第3天，价格是10
//          第9天，价格是30
//          那么 第3天 和 第9天 的 指标X= 10 + 30 - (9 - 3) = 34
//      返回 arr中 最大的指标 X

int IndicatorsOfStocks_A(int* arr, int l);
int IndicatorsOfStocks_B(int* arr, int l);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int* vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ans_A = IndicatorsOfStocks_A(vec, n);
    int ans_B = IndicatorsOfStocks_B(vec, n);
    printf("arr 中 最大的指标为 %d。\n", ans_A);
    printf("arr 中 最大的指标为 %d。\n", ans_B);
}

// 暴力循环：
// Time: O(N^2)
// Space:O(1)
int IndicatorsOfStocks_A(int* arr, int l)
{
    
}

// 贪心：
// Time: O(N)
// Space:O(1)
int IndicatorsOfStocks_B(int* arr, int l)
{
    
}