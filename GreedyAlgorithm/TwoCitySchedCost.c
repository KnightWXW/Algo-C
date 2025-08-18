#include "../Mybasic/mybasic.h"

//      LeetCode 1029. 两地调度

//      链接：https://leetcode.cn/problems/two-city-scheduling/

//      公司计划面试 2n 人。给你一个数组 costs ，其中 costs[i] = [aCosti, bCosti] 。
//      第 i 人飞往 a 市的费用为 aCosti ，飞往 b 市的费用为 bCosti 。
//      返回将每个人都飞到 a 、b 中某座城市的最低费用，要求每个城市都有 n 人抵达。
//      示例 1：
//          输入：costs = [[10,20],[30,200],[400,50],[30,20]]
//          输出：110
//          解释：
//              第一个人去 a 市，费用为 10。
//              第二个人去 a 市，费用为 30。
//              第三个人去 b 市，费用为 50。
//              第四个人去 b 市，费用为 20。
//              最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
//      示例 2：
//          输入：costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
//          输出：1859
//      示例 3：
//          输入：costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
//          输出：3086
//      提示：
//          2 * n == costs.length
//          2 <= costs.length <= 100
//          costs.length 为偶数

int TwoCitySchedCost(int **costs, int costsSize, int *costsColSize);

int main()
{
    int n1 = 4;
    int c1 = 2;
    int **cost1 = (int **)malloc(sizeof(int *) * n1);
    for (int i = 0; i < n1; i++)
    {
        cost1[i] = (int *)malloc(sizeof(int) * c1);
    }
    cost1[0][0] = 10;
    cost1[0][1] = 20;
    cost1[1][0] = 30;
    cost1[1][1] = 200;
    cost1[2][0] = 400;
    cost1[2][1] = 50;
    cost1[3][0] = 30;
    cost1[3][1] = 20;
    printf("costs数组为：\n");
    PrintVecElement2D(cost1, n1);
    int ans = TwoCitySchedCost(cost1, n1, &c1);
    printf("每个人 都飞到 a, b 中 某座城市 的 最低费用为：%d。\n", ans);
    FreeVec2D(cost1, n1);
}

// 贪心：
// Time: O(NlogN)
// Space: O(N)
int TwoCitySchedCost(int **costs, int costsSize, int *costsColSize)
{
}