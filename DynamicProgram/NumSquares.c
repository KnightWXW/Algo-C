#include "../Mybasic/mybasic.h"

//      LeetCode 279. 完全平方数

//      链接：https://leetcode.cn/problems/perfect-squares/

//      给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//      完全平方数 是一个整数，其值等于另一个整数的平方；
//      换句话说，其值等于一个整数自乘的积。
//      例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
//      示例 1：
//          输入：n = 12
//          输出：3 
//          解释：12 = 4 + 4 + 4
//      示例 2：
//          输入：n = 13
//          输出：2
//          解释：13 = 4 + 9
//      提示：
//          1 <= n <= 104

int NumSquares_A(int n);

int main()
{
    int num = GenerateRandomNum(1, 46);
    printf("暴力递归: 和为 %d 的完全平方数的最少数量 为 %d\n", num, NumSquares_A(num));
    printf("记忆化搜索: 和为 %d 的完全平方数的最少数量 为 %d\n", num,NumSquares_B(num));
    printf("动态规划: 和为 %d 的完全平方数的最少数量 为 %d\n",num, NumSquares_C(num));
    printf("动态规划(空间优化): 和为 %d 的完全平方数的最少数量 为 %d\n",num, NumSquares_D(num));
    printf("矩阵快速幂: 和为 %d 的完全平方数的最少数量 为 %d\n",num, NumSquares_E(num));
}

int NumSquares_A(int n)
{

}

int NumSquares_B(int n)
{

}