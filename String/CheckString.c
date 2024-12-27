#include "../Mybasic/mybasic.h"

//      LeetCode 2124. 检查是否所有 A 都在 B 之前

//      链接：https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/

//      给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。
//      如果字符串中 每个 'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回 false 。
//      示例 1：
//          输入：s = "aaabbb"
//          输出：true
//          解释：
//              'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
//              因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//      示例 2：
//          输入：s = "abab"
//          输出：false
//          解释：
//              存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
//              因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
//      示例 3：
//          输入：s = "bbb"
//          输出：true
//          解释：
//              不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
//      提示：
//          1 <= s.length <= 100
//          s[i] 为 'a' 或 'b'

bool CheckString_A(char *s);
bool CheckString_B(char *s);
bool CheckString_C(char *s);

int main()
{
    int n = GenerateRandomNum(0, 10);
    char arr[2] = "ab";
    char *str = GenerateRandomString(n, arr, 2);
    PrintString(str);
    bool ans_A = CheckString_A(str);
    printf("是否所有 A 都在 B 之前: \n");
    PrintBool(ans_A);
    bool ans_B = CheckString_B(str);
    printf("是否所有 A 都在 B 之前: \n");
    PrintBool(ans_B);
    bool ans_C = CheckString_C(str);
    printf("是否所有 A 都在 B 之前: \n");
    PrintBool(ans_C);
}

bool CheckString_A(char *s)
{
    int l = strlen(s);
    int a = -1;
    int b = l;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'a')
        {
            a = i;
        }
    }
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            b = i;
        }
    }
    return a < b;
}

bool CheckString_B(char *s)
{
    int l = strlen(s);
    int a = -1;
    int b = l;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'a')
        {
            a = max(i, a);
        }
        else
        {
            b = min(i, b);
        }
    }
    return a < b;
}

bool CheckString_C(char *s)
{
    int l = strlen(s);
    if (l == 1 && s[0] == 'b')
    {
        return true;
    }
    for (int i = 1; i < l; i++)
    {
        if (s[i - 1] == 'b' && s[i] == 'a')
        {
            return false;
        }
    }
    return true;
}