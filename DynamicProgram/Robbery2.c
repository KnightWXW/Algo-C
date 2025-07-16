#include "../Mybasic/mybasic.h"

//      LeetCode 213. 打家劫舍 II

//      链接: https://leetcode.cn/problems/house-robber-ii/

//      你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
//      这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//      同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
//      给定一个代表每个房屋存放金额的非负整数数组，
//      计算你 在不触动警报装置的情况下，今晚能够偷窃到的最高金额。
//      示例 1：
//          输入：nums = [2,3,2]
//          输出：3
//          解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）,
//               因为他们是相邻的。
//      示例 2：
//          输入：nums = [1,2,3,1]
//          输出：4
//          解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//              偷窃到的最高金额 = 1 + 3 = 4 。
//      示例 3：
//          输入：nums = [1,2,3]
//          输出：3
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 1000

int Robbery2_A(int* nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec);
    int ansA = Robbery2_A(vec, n);
    int ansB = Robbery2_B(vec, n);
    int ansC = Robbery2_C(vec, n);
    int ansD = Robbery2_D(vec, n);
    printf("暴力递归: 一夜之内能够偷窃到的最高金额 为 %d\n", ansB);
    printf("记忆化搜索: 一夜之内能够偷窃到的最高金额 为 %d\n", ansB);
    printf("动态规划 一夜之内能够偷窃到的最高金额 为 %d\n", ansC);
    printf("动态规划(空间优化): 一夜之内能够偷窃到的最高金额 为 %d\n", ansD);
}