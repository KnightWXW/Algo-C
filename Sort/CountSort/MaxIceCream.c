#include "../../Mybasic/mybasic.h"

//      LeetCode 1833. 雪糕的最大数量

//      链接：https://leetcode.cn/problems/maximum-ice-cream-bars/

//      夏日炎炎，小男孩 Tony 想买一些雪糕消消暑。
//      商店中新到 n 支雪糕，用长度为 n 的数组 costs 表示雪糕的定价，
//      其中 costs[i] 表示第 i 支雪糕的现金价格。Tony 一共有 coins 现金可以用于消费，
//      他想要买尽可能多的雪糕。
//      注意：Tony 可以按任意顺序购买雪糕。
//      给你价格数组 costs 和现金量 coins，请你计算并返回 Tony 用 coins 现金能够买到的雪糕的 最大数量 。
//      你必须使用计数排序解决此问题。
//      示例 1：
//          输入：costs = [1,3,2,4,1], coins = 7
//          输出：4
//          解释：Tony 可以买下标为 0、1、2、4 的雪糕，总价为 1 + 3 + 2 + 1 = 7
//      示例 2：
//          输入：costs = [10,6,8,7,7,8], coins = 5
//          输出：0
//          解释：Tony 没有足够的钱买任何一支雪糕。
//      示例 3：
//          输入：costs = [1,6,3,1,2,5], coins = 20
//          输出：6
//          解释：Tony 可以买下所有的雪糕，总价为 1 + 6 + 3 + 1 + 2 + 5 = 18 。
//      提示：
//          costs.length == n
//          1 <= n <= 105
//          1 <= costs[i] <= 105
//          1 <= coins <= 108

#define MAX_ICECREAM_NUM 100001

int MaxIceCream_A(int *costs, int costsSize, int coins);
int MaxIceCream_B(int *costs, int costsSize, int coins);

int main()
{
    int costsSize = GenerateRandomNum(1, 20);
    int *costs = GenerateRandomVec(1, 100, costsSize);
    int coins = GenerateRandomNum(1, 200);
    printf("雪糕的定价 为:\n");
    PrintVecElement(costs, costsSize);
    int ans_A = MaxIceCream_A(costs, costsSize, coins);
    printf("现金量 为 %d 时，可以买到 %d 支雪糕\n", coins, ans_A);
    int ans_B = MaxIceCream_B(costs, costsSize, coins);
    printf("现金量 为 %d 时，可以买到 %d 支雪糕\n", coins, ans_B);
    FreeVec(costs);
}

// 计数排序 + 贪心:
// Time: O(N)
// Space: O(N)
int MaxIceCream_A(int *costs, int costsSize, int coins)
{
    int *cnt = (int *)malloc(sizeof(int) * (MAX_ICECREAM_NUM));
    memset(cnt, 0, sizeof(int) * (MAX_ICECREAM_NUM));
    for (int i = 0; i < costsSize; i++)
    {
        cnt[i]++;
    }
    int ans = 0;
    for (int i = 1; i < MAX_ICECREAM_NUM; i++)
    {
        if (i <= coins)
        {
            int tem = min(coins / i, cnt[i]);
            coins -= (tem * i);
            ans += tem;
        }
        else
        {
            break;
        }
    }
    free(cnt);
    return ans;
}

int CompareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// 普通排序 + 贪心:
// Time: O(NlogN)
// Space: O(logN)
int MaxIceCream_B(int *costs, int costsSize, int coins)
{
    int ans = 0;
    qsort(costs, costsSize, sizeof(int), CompareInt);
    for (int i = 0; i < costsSize; i++)
    {
        if (coins >= costs[i])
        {
            coins -= costs[i];
            ans++;
        }
    }
    return ans;
}