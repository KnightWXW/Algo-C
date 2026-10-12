#include "../Mybasic/mybasic.h"

//      LeetCode 343. 整数拆分

//      链接：https://leetcode.cn/problems/integer-break/

//      给定一个正整数 n ，将其拆分为 k 个 正整数 的和（k >= 2），并使这些整数的乘积最大化。
//      返回 你可以获得的最大乘积 。
//      示例 1:
//          输入: n = 2
//          输出: 1
//          解释: 2 = 1 + 1, 1 × 1 = 1。
//      示例 2:
//          输入: n = 10
//          输出: 36
//          解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//      提示:
//          2 <= n <= 58

int IntegerBreak_A(int n);
int DFSIntegerBreak_A(int n);
int IntegerBreak_B(int n);
int DFSIntegerBreak_B(int n, int *mem);
int IntegerBreak_C(int n);
int IntegerBreak_D(int n);

int main()
{
    int n = GenerateRandomNum(2, 58);
    printf("(暴力递归) 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_A(n));
    printf("(记忆化搜索) 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_B(n));
    printf("(动态规划) 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_C(n));
    printf("(贪心算法) 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_D(n));
}

int DFSIntegerBreak_A(int n)
{
    if (n <= 3)
    {
        return n;
    }
    int tem1 = DFSIntegerBreak_A(n - 2) * 2;
    int tem2 = DFSIntegerBreak_A(n - 3) * 3;
    return max(tem1, tem2);
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int IntegerBreak_A(int n)
{
    if (n <= 3)
    {
        return n - 1;
    }
    return DFSIntegerBreak_A(n);
}

int DFSIntegerBreak_B(int n, int *mem)
{
    if (n <= 3)
    {
        return n;
    }
    if (mem[n] != 0)
    {
        return mem[n];
    }
    int tem1 = DFSIntegerBreak_B(n - 2, mem) * 2;
    int tem2 = DFSIntegerBreak_B(n - 3, mem) * 3;
    mem[n] = max(tem1, tem2);
    return mem[n];
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int IntegerBreak_B(int n)
{
    if (n <= 3)
    {
        return n - 1;
    }
    int *mem = (int *)malloc(sizeof(int) * (n + 1));
    memset(mem, 0, sizeof(int) * (n + 1));
    int ans = DFSIntegerBreak_B(n, mem);
    free(mem);
    return ans;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int IntegerBreak_C(int n)
{
    if (n <= 3)
    {
        return n - 1;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 3] * 3, dp[i - 2] * 2);
    }

    int ans = dp[n];
    free(dp);
    return ans;
}

// 贪心算法：
// Time: O(1)
// Space: O(1)
int IntegerBreak_D(int n)
{
    if (n <= 3)
    {
        return n - 1;
    }
    int k2 = n / 2;
    int m2 = n % 2;
    int k3 = n / 3;
    int m3 = n % 3;
    int tem1 = pow(2, k2);
    int tem2 = pow(3, k3);
    if (m2 == 1)
    {
        tem1 = tem1 / 2 * 3;
    }
    if (m3 == 1)
    {
        tem2 = tem2 / 3 * 4;
    }
    else if (m3 == 2)
    {
        tem2 = tem2 * 2;
    }
    int ans = max(tem1, tem2);
    return ans;
}
