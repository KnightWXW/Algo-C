#include "../Mybasic/mybasic.h"

//      LeetCode 762. 二进制表示中质数个计算置位

//      链接：https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/

//      统计并返回 计算置位位数为质数 的整数个数。
//      计算置位位数 就是二进制表示中 1 的个数。
//      例如， 21 的二进制表示 10101 有 3 个计算置位。
//      示例 1：
//          输入：left = 6, right = 10
//          输出：4
//          解释：
//              6 -> 110 (2 个计算置位，2 是质数)
//              7 -> 111 (3 个计算置位，3 是质数)
//              9 -> 1001 (2 个计算置位，2 是质数)
//              10-> 1010 (2 个计算置位，2 是质数)
//              共计 4 个计算置位为质数的数字。
//      示例 2：
//          输入：left = 10, right = 15
//          输出：5
//          解释：
//              10 -> 1010 (2 个计算置位, 2 是质数)
//              11 -> 1011 (3 个计算置位, 3 是质数)
//              12 -> 1100 (2 个计算置位, 2 是质数)
//              13 -> 1101 (3 个计算置位, 3 是质数)
//              14 -> 1110 (3 个计算置位, 3 是质数)
//              15 -> 1111 (4 个计算置位, 4 不是质数)
//              共计 5 个计算置位为质数的数字。
//      提示：
//          1 <= left <= right <= 106
//          0 <= right - left <= 104

int CountPrimeSetBits(int left, int right);

int main()
{
    int a = GenerateRandomNum(1, 30);
    int b = GenerateRandomNum(30, 100);
    int ans = CountPrimeSetBits(a, b);
    printf("[%d : %d]二进制表示中质数个计算置位 为: %d\n",a, b, ans);
}

bool IsPrimeNum(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// 位运算:
// Time: O(N)
// Space: O(1)
int CountPrimeSetBits(int left, int right)
{
    int ans = 0;
    for (int k = left; k <= right; k++)
    {
        if (IsPrimeNum(__builtin_popcount(k)))
        {
            ans++;
        }
    }
    return ans;
}