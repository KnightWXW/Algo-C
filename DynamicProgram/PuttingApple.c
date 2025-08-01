#include "../Mybasic/mybasic.h"

//      牛客 HJ61. 放苹果

//      把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
//      （用K表示）5，1，1和1，5，1 是同一种分法。
//      0 <= M <= 10; 1 <= N <= 10;
//      示例1：
//          输入: M = 7 N = 3
//          输出: 8

int PuttingApple_A(int m, int n);
int PuttingApple_B(int m, int n);

int main()
{
    int m = GenerateRandomNum(0, 10);
    int n = GenerateRandomNum(1, 10);
    printf("暴力递归: %d 个苹果 放在 %d 个盘子 的 方法数为 %d\n", m, n, PuttingApple_A(m, n));
    printf("记忆化搜索: %d 个苹果 放在 %d 个盘子 的 方法数为 %d\n", m, n, PuttingApple_B(m, n));
    printf("动态规划: %d 个苹果 放在 %d 个盘子 的 方法数为 %d\n", m, n, PuttingApple_C(m, n));
    printf("动态规划(空间压缩): %d 个苹果 放在 %d 个盘子 的 方法数为 %d\n", m, n, PuttingApple_D(m, n));
    printf("矩阵快速幂: %d 个苹果 放在 %d 个盘子 的 方法数为 %d\n", m, n, PuttingApple_E(m, n));
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int PuttingApple_A(int m, int n)
{

}