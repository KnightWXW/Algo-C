#include "../Mybasic/mybasic.h"

//      LeetCode 258. 各位相加

//      链接： https://leetcode.cn/problems/add-digits/

//      给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
//      示例 1:
//          输入: num = 38
//          输出: 2
//          解释: 各位相加的过程为：
//                  38 --> 3 + 8 --> 11
//                  11 --> 1 + 1 --> 2
//                由于 2 是一位数，所以返回 2。
//      示例 2:
//          输入: num = 0
//          输出: 0
//      提示：
//          0 <= num <= 231 - 1

int AddDigits(int num);

int main()
{
    int n = GenerateRandomNum(0, 100000);
    int ans_A = AddDigits(n);
    printf("各位相加 结果 为 %d.\n", ans_A);
}

// 模拟：
// Time: O(N)
// Space: O(1)
int DigitSum(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

// 模拟：
// Time: O(N)
// Space: O(1)
int AddDigits(int num)
{
    int ans = DigitSum(num);
    while (ans >= 10)
    {
        ans = DigitSum(ans);
    }
    return ans;
}