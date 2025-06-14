#include "../Mybasic/mybasic.h"

//      LeetCode 2600. K 件物品的最大和

//      链接：https://leetcode.cn/problems/k-items-with-the-maximum-sum/

//      袋子中装有一些物品，每个物品上都标记着数字 1 、0 或 -1 。
//      给你四个非负整数 numOnes、numZeros、numNegOnes 和 k 。
//      袋子最初包含：
//          numOnes 件标记为 1 的物品。
//          numZeroes 件标记为 0 的物品。
//          numNegOnes 件标记为 -1 的物品。
//      现计划从这些物品中恰好选出 k 件物品。
//      返回所有可行方案中，物品上所标记数字之和的最大值。
//      示例 1：
//          输入：numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
//          输出：2
//          解释：袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。
//                  取 2 件标记为 1 的物品，得到的数字之和为 2 。
//                  可以证明 2 是所有可行方案中的最大值。
//      示例 2：
//          输入：numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
//          输出：3
//          解释：袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。
//              取 3 件标记为 1 的物品，1 件标记为 0 的物品，得到的数字之和为 3 。
//              可以证明 3 是所有可行方案中的最大值。
//      提示：
//          0 <= numOnes, numZeros, numNegOnes <= 50
//          0 <= k <= numOnes + numZeros + numNegOnes

int KItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k);

int main()
{
    int numOnes = GenerateRandomNum(1, 50);
    int numZeros = GenerateRandomNum(1, 51);
    int numNegOnes = GenerateRandomNum(1, 49);
    int k = GenerateRandomNum(1, numOnes + numZeros + numNegOnes);
    int ans = KItemsWithMaximumSum(numOnes, numZeros, numNegOnes, k);
    printf("标记为 1 的物品有 %d 件, \n标记为 0 的物品有 %d 件, \n标记为 -1 的物品有 %d 件, \n从这些物品中恰好选出 %d 件物品\n", numOnes, numZeros, numNegOnes, k);
    printf("所有可行方案中，物品上所标记数字之和的最大值为 %d", ans);
}

// 贪心:
// Time: O(1)
// Space: O(1)
int KItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
{
    
}