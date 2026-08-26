#include "../Mybasic/mybasic.h"

//      LeetCode 45. 跳跃游戏 II

//      链接：https://leetcode.cn/problems/jump-game-ii/

//      给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//      每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。
//      换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//          0 <= j <= nums[i]
//          i + j < n
//      返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
//      示例 1:
//          输入: nums = [2,3,1,1,4]
//          输出: 2
//          解释: 跳到最后一个位置的最小跳跃数是 2。
//              从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//      示例 2:
//          输入: nums = [2,3,0,1,4]
//          输出: 2
//      提示:
//          1 <= nums.length <= 104
//          0 <= nums[i] <= 1000
//          题目保证可以到达 nums[n-1]

int CanJump2_A(int *nums, int numsSize);
int CanJump2_B(int *nums, int numsSize);
int CanJump2_C(int *nums, int numsSize);
int CanJump2_D(int *nums, int numsSize);
int CanJump2_E(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int *nums = GenerateRandomVec(1, 5, n);
    PrintVecElement(nums, n);
    int ansA = CanJump2_A(nums, n);
    int ansB = CanJump2_B(nums, n);
    int ansC = CanJump2_C(nums, n);
    int ansD = CanJump2_D(nums, n);
    int ansE = CanJump2_E(nums, n);
    printf("暴力递归: 跳到最后一个位置的最小跳跃数 为 %d \n", ansA);
    printf("记忆化搜索: 跳到最后一个位置的最小跳跃数 为 %d \n", ansB);
    printf("动态规划: 跳到最后一个位置的最小跳跃数 为 %d \n", ansC);
    printf("贪心(正向): 跳到最后一个位置的最小跳跃数 为 %d \n", ansD);
    printf("贪心(反向): 跳到最后一个位置的最小跳跃数 为 %d \n", ansE);
    FreeVec(nums);
}

int DFSCanJump2_A(int *nums, int numsSize, int start)
{
    if (start >= numsSize - 1)
    {
        return 0;
    }
    int maxRange = nums[start] + start;
    int step = numsSize + 1;
    for (int i = start + 1; i <= maxRange; i++)
    {
        int tem = DFSCanJump2_A(nums, numsSize, i);
        step = fmin(step, tem + 1);
    }
    return step;
}

// 暴力递归
// Time: O(2^N)
// Space: O(N)
int CanJump2_A(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return 0;
    }
    return DFSCanJump2_A(nums, numsSize, 0);
}

int DFSCanJump2_B(int *nums, int numsSize, int start, int *mem)
{
    if (start >= numsSize - 1)
    {
        return 0;
    }
    if (mem[start] != 0)
    {
        return mem[start];
    }
    int maxRange = nums[start] + start;
    int step = numsSize + 1;
    for (int i = start + 1; i <= maxRange; i++)
    {
        int tem = DFSCanJump2_B(nums, numsSize, i, mem);
        step = fmin(step, tem + 1);
    }
    mem[start] = step;
    return step;
}

// 记忆化搜索
// Time: O(2^N)
// Space: O(N)
int CanJump2_B(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return 0;
    }
    int *mem = (int *)malloc(sizeof(int) * (numsSize));
    memset(mem, 0, sizeof(int) * numsSize);
    int ans = DFSCanJump2_B(nums, numsSize, 0, mem);
    free(mem);
    return ans;
}

// 动态规划
// Time: O(N)
// Space: O(N)
int CanJump2_C(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return 0;
    }
    int *dp = (int *)malloc(sizeof(int) * (numsSize));
    memset(dp, 0, sizeof(int) * numsSize);
    for (int i = numsSize - 2; i >= 0; i--)
    {
        int maxRange = nums[i] + i;
        int step = numsSize + 1;
        for (int j = i + 1; j <= min(maxRange, numsSize - 1); j++)
        {
            step = min(step, dp[j] + 1);
        }
        dp[i] = step;
    }
    int ans = dp[0];
    free(dp);
    return ans;
}

// 贪心(正向)
// Time: O(N)
// Space: O(1)
int CanJump2_D(int *nums, int numsSize)
{
    int steps = 0;
    int end = 0;      // 当前这步的最远位置
    int maxRange = 0; // 可到达的最远位置
    for (int i = 0; i < numsSize - 1; i++)
    {
        maxRange = fmax(nums[i] + i, maxRange);
        if (i == end)
        {
            end = maxRange;
            steps++;
        }
    }
    return steps;
}

// 贪心(反向)
// Time: O(N^2)
// Space: O(1)
int CanJump2_E(int *nums, int numsSize)
{
    int steps = 0;
    int pos = numsSize - 1;
    while (pos > 0)
    {
        for (int i = 0; i < pos; i++)
        {
            if (pos <= i + nums[i])
            {
                steps++;
                pos = i;
            }
        }
    }
    return steps;
}