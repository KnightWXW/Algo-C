#include "../Mybasic/mybasic.h"

//      LeetCode 198. 打家劫舍

//      链接：https://leetcode.cn/problems/house-robber/
//      链接: https://leetcode.cn/problems/Gu0c2T/

//      你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
//      影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//      如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//      给定一个代表每个房屋存放金额的非负整数数组，
//      计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//      示例 1：
//          输入：[1,2,3,1]
//          输出：4
//          解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//              偷窃到的最高金额 = 1 + 3 = 4 。
//      示例 2：
//          输入：[2,7,9,3,1]
//          输出：12
//          解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，
//              接着偷窃 5 号房屋 (金额 = 1)。
//              偷窃到的最高金额 = 2 + 9 + 1 = 12 。
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 400

int Robbery_A(int *nums, int numsSize);
int DFSRobbery_A(int *nums, int l, int i);
int Robbery_B(int *nums, int numsSize);
int DFSRobbery_B(int *nums, int l, int index, int *mem);
int Robbery_C(int *nums, int numsSize);
int Robbery_D(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec);
    int ansA = Robbery_A(vec, n);
    int ansB = Robbery_B(vec, n);
    int ansC = Robbery_C(vec, n);
    int ansD = Robbery_D(vec, n);
    printf("暴力递归: 一夜之内能够偷窃到的最高金额 为 %d\n", ansB);
    printf("记忆化搜索: 一夜之内能够偷窃到的最高金额 为 %d\n", ansB);
    printf("动态规划: 一夜之内能够偷窃到的最高金额 为 %d\n", ansC);
    printf("动态规划(空间优化): 一夜之内能够偷窃到的最高金额 为 %d\n", ansD);
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int Robbery_A(int *nums, int numsSize)
{
    return DFSRobbery_A(nums, numsSize, numsSize - 1);
}

int DFSRobbery_A(int *nums, int l, int i)
{
    if (i == 0)
    {
        return nums[0];
    }
    else if (i == 1)
    {
        return max(nums[0], nums[1]);
    }
    return max(DFSRobbery_A(nums, l, i - 1), DFSRobbery_A(nums, l, i - 2) + nums[i]);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int Robbery_B(int *nums, int numsSize)
{
    int *mem = (int *)malloc(sizeof(int) * (numsSize));
    memset(mem, -1, sizeof(int) * (numsSize));
    int ans = DFSRobbery_B(nums, numsSize, numsSize - 1, mem);
    free(mem);
    return ans;
}

int DFSRobbery_B(int *nums, int l, int i, int *mem)
{
    if (i == 0)
    {
        mem[0] = nums[0];
        return nums[0];
    }
    else if (i == 1)
    {
        mem[1] = max(nums[0], nums[1]);
        return max(nums[0], nums[1]);
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int tem = max(DFSRobbery_B(nums, l, i - 1, mem), DFSRobbery_B(nums, l, i - 2, mem) + nums[i]);
    mem[i] = tem;
    return tem;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int Robbery_C(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int *dp = (int *)malloc(sizeof(int) * (numsSize));
    memset(dp, -1, sizeof(int) * (numsSize));
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    int ans = dp[numsSize - 1];
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N)
// Space: O(1)
int Robbery_D(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int a = nums[0];
    int b = max(nums[0], nums[1]);
    int c = 0;
    for (int i = 2; i < numsSize; i++)
    {
        c = max(a + nums[i], b);
        a = b;
        b = c;
    }
    int ans = b;
    return ans;
}