#include "../Mybasic/mybasic.h"

//      LeetCode 70. 爬楼梯

//      链接：https://leetcode.cn/problems/climbing-stairs/
//      链接：https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

//      假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//      每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//      结果可能过大，因此结果需要取模 1e9+7（1000000007），
//      如计算初始结果为：1000000008，请返回 1。
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

#define CLIMBSTAIRS_MOD 1000000007

int ClimbStairs_A(int n);
int ClimbStairs_B(int n);
int DFSClimbStairs_B(int n, int *arr);
int ClimbStairs_C(int n);
int ClimbStairs_D(int n);
int ClimbStairs_E(int n);

int main()
{
    int num = GenerateRandomNum(1, 47);
    printf("暴力递归: 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_A(num));
    printf("记忆化搜索: 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_B(num));
    printf("动态规划: 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_C(num));
    printf("动态规划(空间压缩): 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_D(num));
    printf("矩阵快速幂: 爬 %d 层楼梯的方法数为 %d\n", num, ClimbStairs_E(num));
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int ClimbStairs_A(int n)
{
    if (n <= 2)
    {
        return n;
    }
    return (ClimbStairs_A(n - 1) + ClimbStairs_A(n - 2)) % CLIMBSTAIRS_MOD;
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int ClimbStairs_B(int n)
{
    int *mem = (int *)malloc(sizeof(int) * (n + 1));
    memset(mem, -1, sizeof(int) * (n + 1));
    int ans = DFSClimbStairs_B(n, mem);
    free(mem);
    return ans;
}

int DFSClimbStairs_B(int n, int *mem)
{
    if (n <= 2)
    {
        return n;
    }
    if (mem[n] != -1)
    {
        return mem[n];
    }
    return (DFSClimbStairs_B(n - 1, mem) + DFSClimbStairs_B(n - 2, mem)) % CLIMBSTAIRS_MOD;
}

// 动态规划:
// Time: O(N)
// Space: O(N)
int ClimbStairs_C(int n)
{
    if (n <= 2)
    {
        return n;
    }
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, -1, sizeof(int) * (n + 1));
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % CLIMBSTAIRS_MOD;
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 动态规划(压缩空间):
// Time: O(N)
// Space: O(1)
int ClimbStairs_D(int n)
{
    if (n <= 2)
    {
        return n;
    }
    int a = 1;
    int b = 2;
    int c = 0;
    for (int i = 3; i <= n; i++)
    {
        c = (a + b) % CLIMBSTAIRS_MOD;
        a = b;
        b = c;
    }
    int ans = c;
    return ans;
}

void Multiply(long a[2][2], long b[2][2], long res[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
}

void MatrixPow(long base[2][2], int n, long result[2][2])
{
    // 初始化结果矩阵为单位矩阵 E
    long tempResult[2][2] = {{1, 0}, {0, 1}};

    while (n > 0)
    {
        if (n & 1)
        {
            // 如果 n 是奇数，将结果累乘到 tempResult
            long temp[2][2];
            Multiply(base, tempResult, temp);
            // 将 temp 拷贝回 tempResult
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    tempResult[i][j] = temp[i][j];
                }
            }
        }
        // base = base * base
        long tempBase[2][2];
        Multiply(base, base, tempBase);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                base[i][j] = tempBase[i][j];
            }
        }
        n >>= 1; // n 除以 2
    }

    // 将最终结果拷贝到输出参数
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = tempResult[i][j];
        }
    }
}

// 矩阵快速幂:
// Time: O(logN)
// Space: O(1)
int ClimbStairs_E(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    
    long tranVec[2][2] = {{1, 1}, {1, 0}};
    long vec[2][2];
    MatrixPow(tranVec, n, vec);
    
    return (int)vec[0][0];
}