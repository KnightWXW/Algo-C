#include "../Mybasic/mybasic.h"

//      LeetCode 3754. 连接非零数字并乘以其数字和 I

//      链接: https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

//      给你一个整数 n。将 n 中所有的 非零数字 按照它们的原始顺序连接起来，
//      形成一个新的整数 x。如果不存在 非零数字 ，则 x = 0。
//      sum 为 x 中所有数字的 数字和 。
//      返回一个整数，表示 x * sum 的值。
//      示例 1：
//          输入： n = 10203004
//          输出： 12340
//          解释：
//              非零数字是 1、2、3 和 4。因此，x = 1234。
//              数字和为 sum = 1 + 2 + 3 + 4 = 10。
//              因此，答案是 x * sum = 1234 * 10 = 12340。
//      示例 2：
//          输入： n = 1000
//          输出： 1
//          解释：
//              非零数字是 1，因此 x = 1 且 sum = 1。
//              因此，答案是 x * sum = 1 * 1 = 1。
//      提示：
//          0 <= n <= 109

long long SumAndMultiply(int n);

int main()
{
    int n = GenerateRandomNum(0, 99999);
    long long ans = SumAndMultiply(n);
    printf("数字为 %d时，连接非零数字并乘以其数字和 为 %d\n", n, ans);
}

// 模拟
// Time: O(1)
// Space: O(1)
long long SumAndMultiply(int n)
{
    int k = 0;
    int t = 1;
    int sum = 0;
    while (n != 0)
    {
        int tem = n % 10;
        k += t * tem;
        if (tem != 0)
        {
            t *= 10;
        }
        sum += tem;
        n /= 10;
    }
    return (long long)k * sum;
}