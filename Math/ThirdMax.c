#include "../Mybasic/mybasic.h"

//      LeetCode 414. 第三大的数

//      链接：https://leetcode.cn/problems/third-maximum-number/

//      给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
//      示例 1：
//          输入：[3, 2, 1]
//          输出：1
//          解释：第三大的数是 1 。
//      示例 2：
//          输入：[1, 2]
//          输出：2
//          解释：第三大的数不存在, 所以返回最大的数 2 。
//      示例 3：
//          输入：[2, 2, 3, 1]
//          输出：1
//          解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
//              此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
//      提示：
//          1 <= nums.length <= 104
//          -231 <= nums[i] <= 231 - 1
//      进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？

int ThirdMax_A(int *nums, int numsSize);
int ThirdMax_B(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(-1000, 1000, n);
    PrintVecElement(vec, n);
    int ans_A = ThirdMax_A(vec, n);
    int ans_B = ThirdMax_B(vec, n);
    printf("此数组中 第三大的数 为 %d.\n", ans_A);
    printf("此数组中 第三大的数 为 %d.\n", ans_B);
}

int CompareThirdMax(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

// 排序:
// Time: O(NlogN)
// Space: O(logN)
int ThirdMax_A(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), CompareThirdMax);
    int cnt = 0;
    int cur = nums[0];
    int index = 1;
    while (index < numsSize)
    {
        if (nums[index] != cur)
        {
            cur = nums[index];
            cnt++;
        }
        index++;
        if (cnt == 2)
        {
            return cur;
        }
    }
    return nums[0];
}

// 一次遍历统计:
// Time: O(N)
// Space: O(1)
int ThirdMax_B(int *nums, int numsSize)
{
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < third)
        {
            continue;
        }
        else if (nums[i] > third && nums[i] < second)
        {
            third = nums[i];
        }
        else if (nums[i] > second && nums[i] < first)
        {
            third = second;
            second = nums[i];
        }
        else if (nums[i] > first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
    }
    return third == LONG_MIN ? first : third;
}