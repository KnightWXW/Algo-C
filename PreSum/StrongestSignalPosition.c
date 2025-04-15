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
    int** vec1 = (int**)malloc(sizeof(int*) * row1);
    for(int i = 0; i < row1; i++)
    {
        vec1[i] = (int*)malloc(sizeof(int) * col1);
    } 
    vec1[0][0] = 1;
    vec1[0][1] = 1;
    vec1[1][0] = 3;
    vec1[1][1] = -1;
    vec1[2][0] = 4;
    vec1[2][1] = 1;
    vec1[3][0] = 6;
    vec1[3][1] = -1;
    vec1[4][0] = 7;
    vec1[4][1] = 1;
    vec1[5][0] = 9;
    vec1[5][1] = -1;
    int ans1 = StrongestSignalPosition(vec1, row1, col1);
    PrintVecElement2D(vec1, row1, col1);
    printf("信号最强的位置是 %d\n", ans1);

    int row2 = 6;
    int col2 = 2;
    int** vec2 = (int**)malloc(sizeof(int*) * row2);
    for(int i = 0; i < row2; i++)
    {
        vec2[i] = (int*)malloc(sizeof(int) * col2);
    } 
    vec2[0][0] = 1;
    vec2[0][1] = -1;
    vec2[1][0] = 3;
    vec2[1][1] = -1;
    vec2[2][0] = 4;
    vec2[2][1] = 1;
    vec2[3][0] = 6;
    vec2[3][1] = -1;
    vec2[4][0] = 7;
    vec2[4][1] = 1;
    vec2[5][0] = 9;
    vec2[5][1] = 1;
    int ans2 = StrongestSignalPosition(vec2, row2, col2);
    PrintVecElement2D(vec2, row2, col2);
    printf("信号最强的位置是 %d\n", ans2);
}

// 前缀和：
// Time: O(N)
// Space: O(N)
int StrongestSignalPosition(int **arr, int row, int col)
{
    int ans = 0;
    int * left = (int *)malloc(sizeof(int) * row);
    memset(left, 0, sizeof(int) * row);
    int * right = (int *)malloc(sizeof(int) * row);
    memset(right, 0, sizeof(int) * row);
    for(int i = 0 ;i < row; i++)
    {
        if(arr[i][0] == 1){
            left[arr[i][1]]++;
        }
    }
}