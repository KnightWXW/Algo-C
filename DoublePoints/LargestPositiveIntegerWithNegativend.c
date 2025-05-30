#include "../Mybasic/mybasic.h"

//      LeetCode 2441. 与对应负数同时存在的最大正整数

//      链接：https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/

//      给你一个 不包含 任何零的整数数组 nums，
//      找出自身与对应的负数都在数组中存在的最大正整数 k。
//      返回正整数 k，如果不存在这样的整数，返回 -1。
//      示例 1：
//          输入：nums = [-1,2,-3,3]
//          输出：3
//          解释：3 是数组中唯一一个满足题目要求的 k 。
//      示例 2：
//          输入：nums = [-1,10,6,7,-7,1]
//          输出：7
//          解释：数组中存在 1 和 7 对应的负数，7 的值更大。
//      示例 3：
//          输入：nums = [-10,8,6,7,-2,-3]
//          输出：-1
//          解释：不存在满足题目要求的 k ，返回 -1 。
//      提示：
//          1 <= nums.length <= 1000
//          -1000 <= nums[i] <= 1000
//          nums[i] != 0

int LargestPositiveIntegerWithNegativend_A(int* nums, int l);
int LargestPositiveIntegerWithNegativend_B(int* nums, int l);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int* vec_A = GenerateRandomVec(-100, 100, n);
    PrintVecElement(vec_A, n);
    int ans_A = LargestPositiveIntegerWithNegativend_A(vec_A, n);
    int ans_B = LargestPositiveIntegerWithNegativend_B(vec_A, n);
    printf("自身与对应的负数都在数组中存在的最大正整数 为 %d\n", ans_A);
    printf("自身与对应的负数都在数组中存在的最大正整数 为 %d\n", ans_B);
}

int LargestPositiveIntegerWithNegativend_A(int* nums, int l)
{
    
}

int LargestPositiveIntegerWithNegativend_B(int* nums, int l)
{
    
}