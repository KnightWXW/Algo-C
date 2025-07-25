#include "../Mybasic/mybasic.h"

//      LeetCode 2799. 统计完全子数组的数目

//      链接：https://leetcode.cn/problems/count-complete-subarrays-in-an-array/

//      给你一个由 正 整数组成的数组 nums 。
//      如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：
//      子数组中 不同 元素的数目等于整个数组不同元素的数目。
//      返回数组中 完全子数组 的数目。
//      子数组 是数组中的一个连续非空序列。
//      示例 1：
//          输入：nums = [1,3,1,2,2]
//          输出：4
//          解释：完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
//      示例 2：
//          输入：nums = [5,5,5,5]
//          输出：10
//          解释：数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。
//              子数组的总数为 10 。
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 2000

int CountCompleteSubarrays(int* nums, int l);

int main()
{
    int n = GenerateRandomNum(0, 50);
    int* vec = GenerateRandomVec(0, 5, n);
    PrintVecElement(vec, n);
    int ans_A = CountCompleteSubarrays(vec, n);
    printf("数组中完全子数组的数目 为 %d。\n", ans_A);
}

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int CountCompleteSubarrays(int* nums, int l)
{
    
}