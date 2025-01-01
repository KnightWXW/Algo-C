#include "../Mybasic/mybasic.h"

//      Huawei : 最大口罩产量

//      已知某工厂未来 totalDays 天, 每天口罩的生产产能依次记录于数组 productions中，
//      每天的生产计划依次记录于数组plans中，plans值为1表示生产，值为0表示休息。
//      由于疫情的影响，口罩需求增加，工厂决定修改生产计划进行赶工，在某windows天内连续生产，
//      即: 在这window天中原计划休息的，开工生产
//          在这windows天外的，生产计划保持不变
//      请指定合适的赶工方案，使得这totalDays天的总产量最大，并返回最大值
//      示例 1：
//          输入：
//              {803, 804, 805, 802, 803, 804, 805, 804}
//              {1, 0, 1, 0, 1, 0, 1, 0}
//              3
//          输出：4824
//      示例 2：
//          输入：
//              {980, 910, 1000, 940, 973}
//              {1, 1, 1, 1, 1}
//              5
//          输出：4803

int MaxMaskProduction(int *productions, int productionsSize, int *plans, int plansSize, int window);

int main()
{
    int productions[] = {803, 804, 805, 802, 803, 804, 805, 804};
    int plans[] = {1, 0, 1, 0, 1, 0, 1, 0};
    int window = 3;
    int ans = MaxMaskProduction(productions, 8, plans, 8, window);
    PrintVecElement(productions, 8);
    PrintVecElement(plans, 8);
    printf("在某 %d 天内连续生产，总产量最大是 %d\n", window, ans);
}

// 滑动窗口：定长
// Time: O(N)
// Space: O(1)
int MaxMaskProduction(int *productions, int productionsSize, int *plans, int plansSize, int window)
{
    int sum = 0;
    for (int i = 0; i < productionsSize; i++)
    {
        sum += plans[i] == 1 ? productions[i] : 0;
    }
    for (int i = 0; i < window; i++)
    {
        sum += plans[i] == 0 ? productions[i] : 0;
    }
    int ans = sum;
    for (int i = window; i < productionsSize; i++)
    {
        sum -= plans[i - window] == 0 ? productions[i - window] : 0;
        sum += plans[i] == 0 ? productions[i] : 0;
        ans = max(ans, sum);
    }
    return ans;
}