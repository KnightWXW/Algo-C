#include "../Mybasic/mybasic.h"

//      机器人行走

//      假设有排成一行的 n 个位置，记为 1~n ,n>=2
//      开始时机器人在其中的 cur 位置上(M一定是 1~N 中的一个)
//      如果机器人来到 1 位置，那么下一步只能往右来到 2 位置;
//      如果机器人来到 n 位置，那么下一步只能往左来到 n-1 位置;
//      如果机器人来到中间位置，那么下一步可以往左走或者往右走;
//      规定机器人必须走 cnt 步，最终能来到 end 位置(P 也是 1-n 中的一个)的方法有多少种?
//      给定四个参数 n、cur、cnt、end，返回方法数.

int RobotWalking_A(int n, int cur, int cnt, int end);
int DFSRobotWalking_A(int n, int cur, int cnt, int end);
int RobotWalking_B(int n, int cur, int cnt, int end);
int DFSRobotWalking_B(int n, int cur, int cnt, int end, int **mem);
int RobotWalking_C(int n, int cur, int cnt, int end);
int RobotWalking_D(int n, int cur, int cnt, int end);

int main()
{
    int n = 5;
    int cur = 2;
    int cnt = 6;
    int end = 4;
    int ansA = RobotWalking_A(n, cur, cnt, end);
    int ansB = RobotWalking_B(n, cur, cnt, end);
    //int ansC = RobotWalking_C(n, cur, cnt, end);
    //int ansD = RobotWalking_D(n, cur, cnt, end);
    printf("暴力递归: %d\n", ansA);           // 13
    printf("记忆化搜索: %d\n", ansB);         // 13
    //printf("动态规划: %d\n", ansC);           // 13
    //printf("动态规划(空间优化): %d\n", ansD); // 13
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N)
int RobotWalking_A(int n, int cur, int cnt, int end)
{
    return DFSRobotWalking_A(n, cur, cnt, end);
}

int DFSRobotWalking_A(int n, int cur, int cnt, int end)
{
    if (cnt == 0)
    {
        return cur == end ? 1 : 0;
    }
    if (cur == 1)
    {
        return DFSRobotWalking_A(n, cur + 1, cnt - 1, end);
    }
    if (cur == n)
    {
        return DFSRobotWalking_A(n, cur - 1, cnt - 1, end);
    }
    return DFSRobotWalking_A(n, cur + 1, cnt - 1, end) + DFSRobotWalking_A(n, cur - 1, cnt - 1, end);
}

// 记忆化搜索：
// Time: O(2^(M*N))
// Space: O((M*N)
int RobotWalking_B(int n, int cur, int cnt, int end)
{
    int **mem = (int **)malloc(sizeof(int *) * (cur + 1));
    for (int i = 0; i <= cur; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (n + 1));
        memset(mem[i], -1, sizeof(int) * (n + 1));
    }
    int ans = DFSRobotWalking_B(n, cur, cnt, end, mem);
    for (int i = 0; i <= cur; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSRobotWalking_B(int n, int cur, int cnt, int end, int **mem)
{
    if (cnt == 0)
    {
        mem[cnt][cur] = (cur == end ? 1 : 0);
        return mem[cnt][cur];
    }
    if (cur == 1)
    {
        mem[cnt][cur] = DFSRobotWalking_B(n, cur + 1, cnt - 1, end, mem);
        return mem[cnt][cur];
    }
    if (cur == n)
    {
        mem[cnt][cur] = DFSRobotWalking_B(n, cur - 1, cnt - 1, end, mem);
        return mem[cnt][cur];
    }
    if (mem[cnt][cur] != -1)
    {
        return mem[cnt][cur];
    }
    mem[cnt][cur] = DFSRobotWalking_B(n, cur + 1, cnt - 1, end, mem) + DFSRobotWalking_B(n, cur - 1, cnt - 1, end, mem);
    return mem[cnt][cur];
}

// 动态规划：
// Time: O(cnt * n)
// Space: O(cnt * n)
int RobotWalking_C(int n, int cur, int cnt, int end)
{
    int **dp = (int **)malloc(sizeof(int *) * (cur + 1));
    for (int i = 0; i <= cur; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));
        memset(dp[i], 0, sizeof(int) * (n + 1));
    }
    dp[0][end] = 1;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][j + 1];
            }
            if (j == n)
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    int ans = dp[cnt][cur];
    for (int i = 0; i <= cur; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)：
// Time: O(n)
// Space: O(n)
// int RobotWalking_D(int n, int cur, int cnt, int end)
// {

// }
