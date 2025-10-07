#include "../Mybasic/mybasic.h"

//      LeetCode 3100. 换水问题 II

//      链接: https://leetcode.cn/problems/water-bottles-ii/

//      给你两个整数 numBottles 和 numExchange 。
//      numBottles 代表你最初拥有的满水瓶数量。
//      在一次操作中，你可以执行以下操作之一：
//          喝掉任意数量的满水瓶，使它们变成空水瓶。
//          用 numExchange 个空水瓶交换一个满水瓶。然后，将 numExchange 的值增加 1 。
//      注意，你不能使用相同的 numExchange 值交换多批空水瓶。
//      例如，如果 numBottles == 3 并且 numExchange == 1 ，则不能用 3 个空水瓶交换成 3 个满水瓶。
//      返回你 最多 可以喝到多少瓶水。
//      示例 1:
//          输入：numBottles = 13, numExchange = 6
//          输出：15
//          解释：上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶数量。
//      示例 2：
//          输入：numBottles = 10, numExchange = 3
//          输出：13
//          解释：上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶数量。
//      提示：
//          1 <= numBottles <= 100
//          1 <= numExchange <= 100

int MaxBottlesDrunk(int numBottles, int numExchange);

int main()
{
    int numBottles = GenerateRandomNum(1, 100);
    int numExchange = GenerateRandomNum(1, numBottles);
    int ans_A = MaxBottlesDrunk_A(numBottles, numExchange);
    int ans_B = MaxBottlesDrunk_B(numBottles, numExchange);
    printf("购入了 %d 瓶水, 用 %d 个空水瓶兑换一瓶水, \n最多 可以喝到 %d 瓶水\n", numBottles, numExchange, ans_A);
    printf("购入了 %d 瓶水, 用 %d 个空水瓶兑换一瓶水, \n最多 可以喝到 %d 瓶水\n", numBottles, numExchange, ans_B);
}

// 模拟:
// Time: O(b/e)
// Space: O(1)
int MaxBottlesDrunk_A(int numBottles, int numExchange)
{
    int ans = numBottles;
    int exchange = numExchange;
    while (numBottles >= exchange)
    {
        numBottles -= exchange;
        numBottles++;
        ans++;
        exchange++;
    }
    return ans;
}

// 数学:
// Time: O(1)
// Space: O(1)
int MaxBottlesDrunk_B(int numBottles, int numExchange)
{
    int a = 1;
    int b = 2 * numExchange - 3;
    int c = -2 * numBottles;
    double delta = (double)b * b - 4.0 * a * c;
    int t = (int)ceil((-b + sqrt(delta)) / (2.0 * a));
    return numBottles + t - 1;
}