#include "../Mybasic/mybasic.h"

//      LeetCode 3280. 将日期转换为二进制表示

//      链接：https://leetcode.cn/problems/convert-date-to-binary/

//      给你一个字符串 date，它的格式为 yyyy-mm-dd，表示一个公历日期。
//      date 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）
//      并遵循 year-month-day 的格式。
//      返回 date 的 二进制 表示。
//      示例 1：
//          输入： date = "2080-02-29"
//          输出： "100000100000-10-11101"
//          解释：
//              100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。
//      示例 2：
//          输入： date = "1900-01-01"
//          输出： "11101101100-1-1"
//          解释：
//              11101101100, 1 和 1 分别是 1900, 1 和 1 的二进制表示。
//      提示：
//          date.length == 10
//          date[4] == date[7] == '-'，其余的 date[i] 都是数字。
//          输入保证 date 代表一个有效的公历日期，
//          日期范围从 1900 年 1 月 1 日到 2100 年 12 月 31 日（包括这两天）。

char *ConvertDateToBinary(char *date);

int main()
{
    char *s1 = "2080-02-29";
    printf("公历日期为:\n");
    PrintString(s1);
    char *ans1 = ConvertDateToBinary(s1);
    printf("二进制表示日期为:\n");
    PrintString(ans1);
    FreeString(ans1);

    char *s2 = "1900-01-01";
    printf("公历日期为:\n");
    PrintString(s2);
    char *ans2 = ConvertDateToBinary(s2);
    printf("二进制表示日期为:\n");
    PrintString(ans2);
    FreeString(ans2);
}

int StringToInteger(char *str, int left, int right)
{
    int ans = 0;
    for (int i = left; i <= right; i++)
    {
        ans = ans * 10 + (str[i] - '0');
    }
    return ans;
}

int DecimalismToBinay(char *str, int start, int num)
{
    int index = start;
    while (num != 0)
    {
        str[index++] = '0' + (num & 1);
        num >>= 1;
    }
    for (int i = start, j = index - 1; i < j; i++, j--)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    return index;
}

char *ConvertDateToBinary(char *date)
{
    int l = strlen(date);
    int year = StringToInteger(date, 0, 3);
    int month = StringToInteger(date, 5, 6);
    int day = StringToInteger(date, 8, 9);

    char *ans = (char *)calloc(128, 1);
    int i = DecimalismToBinay(ans, 0, year);
    ans[i++] = '-';
    i = DecimalismToBinay(ans, i, month);
    ans[i++] = '-';
    i = DecimalismToBinay(ans, i, day);
    return ans;
}