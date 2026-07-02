#include "../Mybasic/mybasic.h"

//      LeetCode 31. 下一个排列

//      链接：https://leetcode.cn/problems/next-permutation/

//      整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

//      例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：
//          [1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
//      整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
//      更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
//      那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
//      如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
//          例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
//          类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
//      而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
//      给你一个整数数组 nums ，找出 nums 的下一个排列。
//      必须 原地 修改，只允许使用额外常数空间。
//      示例 1：
//          输入：nums = [1,2,3]
//          输出：[1,3,2]
//      示例 2：
//          输入：nums = [3,2,1]
//          输出：[1,2,3]
//      示例 3：
//          输入：nums = [1,1,5]
//          输出：[1,5,1]
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 100

void NextPermutation(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *arr = GenerateRandomVec(0, 100, n);
    PrintVecElement(arr, n);
    NextPermutation(arr, n);
    printf("下一个排列 为:\n");
    PrintVecElement(arr, n);
    FreeVec(arr);
}

// 两数交换
void swap(int *a, int *b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}

// 反转数组
void reverse(int *vec, int i, int j)
{
    while (i <= j)
    {
        swap(&vec[i], &vec[j]);
        i++;
        j--;
    }
}

// 双指针:
// Time: O(N)
// Space: O(1)
void NextPermutation(int *nums, int numsSize)
{
    // 从右往左找第一个「左侧小于右侧」的下标 i
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }
    if (i >= 0)
    {
        // 从最右侧往左找第一个比 nums [i] 大的数,下标 j
        int j = numsSize - 1;
        while (nums[j] <= nums[i])
        {
            j--;
        }
        // 交换 i, j 位置的两数
        swap(&nums[i], &nums[j]);
    }
    // 反转 i 位置右侧的数组
    reverse(nums, i + 1, numsSize - 1);
}