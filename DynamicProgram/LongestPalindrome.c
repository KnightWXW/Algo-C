#include "../Mybasic/mybasic.h"

//      LeetCode 5. 最长回文子串

//      链接：https://leetcode.cn/problems/longest-palindromic-substring/

//      给你一个字符串 s，找到 s 中最长的 回文 子串。
//      示例 1：
//          输入：s = "babad"
//          输出："bab"
//          解释："aba" 同样是符合题意的答案。
//      示例 2：
//          输入：s = "cbbd"
//          输出："bb"
//      提示：
//          1 <= s.length <= 1000
//          s 仅由数字和英文字母组成

char *LongestPalindrome_A(char *s);
char *LongestPalindrome_B(char *s);
char *LongestPalindrome_C(char *s);
char *LongestPalindrome_D(char *s);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    char arr[] = {'a', 'b', 'c', 'd'};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));
    char *s = GenerateRandomString(n1, arr, len);
    PrintString(s);
    char *ansA = LongestPalindrome_A(s);
    printf("(暴力递归)字符串 s 中最长的 回文 子串为:\n");
    PrintString(ansA);
    char *ansB = LongestPalindrome_B(s);
    printf("(记忆化搜索)字符串 s 中最长的 回文 子串为:\n");
    PrintString(ansB);
    char *ansC = LongestPalindrome_C(s);
    printf("(动态规划)字符串 s 中最长的 回文 子串为:\n");
    PrintString(ansC);
    char *ansD = LongestPalindrome_D(s);
    printf("(中心扩展)字符串 s 中最长的 回文 子串为:\n");
    PrintString(ansD);
    FreeString(s);
    FreeString(ansA);
    FreeString(ansB);
    FreeString(ansC);
    FreeString(ansD);
}

bool Judge_LongestPalindrome_A(char *s, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    if (s[i] != s[j])
    {
        return false;
    }
    return Judge_LongestPalindrome_A(s, i + 1, j - 1);
}

void DFS_LongestPalindrome_A(char *s, int i, int j, int l, int *start, int *maxLen)
{
    if (i >= l)
    {
        return;
    }
    if (j >= l)
    {
        DFS_LongestPalindrome_A(s, i + 1, i + 1, l, start, maxLen);
        return;
    }
    bool flag = Judge_LongestPalindrome_A(s, i, j);
    if (flag == true)
    {
        int curLen = j - i + 1;
        if (curLen > *maxLen)
        {
            *start = i;
            *maxLen = curLen;
        }
    }
    return DFS_LongestPalindrome_A(s, i, j + 1, l, start, maxLen);
}

// 暴力递归
// Time: O(N^3)
// Space: O(1)
char *LongestPalindrome_A(char *s)
{
    int l = strlen(s);
    int maxLen = 1;
    int start = 0;
    DFS_LongestPalindrome_A(s, 0, 0, l, &start, &maxLen);
    char *ans = (char *)malloc(sizeof(char) * (maxLen + 1));
    memcpy(ans, s + start, maxLen);
    ans[maxLen] = '\0';
    return ans;
}

bool Judge_LongestPalindrome_B(char *s, int i, int j, int **mem)
{
    if (i >= j)
    {
        mem[i][i] = 1;
        return true;
    }
    if (s[i] != s[j])
    {
        mem[i][j] = 0;
        return false;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    bool f = Judge_LongestPalindrome_B(s, i + 1, j - 1, mem);
    mem[i][j] = f;
    return f;
}

void DFS_LongestPalindrome_B(char *s, int i, int j, int l, int *start, int *maxLen, int **mem)
{
    if (i >= l)
    {
        return;
    }
    if (j >= l)
    {
        DFS_LongestPalindrome_B(s, i + 1, i + 1, l, start, maxLen, mem);
        return;
    }
    bool flag = Judge_LongestPalindrome_B(s, i, j, mem);
    if (flag == true)
    {
        int curLen = j - i + 1;
        if (curLen > *maxLen)
        {
            *start = i;
            *maxLen = curLen;
        }
    }
    return DFS_LongestPalindrome_B(s, i, j + 1, l, start, maxLen, mem);
}

// 记忆化搜索
// Time: O(N^3)
// Space: O(N^2)
char *LongestPalindrome_B(char *s)
{
    int l = strlen(s);
    int maxLen = 1;
    int start = 0;
    int **mem = (int **)malloc(sizeof(int *) * l);
    for (int i = 0; i < l; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * l);
        memset(mem[i], -1, sizeof(int) * l);
    }
    DFS_LongestPalindrome_B(s, 0, 0, l, &start, &maxLen, mem);
    char *ans = (char *)malloc(sizeof(char) * (maxLen + 1));
    memcpy(ans, s + start, maxLen);
    ans[maxLen] = '\0';
    for (int i = 0; i < l; i++)
    {
        free(mem[i]);
    }
    return ans;
}

// 动态规划
// Time: O(N^2)
// Space: O(N^2)
char *LongestPalindrome_C(char *s)
{
    int l = strlen(s);
    int maxLen = 1;
    int start = 0;
    int **dp = (int **)malloc(sizeof(int *) * l);
    for (int i = 0; i < l; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * l);
        memset(dp[i], 0, sizeof(int) * l);
        dp[i][i] = 1;
    }
    for (int i = 0; i < l - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            maxLen = fmax(maxLen, 2);
            start = i;
            dp[i][i + 1] = 1;
        }
    }
    for (int k = 3; k <= l; k++)
    {
        for (int i = 0; i <= l - k; i++)
        {
            int j = i + k - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                maxLen = fmax(maxLen, k);
                start = i;
                dp[i][j] = 1;
            }
        }
    }
    char *ans = (char *)malloc(sizeof(char) * (maxLen + 1));
    memcpy(ans, s + start, maxLen);
    ans[maxLen] = '\0';
    for (int i = 0; i < l; i++)
    {
        free(dp[i]);
    }
    return ans;
}

int Digit_LongestPalindrome_D(char *s, int i, int j)
{
    int l = strlen(s);
    while (i >= 0 && j < l && s[i] == s[j])
    {
        i--;
        j++;
    }
    return j - i - 1;
}

// 中心扩展法
// Time: O(N^2)
// Space: O(1)
char *LongestPalindrome_D(char *s)
{
    int l = strlen(s);
    int maxLen = 1;
    int start = 0;
    for (int i = 0; i < l; i++)
    {
        int l1 = Digit_LongestPalindrome_D(s, i, i);
        int l2 = Digit_LongestPalindrome_D(s, i, i + 1);
        int curl = l1 > l2 ? l1 : l2;
        if (curl > maxLen)
        {
            maxLen = curl;
            start = i - (maxLen - 1) / 2;
        }
    }
    char *ans = (char *)malloc(sizeof(char) * (maxLen + 1));
    memcpy(ans, s + start, maxLen);
    ans[maxLen] = '\0';
    return ans;
}
