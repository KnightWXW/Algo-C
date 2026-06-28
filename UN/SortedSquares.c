#include "../Mybasic/mybasic.h"

//      LeetCode 977. 有序数组的平方

//      链接: https://leetcode.cn/problems/squares-of-a-sorted-array/

//      给你一个按 非递减顺序 排序的整数数组 nums，
//      返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//      示例 1：
//          输入：nums = [-4,-1,0,3,10]
//          输出：[0,1,9,16,100]
//          解释：平方后，数组变为 [16,1,0,9,100]
//              排序后，数组变为 [0,1,9,16,100]
//      示例 2：
//          输入：nums = [-7,-3,2,3,11]
//          输出：[4,9,9,49,121]
//      提示：
//          1 <= nums.length <= 104
//          -104 <= nums[i] <= 104
//          nums 已按 非递减顺序 排序

int CompareInt(const void *a, const void *b);
int *SortedSquares(int *nums, int numsSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(-100, 100, n);
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int returnSize = 0;
    int *ans_A = SortedSquares(vec, n, &returnSize);
    printf("有序数组的平方为：\n");
    PrintVecElement(ans_A, returnSize);
    FreeVec(vec);
    FreeVec(ans_A);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return *tema - *temb;
}

// 排序：
// Time: O(NlogN)
// Space: O(logN)
int *SortedSquares(int *nums, int numsSize, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] *= nums[i];
    }
    qsort(nums, numsSize, sizeof(int), CompareInt);
    *returnSize = numsSize;
    return nums;
}