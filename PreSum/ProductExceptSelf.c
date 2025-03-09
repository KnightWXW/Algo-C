#include "../Mybasic/mybasic.h"

//      LeetCode 238. 除自身以外数组的乘积

//      链接：https://leetcode.cn/problems/product-of-array-except-self/

//      给你一个整数数组 nums，返回 数组 answer，
//      其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//      题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内。
//      请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//      示例 1:
//          输入: nums = [1,2,3,4]
//          输出: [24,12,8,6]
//      示例 2:
//          输入: nums = [-1,1,0,-3,3]
//          输出: [0,0,9,0,0]
//      提示：
//          2 <= nums.length <= 105
//          -30 <= nums[i] <= 30
//      保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内
//      进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？
//      （ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

int *ProductExceptSelf_A(int *nums, int numsSize, int *returnSize);
int *ProductExceptSelf_B(int *nums, int numsSize, int *returnSize);
int *ProductExceptSelf_C(int *nums, int numsSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(-30, 30, n);
    PrintVecElement(vec, n);
    int returnLenA = 0;
    int *ans_A = ProductExceptSelf_A(vec, n, &returnLenA);
    int returnLenB = 0;
    int *ans_B = ProductExceptSelf_B(vec, n, &returnLenB);
    int returnLenC = 0;
    int *ans_C = ProductExceptSelf_C(vec, n, &returnLenC);
    int returnLenD = 0;
    int *ans_D = ProductExceptSelf_C(vec, n, &returnLenD);
    printf("除自身以外数组的乘积 为：\n");
    PrintVecElement(ans_A, returnLenA);
    PrintVecElement(ans_B, returnLenB);
    PrintVecElement(ans_C, returnLenC);
    PrintVecElement(ans_D, returnLenD);
    FreeVec(ans_A);
    FreeVec(ans_B);
    FreeVec(ans_C);
    FreeVec(ans_D);
}

// 前缀积：两个辅助数组
// Time: O(N)
// Space: O(N)
int *ProductExceptSelf_A(int *nums, int numsSize, int *returnSize)
{
    int *left = (int *)malloc(sizeof(int) * numsSize);
    memset(left, 0, sizeof(int) * numsSize);
    left[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    int *right = (int *)malloc(sizeof(int) * numsSize);
    memset(right, 0, sizeof(int) * numsSize);
    right[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = left[i] * right[i];
    }
    free(left);
    free(right);
    *returnSize = numsSize;
    return ans;
}

// 前缀积：一个辅助数组
// Time: O(N)
// Space: O(N)
int *ProductExceptSelf_B(int *nums, int numsSize, int *returnSize)
{
    int *left = (int *)malloc(sizeof(int) * numsSize);
    memset(left, 0, sizeof(int) * numsSize);
    left[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    int right = 1;
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);
    for (int i = numsSize - 1; i >= 0; i--)
    {
        ans[i] = left[i] * right;
        right *= nums[i];
    }
    free(left);
    *returnSize = numsSize;
    return ans;
}

// 前缀积：零个辅助数组
// Time: O(N)
// Space: O(1)
int *ProductExceptSelf_C(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);
    ans[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        ans[i] *= right;
        right *= nums[i];
    }
    *returnSize = numsSize;
    return ans;
}

// 分情况讨论：0 的个数
// Time: O(N)
// Space: O(1)
int *ProductExceptSelf_D(int *nums, int numsSize, int *returnSize)
{
    int zero = 0;
    int zeroIndex = -1;
    int mul = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            zero++;
            zeroIndex = i;
        }
        mul *= nums[i];
    }
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);
    *returnSize = numsSize;
    if (zero == 0)
    {
        for (int i = 0; i < numsSize; i++)
        {
            ans[i] = mul / nums[i];
        }
    }
    else if (zero == 1)
    {
        mul = 1;
        for (int i = 0; i < numsSize; i++)
        {
            if (i != zeroIndex)
            {
                mul *= nums[i];
            }
        }
        ans[zeroIndex] = mul;
    }
    return ans;
}