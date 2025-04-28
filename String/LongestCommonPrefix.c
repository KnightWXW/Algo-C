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

char *LongestCommonPrefix_A(char **strs, int l);
char *LongestCommonPrefix_B(char **strs, int l);

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
}

// 纵向比较：
// Time: O(N * M)
// Space: O(1)
char *LongestCommonPrefix_A(char **strs, int l)
{
}

// 横向比较：
// Time: O(N * M)
// Space: O(1)
char *LongestCommonPrefix_B(char **strs, int l)
{
    
}