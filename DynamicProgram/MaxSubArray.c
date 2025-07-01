#include "../Mybasic/mybasic.h"

//      LeetCode 53. 最大子数组和

//      链接：https://leetcode.cn/problems/maximum-subarray/

//      给你一个整数数组 nums，
//      请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
//      返回其最大和。
//      子数组 是数组中的一个连续部分。
//      示例 1：
//          输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//          输出：6
//          解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
//      示例 2：
//          输入：nums = [1]
//          输出：1
//      示例 3：
//          输入：nums = [5,4,-1,7,8]
//          输出：23
//      提示：
//          1 <= nums.length <= 105
//          -104 <= nums[i] <= 104

int MaxSubArray_A(int* nums, int numsSize);
int DFSMaxSubArray_A(int* nums, int numsSize);
int main()
{
    int n = GenerateRandomNum(0, 20);
    int* vec = GenerateRandomVec(-100, 100, n);
    int ansA = MaxSubArray_A(vec, n);
    PrintVecElement(vec, n);
    printf("(暴力递归)连续子数组的最大和为 %d \n", );
    printf("(记忆化搜索)连续子数组的最大和为 %d \n", maxSubArray_B(vec));
    printf("(动态规划)连续子数组的最大和为 %d \n", maxSubArray_C(vec));
    printf("(动态规划[空间压缩])连续子数组的最大和为 %d \n", maxSubArray_D(vec));
    printf("(贪心算法)连续子数组的最大和为 %d \n", maxSubArray_E(vec));
    FreeVec(vec);
}