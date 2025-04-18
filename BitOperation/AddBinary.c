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

char* AddBinary(char* a, char* b);

int main()
{
    int n1 = GenerateRandomNum(1, 10);
    int n2 = GenerateRandomNum(1, 9);
    char arr[] = {'0', '1'};
    char *a = GenerateRandomString(n1, arr, strlen(arr));
    char *b = GenerateRandomString(n2, arr, strlen(arr));
    PrintString(a);
    PrintString(b);
    char* ans = AddBinary(a, b);
    printf("二进制求和为:");
    PrintString(ans);
    FreeString(a);
    FreeString(b);
    FreeString(ans);
}

char* AddBinary(char* a, char* b)
{
    
}