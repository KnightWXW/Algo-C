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
char *LongestPalindrome_A(char *s);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    char arr[] = {'a', 'b', 'c', 'd'};
    char *s = GenerateRandomString(n1, arr, strlen(arr));
    PrintString(s);
    char *ansA = LongestPalindrome_A(s);
    printf("暴力递归: 字符串 s 中最长的 回文 子串为:\n");
    PrintString(ansA);
    char *ansB = LongestPalindrome_B(s);
    printf("记忆化搜索: 字符串 s 中最长的 回文 子串为:\n");
    PrintString(ansB);
    FreeString(s);
    FreeString(ansA);
    FreeString(ansB);
}