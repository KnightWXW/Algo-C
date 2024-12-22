#include "../Mybasic/mybasic.h"

//      LeetCode 152. 乘积最大子数组

//      链接：https://leetcode.cn/problems/maximum-product-subarray/

//      给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组
//      （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//      测试用例的答案是一个 32-位 整数。
//      示例 1:
//          输入: nums = [2,3,-2,4]
//          输出: 6
//          解释: 子数组 [2,3] 有最大乘积 6。
//      示例 2:
//          输入: nums = [-2,0,-1]
//          输出: 0
//          解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
//      提示:
//          1 <= nums.length <= 2 * 104
//          -10 <= nums[i] <= 10
//          nums 的任何子数组的乘积都 保证 是一个 32-位 整数

int MaxProduct(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(10, 10, n);
    PrintVecElement(vec, n);
    int ans_A = MaxProduct(vec, n);
    printf("该子数组所对应的乘积 为 %d.\n", ans_A);
    FreeVec(vec);
}

// 动态规划:
// Time:O(N)
// Space:O(1)
int MaxProduct(int *nums, int numsSize)
{
    int ans = nums[0];
    int minMul = nums[0];
    int maxMul = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        int temMin = minMul;
        int temMax = maxMul;
        maxMul = max(temMax * nums[i], max(temMax, temMin * nums[i]));
        minMul = min(temMin * nums[i], max(temMin, temMax * nums[i]));
        ans = max(ans, maxMul);
    }
    return ans;
}