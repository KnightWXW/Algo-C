#include "../Mybasic/mybasic.h"

//      LeetCode 1480. 一维数组的动态和

//      链接：https://leetcode.cn/problems/running-sum-of-1d-array/

//      给你一个数组 nums 。
//      数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
//      请返回 nums 的动态和。
//      示例 1：
//          输入：nums = [1,2,3,4]
//          输出：[1,3,6,10]
//          解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
//      示例 2：
//          输入：nums = [1,1,1,1,1]
//          输出：[1,2,3,4,5]
//          解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
//      示例 3：
//          输入：nums = [3,1,2,10,1]
//          输出：[3,4,6,16,17]
//      提示：
//          1 <= nums.length <= 1000
//          -10^6 <= nums[i] <= 10^6

int *RunningSum(int *nums, int numsSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(-100, 100, n);
    PrintVecElement(vec, n);
    int rs = 0;
    int *ans_A = RunningSum(vec, n, &rs);
    printf("一维数组的动态和 为: \n");
    PrintVecElement(ans_A, rs);
    FreeVec(vec);
    FreeVec(ans_A);
}

// 前缀和：
// Time: O(N)
// Space: O(1)
int *RunningSum(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);
    ans[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        ans[i] = ans[i - 1] + nums[i];
    }
    *returnSize = numsSize;
    return ans;
}