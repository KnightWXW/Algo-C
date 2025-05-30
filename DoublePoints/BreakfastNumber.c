#include "../Mybasic/mybasic.h"

//      LeetCode LCP 18. 早餐组合

//      链接：https://leetcode.cn/problems/2vYnGI/

//      小扣在秋日市集选择了一家早餐摊位，一维整型数组 staple 中记录了每种主食的价格，
//      一维整型数组 drinks 中记录了每种饮料的价格。小扣的计划选择一份主食和一款饮料，
//      且花费不超过 x 元。请返回小扣共有多少种购买方案。
//      注意：答案需要以 1e9 + 7 (1000000007) 为底取模，
//      如：计算初始结果为：1000000008，请返回 1
//      示例 1：
//          输入：staple = [10,20,5], drinks = [5,5,2], x = 15
//          输出：6
//          解释：小扣有 6 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
//              第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；
//              第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；
//              第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；
//              第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；
//              第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；
//              第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。
//      示例 2：
//          输入：staple = [2,1,1], drinks = [8,9,5,1], x = 9
//          输出：8
//          解释：小扣有 8 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
//              第 1 种方案：staple[0] + drinks[2] = 2 + 5 = 7；
//              第 2 种方案：staple[0] + drinks[3] = 2 + 1 = 3；
//              第 3 种方案：staple[1] + drinks[0] = 1 + 8 = 9；
//              第 4 种方案：staple[1] + drinks[2] = 1 + 5 = 6；
//              第 5 种方案：staple[1] + drinks[3] = 1 + 1 = 2；
//              第 6 种方案：staple[2] + drinks[0] = 1 + 8 = 9；
//              第 7 种方案：staple[2] + drinks[2] = 1 + 5 = 6；
//              第 8 种方案：staple[2] + drinks[3] = 1 + 1 = 2；
//      提示：
//          1 <= staple.length <= 10^5
//          1 <= drinks.length <= 10^5
//          1 <= staple[i],drinks[i] <= 10^5
//          1 <= x <= 2*10^5

#define BREAKFAST_MOD 1000000008

int BreakfastNumber(int *staple, int stapleSize, int *drinks, int drinksSize, int x);

int main()
{
    int stapleSize = GenerateRandomNum(1, 20);
    int *staple = GenerateRandomVec(0, 100, stapleSize);
    int drinksSize = GenerateRandomNum(1, 25);
    int *drinks = GenerateRandomVec(0, 99, drinksSize);
    int x = GenerateRandomNum(1, 50);
    printf("每种主食的价格 为:\n");
    PrintVecElement(staple, stapleSize);
    printf("每种饮料的价格 为:\n");
    PrintVecElement(drinks, drinksSize);
    int ans_A = BreakfastNumber_A(staple, stapleSize, drinks, drinksSize, x);
    printf("花费不超过 %d 元时，小扣共有 %d 种购买方案\n", x, ans_A);
    FreeVec(staple);
    FreeVec(drinks);
}

int CompareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// 双指针 + 贪心:
// Time: O(NlogN)
// Space: O(logN)
int BreakfastNumber_A(int *staple, int stapleSize, int *drinks, int drinksSize, int x)
{
    qsort(staple, stapleSize, sizeof(int), CompareInt);
    qsort(drinks, drinksSize, sizeof(int), CompareInt);
    int ans = 0;
    int j = 0;
    for (int i = stapleSize - 1; i >= 0; i--)
    {
        for (; j < drinksSize; j++)
        {
            if (staple[i] + drinks[j] > x)
            {
                break;
            }
        }
        ans = (ans + j) % BREAKFAST_MOD;
    }
    return ans;
}