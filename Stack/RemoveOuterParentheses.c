#include "../Mybasic/mybasic.h"

//      LeetCode 1021. 删除最外层的括号

//      链接：https://leetcode.cn/problems/remove-outermost-parentheses/

//      有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，
//      其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。
//      例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
//      如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，
//      我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
//      给出一个非空有效字符串 s，考虑将其进行原语化分解，
//      使得：s = P_1 + P_2 + ... + P_k，
//      其中 P_i 是有效括号字符串原语。
//      对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。
//      示例 1：
//          输入：s = "(()())(())"
//          输出："()()()"
//          解释：
//              输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
//              删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
//      示例 2：
//          输入：s = "(()())(())(()(()))"
//          输出："()()()()(())"
//          解释：
//              输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
//              删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
//      示例 3：
//          输入：s = "()()"
//          输出：""
//          解释：
//              输入字符串为 "()()"，原语化分解得到 "()" + "()"，
//              删除每个部分中的最外层括号后得到 "" + "" = ""。
//      提示：
//          1 <= s.length <= 105
//          s[i] 为 '(' 或 ')'
//          s 是一个有效括号字符串

char *RemoveOuterParentheses_A(char *s);
char *RemoveOuterParentheses_B(char *s);

int main()
{
    char *s1 = "(()())(())(()(()))";
    PrintString(s1);
    char *ans_A = RemoveOuterParentheses_A(s1);
    char *ans_B = RemoveOuterParentheses_B(s1);
    printf("删除最外层的括号 为: \n");
    PrintString(ans_A);
    PrintString(ans_B);
    FreeString(ans_A);
    FreeString(ans_B);
}

// 单调栈
// Time: O(n)
// Space: O(n)
char *RemoveOuterParentheses_A(char *s)
{
    int l = strlen(s);
    char *ans = (char *)malloc(sizeof(char) * l);
    char *stk = (char *)malloc(sizeof(char) * l);
    memset(stk, 0, sizeof(char) * l);
    int index = 0;
    int k = 0;
    for (int i = 0; i < l; i++)
    {
        char c = s[i];
        if (c == ')')
        {
            k--;
        }
        if (k > 0)
        {
            ans[index++] = c;
        }
        if (c == '(')
        {
            stk[k++] = c;
        }
    }
    ans[index] = '\0';
    free(stk);
    return ans;
}

// 计数遍历
// Time: O(n)
// Space: O(1)
char *RemoveOuterParentheses_B(char *s)
{
    int l = strlen(s);
    char *ans = (char *)malloc(sizeof(char) * l);
    int index = 0;
    int k = 0;
    for (int i = 0; i < l; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            k++;
        }
        if (k != 1)
        {
            ans[index++] = c;
        }
        if (c == ')')
        {
            k--;
        }
    }
    ans[index] = '\0';
    return ans;
}