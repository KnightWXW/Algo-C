#include "../Mybasic/mybasic.h"

//      LeetCode 746. 使用最小花费爬楼梯

//      链接：https://leetcode.cn/problems/min-cost-climbing-stairs/
//      链接：https://leetcode.cn/problems/GzCJIP/

//      给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
//      一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//      你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//      请你计算并返回达到楼梯顶部的最低花费。
//      示例 1：
//          输入：cost = [10,15,20]
//          输出：15
//          解释：你将从下标为 1 的台阶开始。
//              - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
//              总花费为 15 。
//      示例 2：
//          输入：cost = [1,100,1,1,1,100,1,1,100,1]
//          输出：6
//              解释：你将从下标为 0 的台阶开始。
//              - 支付 1，向上爬两个台阶，到达下标为 2 的台阶。
//              - 支付 1，向上爬两个台阶，到达下标为 4 的台阶。
//              - 支付 1，向上爬两个台阶，到达下标为 6 的台阶。
//              - 支付 1，向上爬一个台阶，到达下标为 7 的台阶。
//              - 支付 1，向上爬两个台阶，到达下标为 9 的台阶。
//              - 支付 1，向上爬一个台阶，到达楼梯顶部。
//              总花费为 6 。
//      提示：
//          2 <= cost.length <= 1000
//          0 <= cost[i] <= 999

int MinCostClimbingStairs_A(int *cost, int costSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *nums = GenerateRandomVec(0, 20, n);
    PrintVecElement(nums, n);
    int ansA = MinCostClimbingStairs_A(nums, n);
    int ansB = MinCostClimbingStairs_B(nums, n);
    int ansC = MinCostClimbingStairs_C(nums, n);
    printf("暴力递归: 数组中能被三整除的元素最大和 为 %d \n", ansA);
    printf("记忆化搜索: 数组中能被三整除的元素最大和 为 %d \n", ansB);
    printf("动态规划: 数组中能被三整除的元素最大和 为 %d \n", ansC);
}

