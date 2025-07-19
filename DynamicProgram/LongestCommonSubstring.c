#include "../Mybasic/mybasic.h"

//      最长公共子串

//      最长公共子串问题(Longest Common Substring, LCS)是一个经典的问题。
//      给定两个字符串，找出它们的最长公共子串。
//      子串要求字符在原字符串中的位置必须连续，且在两个字符串中完全一致。
//      给定两个字符串 str1 和 str2，我们要找到它们的最长公共子串的长度和内容。
//      例如：
//          输入：str1 = "abcdef" 和 str2 = "abfdef"
//          输出：最长公共子串为 "def"，长度为 3

int LongestCommonSubstring_A(char *s1, char *s2);
int DFSLongestCommonSubstring_A(char *s1, char *s2, int i, int j);
int LongestCommonSubstring_B(char *s1, char *s2);
int DFSLongestCommonSubstring_B(char *s1, char *s2, int i, int j, int **mem);
int LongestCommonSubstring_C(char *s1, char *s2);
int LongestCommonSubstring_D(char *s1, char *s2);
int LongestCommonSubstring_E(char *s1, char *s2);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    int n2 = GenerateRandomNum(1, 8);
    char arr[] = {'a', 'b', 'c', 'd'};
    char *s1 = GenerateRandomString(n1, arr, strlen(arr));
    char *s2 = GenerateRandomString(n2, arr, strlen(arr));
    PrintString(s1);
    PrintString(s2);
    int ansA = LongestCommonSubstring_A(s1, s2);
    int ansB = LongestCommonSubstring_B(s1, s2);
    int ansC = LongestCommonSubstring_C(s1, s2);
    int ansD = LongestCommonSubstring_D(s1, s2);
    int ansE = LongestCommonSubstring_E(s1, s2);
    printf("暴力递归: 字符串 中 最长公共子串 的 长度 为 %d\n", ansA);
    printf("记忆化搜索: 字符串 中 最长公共子串 的 长度 为 %d\n", ansB);
    printf("动态规划: 字符串 中 最长公共子串 的 长度 为 %d\n", ansC);
    printf("动态规划(空间优化1): 字符串 中 最长公共子串 的 长度 为 %d\n", ansD);
    printf("动态规划(空间优化2): 字符串 中 最长公共子串 的 长度 为 %d\n", ansE);
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N))
int LongestCommonSubstring_A(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int ans = 0;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            ans = max(ans, DFSLongestCommonSubstring_A(s1, s2, i, j));
        }
    }
    return ans;
}

int DFSLongestCommonSubstring_A(char *s1, char *s2, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return s1[i] == s2[j] ? 1 : 0;
    }
    if (s1[i] == s2[j])
    {
        return DFSLongestCommonSubstring_A(s1, s2, i - 1, j - 1) + 1;
    }
    else
    {
        return 0;
    }
}

// 记忆化搜索：
// Time: O(2^(M*N))
// Space: O((M*N))
int LongestCommonSubstring_B(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int **mem = (int **)malloc(sizeof(int *) * (l1));
    for (int i = 0; i < l1; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (l2));
        memset(mem[i], -1, sizeof(int) * (l2));
    }
    int ans = 0;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            ans = max(ans, DFSLongestCommonSubstring_B(s1, s2, i, j, mem));
        }
    }
    for (int i = 0; i < l1; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSLongestCommonSubstring_B(char *s1, char *s2, int i, int j, int **mem)
{
    if (i == 0 || j == 0)
    {
        int tem = s1[i] == s2[j] ? 1 : 0;
        mem[i][j] = tem;
        return tem;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    if (s1[i] == s2[j])
    {
        int tem = DFSLongestCommonSubstring_B(s1, s2, i - 1, j - 1, mem) + 1;
        mem[i][j] = tem;
        return tem;
    }
    else
    {
        int tem = 0;
        mem[i][j] = tem;
        return tem;
    }
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int LongestCommonSubstring_C(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int **dp = (int **)malloc(sizeof(int *) * (l1));
    for (int i = 0; i < l1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (l2));
        memset(dp[i], 0, sizeof(int) * (l2));
    }
    for (int i = 0; i < l1; i++)
    {
        dp[i][0] = s1[i] == s2[0] ? 1 : 0;
    }
    for (int j = 0; j < l2; j++)
    {
        dp[0][j] = s1[0] == s2[j] ? 1 : 0;
    }
    for (int i = 1; i < l1; i++)
    {
        for (int j = 1; j < l2; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    for (int i = 0; i < l1; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化[两个一位数组])：
// Time: O(M * N)
// Space: O(N)
int LongestCommonSubstring_D(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int ans = 0;
    int *dp1 = (int *)malloc(sizeof(int) * l2);
    memset(dp1, 0, sizeof(int) * l2);
    int *dp2 = (int *)malloc(sizeof(int) * l2);
    memset(dp2, 0, sizeof(int) * l2);
    for (int i = 0; i < l2; i++)
    {
        dp1[i] = s1[0] == s2[i] ? 1 : 0;
        ans = max(ans, dp1[i]);
    }
    for (int i = 1; i < l1; i++)
    {
        memcpy(dp2, dp1, sizeof(int) * l2);
        for (int j = 0; j < l2; j++)
        {
            if (j == 0)
            {
                dp1[0] = (s1[i] == s2[0]) ? 1 : 0;
            }
            else
            {
                if (s1[i] == s2[j])
                {
                    dp1[j] = dp2[j - 1]  + 1;
                }
                else
                {
                    dp1[j] = 0;
                }
            }
            ans = max(ans, dp1[j]);
        }
    }
    free(dp1);
    free(dp2);
    return ans;
}

// 动态规划(空间优化[对角线])：
// Time: O(M * N)
// Space: O(1)
int LongestCommonSubstring_E(char *s1, char *s2)
{

}