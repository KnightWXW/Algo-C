#include "../Mybasic/mybasic.h"

//      LeetCode 26. 删除有序数组中的重复项

//      链接: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

//      给你一个 非严格递增排列 的数组 nums，
//      请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//      元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
//      考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。
//      nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
//      示例 1：
//          输入：nums = [1,1,2]
//          输出：2, nums = [1,2,_]
//          解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
//      示例 2：
//          输入：nums = [0,0,1,1,1,2,2,3,3,4]
//          输出：5, nums = [0,1,2,3,4,_,_,_,_,_]
//          解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
//      提示：
//          1 <= nums.length <= 3 * 104
//          -100 <= nums[i] <= 100
//          nums 已按 非递减 顺序排列。

int RemoveDuplicates(int *nums, int numsSize);
int CompareInt(const void *a, const void *b);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 9, n);
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int ans = RemoveDuplicates(vec, n);
    printf("删除有序数组中的重复项后为：\n");
    PrintVecElement(vec, ans);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

// 双指针:快慢指针
// Time: O(N)
// Space: O(1)
int RemoveDuplicates(int *nums, int numsSize)
{
    int slow = 1;
    for (int fast = 0; fast < numsSize - 1; fast++)
    {
        if (nums[fast] != nums[fast + 1])
        {
            nums[slow++] = nums[fast + 1];
        }
    }
    return slow;
}