#include "../Mybasic/mybasic.h"

//      LeetCode 121. 买卖股票的最佳时机

//      链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

//      给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//      你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
//      设计一个算法来计算你所能获取的最大利润。
//      返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//      示例 1：
//          输入：[7,1,5,3,6,4]
//          输出：5
//          解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，
//              最大利润 = 6-1 = 5 。
//              注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；
//              同时，你不能在买入前卖出股票。
//      示例 2：
//          输入：prices = [7,6,4,3,1]
//          输出：0
//          解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
//      提示：
//          1 <= prices.length <= 105
//          0 <= prices[i] <= 104

int MaxProfit1_A(int *prices, int pricesSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *nums = GenerateRandomVec(0, 1000, n);
    PrintVecElement(nums, n);
    int ans_A = MaxProfit1_A(nums, n);
    int ans_B = MaxProfit1_B(nums, n);
    printf("从这笔交易中获取的最大利润 为 %d \n", ans_A);
    printf("从这笔交易中获取的最大利润 为 %d \n", ans_A);
    FreeVec(nums);
}

// 双层遍历
// Time: O(N^2)
// Space: O(1)
int MaxProfit1(int *prices, int pricesSize)
{
    int ans = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            ans = max(ans, prices[j] - prices[i]);
        }
    }
    return ans;
}

// 贪心：单层遍历
// Time: O(N)
// Space: O(1)
int MaxProfit1(int *prices, int pricesSize)
{
    int ans = 0;
    int preMin = prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] > preMin)
        {
            ans = max(ans, prices[i] - preMin);
        }
        else
        {
            preMin = prices[i];
        }
    }
    return ans;
}