#include "../Mybasic/mybasic.h"

//      LeetCode 53. 最大子数组和

//      链接：https://leetcode.cn/problems/maximum-subarray/

//      给你一个整数数组 nums，
//      请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
//      返回其最大和。
//      子数组 是数组中的一个连续部分。
//      示例 1：
//          输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//          输出：6
//          解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
//      示例 2：
//          输入：nums = [1]
//          输出：1
//      示例 3：
//          输入：nums = [5,4,-1,7,8]
//          输出：23
//      提示：
//          1 <= nums.length <= 105
//          -104 <= nums[i] <= 104

int MaxSubArray_A(int *nums, int numsSize);
int DFSMaxSubArray_A(int *nums, int numsSize, int i);
int MaxSubArray_B(int *nums, int numsSize);
int DFSMaxSubArray_B(int *nums, int numsSize, int i, int *mem);
int MaxSubArray_C(int *nums, int numsSize);
int MaxSubArray_D(int *nums, int numsSize);
int MaxSubArray_E(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(-100, 100, n);
    int ansA = MaxSubArray_A(vec, n);
    int ansB = MaxSubArray_B(vec, n);
    int ansC = MaxSubArray_C(vec, n);
    int ansD = MaxSubArray_D(vec, n);
    int ansE = MaxSubArray_D(vec, n);
    PrintVecElement(vec, n);
    printf("暴力递归: 连续子数组的最大和为 %d \n", ansA);
    printf("记忆化搜索: 连续子数组的最大和为 %d \n", ansB);
    printf("动态规划: 连续子数组的最大和为 %d \n", ansC);
    printf("动态规划(空间压缩): 连续子数组的最大和为 %d \n", ansD);
    printf("贪心算法: 连续子数组的最大和为 %d \n", ansE);
    FreeVec(vec);
}

int DFSMaxSubArray_A(int *nums, int numsSize, int i)
{
    if (i == 0)
    {
        return nums[i];
    }
    int a = DFSMaxSubArray_A(nums, numsSize, i - 1);
    if (a >= 0)
    {
        return a + nums[i];
    }
    else
    {
        return nums[i];
    }
}

// 暴力递归
// Time: O(2^N)
// Space: O(N)
int MaxSubArray_A(int *nums, int numsSize)
{
    int ans = INT_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        int tem = DFSMaxSubArray_A(nums, numsSize, i);
        ans = max(ans, tem);
    }
    return ans;
}

int DFSMaxSubArray_B(int *nums, int numsSize, int i, int *mem)
{
    if (i == 0)
    {
        mem[i] = nums[i];
        return nums[i];
    }
    if (mem[i] != INT_MIN)
    {
        return mem[i];
    }
    int a = DFSMaxSubArray_B(nums, numsSize, i - 1, mem);
    int tem = 0;
    if (a >= 0)
    {
        tem = a + nums[i];
    }
    else
    {
        tem = nums[i];
    }
    mem[i] = tem;
    return mem[i];
}

// 记忆化搜索
// Time: O(2^N)
// Space: O(N)
int MaxSubArray_B(int *nums, int numsSize)
{
    int ans = INT_MIN;
    int *mem = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        mem[i] = INT_MIN;
    }
    for (int i = 0; i < numsSize; i++)
    {
        int a = DFSMaxSubArray_B(nums, numsSize, i, mem);
        ans = max(ans, a);
    }
    free(mem);
    return ans;
}

// 动态规划
// Time:O(N)
// Space:O(N)
int MaxSubArray_C(int *nums, int numsSize)
{
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = nums[i];
        if (dp[i - 1] >= 0)
        {
            dp[i] += dp[i - 1];
        }
        ans = max(ans, dp[i]);
    }
    free(dp);
    return ans;
}

// 动态规划(空间压缩)
// Time:O(N)
// Space:O(1)
int MaxSubArray_D(int *nums, int numsSize)
{
    int a = nums[0];
    int ans = a;
    for (int i = 1; i < numsSize; i++)
    {
        int b = nums[i];
        if (a >= 0)
        {
            b += a;
        }
        ans = max(ans, b);
        a = b;
    }
    return ans;
}

// 贪心算法
// Time:O(N)
// Space:O(1)
int MaxSubArray_E(int *nums, int numsSize)
{
    int ans = nums[0];
    int tem = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (tem < 0)
        {
            tem = nums[i];
        }
        else
        {
            tem += nums[i];
        }
        ans = max(ans, tem);
    }
    return ans;
}