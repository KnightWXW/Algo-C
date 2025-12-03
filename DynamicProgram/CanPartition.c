#include "../Mybasic/mybasic.h"

//      LeetCode 416. 分割等和子集

//      链接: https://leetcode.cn/problems/partition-equal-subset-sum/

//      给你一个 只包含正整数 的 非空 数组 nums
//      请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//      示例 1：
//          输入：nums = [1,5,11,5]
//          输出：true
//          解释：数组可以分割成 [1, 5, 5] 和 [11]
//      示例 2：
//          输入：nums = [1,2,3,5]
//          输出：false
//          解释：数组不能分割成两个元素和相等的子集。
//      提示：
//          1 <= nums.length <= 200
//          1 <= nums[i] <= 100

bool CanPartition_A(int* nums, int numsSize);
bool CanPartition_B(int* nums, int numsSize);
bool CanPartition_C(int* nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *nums = GenerateRandomVec(1, 100, n);
    PrintVecElement(nums, n);
    bool ans1A = CanPartition_A(nums, n);
    bool ans1B = CanPartition_B(nums, n);
    bool ans1C = CanPartition_C(nums, n);
    printf("暴力递归: 是否可以分割等和子集?\n");
    PrintBool(ans1A);
    printf("记忆化搜索: 是否可以分割等和子集?\n");
    PrintBool(ans1B);
    printf("动态规划: 是否可以分割等和子集?\n");
    PrintBool(ans1C);
    FreeVec(nums);
}

bool CanPartition_A(int* nums, int numsSize)
{
    
}