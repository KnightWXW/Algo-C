#include "../Mybasic/mybasic.h"

//      LeetCode 3190. 使所有元素都可以被 3 整除的最少操作数

//      链接：https://leetcode.cn/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

//      给你一个整数数组 nums 。一次操作中，你可以将 nums 中的 任意 一个元素增加或者减少 1 。
//      请你返回将 nums 中所有元素都可以被 3 整除的 最少 操作次数。
//      示例 1：
//          输入：nums = [1,2,3,4]
//          输出：3
//          解释：
//              通过以下 3 个操作，数组中的所有元素都可以被 3 整除：
//              将 1 减少 1 。
//              将 2 增加 1 。
//              将 4 减少 1 。
//      示例 2：
//          输入：nums = [3,6,9]
//          输出：0
//      提示：
//          1 <= nums.length <= 50
//          1 <= nums[i] <= 50

int MinimumOperations(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *arr = GenerateRandomVec(0, 100, n);
    int ans = MinimumOperations(arr, n);
    PrintVecElement(arr, n);
    printf("使所有元素都可以被 3 整除的最少操作数 为 %d\n", ans);
    FreeVec(arr);
}

// 模拟：
// Time: O(N)
// Space: O(1)
int MinimumOperations(int *nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int tem = nums[i] % 3;
        ans += (fmin(tem, 3 - tem));
    }
    return ans;
}