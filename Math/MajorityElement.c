#include "../Mybasic/mybasic.h"

//      LeetCode 229. 多数元素 II

//      链接：https://leetcode.cn/problems/majority-element-ii/

//      给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n / 3 ⌋ 次的元素。
//      示例 1：
//          输入：nums = [3,2,3]
//          输出：[3]
//      示例 2：
//          输入：nums = [1]
//          输出：[1]
//      示例 3：
//          输入：nums = [1,2]
//          输出：[1,2]
//      提示：
//          1 <= nums.length <= 5 * 104
//          -109 <= nums[i] <= 109
//      进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

int* MajorityElement_A(int* nums, int numsSize, int* returnSize);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int* arr = GenerateRandomVec(0, 100, n);
    printf("arr数组 元素为: ");
    PrintVecElement(arr, n);
    int la = 0;
    int* ans_A = MajorityElement_A(arr, n, &la);
    printf("所有出现超过 ⌊ n/3 ⌋ 次的元素为: \n");
    PrintVecElement(ans_A, la);
    FreeVec(ans_A);
}

int* MajorityElement_A(int* nums, int numsSize, int* returnSize)
{
    
}