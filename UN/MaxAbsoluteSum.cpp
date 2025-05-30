#include "../Mybasic/mybasic.h"

//      LeetCode 1749. 任意子数组和的绝对值的最大值

//      链接：https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/

//      给你一个整数数组 nums。
//      一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为
//      abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。
//      请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值。
//      abs(x) 定义如下：
//          如果 x 是负整数，那么 abs(x) = -x。
//          如果 x 是非负整数，那么 abs(x) = x。
//      示例 1：
//          输入：nums = [1,-3,2,3,-4]
//          输出：5
//          解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5。
//      示例 2：
//          输入：nums = [2,-5,1,-4,3,-2]
//          输出：8
//          解释：子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8。
//      提示：
//          1 <= nums.length <= 105
//          -104 <= nums[i] <= 104

int MaxAbsoluteSum(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(-1000, 1000, n);
    PrintVecElement(vec);
    int ans_A = MaxAbsoluteSum(vec, n);
    printf("和的绝对值 最大的任意子数组, 该值为: %d\n", ans_A);
    FreeVec(vec);
}

// 贪心：
// Time：O(N)
// Space: O(1)
int MaxAbsoluteSum(int *nums, int numsSize)
{
    int ans = 0;
    int a = 0;
    int b = 0;
    int cur = 0;
    for (int i = 0; i < numsSize; i++)
    {
        cur += nums[i];
        if (cur < 0)
        {
            cur = 0;
        }
        a = max(a, cur);
    }
    cur = 0;
    for (int i = 0; i < numsSize; i++)
    {
        cur += nums[i];
        if (cur > 0)
        {
            cur = 0;
        }
        b = max(b, -cur);
    }
    return max(a, b);
}