#include "../Mybasic/mybasic.h"

//      LeetCode 740. 删除并获得点数

//      链接：https://leetcode.cn/problems/delete-and-earn/

//      给你一个整数数组 nums ，你可以对它进行一些操作。
//      每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。
//      之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
//      开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//      示例 1：
//          输入：nums = [3,4,2]
//          输出：6
//          解释：
//              删除 4 获得 4 个点数，因此 3 也被删除。
//              之后，删除 2 获得 2 个点数。总共获得 6 个点数。
//      示例 2：
//          输入：nums = [2,2,3,3,3,4]
//          输出：9
//          解释：
//              删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
//              之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
//              总共获得 9 个点数。
//      提示：
//          1 <= nums.length <= 2 * 104
//          1 <= nums[i] <= 104

int DeleteAndEarn_A(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ansA = DeleteAndEarn_A(vec, n);
    int ansB = DeleteAndEarn_B(vec, n);
    int ansC = DeleteAndEarn_C(vec, n);
    int ansD = DeleteAndEarn_D(vec, n);
    printf("暴力递归: 通过操作获得的最大点数 为 %d\n", ansB);
    printf("记忆化搜索: 通过操作获得的最大点数 为 %d\n", ansB);
    printf("动态规划: 通过操作获得的最大点数 为 %d\n", ansC);
    printf("动态规划(空间优化): 通过操作获得的最大点数 为 %d\n", ansD);
    FreeVec(vec);
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int DeleteAndEarn_A(int *nums, int numsSize)
{
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++)
    {
        maxVal = max(maxVal, nums[i]);
    }
    int *vec = (int *)malloc(sizeof(int) * (maxVal + 1));
    memset(vec, 0, sizeof(int) * (maxVal + 1));
    for (int i = 0; i < numsSize; i++)
    {
        vec[nums[i]] += nums[i];
    }
    int ans = DFSDeleteAndEarn_A(vec, maxVal + 1, maxVal);
    free(vec);
    return ans;
}

int DFSDeleteAndEarn_A(int *vec, int l, int i)
{
    if (i == 1)
    {
        return vec[1];
    }
    else if (i == 2)
    {
        return max(vec[1], vec[2]);
    }
    int a1 = DFSDeleteAndEarn_A(vec, l, i - 2) + vec[i];
    int a2 = DFSDeleteAndEarn_A(vec, l, i - 1);
    return max(a1, a2);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int DeleteAndEarn_B(int *nums, int numsSize)
{
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++)
    {
        maxVal = max(maxVal, nums[i]);
    }
    int *vec = (int *)malloc(sizeof(int) * (maxVal + 1));
    memset(vec, 0, sizeof(int) * (maxVal + 1));
    int *mem = (int *)malloc(sizeof(int) * (maxVal + 1));
    memset(mem, -1, sizeof(int) * (maxVal + 1));
    for (int i = 0; i < numsSize; i++)
    {
        vec[nums[i]] += nums[i];
    }
    int ans = DFSDeleteAndEarn_B(vec, maxVal + 1, maxVal, mem);
    free(mem);
    free(vec);
    return ans;
}

int DFSDeleteAndEarn_B(int *vec, int l, int i, int *mem)
{
    if (i == 1)
    {
        mem[i] = vec[1];
        return vec[1];
    }
    else if (i == 2)
    {
        mem[i] = max(vec[1], vec[2]);
        return mem[i];
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int a1 = DFSDeleteAndEarn_B(vec, l, i - 2, mem) + vec[i];
    int a2 = DFSDeleteAndEarn_B(vec, l, i - 1, mem);
    mem[i] = max(a1, a2);
    return mem[i];
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int DeleteAndEarn_C(int *nums, int numsSize)
{
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++)
    {
        maxVal = max(maxVal, nums[i]);
    }
    int *vec = (int *)malloc(sizeof(int) * (maxVal + 1));
    memset(vec, 0, sizeof(int) * (maxVal + 1));
    int *dp = (int *)malloc(sizeof(int) * (maxVal + 1));
    memset(dp, 0, sizeof(int) * (maxVal + 1));
    for (int i = 0; i < numsSize; i++)
    {
        vec[nums[i]] += nums[i];
    }
    if (maxVal == 1)
    {
        return vec[1];
    }
    else if (maxVal == 2)
    {
        max(vec[1], vec[2]);
    }
    dp[1] = vec[1];
    dp[2] = max(vec[1], vec[2]);
    for (int i = 2; i <= maxVal; i++)
    {
        dp[i] = max(dp[i - 2] + vec[i], dp[i - 1]);
    }
    int ans = dp[maxVal];
    free(vec);
    free(dp);
    return ans;
}