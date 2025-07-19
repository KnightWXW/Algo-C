#include "../Mybasic/mybasic.h"

//      LeetCode 746. 使用最小花费爬楼梯

//      链接：https://leetcode.cn/problems/min-cost-climbing-stairs/
//      链接：https://leetcode.cn/problems/GzCJIP/

//      给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
//      一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//      你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//      请你计算并返回达到楼梯顶部的最低花费。
//      示例 1：
//          输入：cost = [10,15,20]
//          输出：15
//          解释：你将从下标为 1 的台阶开始。
//              - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
//              总花费为 15 。
//      示例 2：
//          输入：cost = [1,100,1,1,1,100,1,1,100,1]
//          输出：6
//              解释：你将从下标为 0 的台阶开始。
//              - 支付 1，向上爬两个台阶，到达下标为 2 的台阶。
//              - 支付 1，向上爬两个台阶，到达下标为 4 的台阶。
//              - 支付 1，向上爬两个台阶，到达下标为 6 的台阶。
//              - 支付 1，向上爬一个台阶，到达下标为 7 的台阶。
//              - 支付 1，向上爬两个台阶，到达下标为 9 的台阶。
//              - 支付 1，向上爬一个台阶，到达楼梯顶部。
//              总花费为 6 。
//      提示：
//          2 <= cost.length <= 1000
//          0 <= cost[i] <= 999

int MinCostClimbingStairs_A(int *cost, int costSize);
int DFSMinCostClimbingStairs_A(int *cost, int costSize, int i);
int MinCostClimbingStairs_B(int *cost, int costSize);
int DFSMinCostClimbingStairs_B(int *cost, int costSize, int i, int* mem);
int MinCostClimbingStairs_C(int *cost, int costSize);
int MinCostClimbingStairs_D(int *cost, int costSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *nums = GenerateRandomVec(0, 20, n);
    PrintVecElement(nums, n);
    int ansA = MinCostClimbingStairs_A(nums, n);
    int ansB = MinCostClimbingStairs_B(nums, n);
    int ansC = MinCostClimbingStairs_C(nums, n);
    int ansD = MinCostClimbingStairs_D(nums, n);
    printf("暴力递归: 数组中能被三整除的元素最大和 为 %d \n", ansA);
    printf("记忆化搜索: 数组中能被三整除的元素最大和 为 %d \n", ansB);
    printf("动态规划: 数组中能被三整除的元素最大和 为 %d \n", ansC);
    printf("动态规划(空间优化): 数组中能被三整除的元素最大和 为 %d \n", ansD);
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int MinCostClimbingStairs_A(int *cost, int costSize)
{
    if (costSize == 2)
    {
        return min(cost[0], cost[1]);
    }
    return DFSMinCostClimbingStairs_A(cost, costSize, costSize);
}

int DFSMinCostClimbingStairs_A(int *cost, int costSize, int i)
{
    if (i <= 1)
    {
        return 0;
    }
    int a0 = DFSMinCostClimbingStairs_A(cost, costSize, i - 1) + cost[i - 1];
    int a1 = DFSMinCostClimbingStairs_A(cost, costSize, i - 2) + cost[i - 2];
    return min(a0, a1);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int MinCostClimbingStairs_B(int *cost, int costSize)
{
    if (costSize == 2)
    {
        return min(cost[0], cost[1]);
    }
    int *mem = (int *)malloc(sizeof(int) * (costSize + 1));
    memset(mem, -1, sizeof(int) * (costSize + 1));
    int ans = DFSMinCostClimbingStairs_B(cost, costSize, costSize, mem);
    free(mem);
    return ans;
}

int DFSMinCostClimbingStairs_B(int *cost, int costSize, int i, int *mem)
{
    if (i <= 1)
    {
        mem[i] = 0;
        return 0;
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int a0 = DFSMinCostClimbingStairs_B(cost, costSize, i - 1, mem) + cost[i - 1];
    int a1 = DFSMinCostClimbingStairs_B(cost, costSize, i - 2, mem) + cost[i - 2];
    mem[i] = min(a0, a1);
    return mem[i];
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int MinCostClimbingStairs_C(int *cost, int costSize)
{
    if (costSize == 2)
    {
        return min(cost[0], cost[1]);
    }
    int *dp = (int *)malloc(sizeof(int) * (costSize + 1));
    memset(dp, 0, sizeof(int) * (costSize + 1));
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= costSize; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    int ans = dp[costSize];
    free(dp);
    return ans;
}

// 动态规划(空间优化):
// Time: O(N)
// Space: O(1)
int MinCostClimbingStairs_D(int *cost, int costSize)
{
    if (costSize == 2)
    {
        return min(cost[0], cost[1]);
    }
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 2; i <= costSize; i++)
    {
        c = min(a + cost[i - 2], b + cost[i - 1]);
        a = b;
        b = c;
    }
    int ans = b;
    return ans;
}