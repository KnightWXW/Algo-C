#include "../Mybasic/mybasic.h"

//      LeetCode 28. 找出字符串中第一个匹配项的下标

//      链接: https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

//      给你两个字符串 haystack 和 needle ，
//      请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//      如果 needle 不是 haystack 的一部分，则返回  -1 。
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

int StrStr_A(char *haystack, char *needle);

int main()
{
    int n1 = GenerateRandomNum(1, 20);
    int n2 = GenerateRandomNum(1, 3);
    char arr[] = {'a', 'b', 'c'};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));
    char *s1 = GenerateRandomString(n1, arr, len);
    char *s2 = GenerateRandomString(n2, arr, len);
    PrintString(s1);
    PrintString(s2);
    int ansA = StrStr_A(s1, s2);
    printf("字符串中第一个匹配项的下标 为: %d\n", ansA);
    FreeString(s1);
    FreeString(s2);
}

// 直接遍历
// Time: O(n*m)
// Space: O(1) 
int StrStr_A(char *haystack, char *needle)
{
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    int k = 0;
    int i = 0;
    while (i <= l1 - l2)
    {
        k = 0;
        int j = i;
        while (k < l2 && haystack[j] == needle[k])
        {
            k++;
            j++;
        }
        if (k == l2)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return -1;
}

// KMP 算法