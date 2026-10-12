#include "../Mybasic/mybasic.h"

//      LeetCode 115. 不同的子序列

//      链接：https://leetcode.cn/problems/distinct-subsequences/

//      给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
//      测试用例保证结果在 32 位有符号整数范围内。
//      示例 1：
//          输入：s = "rabbbit", t = "rabbit"
//          输出：3
//          解释：
//              如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//              rabbbit
//              rabbbit
//              rabbbit
//      示例 2：
//          输入：s = "babgbag", t = "bag"
//          输出：5
//          解释：
//              如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//              babgbag
//              babgbag
//              babgbag
//              babgbag
//              babgbag
//      提示：
//          1 <= s.length, t.length <= 1000
//          s 和 t 由英文字母组成

int NumDistinct_A(char* s, char* t);
int NumDistinct_B(char* s, char* t);
int NumDistinct_C(char* s, char* t);
int NumDistinct_D(char* s, char* t);
int NumDistinct_E(char* s, char* t);

int main()
{
    int n1 = GenerateRandomNum(1, 20);
    int n2 = GenerateRandomNum(1, 5);
    char arr[] = {'a', 'b', 'c', 'd'};
    int len = (int)(sizeof(arr) / sizeof(arr[0]));
    char *s1 = GenerateRandomString(n1, arr, len);
    char *s2 = GenerateRandomString(n2, arr, len);
    PrintString(s1);
    PrintString(s2);
    int ansA = LongestCommonSubstring_A(s1, s2);
    int ansB = LongestCommonSubstring_B(s1, s2);
    int ansC = LongestCommonSubstring_C(s1, s2);
    int ansD = LongestCommonSubstring_D(s1, s2);
    int ansE = LongestCommonSubstring_E(s1, s2);
    printf("(暴力递归) 在 s1 的 子序列 中 s2 出现的个数 为 %d\n", ansA);
    printf("(记忆化搜索) 在 s1 的 子序列 中 s2 出现的个数 为 %d\n", ansB);
    printf("(动态规划) 在 s1 的 子序列 中 s2 出现的个数 为 %d\n", ansC);
    printf("(动态规划[空间优化1]) 在 s1 的 子序列 中 s2 出现的个数 为 %d\n", ansD);
    printf("(动态规划[空间优化2]) 在 s1 的 子序列 中 s2 出现的个数 为 %d\n", ansE);
    FreeString(s1);
    FreeString(s2);
}

int NumDistinct_A(char* s, char* t)
{
    
}