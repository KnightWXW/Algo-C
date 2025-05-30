#include "../Mybasic/mybasic.h"

//      LeetCode 2259. 移除指定数字得到的最大结果

//      链接：https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/

//      给你一个表示某个正整数的字符串 number 和一个字符 digit 。
//      从 number 中 恰好 移除 一个 等于 digit 的字符后，
//      找出并返回按 十进制 表示 最大 的结果字符串。
//      生成的测试用例满足 digit 在 number 中出现至少一次。
//      示例 1：
//          输入：number = "123", digit = "3"
//          输出："12"
//          解释："123" 中只有一个 '3' ，在移除 '3' 之后，结果为 "12" 。
//      示例 2：
//          输入：number = "1231", digit = "1"
//          输出："231"
//          解释：可以移除第一个 '1' 得到 "231" 或者移除第二个 '1' 得到 "123" 。
//              由于 231 > 123 ，返回 "231" 。
//      示例 3：
//          输入：number = "551", digit = "5"
//          输出："51"
//          解释：可以从 "551" 中移除第一个或者第二个 '5' 。
//              两种方案的结果都是 "51" 。
//      提示：
//          2 <= number.length <= 100
//          number 由数字 '1' 到 '9' 组成
//          digit 是 '1' 到 '9' 中的一个数字
//          digit 在 number 中出现至少一次

char *RemoveDigit_A(char *number, char digit);
char *RemoveDigit_B(char *number, char digit);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int k = GenerateRandomNum(1, n);
    char arr1[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char *number = GenerateRandomString(n, arr1, strlen(arr1));
    char digit = number[k - 1];
    PrintString(number);
    char *ans_A = RemoveDigit_A(number, digit);
    printf("移除指定数字 %c 得到的最大结果为：\n", digit);
    char *ans_B = RemoveDigit_B(number, digit);
    printf("移除指定数字 %c 得到的最大结果为：\n", digit);
    PrintString(ans_A);
    FreeString(number);
    FreeString(ans_A);
    FreeString(ans_B);
}

// 模拟：
// Time：O(N)
// Space：O(N)
char *RemoveDigit_A(char *number, char digit)
{
    int l = strlen(number);
    char *ans = (char *)malloc(sizeof(char) * l);
    memset(ans, 0, sizeof(char) * l);
    ans[l - 1] = '\0';
    char *s = (char *)malloc(sizeof(char) * l);
    for (int i = 0; i < l; i++)
    {
        if (number[i] != digit)
        {
            continue;
        }
        memcpy(&s[0], &number[0], sizeof(char) * i);
        memcpy(&s[i], &number[i + 1], sizeof(char) * (l - i - 1));
        s[l - 1] = '\0';
        if (strcmp(s, ans) > 0)
        {
            strcpy(ans, s);
        }
    }
    return ans;
}

// 贪心：
// Time：O(N)
// Space：O(1)
char *RemoveDigit_B(char *number, char digit)
{
    int l = strlen(number);
    int i = 0;
    int index = 0;
    for (i = 0; i < l; i++)
    {
        if (number[i] == digit)
        {
            index = i;
            if (number[i] < number[i + 1])
            {
                break;
            }
        }
    }
    for (int i = index; i < l; i++)
    {
        number[i] = number[i + 1];
    }
    return number;
}