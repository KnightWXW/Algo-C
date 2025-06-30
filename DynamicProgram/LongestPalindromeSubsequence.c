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
int DFSLongestPalindromeSubsequence_B(char *s, int start, int end, );
int LongestPalindromeSubsequence_C(char *s);

int main()
{
    int n = GenerateRandomNum(0, 20);
    char arr[] = {'a', 'b', 'c'};
    char *s = GenerateRandomString(n, arr, strlen(arr) + 1);
    PrintString(s);
    int ansA = LongestPalindromeSubsequence_A(s);
    int ansB = LongestPalindromeSubsequence_B(s);
    int ansC = LongestPalindromeSubsequence_C(s);
    printf("(暴力递归) 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansA);
    printf("(记忆化搜索) 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansB);
    printf("(动态规划) 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", ansC);
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int LongestPalindromeSubsequence_A(char * s)
{
}

int DFSLongestPalindromeSubsequence_A(char * s, int start, int end)
{
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int LongestPalindromeSubsequence_B(char * s)
{
}

int DFSLongestPalindromeSubsequence_B(char * s, int start, int end, vector<vector<int>> arr)
{
}

// 动态规划：
// Time: O(N * N)
// Space: O(N * N)
int LongestPalindromeSubsequence_C(char * s)
{
}