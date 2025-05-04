#include "../Mybasic/mybasic.h"

//      LeetCode 14. 最长公共前缀

//      链接：https://leetcode.cn/problems/longest-common-prefix/

//      编写一个函数来查找字符串数组中的最长公共前缀。
//      如果不存在公共前缀，返回空字符串 ""。
//      示例 1：
//          输入：strs = ["flower","flow","flight"]
//          输出："fl"
//      示例 2：
//          输入：strs = ["dog","racecar","car"]
//          输出：""
//          解释：输入不存在公共前缀。
//      提示：
//          1 <= strs.length <= 200
//          0 <= strs[i].length <= 200
//          strs[i] 仅由小写英文字母组成

char *LongestCommonPrefix_A(char **strs, int strsSize);
char *LongestCommonPrefix_B(char **strs, int strsSize);

int main()
{
    int l1 = 3;
    char *arr1[] = {"flower", "flow", "flight"};
    PrintStringVec(arr1, l1);
    char *ans_A = LongestCommonPrefix_A(arr1, l1);
    char *ans_B = LongestCommonPrefix_B(arr1, l1);
    printf("字符串数组中的最长公共前缀为：\n");
    PrintString(ans_A);
    PrintString(ans_B);
    FreeString(ans_A);
    FreeString(ans_B);
}

// 纵向比较：
// Time: O(N * M)
// Space: O(1)
char *LongestCommonPrefix_A(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        return "";
    }
    int n = strlen(strs[0]);
    char *s = strs[0];
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < strsSize; i++)
        {
            if (s[j] != strs[i][j])
            {
                s[j] = '\0';
                return s;
            }
        }
    }
    return s;
}

// 横向比较：
// Time: O(N * M)
// Space: O(1)
char *LongestCommonPrefix_B(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        return "";
    }
    if (strsSize == 1)
    {
        return strs[0];
    }
    int n = strlen(strs[0]);
    char *s = strs[0];
    int curL = n + 1;
    int ansL = n + 1;
    char *ans = (char *)malloc(sizeof(int) * (n + 1));
    memset(ans, 0, sizeof(char) * (n + 1));
    int j = 0;
    for (int i = 1; i < strsSize; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[j] != strs[i][j] || j > strlen(strs[i]))
            {
                break;
            }
        }
        ansL = min(ansL, j);
    }
    s[ansL] = '\0';
    return s;
}