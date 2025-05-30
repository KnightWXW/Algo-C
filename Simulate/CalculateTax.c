#include "../Mybasic/mybasic.h"

//      LeetCode 2303. 计算应缴税款总额

//      链接：https://leetcode.cn/problems/calculate-amount-paid-in-taxes/

//      给你一个下标从 0 开始的二维整数数组 brackets ，
//      其中 brackets[i] = [upperi, percenti] ，
//      表示 第 i 个税级的上限是 upperi ，征收的税率为 percenti。
//      税级按上限 从低到高排序
//      (在满足 0 < i < brackets.length 的前提下，upperi-1 < upperi)。
//      税款计算方式如下：
//          不超过 upper0 的收入按税率 percent0 缴纳
//          接着 upper1 - upper0 的部分按税率 percent1 缴纳
//          然后 upper2 - upper1 的部分按税率 percent2 缴纳
//          以此类推
//      给你一个整数 income 表示你的总收入。
//      返回你需要缴纳的税款总额。与标准答案误差不超 10-5 的结果将被视作正确答案。
//      示例 1：
//          输入：brackets = [[3,50],[7,10],[12,25]], income = 10
//          输出：2.65000
//          解释：
//              前 $3 的税率为 50% 。需要支付税款 $3 * 50% = $1.50 。
//              接下来 $7 - $3 = $4 的税率为 10% 。需要支付税款 $4 * 10% = $0.40 。
//              最后 $10 - $7 = $3 的税率为 25% 。需要支付税款 $3 * 25% = $0.75 。
//              需要支付的税款总计 $1.50 + $0.40 + $0.75 = $2.65 。
//      示例 2：
//          输入：brackets = [[1,0],[4,25],[5,50]], income = 2
//          输出：0.25000
//          解释：
//              前 $1 的税率为 0% 。需要支付税款 $1 * 0% = $0 。
//              剩下 $1 的税率为 25% 。需要支付税款 $1 * 25% = $0.25 。
//              需要支付的税款总计 $0 + $0.25 = $0.25 。
//      示例 3：
//          输入：brackets = [[2,50]], income = 0
//          输出：0.00000
//          解释：
//              没有收入，无需纳税，需要支付的税款总计 $0 。
//      提示：
//          1 <= brackets.length <= 100
//          1 <= upperi <= 1000
//          0 <= percenti <= 100
//          0 <= income <= 1000
//          upperi 按递增顺序排列
//          upperi 中的所有值 互不相同
//          最后一个税级的上限大于等于 income

double CalculateTax(int **brackets, int bracketsSize, int *bracketsColSize, int income);

int main()
{
    int bracketsSize_A = 3;
    int bracketsColSize_A = 2;
    int** brackets_A = (int**)malloc(sizeof(int*) * bracketsSize_A);
    for(int i = 0; i < bracketsSize_A; i++)
    {
        brackets_A[i] = (int*)malloc(sizeof(int) * bracketsSize_A);
    }
    brackets_A[0][0] = 3;
    brackets_A[0][1] = 50;
    brackets_A[1][0] = 7;
    brackets_A[1][1] = 10;
    brackets_A[2][0] = 12;
    brackets_A[2][1] = 25;
    int income_A = 10;
    PrintVecElement2D(brackets_A, 3, 2);
    double ans_A = CalculateTax((int **)brackets_A, bracketsSize_A, &bracketsColSize_A, income_A);
    printf("需要缴纳的税款总额为：%lf。\n", ans_A); // 2.65
    FreeVec2D(brackets_A, bracketsSize_A);

    int bracketsSize_B = 3;
    int bracketsColSize_B = 2;
    int** brackets_B = (int**)malloc(sizeof(int*) * bracketsSize_B);
    for(int i = 0; i < bracketsSize_B; i++)
    {
        brackets_B[i] = (int*)malloc(sizeof(int) * bracketsSize_B);
    }
    brackets_B[0][0] = 1;
    brackets_B[0][1] = 0;
    brackets_B[1][0] = 4;
    brackets_B[1][1] = 25;
    brackets_B[2][0] = 5;
    brackets_B[2][1] = 50;
    int income_B = 2;
    PrintVecElement2D(brackets_B, 3, 2);
    double ans_B = CalculateTax((int **)brackets_B, bracketsSize_B, &bracketsColSize_B, income_B);
    printf("需要缴纳的税款总额为：%lf。\n", ans_B);  // 0.25
    FreeVec2D(brackets_B, bracketsSize_B);
}

// 模拟：
// Time: O(N)
// Space: O(1)
double CalculateTax(int **brackets, int bracketsSize, int *bracketsColSize, int income)
{
    double ans = 0.0;
    int preUpper = 0;
    for (int i = 0; i < bracketsSize; i++)
    {
        int upper = brackets[i][0];
        int percent=  brackets[i][1];
        int tem = (min(income, upper) - preUpper) * percent;
        ans += tem;
        if (income <= upper)
        {
            break;
        }
        preUpper = upper;
    }
    return (double)(ans / 100.00);
}