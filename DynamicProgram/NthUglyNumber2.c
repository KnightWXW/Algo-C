#include "../Mybasic/mybasic.h"

//      LeetCode 264. 丑数 II

//      链接：https://leetcode.cn/problems/ugly-number-ii/

//      给你一个整数 n ，请你找出并返回第 n 个 丑数 。
//      丑数 就是质因子只包含 2、3 和 5 的正整数。
//      示例 1：
//          输入：n = 10
//          输出：12
//          解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
//      示例 2：
//          输入：n = 1
//          输出：1
//          解释：1 通常被视为丑数。
//      提示：
//          1 <= n <= 1690

int NthUglyNumber2_A(int n);

int main()
{
    int n = GenerateRandomNum(1, 1000);
    printf("(暴力递归): 第 %d 个 丑数 为 %d \n", n, NthUglyNumber2_A(n));
    printf("(记忆化搜索): 第 %d 个 丑数 为 %d \n", n, NthUglyNumber2_B(n));
    printf("(动态规划): 第 %d 个 丑数 为 %d \n", n, NthUglyNumber2_C(n));
    printf("(贪心算法): 第 %d 个 丑数 为 %d \n", n, NthUglyNumber2_D(n));
}