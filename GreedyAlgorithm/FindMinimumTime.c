#include "../Mybasic/mybasic.h"

//      LeetCode 2589. 完成所有任务的最少时间

//      链接：https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/

//      你有一台电脑，它可以 同时 运行无数个任务。给你一个二维整数数组 tasks ，
//      其中 tasks[i] = [starti, endi, durationi]
//      表示第 i 个任务需要在 闭区间 时间段 [starti, endi] 内运行 durationi 个整数时间点
//      （但不需要连续）。
//      当电脑需要运行任务时，你可以打开电脑，如果空闲时，你可以将电脑关闭。
//      请你返回完成所有任务的情况下，电脑最少需要运行多少秒。
//      示例 1：
//          输入：tasks = [[2,3,1],[4,5,1],[1,5,2]]
//          输出：2
//          解释：
//              - 第一个任务在闭区间 [2, 2] 运行。
//              - 第二个任务在闭区间 [5, 5] 运行。
//              - 第三个任务在闭区间 [2, 2] 和 [5, 5] 运行。
//              电脑总共运行 2 个整数时间点。
//      示例 2：
//          输入：tasks = [[1,3,2],[2,5,3],[5,6,2]]
//          输出：4
//          解释：
//              - 第一个任务在闭区间 [2, 3] 运行
//              - 第二个任务在闭区间 [2, 3] 和 [5, 5] 运行。
//              - 第三个任务在闭区间 [5, 6] 运行。
//              电脑总共运行 4 个整数时间点。
//      提示：
//          1 <= tasks.length <= 2000
//          tasks[i].length == 3
//          1 <= starti, endi <= 2000
//          1 <= durationi <= endi - starti + 1

int FindMinimumTime(int **tasks, int tasksSize, int *tasksColSize);

int main()
{
    int r1 = 3;
    int c1 = 2;
    int **v1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        v1[i] = (int *)malloc(sizeof(int) * c1);
    }
    v1[0][0] = 2;
    v1[0][1] = 3;
    v1[0][2] = 1;
    v1[1][0] = 4;
    v1[1][1] = 5;
    v1[1][2] = 1;
    v1[2][0] = 1;
    v1[2][1] = 5;
    v1[2][2] = 2;
    PrintVecElement2D(v1, r1, c1);
    int ans1 = FindMinimumTime(v1, r1, &c1);
    printf("完成所有任务的情况下，电脑最少需要运行 %d 秒\n", ans1);
    FreeVec2D(v1, r1);

    int r2 = 3;
    int c2 = 2;
    int **v2 = (int **)malloc(sizeof(int *) * r2);
    for (int i = 0; i < r2; i++)
    {
        v2[i] = (int *)malloc(sizeof(int) * c2);
    }
    v2[0][0] = 1;
    v2[0][1] = 3;
    v2[0][2] = 2;
    v2[1][0] = 2;
    v2[1][1] = 5;
    v2[1][2] = 3;
    v2[2][0] = 5;
    v2[2][1] = 6;
    v2[2][2] = 2;
    PrintVecElement2D(v2, r2, c2);
    int ans2 = FindMinimumTime(v2, r2, &c2);
    printf("完成所有任务的情况下，电脑最少需要运行 %d 秒\n", ans2);
    FreeVec2D(v2, r2);
}

// 贪心：
// Time: O(N)
// Space: O(1)
int FindMinimumTime(int **tasks, int tasksSize, int *tasksColSize)
{
}