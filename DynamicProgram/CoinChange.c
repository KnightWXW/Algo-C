#include "../Mybasic/mybasic.h"

//      LeetCode 322. 零钱兑换

//      链接：https://leetcode.cn/problems/coin-change/

//      给你一个整数数组 coins ，表示不同面额的硬币；
//      以及一个整数 amount ，表示总金额。
//      计算并返回可以凑成总金额所需的 最少的硬币个数 。
//      如果没有任何一种硬币组合能组成总金额，返回 -1 。
//      你可以认为每种硬币的数量是无限的。
//      示例 1：
//          输入：coins = [1, 2, 5], amount = 11
//          输出：3
//          解释：11 = 5 + 5 + 1
//      示例 2：
//          输入：coins = [2], amount = 3
//          输出：-1
//      示例 3：
//          输入：coins = [1], amount = 0
//          输出：0
//      提示：
//          1 <= coins.length <= 12
//          1 <= coins[i] <= 231 - 1
//          0 <= amount <= 104

int CoinChange1_A(int *coins, int coinsSize, int amount);
int DFSCoinChange1_A(int *coins, int coinsSize, int amount, int i);
int CoinChange1_B(int *coins, int coinsSize, int amount);
int DFSCoinChange1_B(int *coins, int coinsSize, int amount, int i, int **mem);
int CoinChange1_C(int *coins, int coinsSize, int amount);

int main()
{
    int n = 3;
    int coins[] = {1, 2, 5};
    int amount = GenerateRandomNum(10, 100);
    int ans1A = CoinChange1_A(coins, n, amount);
    int ans1B = CoinChange1_B(coins, n, amount);
    int ans1C = CoinChange1_C(coins, n, amount);
    printf("暴力递归: 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, ans1A);
    printf("记忆化搜索: 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, ans1B);
    printf("动态规划: 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, ans1C);
}

int CoinChange1_A(int *coins, int coinsSize, int amount)
{
    
}