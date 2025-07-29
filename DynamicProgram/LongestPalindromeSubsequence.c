#include "../Mybasic/mybasic.h"

//      LeetCode 516. 最长回文子序列

//      链接：https://leetcode.cn/problems/longest-palindromic-subsequence/

//      给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
//      子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
//      示例 1：
//          输入：s = "bbbab"
//          输出：4
//          解释：一个可能的最长回文子序列为 "bbbb" 。
//      示例 2：
//          输入：s = "cbbd"
//          输出：2
//          解释：一个可能的最长回文子序列为 "bb" 。
//      提示：
//          1 <= s.length <= 1000
//          s 仅由小写英文字母组成

int LongestPalindromeSubsequence_A(char *s);
int DFSLongestPalindromeSubsequence_A(char *s, int start, int end);
int LongestPalindromeSubsequence_B(char *s);
int DFSLongestPalindromeSubsequence_B(char *s, int start, int end, int **mem);
int LongestPalindromeSubsequence_C(char *s);
int LongestPalindromeSubsequence_D(char *s);

int main()
{
    int n = GenerateRandomNum(0, 20);
    char arr[] = {'a', 'b', 'c'};
    char *s = GenerateRandomString(n, arr, strlen(arr) + 1);
    PrintString(s);
    int ansA = LongestPalindromeSubsequence_A(s);
    int ansB = LongestPalindromeSubsequence_B(s);
    int ansC = LongestPalindromeSubsequence_C(s);
    int ansD = LongestPalindromeSubsequence_D(s);
    printf("暴力递归: 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansA);
    printf("记忆化搜索: 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansB);
    printf("动态规划: 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansC);
    printf("动态规划(空间优化): 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansD);
    FreeString(s);
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int LongestPalindromeSubsequence_A(char *s)
{
    int l = strlen(s);
    if (l == 1)
    {
        return 1;
    }
    int ans = DFSLongestPalindromeSubsequence_A(s, 0, l - 1);
    return ans;
}

int DFSLongestPalindromeSubsequence_A(char *s, int start, int end)
{
    if (start == end)
    {
        return 1;
    }
    if (start > end)
    {
        return 0;
    }
    int ans = 0;
    if (s[start] == s[end])
    {
        ans = DFSLongestPalindromeSubsequence_A(s, start + 1, end - 1) + 2;
    }
    else
    {
        ans = max(DFSLongestPalindromeSubsequence_A(s, start + 1, end), DFSLongestPalindromeSubsequence_A(s, start, end - 1));
    }
    return ans;
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int LongestPalindromeSubsequence_B(char *s)
{
    int l = strlen(s);
    if (l == 1)
    {
        return 1;
    }
    int **mem = (int **)malloc(sizeof(int *) * (l));
    for (int i = 0; i < l; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (l));
        memset(mem[i], 0, sizeof(int) * (l));
    }
    int ans = DFSLongestPalindromeSubsequence_B(s, 0, l - 1, mem);
    for (int i = 0; i < l; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSLongestPalindromeSubsequence_B(char *s, int start, int end, int **mem)
{
    if (start == end)
    {
        mem[start][end] = 1;
        return 1;
    }
    if (start > end)
    {
        return 0;
    }
    if (mem[start][end] != 0)
    {
        return mem[start][end];
    }
    int ans = 0;
    if (s[start] == s[end])
    {
        ans = DFSLongestPalindromeSubsequence_B(s, start + 1, end - 1, mem) + 2;
    }
    else
    {
        ans = max(DFSLongestPalindromeSubsequence_B(s, start + 1, end, mem), DFSLongestPalindromeSubsequence_B(s, start, end - 1, mem));
    }
    mem[start][end] = ans;
    return ans;
}

// 动态规划：
// Time: O(N * N)
// Space: O(N * N)
int LongestPalindromeSubsequence_C(char *s)
{
    int l = strlen(s);
    if (l == 1)
    {
        return 1;
    }
    int **dp = (int **)malloc(sizeof(int *) * (l));
    for (int i = 0; i < l; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (l));
        memset(dp[i], 0, sizeof(int) * (l));
    }
    for (int i = 0; i < l; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = l - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    int ans = dp[0][l - 1];
    for (int i = 0; i < l; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N * N)
// Space: O(N * N)
int LongestPalindromeSubsequence_D(char *s)
{
    int l = strlen(s);
    if (l == 1)
    {
        return 1;
    }
    int *dp = (int *)malloc(sizeof(int) * (l));
    memset(dp, 0, sizeof(int) * (l));
    for (int i = l - 2; i >= 0; i--)
    {
        dp[i] = 1;
        int pre = 0;
        for (int j = i + 1; j < l; j++)
        {
            int tem = dp[j];
            if (s[i] == s[j])
            {
                dp[j] = pre + 2;
            }
            else
            {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            pre = tem;
        }
    }
    int ans = dp[l - 1];
    free(dp);
    return ans;
}