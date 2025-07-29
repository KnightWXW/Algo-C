#include "../Mybasic/mybasic.h"

//      LeetCode 712. 两个字符串的最小ASCII删除和

//      链接：https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/

//      给定两个字符串s1 和 s2，返回使两个字符串相等所需删除字符的 ASCII 值的最小和。
//      示例 1:
//          输入: s1 = "sea", s2 = "eat"
//          输出: 231
//          解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
//              在 "eat" 中删除 "t" 并将 116 加入总和。
//              结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
//      示例 2:
//          输入: s1 = "delete", s2 = "leet"
//          输出: 403
//          解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
//              将 100[d]+101[e]+101[e] 加入总和。
//              在 "leet" 中删除 "e" 将 101[e] 加入总和。
//              结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
//              如果改为将两个字符串转换为 "lee" 或 "eet"，
//              我们会得到 433 或 417 的结果，比答案更大。
//      提示:
//          0 <= s1.length, s2.length <= 1000
//          s1 和 s2 由小写英文字母组成

int MinimumDeleteSum_A(char* s1, char* s2);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    int n2 = GenerateRandomNum(1, 8);
    char arr[] = {'a', 'b', 'c', 'd'};
    char *s1 = GenerateRandomString(n1, arr, strlen(arr));
    char *s2 = GenerateRandomString(n2, arr, strlen(arr));
    PrintString(s1);
    PrintString(s2);
    int ansA = MinimumDeleteSum_A(s1, s2);
    int ansB = MinimumDeleteSum_B(s1, s2);
    int ansC = MinimumDeleteSum_C(s1, s2);
    int ansD = MinimumDeleteSum_D(s1, s2);
    int ansE = MinimumDeleteSum_E(s1, s2);
    printf("暴力递归: 使两个字符串相等所需删除字符的 ASCII 值的最小和 为 %d\n", ansA);
    printf("记忆化搜索: 使两个字符串相等所需删除字符的 ASCII 值的最小和 为 %d\n", ansB);
    printf("动态规划: 使两个字符串相等所需删除字符的 ASCII 值的最小和 为 %d\n", ansC);
    printf("动态规划(空间优化1): 使两个字符串相等所需删除字符的 ASCII 值的最小和 为 %d\n", ansD);
    printf("动态规划(空间优化2): 使两个字符串相等所需删除字符的 ASCII 值的最小和 为 %d\n", ansE);
    FreeString(s1);
    FreeString(s2);
}

int MinimumDeleteSum_A(char* s1, char* s2)
{

}