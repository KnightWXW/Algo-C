#include "../Mybasic/mybasic.h"

//      LeetCode 1137. 第 N 个泰波那契数

//      链接：https://leetcode.cn/problems/n-th-tribonacci-number/

//      泰波那契序列 Tn 定义如下：
//      T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
//      给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
//      示例 1：
//          输入：n = 4
//          输出：4
//          解释：
//              T_3 = 0 + 1 + 1 = 2
//              T_4 = 1 + 1 + 2 = 4
//      示例 2：
//          输入：n = 25
//          输出：1389537
//      提示：
//          0 <= n <= 37
//          答案保证是一个 32 位整数，即 answer <= 2^31 - 1。

int Tribonacci_A(int n);
int Tribonacci_B(int n);
int DFSTribonacci_B(int n, int *mem);
int Tribonacci_C(int n);
int Tribonacci_D(int n);

int main()
{
    int num = GenerateRandomNum(0, 37);
    printf("暴力递归: 第 %d 个 泰波那契数 为 %d\n", num, Tribonacci_A(num));
    printf("记忆化搜索: 第 %d 个 泰波那契数 为 %d\n", num, Tribonacci_B(num));
    printf("动态规划: 第 %d 个 泰波那契数 为 %d\n", num, Tribonacci_C(num));
    printf("动态规划(空间优化): 第 %d 个 泰波那契数 为 %d\n", num, Tribonacci_D(num));
    //printf("矩阵快速幂: 第 %d 个 泰波那契数 为 %d\n", num, Tribonacci_E(num));
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int Tribonacci_A(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    return Tribonacci_A(n - 3) + Tribonacci_A(n - 2) + Tribonacci_A(n - 1);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int Tribonacci_B(int n)
{
    int *mem = (int *)malloc(sizeof(int) * (n + 1));
    memset(mem, -1, sizeof(int) * (n + 1));
    int ans = DFSTribonacci_B(n, mem);
    free(mem);
    return ans;
}

int DFSTribonacci_B(int n, int *mem)
{
    if (n == 0)
    {
        mem[0] = 0;
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        mem[n] = 1;
        return 1;
    }
    if (mem[n] != -1)
    {
        return mem[n];
    }
    int a = DFSTribonacci_B(n - 3, mem) + DFSTribonacci_B(n - 2, mem) + DFSTribonacci_B(n - 1, mem);
    mem[n] = a;
    return a;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int Tribonacci_C(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N)
// Space: O(1)
int Tribonacci_D(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;
    for (int i = 3; i <= n; i++)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    int ans = c;
    return ans;
}