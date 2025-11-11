#include "../Mybasic/mybasic.h"

//      Huawei: 磁盘空间统计

//      现网设备每天都会产生大量日志，这些日志会占用磁盘空间，并按某种规则自动清除，
//      所以这台设备每天的磁盘空间占有量都在变化。
//      运维系统从上电到现在，每天采集了一次磁盘空间占用情况，记录于数组 record 中。
//      以 M 为单位，运维人员想分析一段时间内的磁盘空间占用情况, 来确定系统运行状况，
//      请找出同时满足以下条件的区间，并返回区间个数。
//      区间长度处于 [minLen, MaxLen] 左闭右闭范围内。
//      区间中磁盘空间平均占有值大于等于给定的阈值，
//      样例1
//          输入:
//              {2, 0, 2, 0, 2}
//              {2, 4}
//              1
//          输出:
//              8

int CountIntervals(int *records, int recordsSize, int *lengthRange, int lengthSize, int threshold);

int main()
{
    int n1 = 5;
    int n2 = 2;
    int threshold = 1;
    int records[] = {2, 0, 2, 0, 2};
    int lengthRange[] = {2, 4};
    PrintVecElement(records, n1);
    PrintVecElement(lengthRange, n2);
    int ans = CountIntervals(records, n1, lengthRange, n2, threshold);
    printf("磁盘空间统计 为 %d \n", ans);
}

// 前缀和:
// Time: O(N)
// Space: O(N)
int CountIntervals(int *records, int recordsSize, int *lengthRange, int lengthSize, int threshold)
{
    int ans = 0;
    int *pre = (int *)malloc(sizeof(int) * (recordsSize + 1));
    memset(pre, 0, sizeof(int) * (recordsSize + 1));
    for (int i = 1; i <= recordsSize; i++)
    {
        pre[i] = pre[i - 1] + records[i - 1];
    }
    for (int i = 0; i <= recordsSize; i++)
    {
        int tem = pre[i];
        for (int j = lengthRange[0]; j <= lengthRange[1]; j++)
        {
            if (i + j > recordsSize)
            {
                break;
            }
            if (pre[i + j] - pre[i] >= (j * threshold))
            {
                ans++;
            }
        }
    }
    free(pre);
    return ans;
}
