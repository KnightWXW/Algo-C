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

int LongestCommonSubsequence_A(char *s);
int DfsLongestCommonSubsequence_A(char *s, int start, int end);
int LongestCommonSubsequence_B(char *s);
int DfsLongestCommonSubsequence_B(char *s, int start, int end);
int LongestCommonSubsequence_C(char *s);

int main()
{
    int n = GenerateRandomNum(0, 20);
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int l = strlen(arr);
    char *s = GenerateRandomString(n, arr, l);
    PrintString(s);
    int ansA = LongestCommonSubsequence_A(s);
    int ansB = LongestCommonSubsequence_B(s);
    int ansC = LongestCommonSubsequence_C(s);
    printf("暴力递归: 字符串 中 最长公共子序列 的 长度 为 %d\n", ansA);
    printf("记忆化搜索: 字符串 中 最长公共子序列 的 长度 为 %d\n", ansB);
    printf("动态规划: 字符串 中 最长公共子序列 的 长度 为 %d\n", ansC);
}
