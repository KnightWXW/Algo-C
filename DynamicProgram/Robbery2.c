#include "../Mybasic/mybasic.h"

//      LeetCode 213. 打家劫舍 II

//      链接: https://leetcode.cn/problems/house-robber-ii/

//      你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
//      这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//      同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
//      给定一个代表每个房屋存放金额的非负整数数组，
//      计算你 在不触动警报装置的情况下，今晚能够偷窃到的最高金额。
//      示例 1：
//          输入：nums = [2,3,2]
//          输出：3
//          解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）,
//               因为他们是相邻的。
//      示例 2：
//          输入：nums = [1,2,3,1]
//          输出：4
//          解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//              偷窃到的最高金额 = 1 + 3 = 4 。
//      示例 3：
//          输入：nums = [1,2,3]
//          输出：3
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 1000

int Robbery2_A(int *nums, int numsSize);
int DFSRobbery2_A(int *nums, int l, int i);
int Robbery2_B(int *nums, int numsSize);
int DFSRobbery2_B(int *nums, int l, int i, int *mem);
int Robbery2_C(int *nums, int numsSize);
int DPRobbery2_C(int *nums, int numsSize);
int Robbery2_D(int *nums, int numsSize);
int DPRobbery2_D(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ansA = Robbery2_A(vec, n);
    int ansB = Robbery2_B(vec, n);
    int ansC = Robbery2_C(vec, n);
    int ansD = Robbery2_D(vec, n);
    printf("暴力递归: 一夜之内能够偷窃到的最高金额 为 %d\n", ansB);
    printf("记忆化搜索: 一夜之内能够偷窃到的最高金额 为 %d\n", ansB);
    printf("动态规划 一夜之内能够偷窃到的最高金额 为 %d\n", ansC);
    printf("动态规划(空间优化): 一夜之内能够偷窃到的最高金额 为 %d\n", ansD);
    FreeVec(vec);
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int Robbery2_A(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int *arr1 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr1, nums, sizeof(int) * (numsSize - 1));
    int *arr2 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr2, nums + 1, sizeof(int) * (numsSize - 1));
    int a1 = DFSRobbery2_A(arr1, numsSize - 1, numsSize - 2);
    int a2 = DFSRobbery2_A(arr2, numsSize - 1, numsSize - 2);
    int ans = max(a1, a2);
    free(arr1);
    free(arr2);
    return ans;
}

int DFSRobbery2_A(int *nums, int l, int i)
{
    if (i == 0)
    {
        return nums[0];
    }
    if (i == 1)
    {
        return max(nums[0], nums[1]);
    }
    return max(DFSRobbery2_A(nums, l, i - 1), DFSRobbery2_A(nums, l, i - 2) + nums[i]);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int Robbery2_B(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int *arr1 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr1, nums, sizeof(int) * (numsSize - 1));
    int *arr2 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr2, nums + 1, sizeof(int) * (numsSize - 1));
    int *mem1 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memset(mem1, -1, sizeof(int) * (numsSize - 1));
    int *mem2 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memset(mem2, -1, sizeof(int) * (numsSize - 1));
    int a1 = DFSRobbery2_B(arr1, numsSize - 1, numsSize - 2, mem1);
    int a2 = DFSRobbery2_B(arr2, numsSize - 1, numsSize - 2, mem2);
    int ans = max(a1, a2);
    free(arr1);
    free(arr2);
    free(mem1);
    free(mem2);
    return ans;
}

int DFSRobbery2_B(int *nums, int l, int i, int *mem)
{
    if (i == 0)
    {
        mem[0] = nums[0];
        return nums[0];
    }
    if (i == 1)
    {
        mem[1] = max(nums[0], nums[1]);
        return max(nums[0], nums[1]);
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int a1 = DFSRobbery2_B(nums, l, i - 1, mem);
    int a2 = DFSRobbery2_B(nums, l, i - 2, mem) + nums[i];
    mem[i] = max(a1, a2);
    return max(a1, a2);
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int Robbery2_C(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int *arr1 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr1, nums, sizeof(int) * (numsSize - 1));
    int *arr2 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr2, nums + 1, sizeof(int) * (numsSize - 1));
    int a1 = DPRobbery2_C(arr1, numsSize - 1);
    int a2 = DPRobbery2_C(arr2, numsSize - 1);
    int ans = max(a1, a2);
    free(arr1);
    free(arr2);
    return ans;
}

int DPRobbery2_C(int *nums, int numsSize)
{
    int *dp = (int *)malloc(sizeof(int) * (numsSize));
    memset(dp, 0, sizeof(int) * (numsSize));
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int ans = dp[numsSize - 1];
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N)
// Space: O(N)
int Robbery2_D(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int *arr1 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr1, nums, sizeof(int) * (numsSize - 1));
    int *arr2 = (int *)malloc(sizeof(int) * (numsSize - 1));
    memcpy(arr2, nums + 1, sizeof(int) * (numsSize - 1));
    int a1 = DPRobbery2_C(arr1, numsSize - 1);
    int a2 = DPRobbery2_C(arr2, numsSize - 1);
    int ans = max(a1, a2);
    free(arr1);
    free(arr2);
    return ans;
}

int DPRobbery2_D(int *nums, int numsSize)
{
    int a = nums[0];
    int b = max(nums[0], nums[1]);
    int c = 0;
    for (int i = 2; i < numsSize; i++)
    {
        c = max(b, a + nums[i]);
        a = b;
        b = c;
    }
    int ans = b;
    return ans;
}