#include "../Mybasic/mybasic.h"

//      LeetCode 67. 二进制求和

//      链接：https://leetcode.cn/problems/add-binary/

//      给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
//      示例 1：
//          输入:a = "11", b = "1"
//          输出："100"
//      示例 2：
//          输入：a = "1010", b = "1011"
//          输出："10101"
//      提示：
//          1 <= a.length, b.length <= 104
//          a 和 b 仅由字符 '0' 或 '1' 组成
//          字符串如果不是 "0" ，就不含前导零

char *DigitAddBinary(char *a, char *b);
char *AddBinary(char *a, char *b);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    int n2 = GenerateRandomNum(1, 9);
    char arr[] = {'0', '1'};
    char *a = GenerateRandomString(n1, arr, strlen(arr));
    char *b = GenerateRandomString(n2, arr, strlen(arr));
    PrintString(a);
    PrintString(b);
    char *ans = AddBinary(a, b);
    printf("二进制求和为:");
    PrintString(ans);
    FreeString(a);
    FreeString(b);
    FreeString(ans);
}

char *DigitAddBinary(char *a, char *b)
{
    int l1 = strlen(a);
    int l2 = strlen(b);
    int i = l1 - 1;
    int j = l2 - 1;
    int add = 0;
    while (j >= 0)
    {
        int tem = (a[i] - '0') + (b[j] - '0') + add;
        a[i] = tem % 2 + '0';
        add = tem / 2;
        i--;
        j--;
    }
    while (i >= 0)
    {
        int tem = (a[i] - '0') + add;
        a[i] = tem % 2 + '0';
        add = tem / 2;
        i--;
    }
    char *ans = (char *)malloc(sizeof(char) * (l1 + 2));
    memset(ans, 0, sizeof(char) * (l1 + 2));
    if (add > 0)
    {
        sprintf(ans, "%s%s", "1", a);
    }
    else
    {
        strcpy(ans, a);
    }
    return ans;
}

// 模拟：
// Time：O(N)
// Space: O(1)
char *AddBinary(char *a, char *b)
{
    int l1 = strlen(a);
    int l2 = strlen(b);
    if (l1 >= l2)
    {
        return DigitAddBinary(a, b);
    }
    else
    {
        return DigitAddBinary(b, a);
    }
}