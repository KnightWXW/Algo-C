#include "../Mybasic/mybasic.h"

//      LeetCode 1437. 是否所有 1 都至少相隔 k 个元素

//      链接：https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away/

//      给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。
//      如果所有 1 都至少相隔 k 个元素，则返回 true ；否则，返回 false 。
//      示例 1：
//          输入：nums = [1,0,0,0,1,0,0,1], k = 2
//          输出：true
//          解释：每个 1 都至少相隔 2 个元素。
//      示例 2：
//          输入：nums = [1,0,0,1,0,1], k = 2
//          输出：false
//          解释：第二个 1 和第三个 1 之间只隔了 1 个元素。
//      提示：
//          1 <= nums.length <= 105
//          0 <= k <= nums.length
//          nums[i] 的值为 0 或 1

bool KLengthApart(int *nums, int numsSize, int k);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int k = GenerateRandomNum(0, n);
    int *arr = GenerateRandomVec(0, 1, n);
    bool ans = KLengthApart(arr, n, k);
    PrintVecElement(arr, n);
    printf("是否所有 1 都至少相隔 k 个元素:\n");
    PrintBool(ans);
    FreeVec(arr);
}

// 模拟：
// Time: O(N)
// Space: O(1)
bool KLengthApart(int *nums, int numsSize, int k)
{
    int pre = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            if (pre != -1 && i - pre - 1 < k)
            {
                return false;
            }
            pre = i;
        }
    }
    return true;
}