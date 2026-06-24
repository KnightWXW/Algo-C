#include "../Mybasic/mybasic.h"

//      LeetCode 330. 按要求补齐数组

//      链接：https://leetcode.cn/problems/patching-array/

//      给定一个已排序的正整数数组 nums，和一个正整数 n 。
//      从 [1, n] 区间内选取任意个数字补充到 nums 中，
//      使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。
//      请返回 满足上述要求的最少需要补充的数字个数 。
//      示例 1:
//          输入: nums = [1,3], n = 6
//          输出: 1
//          解释:
//              根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
//              现在如果我们将 2 添加到 nums 中，
//              组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
//              其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
//              所以我们最少需要添加一个数字。
//      示例 2:
//          输入: nums = [1,5,10], n = 20
//          输出: 2
//          解释: 我们需要添加 [2,4]。
//      示例 3:
//          输入: nums = [1,2,2], n = 5
//          输出: 0
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 104
//          nums 按 升序排列
//          1 <= n <= 231 - 1

int MinPatches(int *nums, int numsSize, int n);
int CompareInt(const void *a, const void *b);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int num = GenerateRandomNum(50, 100);
    int *vec = GenerateRandomVec(1, 50, n);
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int ans_A = MinPatches(vec, n, num);
    printf("正整数为 %d 时, 最少需要补充的数字个数为: %d\n", num, ans_A);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

// 贪心:
//   若选取数字为 1,2,4,8...2ⁿ(2 的幂次),子集和可以连续覆盖 1 ~ 2ⁿ⁺¹-1
// Time: O(N)
// Space: O(1)
int MinPatches(int *nums, int numsSize, int n)
{
    long k = 1;
    int ans = 0;
    int i = 0;
    while (k <= n)
    {
        if (i < numsSize && nums[i] <= k)
        {
            k += nums[i];
            i++;
        }
        else
        {
            k <<= 1;
            ans++;
        }
    }
    return ans;
}