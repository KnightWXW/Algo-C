#include "../Mybasic/mybasic.h"

//      LeetCode 62. 不同路径

//      链接：https://leetcode.cn/problems/unique-paths/

//      一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//      机器人每次只能向下或者向右移动一步。
//      机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//      问总共有多少条不同的路径？
//      示例 1：
//          输入：m = 3, n = 7
//          输出：28
//      示例 2：
//          输入：m = 3, n = 2
//          输出：3
//          解释：
//              从左上角开始，总共有 3 条路径可以到达右下角。
//              1. 向右 -> 向下 -> 向下
//              2. 向下 -> 向下 -> 向右
//              3. 向下 -> 向右 -> 向下
//      示例 3：
//          输入：m = 7, n = 3
//          输出：28
//      示例 4：
//          输入：m = 3, n = 3
//          输出：6
//      提示：
//          1 <= m, n <= 100
//          题目数据保证答案小于等于 2 * 109

int UniquePaths_A(int m, int n);
int DFSUniquePaths_A(int i, int j);
int UniquePaths_B(int m, int n);
int DFSUniquePaths_B(int i, int j, int **mem);
int UniquePaths_C(int m, int n);
int UniquePaths_D(int m, int n);
int UniquePaths_E(int m, int n);

int main()
{
    int m = GenerateRandomNum(0, 10);
    int n = GenerateRandomNum(0, 9);
    printf("暴力递归: %d x %d 网格 共有 %d 条不同路径\n", m, n, UniquePaths_A(m, n));
    printf("记忆化搜索: %d x %d 网格 共有 %d 条不同路径\n", m, n, UniquePaths_B(m, n));
    printf("动态规划: %d x %d 网格 共有 %d 条不同路径\n", m, n, UniquePaths_C(m, n));
    printf("动态规划(空间优化): %d x %d 网格 共有 %d 条不同路径\n", m, n, UniquePaths_D(m, n));
    printf("数学公式: %d x %d 网格 共有 %d 条不同路径\n", m, n, UniquePaths_E(m, n));
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N))
int UniquePaths_A(int m, int n)
{
    return DFSUniquePaths_A(m - 1, n - 1);
}

int DFSUniquePaths_A(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 1;
    }
    return DFSUniquePaths_A(i - 1, j) + DFSUniquePaths_A(i, j - 1);
}

// 记忆化搜索:
// Time: O(2^(M*N))
// Space: O(M*N)
int UniquePaths_B(int m, int n)
{
    int **mem = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (n));
        memset(mem[i], -1, sizeof(int) * (n));
    }
    int ans = DFSUniquePaths_B(m - 1, n - 1, mem);
    for (int i = 0; i < m; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSUniquePaths_B(int i, int j, int **mem)
{
    if (i == 0 || j == 0)
    {
        mem[i][j] = 1;
        return 1;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int a = DFSUniquePaths_B(i - 1, j, mem) + DFSUniquePaths_B(i, j - 1, mem);
    return a;
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int UniquePaths_C(int m, int n)
{
    int **dp = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (n));
        memset(dp[i], 0, sizeof(int) * (n));
    }
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    int ans = dp[m - 1][n - 1];
    for (int i = 0; i < m; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)：
// Time: O(M * N)
// Space: O(N)
int UniquePaths_D(int m, int n)
{
    int *dp = (int *)malloc(sizeof(int) * n);
    memset(dp, 0, sizeof(int) * (n));
    for (int j = 0; j < n; j++)
    {
        dp[j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j] += dp[j - 1];
        }
    }
    int ans = dp[n - 1];
    free(dp);
    return ans;
}

// 数学公式：
// Time: O(1)
// Space: O(1)
int UniquePaths_E(int m, int n)
{
    long long ans = 1;
    int x = n;
    int y = 1;
    for (; y < m; x++, y++)
    {
        ans = ans * x / y;
    }
    return ans;
}