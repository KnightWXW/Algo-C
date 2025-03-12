#include "../Mybasic/mybasic.h"

//      Huawei: 最强信号位置

//      有若干个信号塔，沿东西方向排列成一条直线，位置从 0 开始，
//      信号塔可以向东或者向西方向发射信号，信号强度是1个信号单位，
//      假设信号塔发射的信号不会衰减，
//      现给出N组信号塔的位置和信号发射的方向。
//      计算直线上的哪个位置信号最强。

int StrongestSignalPosition(int **arr, int row, int col);

int main()
{
    int row1 = 6;
    int col1 = 2;
    int vec1[row1][col1] = {{1, 1}, {3, -1}, {4, 1}, {6, -1}, {7, 1}, {9, -1}};
    int ans1 = StrongestSignalPosition(vec1, row1, col1);
    PrintVecElement2D(vec1, row1, col1);
    printf("信号最强的位置是 %d\n", ans1);

    int row2 = 6;
    int col2 = 2;
    int vec2[row2][col2] = {{1, -1}, {3, -1}, {4, 1}, {6, -1}, {7, 1}, {9, 1}};
    int ans2 = StrongestSignalPosition(vec2, row2, col2);
    PrintVecElement2D(vec2, row2, col2);
    printf("信号最强的位置是 %d\n", ans2);
}

// 前缀和：
// Time: O(N)
// Space: O(N)
int StrongestSignalPosition(int **arr, int row, int col)
{
}