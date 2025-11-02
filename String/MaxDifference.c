#include "../Mybasic/mybasic.h"

//      LeetCode 3442. 奇偶频次间的最大差值 I

//      链接: https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/

//      给你一个由小写英文字母组成的字符串 s。
//      请你找出字符串中两个字符 a1 和 a2 的出现频次之间的 最大 差值
//          diff = freq(a1) - freq(a2)，这两个字符需要满足：
//      a1 在字符串中出现 奇数次 。
//      a2 在字符串中出现 偶数次 。
//      返回 最大 差值。
//      示例 1：
//          输入：s = "aaaaabbc"
//          输出：3
//          解释：
//              字符 'a' 出现 奇数次，次数为 5；字符 'b' 出现 偶数次，次数为 2。
//              最大差值为 5 - 2 = 3。
//      示例 2：
//          输入：s = "abcabcab"
//          输出：1
//          解释：
//              字符 'a' 出现 奇数次，次数为 3；字符 'c' 出现 偶数次，次数为 2。
//              最大差值为 3 - 2 = 1。
//      提示：
//          3 <= s.length <= 100
//          s 仅由小写英文字母组成。
//          s 至少由一个出现奇数次的字符和一个出现偶数次的字符组成。

int MaxDifference(char *s);

int main()
{
    int n = GenerateRandomNum(3, 20);
    char arr[6] = "abcdef";
    char *str = GenerateRandomString(n, arr, 6);
    PrintString(str);
    int ans_A = MaxDifference(str);
    printf("奇偶频次间的最大差值为 %d ", ans_A);
    FreeString(str);
}

int MaxDifference(char *s)
{
    int l = strlen(s);
    int hp[26] = {0};
    int a1 = 0;
    int a2 = l + 1;
    for (int i = 0; i < l; i++)
    {
        hp[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if ((hp[i] != 0) && (hp[i] & 1) == 1)
        {
            a1 = max(a1, hp[i]);
        }
        if ((hp[i] != 0) && (hp[i] & 1) == 0)
        {
            a2 = min(a2, hp[i]);
        }
    }
    return a1 - a2;
}