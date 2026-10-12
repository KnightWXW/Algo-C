#include "../Mybasic/mybasic.h"

//      LeetCode 494. 目标和

//      链接：https://leetcode.cn/problems/target-sum/

//      给你一个非负整数数组 nums 和一个整数 target 。
//      向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//      例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，
//      然后串联起来得到表达式 "+2-1" 。
//      返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//      示例 1：
//          输入：nums = [1,1,1,1,1], target = 3
//          输出：5
//          解释：一共有 5 种方法让最终目标和为 3 。
//              -1 + 1 + 1 + 1 + 1 = 3
//              +1 - 1 + 1 + 1 + 1 = 3
//              +1 + 1 - 1 + 1 + 1 = 3
//              +1 + 1 + 1 - 1 + 1 = 3
//              +1 + 1 + 1 + 1 - 1 = 3
//      示例 2：
//          输入：nums = [1], target = 1
//          输出：1
//      提示：
//          1 <= nums.length <= 20
//          0 <= nums[i] <= 1000
//          0 <= sum(nums[i]) <= 1000
//          -1000 <= target <= 1000

int SumVec(int *nums, int numsSize);
int FindTargetSumWays_A(int *nums, int numsSize, int target);
int FindTargetSumWays_B(int *nums, int numsSize, int target);
int FindTargetSumWays_C(int *nums, int numsSize, int target);
int FindTargetSumWays_D(int *nums, int numsSize, int target);


int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 10, n);
    int sum = SumVec(vec, n);
    PrintVecElement(vec, n);
    int target = GenerateRandomNum(0, sum / 2 + 1);
    int ans1A = FindTargetSumWays_A(vec, n, target);
    int ans1B = FindTargetSumWays_B(vec, n, target);
    int ans1C = FindTargetSumWays_C(vec, n, target);
    printf("(暴力递归) 目标和 等于 %d 的不同 表达式 的数目为 %d \n", target, ans1A);
    printf("(记忆化搜索) 目标和 等于 %d 的不同 表达式 的数目为 %d\n", target, ans1B);
    printf("(动态规划) 目标和 等于 %d 的不同 表达式 的数目为 %d\n", target, ans1C);
}

int SumVec(int *nums, int numsSize)
{
    int s = 0;
    for (int i = 0; i < numsSize; i++)
    {
        s += nums[i];
    }
    return s;
}

int DFS_FindTargetSumWays_A(int *nums, int numsSize, int target, int i, int sum)
{
    if (i >= numsSize)
    {
        if (sum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int tem1 = DFS_FindTargetSumWays_A(nums, numsSize, target, i + 1, sum + nums[i]);
    int tem2 = DFS_FindTargetSumWays_A(nums, numsSize, target, i + 1, sum - nums[i]);
    return tem1 + tem2;
}

// 暴力递归
// Time: O(2^n)
// Space: O(n)
int FindTargetSumWays_A(int *nums, int numsSize, int target)
{
    int ans = DFS_FindTargetSumWays_A(nums, numsSize, target, 0, 0);
    return ans;
}

int DFS_FindTargetSumWays_B(int *nums, int numsSize, int target, int i, int sum, int **mem, int sumAll)
{
    if (i >= numsSize)
    {
        if (sum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int j = sumAll + sum;
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int tem1 = DFS_FindTargetSumWays_B(nums, numsSize, target, i + 1, sum + nums[i], mem, sumAll);
    int tem2 = DFS_FindTargetSumWays_B(nums, numsSize, target, i + 1, sum - nums[i], mem, sumAll);
    mem[i][j] = tem1 + tem2;
    return mem[i][j];
}

int FindTargetSumWays_B(int *nums, int numsSize, int target)
{
    int sumAll = SumVec(nums, numsSize);
    int l = sumAll * 2 + 1;
    int **mem = (int **)malloc(sizeof(int *) * (numsSize));
    for (int i = 0; i < numsSize; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * l);
        memset(mem[i], -1, sizeof(int) * l);
    }
    int ans = DFS_FindTargetSumWays_B(nums, numsSize, target, 0, 0, mem, sumAll);
    for (int i = 0; i < numsSize; i++)
    {
        free(mem[i]);
    }
    return ans;
}

// 动态规划
// Time: O(n^2)
// Space: O(n^2)
int FindTargetSumWays_C(int *nums, int numsSize, int target)
{
    int sumAll = SumVec(nums, numsSize);
    if (target > sumAll || target < -sumAll)
    {
        return 0;
    }
    int l = sumAll * 2 + 1;
    int **dp = (int **)malloc(sizeof(int *) * (numsSize + 1));
    for (int i = 0; i <= numsSize; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * l);
        memset(dp[i], 0, sizeof(int) * l);
    }
    dp[0][sumAll] = 1;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }
            int curSum = j - sumAll;
            int index1 = curSum + nums[i] + sumAll;
            if (index1 >= 0 && index1 <= l)
            {
                dp[i + 1][index1] += dp[i][j];
            }
            int index2 = curSum - nums[i] + sumAll;
            if (index2 >= 0 && index2 <= l)
            {
                dp[i + 1][index2] += dp[i][j];
            }
        }
    }
    int ans = dp[numsSize][target + sumAll];
    for (int i = 0; i <= numsSize; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)
// Time: O(n^2)
// Space: O(n)
int FindTargetSumWays_D(int *nums, int numsSize, int target)
{
    int sumAll = SumVec(nums, numsSize);
    if (target > sumAll || target < -sumAll)
    {
        return 0;
    }
    int l = sumAll * 2 + 1;
    int *dp = (int *)malloc(sizeof(int) * l);
    memset(dp, 0, sizeof(int) * l);
    int *next = (int *)malloc(sizeof(int) * l);
    dp[sumAll] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        memset(next, 0, sizeof(int) * l);
        for (int j = 0; j < l; j++)
        {
            if (dp[j] == 0)
            {
                continue;
            }
            int curSum = j - sumAll;
            int index1 = curSum + nums[i] + sumAll;
            if (index1 >= 0 && index1 <= l)
            {
                next[index1] += dp[j];
            }
            int index2 = curSum - nums[i] + sumAll;
            if (index2 >= 0 && index2 <= l)
            {
                next[index2] += dp[j];
            }
        }
        memcpy(dp, next, sizeof(int) * l);
    }
    int ans = dp[target + sumAll];
    free(dp);
    free(next);
    return ans;
}