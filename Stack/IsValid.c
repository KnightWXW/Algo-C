#include "../Mybasic/mybasic.h"

//      LeetCode 20. 有效的括号

//      链接: https://leetcode.cn/problems/valid-parentheses/

//      给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//      有效字符串需满足：
//          左括号必须用相同类型的右括号闭合。
//          左括号必须以正确的顺序闭合。
//          每个右括号都有一个对应的相同类型的左括号。
//      示例 1：
//          输入：s = "()"
//          输出：true
//      示例 2：
//          输入：s = "()[]{}"
//          输出：true
//      示例 3：
//          输入：s = "(]"
//          输出：false
//      示例 4：
//          输入：s = "([])"
//          输出：true
//      示例 5：
//          输入：s = "([)]"
//          输出：false
//      提示：
//          1 <= s.length <= 104
//          s 仅由括号 '()[]{}' 组成

bool IsValid(char *s);

int main()
{
    int n1 = GenerateRandomNum(0, 10);
    char arr[6] = "()[]{}";
    char *s1 = GenerateRandomString(n1, arr, 6);
    PrintString(s1);
    bool ans_A = IsValid(s1);
    printf("有效的括号 ? \n");
    PrintBool(ans_A);
    FreeString(s1);
}

// 栈:
// Time: O(N)
// Space: O(N)
bool IsValid(char *s)
{
    int l = strlen(s);
    char *vec = (char *)malloc(sizeof(char) * l);
    memset(vec, 0, sizeof(char) * l);
    int j = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(')
        {
            vec[j++] = ')';
        }
        else if (s[i] == '[')
        {
            vec[j++] = ']';
        }
        else if (s[i] == '{')
        {
            vec[j++] = '}';
        }
        else
        {
            if (j > 0 && s[i] == vec[j - 1])
            {
                j--;
            }
            else
            {
                return false;
            }
        }
    }
    free(vec);
    return j == 0;
}