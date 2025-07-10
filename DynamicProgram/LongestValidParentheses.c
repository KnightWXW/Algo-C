#include "../Mybasic/mybasic.h"

//      LeetCode 32. 最长有效括号

//      链接：https://leetcode.cn/problems/longest-valid-parentheses/

//      给你一个只包含 '(' 和 ')' 的字符串，
//      找出最长有效（格式正确且连续）括号子串的长度。
//      示例 1：
//          输入：s = "(()"
//          输出：2
//          解释：最长有效括号子串是 "()"
//      示例 2：
//          输入：s = ")()())"
//          输出：4
//          解释：最长有效括号子串是 "()()"
//      示例 3：
//          输入：s = ""
//          输出：0
//      提示：
//          0 <= s.length <= 3 * 104
//          s[i] 为 '(' 或 ')'

int LongestValidParentheses(char* s);

int main()
{
    int n = GenerateRandomNum(0, 20);
    char arr[] = {'(', ')'};
    char* s = GenerateRandomString(n, arr, strlen(arr) + 1);
    PrintString(s); 
    int ansA =  LongestValidParentheses(s);
    printf("最长有效括号长度为：%d", ansA);
    FreeString(s);
}

int LongestValidParentheses(char* s)
{
    
}