#include "../Mybasic/mybasic.h"

//      LeetCode 面试题 08.01. 三步问题

//      链接: https://leetcode.cn/problems/three-steps-problem-lcci/

//      三步问题。有个小孩正在上楼梯，楼梯有 n 阶台阶，小孩一次可以上 1 阶、2 阶或 3 阶。
//      实现一种方法，计算小孩有多少种上楼梯的方式。
//      结果可能很大，你需要对结果模 1000000007。
//      示例 1：
//          输入：n = 3
//          输出：4
//          说明：有四种走法
//      示例 2：
//          输入：n = 5
//          输出：13
//      提示:
//          n 范围在[1, 1000000]之间

#define WAYSTOSTEP_MOD 1000000007

int WaysToStep_A(int n);

int main()
{
    int num = GenerateRandomNum(1, 47);
    printf("(暴力递归): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_A(num));
    printf("(记忆化搜索): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_B(num));
    printf("(动态规划): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_C(num));
    printf("(动态规划-空间压缩): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_D(num));
    printf("(矩阵快速幂): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_E(num));
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int WaysToStep_A(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }
    else
    {
        return WaysToStep_A(n - 1) + WaysToStep_A(n - 2) + WaysToStep_A(n - 3);
    }
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int WaysToStep_B(int n)
{
    int *mem = (int *)malloc(sizeof(int) * (n + 1));
    memset(mem, 0, sizeof(int) * (n + 1));
    int ans = DFSWaysToStep_B(n, mem);
    free(mem);
    return ans;
}

int DFSWaysToStep_B(int n, int *mem)
{
    if (n == 1)
    {
        mem[n] = 1;
        return 1;
    }
    else if (n == 2)
    {
        mem[n] = 2;
        return 2;
    }
    else if (n == 3)
    {
        mem[n] = 4;
        return 4;
    }
    if (mem[n] != 0)
    {
        return mem[n];
    }
    int tem = (((DFSWaysToStep_B(n - 1, mem) + DFSWaysToStep_B(n - 2, mem)) % WAYSTOSTEP_MOD) + DFSWaysToStep_B(n - 3, mem)) % WAYSTOSTEP_MOD;
    mem[n] = tem;
    return tem;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int WaysToStep_C(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (((dp[i - 1] + dp[i - 2]) % WAYSTOSTEP_MOD) + dp[i - 3]) % WAYSTOSTEP_MOD;
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N)
// Space: O(1)
int WaysToStep_D(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }
    int a = 1;
    int b = 2;
    int c = 4;
    int d = 0;
    for (int i = 4; i <= n; i++)
    {
        d = (((a + b) % WAYSTOSTEP_MOD) + c) % WAYSTOSTEP_MOD;
        a = b;
        b = c;
        c = d;
    }
    int ans = c;
    return ans;
}

// 矩阵快速幂:
// Time: O(N)
// Space: O(1)
int WaysToStep_E(int n)
{

}