#include "../Mybasic/mybasic.h"

//      LeetCode 2860. 让所有学生保持开心的分组方法数

//      链接：https://leetcode.cn/problems/happy-students/

//      给你一个下标从 0 开始、长度为 n 的整数数组 nums ，
//      其中 n 是班级中学生的总数。班主任希望能够在让所有学生保持开心的情况下选出一组学生：
//      如果能够满足下述两个条件之一，则认为第 i 位学生将会保持开心：
//      这位学生被选中，并且被选中的学生人数 严格大于 nums[i] 。
//      这位学生没有被选中，并且被选中的学生人数 严格小于 nums[i] 。
//      返回能够满足让所有学生保持开心的分组方法的数目。
//      示例 1：
//          输入：nums = [1,1]
//          输出：2
//          解释：
//              有两种可行的方法：
//              班主任没有选中学生。
//              班主任选中所有学生形成一组。
//              如果班主任仅选中一个学生来完成分组，那么两个学生都无法保持开心。
//              因此，仅存在两种可行的方法。
//      示例 2：
//          输入：nums = [6,0,3,3,6,7,2,7]
//          输出：3
//          解释：
//              存在三种可行的方法：
//              班主任选中下标为 1 的学生形成一组。
//              班主任选中下标为 1、2、3、6 的学生形成一组。
//              班主任选中所有学生形成一组。
//      提示：
//          1 <= nums.length <= 105
//          0 <= nums[i] < nums.length

int CountWays(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *nums = GenerateRandomVec(0, 1000, n);
    PrintString(nums);
    int ans_A = CountWays(nums, strlen(nums));
    printf("能够满足让所有学生保持开心的分组方法的数目 为 %d \n", ans_A);
    FreeVec(nums);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return *tema - *temb;
}

// 模拟：
// Time: O(N)
// Space: O(1)
int CountWays(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), CompareInt);
    int ans = 1; // 全部选中一定可以(nums[i] < numsSize)
    ans += (nums[0] > 0 ? 1 : 0);
    for (int i = 1; i < numsSize; i++)
    {
        if ((nums[i - 1] < i) && (nums[i] > i))
        {
            ans++;
        }
    }
    return ans;
}