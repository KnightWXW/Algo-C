#include "../Mybasic/mybasic.h"

//      LeetCode 2974. 最小数字游戏

//      链接：https://leetcode.cn/problems/minimum-number-game/description/

//      你有一个下标从 0 开始、长度为 偶数 的整数数组 nums ，同时还有一个空数组 arr 。
//      Alice 和 Bob 决定玩一个游戏，游戏中每一轮 Alice 和 Bob 都会各自执行一次操作。
//      游戏规则如下：
//          每一轮，Alice 先从 nums 中移除一个 最小 元素，然后 Bob 执行同样的操作。
//          接着，Bob 会将移除的元素添加到数组 arr 中，然后 Alice 也执行同样的操作。
//          游戏持续进行，直到 nums 变为空。
//      返回结果数组 arr 。
//      示例 1：
//          输入：nums = [5,4,2,3]
//          输出：[3,2,5,4]
//          解释：第一轮，Alice 先移除 2 ，然后 Bob 移除 3 。
//              然后 Bob 先将 3 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [3,2] 。
//              第二轮开始时，nums = [5,4] 。Alice 先移除 4 ，然后 Bob 移除 5 。
//              接着他们都将元素添加到 arr 中，arr 变为 [3,2,5,4] 。
//      示例 2：
//          输入：nums = [2,5]
//          输出：[5,2]
//          解释：第一轮，Alice 先移除 2 ，然后 Bob 移除 5 。
//              然后 Bob 先将 5 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [5,2]。
//      提示：
//          1 <= nums.length <= 100
//          1 <= nums[i] <= 100
//          nums.length % 2 == 0

int *NumberGame(int *nums, int numsSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(0, 10);
    n *= 2;
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int rs = 0;
    int *ans_A = NumberGame(vec, n, &rs);
    printf("最小数字游戏 结果为 为: \n");
    PrintVecElement(ans_A, rs);
    FreeVec(vec);
    FreeVec(ans_A);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return *tema - *temb;
}

int *NumberGame(int *nums, int numsSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), CompareInt);
    *returnSize = numsSize;
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);
    memcpy(ans, nums, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i += 2)
    {
        int tem = ans[i];
        ans[i] = ans[i + 1];
        ans[i + 1] = tem;
    }
    return ans;
}