#include "../Mybasic/mybasic.h"

//      LeetCode 1143. 最长公共子序列

//      链接：https://leetcode.cn/problems/longest-common-subsequence/

//      给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。
//      如果不存在 公共子序列 ，返回 0 。
//      一个字符串的 子序列 是指这样一个新的字符串：
//      它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//      例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
//      两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
//      示例 1：
//          输入：text1 = "abcde", text2 = "ace"
//          输出：3
//          解释：最长公共子序列是 "ace" ，它的长度为 3 。
//      示例 2：
//          输入：text1 = "abc", text2 = "abc"
//          输出：3
//          解释：最长公共子序列是 "abc" ，它的长度为 3 。
//      示例 3：
//          输入：text1 = "abc", text2 = "def"
//          输出：0
//          解释：两个字符串没有公共子序列，返回 0
//      提示：
//          1 <= text1.length, text2.length <= 1000
//          text1 和 text2 仅由小写英文字符组成。

int LongestCommonSubsequence_A(char *s1, char *s2);
int DFSLongestCommonSubsequence_A(char *s1, char *s2, int i, int j);
int LongestCommonSubsequence_B(char *text1, char *text2);
int DFSLongestCommonSubsequence_B(char *s1, char *s2, int i, int j, int **mem);
int LongestCommonSubsequence_C(char *text1, char *text2);
int LongestCommonSubsequence_D(char *text1, char *text2);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    int n2 = GenerateRandomNum(1, 8);
    char arr[] = {'a', 'b', 'c', 'd'};
    char *s1 = GenerateRandomString(n1, arr, strlen(arr));
    char *s2 = GenerateRandomString(n2, arr, strlen(arr));
    PrintString(s1);
    PrintString(s2);
    int ansA = LongestCommonSubsequence_A(s1, s2);
    int ansB = LongestCommonSubsequence_B(s1, s2);
    int ansC = LongestCommonSubsequence_C(s1, s2);
    int ansD = LongestCommonSubsequence_D(s1, s2);
    printf("暴力递归: 字符串 中 最长公共子序列 的 长度 为 %d\n", ansA);
    printf("记忆化搜索: 字符串 中 最长公共子序列 的 长度 为 %d\n", ansB);
    printf("动态规划: 字符串 中 最长公共子序列 的 长度 为 %d\n", ansC);
    printf("动态规划(空间优化): 字符串 中 最长公共子序列 的 长度 为 %d\n", ansD);
    FreeVec(s1);
    FreeVec(s2);
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N)
int LongestCommonSubsequence_A(char *text1, char *text2)
{
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    return DFSLongestCommonSubsequence_A(text1, text2, l1 - 1, l2 - 1);
}

int DFSLongestCommonSubsequence_A(char *s1, char *s2, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return s1[i] == s2[j] ? 1 : 0;
    }
    if (i == 0 && j != 0)
    {
        return (s1[i] == s2[j] ? 1 : DFSLongestCommonSubsequence_A(s1, s2, i, j - 1));
    }
    if (i != 0 && j == 0)
    {
        return (s1[i] == s2[j] ? 1 : DFSLongestCommonSubsequence_A(s1, s2, i - 1, j));
    }
    if (s1[i] == s2[j])
    {
        return DFSLongestCommonSubsequence_A(s1, s2, i - 1, j - 1) + 1;
    }
    else
    {
        int a1 = DFSLongestCommonSubsequence_A(s1, s2, i - 1, j);
        int a2 = DFSLongestCommonSubsequence_A(s1, s2, i, j - 1);
        return max(a1, a2);
    }
}

// 记忆化搜索：
// Time: O(2^(M*N))
// Space: O((M*N)
int LongestCommonSubsequence_B(char *text1, char *text2)
{
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    int **mem = (int **)malloc(sizeof(int *) * l1);
    for (int i = 0; i < l1; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (l2));
        memset(mem[i], -1, sizeof(int) * (l2));
    }
    int ans = DFSLongestCommonSubsequence_B(text1, text2, l1 - 1, l2 - 1, mem);
    for (int i = 0; i < l1; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSLongestCommonSubsequence_B(char *s1, char *s2, int i, int j, int **mem)
{
    if (i == 0 && j == 0)
    {
        int a = s1[i] == s2[j] ? 1 : 0;
        mem[i][j] = a;
        return a;
    }
    if (i == 0 && j != 0)
    {
        int a = (s1[i] == s2[j] ? 1 : DFSLongestCommonSubsequence_B(s1, s2, i, j - 1, mem));
        mem[i][j] = a;
        return a;
    }
    if (i != 0 && j == 0)
    {
        int a = (s1[i] == s2[j] ? 1 : DFSLongestCommonSubsequence_B(s1, s2, i - 1, j, mem));
        mem[i][j] = a;
        return a;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    if (s1[i] == s2[j])
    {
        int a = DFSLongestCommonSubsequence_B(s1, s2, i - 1, j - 1, mem) + 1;
        mem[i][j] = a;
        return a;
    }
    else
    {
        int a1 = DFSLongestCommonSubsequence_B(s1, s2, i - 1, j, mem);
        int a2 = DFSLongestCommonSubsequence_B(s1, s2, i, j - 1, mem);
        mem[i][j] = max(a1, a2);
        return max(a1, a2);
    }
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int LongestCommonSubsequence_C(char *text1, char *text2)
{
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    int **dp = (int **)malloc(sizeof(int *) * l1);
    for (int i = 0; i < l1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (l2));
        memset(dp[i], 0, sizeof(int) * (l2));
    }
    dp[0][0] = text1[0] == text2[0] ? 1 : 0;
    for (int i = 1; i < l1; i++)
    {
        dp[i][0] = (text1[i] == text2[0] ? 1 : dp[i - 1][0]);
    }
    for (int j = 1; j < l2; j++)
    {
        dp[0][j] = (text1[0] == text2[j] ? 1 : dp[0][j - 1]);
    }
    for (int i = 1; i < l1; i++)
    {
        for (int j = 1; j < l2; j++)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int ans = dp[l1 - 1][l2 - 1];
    for (int i = 0; i < l1; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)：
// Time: O(M * N)
// Space: O(N)
int LongestCommonSubsequence_C(char *text1, char *text2)
{
    int l1 = strlen(text1);
    int l2 = strlen(text2);
}