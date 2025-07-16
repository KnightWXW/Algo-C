#include "../Mybasic/mybasic.h"

//      LeetCode 509. 斐波那契数

//      链接1：https://leetcode.cn/problems/fibonacci-number/
//      链接2：https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/

//      斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。
//      该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
//      也就是：
//          F(0) = 0，F(1) = 1
//          F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//      给定 n ，请计算 F(n) 。
//      答案需要取模 1e9+7(1000000007) ，如计算初始结果为：1000000008，请返回 1。
//      示例 1：
//          输入：n = 2
//          输出：1
//          解释：F(2) = F(1) + F(0) = 1 + 0 = 1
//      示例 2：
//          输入：n = 3
//          输出：2
//          解释：F(3) = F(2) + F(1) = 1 + 1 = 2
//      示例 3：
//          输入：n = 4
//          输出：3
//          解释：F(4) = F(3) + F(2) = 2 + 1 = 3
//      提示：0 <= n <= 30

#define FIBONACCI_MOD 1000000007

int Fibonacci_A(int n);
int Fibonacci_B(int n);
int DFSFibonacci_B(int n, int *arr);
int Fibonacci_C(int n);
int Fibonacci_D(int n);
int Fibonacci_E(int n);

int main()
{
    int num = GenerateRandomNum(0, 46);
    printf("随机数字为: %d\n", num);
    printf("暴力递归: 第 %d 个斐波那契数 为 %d\n", num, Fibonacci_A(num));
    printf("记忆化搜索: 第 %d 个斐波那契数 为 %d\n", num,Fibonacci_B(num));
    printf("动态规划: 第 %d 个斐波那契数 为 %d\n",num, Fibonacci_C(num));
    printf("动态规划(空间优化): 第 %d 个斐波那契数 为 %d\n",num, Fibonacci_D(num));
    printf("矩阵快速幂: 第 %d 个斐波那契数 为 %d\n",num, Fibonacci_E(num));
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int Fibonacci_A(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return (Fibonacci_A(n - 2) + Fibonacci_A(n - 1)) % FIBONACCI_MOD;
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int Fibonacci_B(int n)
{
    int *mem = (int *)malloc(sizeof(int) * (n + 1));
    memset(mem, -1, sizeof(int) * (n + 1));
    int ans = DFSFibonacci_B(n, mem);
    free(mem);
    return ans;
}

int DFSFibonacci_B(int n, int *mem)
{
    if (n <= 1)
    {
        mem[n] = n;
        return n;
    }
    if (mem[n] != -1)
    {
        return mem[n];
    }
    int f = (DFSFibonacci_B(n - 2, mem) + DFSFibonacci_B(n - 1, mem)) % FIBONACCI_MOD;
    mem[n] = f;
    return f;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int Fibonacci_C(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, -1, sizeof(int) * (n + 1));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % FIBONACCI_MOD;
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N)
// Space: O(1)
int Fibonacci_D(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = 0;
    int b = 1;
    int c = -1;
    for (int i = 2; i <= n; i++)
    {
        c = (a + b) % FIBONACCI_MOD;
        a = b;
        b = c;
    }
    return b;
}

// 矩阵快速幂:
// Time: O(N)
// Space: O(1)
int Fibonacci_E(int n)
{
}