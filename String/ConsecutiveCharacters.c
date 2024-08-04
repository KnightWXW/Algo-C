#include "../mybasic.h"

//      LeetCode 1446. 连续字符

//      链接：https://leetcode.cn/problems/consecutive-characters/

//      给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
//      请你返回字符串 s 的 能量。
//      示例 1：
//          输入：s = "leetcode"
//          输出：2
//          解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
//      示例 2：
//          输入：s = "abbcccddddeeeeedcba"
//          输出：5
//          解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
//      提示：
//          1 <= s.length <= 500
//          s 只包含小写英文字母。

int ConsecutiveCharacters(char *s);

int main()
{
    int n = GenerateRandomNum(1, 20);
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char *str = GenerateRandomString(n, arr, 26);
    PrintString(str);
    int ans = ConsecutiveCharacters(str);
    printf("字符串 s 的 能量 为 %d 。\n", ans);
    FreeString(str);
}

int ConsecutiveCharacters(char *s)
{
    int ans = 1;
    int cnt = 1;
    int i = 1;
    while (s[i] != '\0')
    {
        if (s[i] != s[i - 1])
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        i++;
    }
    ans = max(ans, cnt);
    return ans;
}