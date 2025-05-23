#include "../Mybasic/mybasic.h"

//      LeetCode 738. 单调递增的数字

//      链接：https://leetcode.cn/problems/monotone-increasing-digits/

//      当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，
//      我们称这个整数是单调递增的。
//      给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增。
//      示例 1:
//          输入: n = 10
//          输出: 9
//      示例 2:
//          输入: n = 1234
//          输出: 1234
//      示例 3:
//          输入: n = 332
//          输出: 299
//      提示:
//          0 <= n <= 109

int MonotoneIncreasingDigits(int n);

int main()
{
    int n = GenerateRandomNum(1, 999999);
    int ans = MonotoneIncreasingDigits(n);
    printf("小于或等于 %d 的最大数字, 且数字呈 单调递增 为 %d。\n", n, ans);
}

int MonotoneIncreasingDigits(int n)
{
    char str[32] = {0};
    sprintf(str, "%d", n);
    int l = strlen(str);
    int minVal = 10;
    int minIndex = -1;
    int maxVal = -1;
    int maxIndex = -1;
    for (int i = 0; i < l; i++)
    {
        if (str[i] < minVal)
        {
            minVal = str[i] - '0';
            minIndex = i;
        }
        if (str[i] > maxVal)
        {
            maxVal = str[i] - '0';
            maxIndex = i;
        }
    }
    int ans = 0;
    char *c = (char *)malloc(sizeof(char) * l);
    memset(c, 0, sizeof(char) * l);
    if (minIndex != 0)
    {
        for (int i = minIndex; i < l; i++)
        {
            str[i] = '0';
        }
        ans = atoi(str);
        return ans - 1;
    }
}