#include "../Mybasic/mybasic.h"

//      LeetCode 300. 最长递增子序列

//      链接：https://leetcode.cn/problems/longest-increasing-subsequence/

//      给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//      子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
//      例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
//      示例 1：
//          输入：nums = [10,9,2,5,3,7,101,18]
//          输出：4
//          解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//      示例 2：
//          输入：nums = [0,1,0,3,2,3]
//          输出：4
//      示例 3：
//          输入：nums = [7,7,7,7,7,7,7]
//          输出：1
//      提示：
//          1 <= nums.length <= 2500
//          -104 <= nums[i] <= 104
//      进阶：
//          你能将算法的时间复杂度降低到 O(n log(n)) 吗?

int LengthOfLIS_A(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *nums = GenerateRandomVec(-100, 100, n);
    PrintVecElement(nums, n);
    int ansA = LengthOfLIS_A(nums, n);
    int ansB = LengthOfLIS_B(nums, n);
    int ansC = LengthOfLIS_C(nums, n);
    printf("暴力递归: 最长递增子序列 长度 为 %d \n", ansA);
    printf("记忆化搜索: 最长递增子序列 长度 为 %d \n", ansB);
    FreeVec(nums);
}

// 动态规划:
// Time: O(N)
// Space: O(N)
int LengthOfLIS_A(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }
    return DFSLengthOfLIS_A(nums, numsSize, numsSize - 1);
}

int DFSLengthOfLIS_A(int *nums, int numsSize, int i)
{
    if (i == 0)
    {
        return 1;
    }
}