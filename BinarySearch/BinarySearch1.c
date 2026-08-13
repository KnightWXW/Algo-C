#include "../Mybasic/mybasic.h"

//      LeetCode 704. 二分查找

//      链接: https://leetcode.cn/problems/binary-search/

//      给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
//      写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。
//      你必须编写一个具有 O(log n) 时间复杂度的算法。
//      示例 1:
//          输入: nums = [-1,0,3,5,9,12], target = 9
//          输出: 4
//          解释: 9 出现在 nums 中并且下标为 4
//      示例 2:
//          输入: nums = [-1,0,3,5,9,12], target = 2
//          输出: -1
//          解释: 2 不存在 nums 中因此返回 -1
//      提示：
//          你可以假设 nums 中的所有元素是不重复的。
//          n 将在 [1, 10000]之间。
//          nums 的每个元素都将在 [-9999, 9999]之间。

int BinarySearch(int* nums, int numsSize, int target);

int CompareInt(const void *a, const void *b);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 100, n);
    int target = vec[0];
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int ans = BinarySearch(vec, n, target);
    printf("数组中查找 等于 %d 的元素 所在的索引位置 为: %d\n", target, ans);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

int BinarySearch(int* nums, int numsSize, int target)
{
    
}