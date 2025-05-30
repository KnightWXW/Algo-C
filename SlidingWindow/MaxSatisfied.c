#include "../Mybasic/mybasic.h"

//      LeetCode 1052. 爱生气的书店老板

//      链接：https://leetcode.cn/problems/grumpy-bookstore-owner/

//      有一个书店老板，他的书店开了 n 分钟。
//      每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，
//      其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，
//      所有这些顾客在第 i 分钟结束后离开。在某些时候，书店老板会生气。
//      如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。
//      当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。
//      书店老板知道一个秘密技巧，能抑制自己的情绪，
//      可以让自己连续 minutes 分钟不生气，但却只能使用一次。
//      请你返回 这一天营业下来，最多有多少客户能够感到满意 。
//      示例 1：
//      输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
//      输出：16
//          解释：书店老板在最后 3 分钟保持冷静。
//          感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
//      示例 2：
//      输入：customers = [1], grumpy = [0], minutes = 1
//      输出：1
//      提示：
//          n == customers.length == grumpy.length
//          1 <= minutes <= n <= 2 * 104
//          0 <= customers[i] <= 1000
//          grumpy[i] == 0 or 1

int MaxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize, int minutes);

int main()
{
    // int n = GenerateRandomNum(1, 20);
    // int minutes = GenerateRandomNum(1, n);
    // int *customers = GenerateRandomVec(0, 10, n);
    // int *grumpy = GenerateRandomVec(0, 1, n);
    int customers[] = {1,0,1,2,1,1,7,5};
    int grumpy[] = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    int n = 8;
    printf("customers数组 元素为: ");
    PrintVecElement(customers, n);
    printf("grumpy数组 元素为: ");
    PrintVecElement(grumpy, n);
    printf("minutes 为: %d\n", minutes);
    int ans = MaxSatisfied(customers, n, grumpy, n, minutes);
    printf("这一天营业下来，最多有 %d 名客户能够感到满意 \n", ans);
    FreeVec(customers);
    FreeVec(grumpy);
}

// 滑动窗口：定长
// Time: O(N)
// Space: O(1)
int MaxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize, int minutes)
{
    int sum = 0;
    for (int i = 0; i < customersSize; i++)
    {
        sum += (grumpy[i] == 0 ? customers[i] : 0);
    }
    int cur = sum;
    for (int i = 0; i < minutes; i++)
    {
        cur += (grumpy[i] == 1 ? customers[i] : 0);
    }
    int ans = cur;
    for (int i = 0; i < customersSize - minutes; i++)
    {
        cur -= (grumpy[i] == 1 ? customers[i] : 0);
        cur += (grumpy[i + minutes] == 1 ? customers[i + minutes] : 0);
        ans = max(ans, cur);
    }
    return ans;
}