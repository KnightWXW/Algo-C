#include "../Mybasic/mybasic.h"

//      LeetCode 435. 无重叠区间

//      链接：https://leetcode.cn/problems/non-overlapping-intervals/

//      给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
//      返回 需要移除区间的最小数量，使剩余区间互不重叠 。
//      注意 只在一点上接触的区间是 不重叠的。例如 [1, 2] 和 [2, 3] 是不重叠的。
//      示例 1:
//          输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
//          输出: 1
//          解释: 移除 [1,3] 后，剩下的区间没有重叠。
//      示例 2:
//          输入: intervals = [[1,2], [1,2], [1,2]]
//          输出: 2
//          解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
//      示例 3:
//          输入: intervals = [[1,2], [2,3]]
//          输出: 0
//          解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
//      提示:
//          1 <= intervals.length <= 105
//          intervals[i].length == 2
//          -5 * 104 <= starti < endi <= 5 * 104

int EraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize);

int main()
{
    int r1 = 4;
    int c1 = 2;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 2;
    vec1[1][0] = 2;
    vec1[1][1] = 3;
    vec1[2][0] = 3;
    vec1[2][1] = 4;
    vec1[3][0] = 1;
    vec1[3][1] = 3;
    PrintVecElement2D(vec1, r1, c1);
    int ans1 = EraseOverlapIntervals((int **)vec1, r1, &c1);
    printf("需要移除区间的最小数量为:%d\n", ans1);
    FreeVec2D(vec1, r1);
}

int Compare2DInt(const void *a, const void *b)
{
    int *tema = *(int **)a;
    int *temb = *(int **)b;
    return tema[1] - temb[1];
}

// 贪心:按照右端点升序排序
// Time: O(NlogN)
// Space: O(logN)
int EraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    int ans = 1;
    qsort(intervals, intervalsSize, sizeof(int *), Compare2DInt);
    int right = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++)
    {
        if (right <= intervals[i][0])
        {
            ans++;
            right = intervals[i][1];
        }
    }
    return intervalsSize - ans;
}
