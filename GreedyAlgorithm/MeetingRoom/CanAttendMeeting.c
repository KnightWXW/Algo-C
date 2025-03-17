#include "../../Mybasic/mybasic.h"

//      LeetCode: 252 会议室

//      链接：https://leetcode.cn/problems/meeting-rooms

//      给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间
//          [[s1,e1],[s2,e2],...] (si < ei)，
//      请你判断一个人是否能够参加这里面的全部会议。
//      示例 1:
//          输入: [[0,30],[5,10],[15,20]]
//          输出: false
//      示例 2:
//          输入: [[7,10],[2,4]]
//          输出: true

bool CanAttendMeeting(int **intervals, int intervalsSize, int intervalsColSize);

int main()
{
    int intervalsSize1 = 3;
    int intervalsColSize1 = 2;
    int** intervals1 = (int**)malloc(sizeof(int*) * intervalsSize1);
    for(int i = 0; i < intervalsSize1; i++)
    {
        intervals1[i] = (int*)malloc(sizeof(int) * intervalsColSize1);
    }
    intervals1[0][0] = 0;
    intervals1[0][1] = 30;
    intervals1[1][0] = 5;
    intervals1[1][1] = 10;
    intervals1[2][0] = 15;
    intervals1[2][1] = 20;
    printf("会议时间安排为：\n");
    PrintVecElement2D(intervals1, intervalsSize1, intervalsColSize1);
    bool flag1 = CanAttendMeeting((int **)intervals1, intervalsSize1, intervalsColSize1);
    if (flag1 == true)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    FreeVec2D(intervals1, intervalsSize1);

    int intervalsSize2 = 2;
    int intervalsColSize2 = 2;
    int** intervals2 = (int**)malloc(sizeof(int*) * intervalsSize2);
    for(int i = 0; i < intervalsSize2; i++)
    {
        intervals2[i] = (int*)malloc(sizeof(int) * intervalsColSize2);
    }
    intervals2[0][0] = 7;
    intervals2[0][1] = 10;
    intervals2[1][0] = 2;
    intervals2[1][1] = 4;
    printf("会议时间安排为：\n");
    PrintVecElement2D(intervals2, intervalsSize2, intervalsColSize2);
    bool flag2 = CanAttendMeeting((int **)intervals2, intervalsSize2, intervalsColSize2);
    if (flag2 == true)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    FreeVec2D(intervals2, intervalsSize2);
}

int CompareMeeting(const void *a, const void *b)
{
    int *tmpA = *(int **)a;
    int *tmpB = *(int **)b;
    if (tmpA[0] == tmpB[0])
    {
        return tmpB[1] - tmpA[1];
    }
    return tmpA[0] - tmpB[0];
}

// 贪心：
// Time: O(NlogN)
// Space: O(N)
bool CanAttendMeeting(int **intervals, int intervalsSize, int intervalsColSize)
{
    if (intervals == NULL || intervalsSize == 1)
    {
        return true;
    }
    qsort(intervals, intervalsSize, sizeof(intervals), CompareMeeting);
    for (int i = 0; i < intervalsSize - 1; i++)
    {
        if (intervals[i][1] > intervals[i + 1][0])
        {
            return false;
        }
    }
    return true;
}