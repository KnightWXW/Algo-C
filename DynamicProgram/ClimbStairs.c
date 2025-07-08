#include "../Mybasic/mybasic.h"

//      LeetCode 70. 爬楼梯

//      链接：https://leetcode.cn/problems/climbing-stairs/

//      假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//      每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//      示例 1：
//          输入：n = 2
//          输出：2
//          解释：有两种方法可以爬到楼顶。
//              1. 1 阶 + 1 阶
//              2. 2 阶
//      示例 2：
//          输入：n = 3
//          输出：3
//          解释：有三种方法可以爬到楼顶。
//              1. 1 阶 + 1 阶 + 1 阶
//              2. 1 阶 + 2 阶
//              3. 2 阶 + 1 阶
//      提示：1 <= n <= 45

int ClimbStairs_A(int n);
int ClimbStairs_B(int n);
int DFSClimbStairs_B(int n, int *arr);
int ClimbStairs_C(int n);
int ClimbStairs_D(int n);
int ClimbStairs_E(int n);

int main()
{
    int num = generateRandomNum(1, 47);
    printf("(暴力递归): 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_A(num));
    printf("(记忆化搜索): 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_B(num));
    printf("(动态规划): 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_C(num));
    printf("(动态规划-空间压缩): 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_D(num));
    printf("(矩阵快速幂): 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_E(num));
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int ClimbStairs_A(int n)
{
   
}

int DFSClimbStairs_B(int n, int *arr)
{
    
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int ClimbStairs_B(int n)
{
    
}

// 动态规划:
// Time: O(N)
// Space: O(N)
int ClimbStairs_C(int n)
{
    
}

// 动态规划(压缩空间):
// Time: O(N)
// Space: O(1)
int ClimbStairs_D(int n)
{
    
}

// 矩阵快速幂:
// Time: O(logN)
// Space: O(1)
int ClimbStairs_E(int n)
{
   
}