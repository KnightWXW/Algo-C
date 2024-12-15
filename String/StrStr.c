#include "../Mybasic/mybasic.h"

//      LeetCode 28. 找出字符串中第一个匹配项的下标

//      链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

//      给你两个字符串 haystack 和 needle ，
//      请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//      如果 needle 不是 haystack 的一部分，则返回 -1 。
//      示例 1：
//          输入：haystack = "sadbutsad", needle = "sad"
//          输出：0
//          解释："sad" 在下标 0 和 6 处匹配。
//              第一个匹配项的下标是 0 ，所以返回 0 。
//      示例 2：
//          输入：haystack = "leetcode", needle = "leeto"
//          输出：-1
//          解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
//      提示：
//          1 <= haystack.length, needle.length <= 104
//          haystack 和 needle 仅由小写英文字符组成

int StrStr(char *haystack, char *needle);

int main()
{
    char haystack1[] = "sadbutsad";
    char needle1[] = "sad";
    PrintString(haystack1);
    PrintString(needle1);
    int ans1 = StrStr(haystack1, needle1);
    printf("第一个 匹配项的下标 为: %d\n", ans1);

    char haystack2[] = "leetcode";
    char needle2[] = "leeto";
    PrintString(haystack2);
    PrintString(needle2);
    int ans2 = StrStr(haystack2, needle2);
    printf("第一个匹配项的下标 为: %d\n", ans2);
}

// 字符串遍历:
// Space: O(N)
// Time: O(1)
int StrStr(char *haystack, char *needle)
{
    int ans = 0;
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    for (int i = 0; i + l2 <= l1; i++)
    {
        bool flag = true;
        for (int j = 0; j < l2; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            return i;
        }
    }
    return -1;
}