#include "../Mybasic/mybasic.h"

//      LeetCode 518. 零钱兑换 II

//      链接：https://leetcode.cn/problems/coin-change-ii/

//      给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
//      请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
//      假设每一种面额的硬币有无限个。 
//      题目数据保证结果符合 32 位带符号整数。
//      示例 1：
//          输入：amount = 5, coins = [1, 2, 5]
//          输出：4
//          解释：有四种方式可以凑成总金额：
//              5=5
//              5=2+2+1
//              5=2+1+1+1
//              5=1+1+1+1+1
//      示例 2：
//          输入：amount = 3, coins = [2]
//          输出：0
//          解释：只用面额 2 的硬币不能凑成总金额 3 。
//      示例 3：
//          输入：amount = 10, coins = [10] 
//          输出：1
//      提示：
//          1 <= coins.length <= 300
//          1 <= coins[i] <= 5000
//          coins 中的所有值 互不相同
//          0 <= amount <= 5000

int CoinChange2_A(int *coins, int coinsSize, int amount);
int DFSCoinChange2_A(int *coins, int coinsSize, int amount, int i);
int CoinChange2_B(int *coins, int coinsSize, int amount);
int DFSCoinChange2_B(int *coins, int coinsSize, int amount, int i, int **mem);
int CoinChange2_C(int *coins, int coinsSize, int amount);

int main()
{
    int n = 3;
    int coins[] = {1, 2, 5};
    int amount = GenerateRandomNum(10, 100);
    int ans1A = CoinChange1_A(coins, n, amount);
    int ans1B = CoinChange1_B(coins, n, amount);
    int ans1C = CoinChange1_C(coins, n, amount);
    printf("暴力递归: 可以凑成总金额为 %d 的硬币组合数为 %d。\n", amount, ans1A);
    printf("记忆化搜索: 可以凑成总金额为 %d 的硬币组合数为 %d。\n", amount, ans1B);
    printf("动态规划: 可以凑成总金额为 %d 的硬币组合数为 %d。\n", amount, ans1C);
}

int CoinChange2_A(int *coins, int coinsSize, int amount)
{
    
}