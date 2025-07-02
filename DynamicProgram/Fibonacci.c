#include "../Mybasic/mybasic.h"

//      LeetCode 509. 斐波那契数

//      链接1：https://leetcode.cn/problems/fibonacci-number/
//      链接2：https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/

//      斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。
//      该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
//      也就是：
//          F(0) = 0，F(1) = 1
//          F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//      给定 n ，请计算 F(n) 。
//      示例 1：
//          输入：n = 2
//          输出：1
//          解释：F(2) = F(1) + F(0) = 1 + 0 = 1
//      示例 2：
//          输入：n = 3
//          输出：2
//          解释：F(3) = F(2) + F(1) = 1 + 1 = 2
//      示例 3：
//          输入：n = 4
//          输出：3
//          解释：F(4) = F(3) + F(2) = 2 + 1 = 3
//      提示：0 <= n <= 30

int Fibonacci_A(int n);
int Fibonacci_B(int n);
int DFSFibonacci_B(int n, int *arr);
int Fibonacci_C(int n);
int Fibonacci_D(int n);
int Fibonacci_E(int n);

int main()
{
    int num = GenerateRandomNum(0, 46);
    printf("随机数字为：%d\n", num);
    printf("暴力递归：%d\n", Fibonacci_A(num));
    printf("记忆化搜索：%d\n", Fibonacci_B(num));
    printf("动态规划：%d\n", Fibonacci_C(num));
    printf("动态规划（空间优化）：%d\n", Fibonacci_D(num));
    printf("矩阵快速幂：%d\n", Fibonacci_E(num));
}

int Fibonacci_A(int n)
{
    
}