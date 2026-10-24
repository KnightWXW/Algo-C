#include "../Mybasic/mybasic.h"

//      LeetCode 3727. 最大交替平方和

//      链接: https://leetcode.cn/problems/maximum-alternating-sum-of-squares

//      给你一个整数数组 nums。你可以以任意顺序 重新排列元素 。
//      数组 arr 的 交替得分 定义为：
//          score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
//      在对 nums 重新排列后，返回其 最大可能的交替得分。
//      示例 1：
//          输入： nums = [1,2,3]
//          输出： 12
//          解释：
//              nums 的一种可行重排为 [2,1,3]，该排列在所有可能重排中给出了最大交替得分。
//              交替得分计算如下：
//                  score = 22 - 12 + 32 = 4 - 1 + 9 = 12
//      示例 2：
//          输入： nums = [1,-1,2,-2,3,-3]
//          输出： 16
//          解释：
//              nums 的一种可行重排为 [-3,-1,-2,1,3,2]，该排列在所有可能重排中给出了最大交替得分。
//              交替得分计算如下：
//                  score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16
//      提示：
//          1 <= nums.length <= 105
//          -4 * 104 <= nums[i] <= 4 * 104

long long MaxAlternatingSum_A(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 30, n);
    printf("数组元素为：\n");
    PrintVecElement(vec, n);
    long long ans_A = MaxAlternatingSum_A(vec, n);
    printf("最大交替平方和 为 %lld\n", ans_A);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return abs(*tema) - abs(*temb);
}

// 贪心
// Time: O(NlogN)
// Space: O(1)
long long MaxAlternatingSum_A(int *nums, int numsSize)
{
    long long ans = 0;
    qsort(nums, numsSize, sizeof(int), CompareInt);
    for (int i = 0; i < numsSize / 2; i++)
    {
        ans -= (nums[i] * nums[i]);
    }
    for (int i = numsSize / 2; i < numsSize; i++)
    {
        ans += (nums[i] * nums[i]);
    }
    return ans;
}