#include "../Mybasic/mybasic.h"

//      LeetCode 96. 不同的二叉搜索树

//      链接: https://leetcode.cn/problems/unique-binary-search-trees/

//      给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
//      返回满足题意的二叉搜索树的种数。
//      示例 1:
//          输入：n = 3
//          输出：5
//      示例 2：
//          输入：n = 1
//          输出：1
//      提示：
//          1 <= n <= 19

int NumTrees_A(int n);
int NumTrees_B(int n);
int NumTrees_C(int n);
int NumTrees_D(int n);

int main()
{
    int n = GenerateRandomNum(0, 19);
    printf("(暴力递归) %d 个节点的不同的二叉搜索树有 %d 种 \n", n, NumTrees_A(n));
    printf("(记忆化搜索) %d 个节点的不同的二叉搜索树有 %d 种 \n", n, NumTrees_B(n));
    printf("(动态规划) %d 个节点的不同的二叉搜索树有 %d 种 \n", n, NumTrees_C(n));
    printf("(数学公式)  %d 个节点的不同的二叉搜索树有 %d 种 \n", n, NumTrees_D(n));
}

int DFS_NumTrees_A(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (DFS_NumTrees_A(i) * DFS_NumTrees_A(n - i - 1));
    }
    return cnt;
}

// 暴力递归
// Time: O(2^(M*N))
// Space: O((M*N))
int NumTrees_A(int n)
{
    return DFS_NumTrees_A(n);
}

int DFS_NumTrees_B(int n, int *mem)
{
    if (n == 0 || n == 1)
    {
        mem[n] = 1;
        return 1;
    }
    if (mem[n] != 0)
    {
        return mem[n];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (DFS_NumTrees_B(i, mem) * DFS_NumTrees_B(n - i - 1, mem));
    }
    mem[n] = cnt;
    return cnt;
}

// 记忆化搜索
// Time: O(2^(M*N))
// Space: O(M*N)
int NumTrees_B(int n)
{
    int *mem = (int *)malloc(sizeof(int) * (n + 1));
    memset(mem, 0, sizeof(int) * (n + 1));
    int ans = DFS_NumTrees_B(n, mem);
    free(mem);
    return ans;
}

// 动态规划
// Time: O(M*N)
// Space: O(M*N)
int NumTrees_C(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 数学公式
// Time: O(1)
// Space: O(1)
int NumTrees_D(int n)
{
    long long ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans = ans * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)ans;
}