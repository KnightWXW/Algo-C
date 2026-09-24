#include "../Mybasic/mybasic.h"

//      LeetCode 647. 回文子串

//      链接: https://leetcode.cn/problems/palindromic-substrings/

//      给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
//      回文字符串 是正着读和倒过来读一样的字符串。
//      子字符串 是字符串中的由连续字符组成的一个序列。
//      示例 1：
//          输入：s = "abc"
//          输出：3
//          解释：三个回文子串: "a", "b", "c"
//      示例 2：
//          输入：s = "aaa"
//          输出：6
//          解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
//      提示：
//          1 <= s.length <= 1000
//          s 由小写英文字母组成

int CountSubstrings_A(char *s);
int CountSubstrings_B(char *s);
int CountSubstrings_C(char *s);
int CountSubstrings_D(char *s);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    char arr[] = {'a', 'b', 'c', 'd'};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));
    char *s = GenerateRandomString(n1, arr, len);
    PrintString(s);
    int ansA = CountSubstrings_A(s);
    printf("(暴力递归)回文子串 的数目为: %d\n", ansA);
    int ansB = CountSubstrings_B(s);
    printf("(记忆化搜索)回文子串 的数目为: %d\n", ansB);
    int ansC = CountSubstrings_C(s);
    printf("(动态规划)回文子串 的数目为: %d\n", ansC);
    int ansD = CountSubstrings_D(s);
    printf("(中心扩展)回文子串 的数目为: %d\n", ansD);
    FreeString(s);
}

int DFS_CountSubstrings_A(char *s, int l, int i, int j)
{
    if (i >= j)
    {
        return 1;
    }
    if (s[i] == s[j])
    {
        return DFS_CountSubstrings_A(s, l, i + 1, j - 1);
    }
    else
    {
        return 0;
    }
}

// 暴力递归
// Time: O(N^3)
// Space: O(1)
int CountSubstrings_A(char *s)
{
    int l = strlen(s);
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            ans += DFS_CountSubstrings_A(s, l, i, j);
        }
    }
    return ans;
}

int DFS_CountSubstrings_B(char *s, int l, int i, int j, int **mem)
{
    if (i >= j)
    {
        mem[i][j] = 1;
        return 1;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    if (s[i] == s[j])
    {
        mem[i][j] = DFS_CountSubstrings_B(s, l, i + 1, j - 1, mem);
        return mem[i][j];
    }
    else
    {
        mem[i][j] = 0;
        return 0;
    }
}

// 记忆化搜索
// Time: O(N^3)
// Space: O(N^2)
int CountSubstrings_B(char *s)
{
    int l = strlen(s);
    int **mem = (int **)malloc(sizeof(int *) * l);
    for (int i = 0; i < l; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * l);
        memset(mem[i], -1, sizeof(int) * l);
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            int a = DFS_CountSubstrings_B(s, l, i, j, mem);
            ans += a;
        }
    }
    for (int i = 0; i < l; i++)
    {
        free(mem[i]);
    }
    return ans;
}

// 动态规划
// Time: O(N^2)
// Space: O(N^2)
int CountSubstrings_C(char *s)
{
    int l = strlen(s);
    bool **dp = (bool **)malloc(sizeof(bool *) * l);
    for (int i = 0; i < l; i++)
    {
        dp[i] = (bool *)malloc(sizeof(bool) * l);
        memset(dp[i], 0, sizeof(bool) * l);
        dp[i][i] = true;
    }
    int ans = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        for (int j = i; j < l; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1 || dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        free(dp[i]);
    }
    return ans;
}

int DFS_CountSubstrings_D(char *s, int l, int i, int j)
{
    int cnt = 0;
    while (i >= 0 && j < l && s[i] == s[j])
    {
        i--;
        j++;
        cnt++;
    }
    return cnt;
}

// 中心扩展
// Time: O(N^2)
// Space: O(1)
int CountSubstrings_D(char *s)
{
    int l = strlen(s);
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        ans += DFS_CountSubstrings_D(s, l, i, i);
        if (i + 1 < l)
        {
            ans += DFS_CountSubstrings_D(s, l, i, i + 1);
        }
    }
    return ans;
}