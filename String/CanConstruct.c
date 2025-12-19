#include "../Mybasic/mybasic.h"

//      LeetCode 383. 赎金信

//      链接: https://leetcode.cn/problems/ransom-note/

//      给你两个字符串：ransomNote 和 magazine ，
//      判断 ransomNote 能不能由 magazine 里面的字符构成。
//      如果可以，返回 true ；否则返回 false 。
//      magazine 中的每个字符只能在 ransomNote 中使用一次。
//      示例 1：
//          输入：ransomNote = "a", magazine = "b"
//          输出：false
//      示例 2：
//          输入：ransomNote = "aa", magazine = "ab"
//          输出：false
//      示例 3：
//          输入：ransomNote = "aa", magazine = "aab"
//          输出：true
//      提示：
//          1 <= ransomNote.length, magazine.length <= 105
//          ransomNote 和 magazine 由小写英文字母组成

bool CanConstruct(char *ransomNote, char *magazine);

int main()
{
    int n1 = GenerateRandomNum(0, 10);
    int n2 = GenerateRandomNum(0, 20);
    char arr[5] = "abcde";
    char *s1 = GenerateRandomString(n1, arr, 5);
    char *s2 = GenerateRandomString(n2, arr, 5);
    PrintString(s1);
    PrintString(s2);
    bool ans_A = CanConstruct(s1, s2);
    printf("ransomNote 能不能由 magazine 里面的字符构成 ? \n");
    PrintBool(ans_A);
    FreeString(s1);
    FreeString(s2);
}

bool CanConstruct(char *ransomNote, char *magazine)
{
    int l1 = strlen(ransomNote);
    int l2 = strlen(magazine);
    int vec[26] = {0};
    for (int i = 0; i < l2; i++)
    {
        vec[magazine[i] - 'a']++;
    }
    for (int i = 0; i < l1; i++)
    {
        vec[ransomNote[i] - 'a']--;
        if (vec[ransomNote[i] - 'a'] < 0)
        {
            return false;
        }
    }
    return true;
}