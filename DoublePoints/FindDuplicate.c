#include "../Mybasic/mybasic.h"

//      LeetCode 287. 寻找重复数

//      链接：https://leetcode.cn/problems/find-the-duplicate-number/

//      给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），
//      可知至少存在一个重复的整数。
//      假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
//      你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
//      示例 1：
//          输入：nums = [1,3,4,2,2]
//          输出：2
//      示例 2：
//          输入：nums = [3,1,3,4,2]
//          输出：3
//      示例 3 :
//          输入：nums = [3,3,3,3,3]
//          输出：3
//      提示：
//          1 <= n <= 105
//          nums.length == n + 1
//          1 <= nums[i] <= n
//          nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
//      进阶：
//          如何证明 nums 中至少存在一个重复的数字?
//          你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？

int FindDuplicate(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, n - 1, n);
    PrintVecElement(vec, n);
    int ans = FindDuplicate(vec, n);
    printf("nums 中 重复的数 为: %d。\n", ans);
    FreeVec(vec);
}

// 快慢双指针:
// Time: O(N)
// Space: O(1)
int FindDuplicate(int *nums, int numsSize)
{
    int slow = 0;
    int fast = 0;
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}