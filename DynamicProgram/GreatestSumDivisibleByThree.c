#include "../Mybasic/mybasic.h"

//      LeetCode 1262. 可被三整除的最大和

//      链接：https://leetcode.cn/problems/greatest-sum-divisible-by-three/

//      给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
//      示例 1：
//          输入：nums = [3,6,5,1,8]
//          输出：18
//          解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
//      示例 2：
//          输入：nums = [4]
//          输出：0
//          解释：4 不能被 3 整除，所以无法选出数字，返回 0。
//      示例 3：
//          输入：nums = [1,2,3,4,4]
//          输出：12
//          解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
//      提示：
//          1 <= nums.length <= 4 * 10^4
//          1 <= nums[i] <= 10^4
int DFSMaxSumDivThree_A(int *nums, int l, int len, int sum);
int MaxSumDivThree_A(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *nums = GenerateRandomVec(0, 20, n);
    PrintVecElement(nums, n);
    int ansA = MaxSumDivThree_A(nums, n);
    int ansB = MaxSumDivThree_B(nums, n);
    int ansC = MaxSumDivThree_C(nums, n);
    printf("(暴力递归<一>) 数组中能被三整除的元素最大和 为 %d \n", ansA);
    printf("(记忆化搜索<一>) 数组中能被三整除的元素最大和 为 %d \n", ansB);
}