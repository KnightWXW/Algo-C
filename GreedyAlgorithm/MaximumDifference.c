#include "../Mybasic/mybasic.h"

//      LeetCode 2016. 增量元素之间的最大差值

//      链接：https://leetcode.cn/problems/maximum-difference-between-increasing-elements/

//      给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，
//      请你计算 nums[j] - nums[i] 能求得的 最大差值 ，
//      其中 0 <= i < j < n 且 nums[i] < nums[j] 。
//      返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1。
//      示例 1：
//          输入：nums = [7,1,5,4]
//          输出：4
//          解释：
//              最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
//              注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
//      示例 2：
//          输入：nums = [9,4,3,2]
//          输出：-1
//          解释：
//              不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
//      示例 3：
//          输入：nums = [1,5,2,10]
//          输出：9
//          解释：
//              最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
//      提示：
//          n == nums.length
//          2 <= n <= 1000
//          1 <= nums[i] <= 109

int MaximumDifference(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ans_A = MaximumDifference(vec, n);
    printf("nums 中 增量元素之间的最大差值 为: %d\n", ans_A);
    FreeVec(vec);
}

// 贪心
// Time: O(N)
// Space: O(1)
int MaximumDifference(int *nums, int numsSize)
{
    int ans = -1;
    int minVal = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > minVal)
        {
            ans = max(ans, nums[i] - minVal);
        }
        else
        {
            minVal = nums[i];
        }
    }
    return ans;
}