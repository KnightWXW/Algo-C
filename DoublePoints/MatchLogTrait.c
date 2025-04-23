#include "../Mybasic/mybasic.h"

//      Huawei: 基于日志的系统故障预测

//      某通讯设备系统定义了一系列系统事件，当事件发生时会将该事件ID记录到日志中，
//      该日志的数据全集称为原始时间序列。
//      根据经验，当某些特征事件出现时，预示着存在风险。
//      现给定一组原始事件序列 events (元素可以重复)，以及一个特征序列traits(元素不重复)。
//      请在events中从左往右按匹配规则找到一个匹配特征序列的最短连续子序列；
//      如果存在多个最短的，则返回最早匹配的连续子序列。
//      输入：原始事件序列 events  (元素可以重复)
//           特征序列 traits (元素不重复)
//      输出：一个连续子序列
//      样例1：
//          输入: {4, 8, 4, 3, 6, 6, 8}
//                {4, 6, 8}
//          输出: {4, 3, 6, 6, 8}
//      样例2：
//          输入: {2, 30, 4, 4, 6, 2, 2, 3, 4, 6, 6, 2, 4, 4, 6}
//                {2, 4, 6}
//          输出: {2, 3, 4, 6}

int *MatchLogTrait_A(int *events, int l1, int *traits, int l2);
int *MatchLogTrait_B(int *events, int l1, int *traits, int l2);

int main()
{
    int l11 = 7;
    int events1[] = {4, 8, 4, 3, 6, 6, 8};
    int l12 = 3;
    int traits1[] = {4, 6, 8};
    int *ans11 = MatchLogTrait_A(events1, l11, traits1, l12);
    int *ans12 = MatchLogTrait_B(events1, l11, traits1, l12);
    printf("events 数组为: \n");
    PrintVecElement(events1);
    printf("traits1 数组为: \n");
    PrintVecElement(traits1);
    printf("最早匹配的 连续子序列 数组为: \n");
    PrintVecElement(ans11); //{4, 3, 6, 6, 8}
    PrintVecElement(ans12); //{4, 3, 6, 6, 8}
    FreeVec(ans11);
    FreeVec(ans12);

    int l21 = 15;
    int events2[] = {2, 30, 4, 4, 6, 2, 2, 3, 4, 6, 6, 2, 4, 4, 6};
    int l22 = 3;
    int traits2[] = {2, 4, 6};
    int *ans21 = MatchLogTrait_A(events2, l21, traits2, l22);
    int *ans22 = MatchLogTrait_B(events2, l21, traits2, l22);
    printf("events 数组为: \n");
    PrintVecElement(events2);
    printf("traits1 数组为: \n");
    PrintVecElement(traits2); 
    printf("最早匹配的 连续子序列 数组为: \n");
    PrintVecElement(ans21); //  {2, 3, 4, 6}
    PrintVecElement(ans22); //  {2, 3, 4, 6}
    FreeVec(ans21);
    FreeVec(ans22);
}

// 双指针:
// Time: O(N ^ 2)
// Space: O(N)
int *MatchLogTrait_A(int *events, int l1, int *traits, int l2);
{
}

// 贪心:
// Time: O(N ^ 2)
// Space: O(N)
int *MatchLogTrait_B(int *events, int l1, int *traits, int l2);
{
}