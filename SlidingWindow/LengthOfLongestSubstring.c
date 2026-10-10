#include "../Mybasic/mybasic.h"

//      LeetCode 3. 无重复字符的最长子串

//      链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/

//      给定一个字符串 s, 请你找出其中不含有重复字符的 最长 子串 的长度。
//      示例 1:
//          输入: s = "abcabcbb"
//          输出: 3
//          解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
//      示例 2:
//          输入: s = "bbbbb"
//          输出: 1
//          解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//      示例 3:
//          输入: s = "pwwkew"
//          输出: 3
//          解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//              请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//      提示：
//          0 <= s.length <= 5 * 104
//          s 由英文字母、数字、符号和空格组成

int LengthOfLongestSubstring(char *s);

int main()
{
    int n = GenerateRandomNum(0, 20);
    char arr[10] = "abcde 1234";
    char *str = GenerateRandomString(n, arr, 10);
    PrintString(str);
    int ans_A = LengthOfLongestSubstring(str);
    printf("无重复字符的最长子串 的长度 为: %d", ans_A);
    FreeString(str);
}

typedef struct
{
    char key;
    int val;
    UT_hash_handle hh;
} HashSet;

// 滑动窗口
// Time: O(n)
// Space: O(N)
int LengthOfLongestSubstring(char *s)
{
    int l = strlen(s);
    HashSet *set = NULL;
    HashSet *cur = NULL;
    int left = 0;
    int right = 0;
    int ans = 0;
    while (right < l)
    {
        char c = s[right];
        HASH_FIND(hh, set, &c, sizeof(char), cur);
        if (cur != NULL)
        {
            left = fmax(left, cur->val + 1);
            HASH_DEL(set, cur);
            free(cur);
        }
        cur = (HashSet *)malloc(sizeof(HashSet));
        cur->key = c;
        cur->val = right;
        HASH_ADD(hh, set, key, sizeof(char), cur);
        ans = fmax(ans, right - left + 1);
        right++;
    }
    HASH_CLEAR(hh, set);
    return ans;
}