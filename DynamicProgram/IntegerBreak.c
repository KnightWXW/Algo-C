#include "../Mybasic/mybasic.h"

//      LeetCode 343. 整数拆分

//      链接：https://leetcode.cn/problems/integer-break/

//      给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//      返回 你可以获得的最大乘积 。
//      示例 1:
//          输入: n = 2
//          输出: 1
//          解释: 2 = 1 + 1, 1 × 1 = 1。
//      示例 2:
//          输入: n = 10
//          输出: 36
//          解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//      提示:
//          2 <= n <= 58

int IntegerBreak_A(int n);
int DFSIntegerBreak_A(int n);
int IntegerBreak_B(int n);
int DFSIntegerBreak_B(int n);
int IntegerBreak_C(int n);
int IntegerBreak_D(int n);

int main()
{
    int n = GenerateRandomNum(2, 58);
    printf("暴力递归: 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_A(n));
    printf("记忆化搜索: 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_B(n));
    printf("动态规划: 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_C(n));
    printf("贪心算法: 整数 %d 分割得到的最大乘积 为 %d。\n", n, IntegerBreak_D(n));
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)


// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)


// 动态规划：
// Time: O(N)
// Space: O(N)


// 贪心算法：
// Time: O(1)
// Space: O(1)
