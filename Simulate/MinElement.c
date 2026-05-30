#include "../Mybasic/mybasic.h"

//      LeetCode 3300. 替换为数位和以后的最小元素

//      链接：https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/

//      给你一个整数数组 nums 。
//      请你将 nums 中每一个元素都替换为它的各个数位之 和 。
//      请你返回替换所有元素以后 nums 中的 最小 元素。
//      示例 1：
//          输入：nums = [10,12,13,14]
//          输出：1
//          解释：
//              nums 替换后变为 [1, 3, 4, 5] ，最小元素为 1 。
//      示例 2：
//          输入：nums = [1,2,3,4]
//          输出：1
//          解释：
//              nums 替换后变为 [1, 2, 3, 4] ，最小元素为 1 。
//      示例 3：
//          输入：nums = [999,19,199]
//          输出：10
//          解释：
//              nums 替换后变为 [27, 10, 19] ，最小元素为 10 。
//      提示：
//          1 <= nums.length <= 100
//          1 <= nums[i] <= 104

int MinElement(int *nums, int numsSize)

    int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ansA = MinElement(vec, n);
    printf("替换为数位和以后的最小元素 为: %d\n", ansA);
    FreeVec(vec);
}

// 模拟：
// Time: O(N)
// Space: O(1)
int MinElement(int *nums, int numsSize)
{
    int ans = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        int val = nums[i];
        int sum = 0;
        while (val != 0)
        {
            int tem = val % 10;
            val /= 10;
            sum += tem;
        }
        if (sum < ans)
        {
            ans = sum;
        }
    }
    return ans;
}