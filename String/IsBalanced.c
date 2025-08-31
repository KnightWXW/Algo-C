#include "../Mybasic/mybasic.h"

//      LeetCode 3340. 检查平衡字符串

//      链接: https://leetcode.cn/problems/check-balanced-string/

//      给你一个仅由数字 0 - 9 组成的字符串 num。
//      如果偶数下标处的数字之和等于奇数下标处的数字之和，则认为该数字字符串是一个 平衡字符串。
//      如果 num 是一个 平衡字符串，则返回 true；否则，返回 false。
//      示例 1：
//          输入：num = "1234"
//          输出：false
//          解释：
//              偶数下标处的数字之和为 1 + 3 = 4，奇数下标处的数字之和为 2 + 4 = 6。
//              由于 4 不等于 6，num 不是平衡字符串。
//      示例 2：
//          输入：num = "24123"
//          输出：true
//          解释：
//              偶数下标处的数字之和为 2 + 1 + 3 = 6，奇数下标处的数字之和为 4 + 2 = 6。
//              由于两者相等，num 是平衡字符串。
//      提示：
//          2 <= num.length <= 100
//          num 仅由数字 0 - 9 组成。

bool IsBalanced(char *num);

int main()
{
    int n = GenerateRandomNum(0, 10);
    char arr[10] = "0123456789";
    char *str = GenerateRandomString(n, arr, 10);
    PrintString(str);
    bool ans_A = IsBalanced(str);
    printf("字符串是否有效: ");
    PrintBool(ans_A);
    FreeString(str);
}

bool IsBalanced(char *num)
{
    int l = strlen(num);
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < l; i++)
    {
        int k = (num[i] - '0');
        if ((i & 1) == 0)
        {
            s2 += k;
        }
        else
        {
            s1 += k;
        }
    }
    return s1 == s2;
}