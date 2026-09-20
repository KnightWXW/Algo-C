#include "../Mybasic/mybasic.h"

//      LeetCode 174. 地下城游戏

//      链接：https://leetcode.cn/problems/dungeon-game/

//      恶魔们抓住了公主并将她关在了地下城 dungeon 的 右下角 。
//      地下城是由 m x n 个房间组成的二维网格。
//      我们英勇的骑士最初被安置在 左上角 的房间里，
//      他必须穿过地下城并通过对抗恶魔来拯救公主。
//      骑士的初始健康点数为一个正整数。
//      如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
//      有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数
//      （若房间里的值为负整数，则表示骑士将损失健康点数）；
//      其他房间要么是空的（房间里的值为 0），
//      要么包含增加骑士健康点数的魔法球
//      （若房间里的值为正整数，则表示骑士将增加健康点数）。
//      为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。
//      返回确保骑士能够拯救到公主所需的最低初始健康点数。
//      注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，
//      包括骑士进入的左上角房间以及公主被监禁的右下角房间。
//      示例 1：
//          输入：dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
//          输出：7
//          解释：如果骑士遵循最佳路径：右 -> 右 -> 下 -> 下 ，
//              则骑士的初始健康点数至少为 7 。
//      示例 2：
//          输入：dungeon = [[0]]
//          输出：1
//      提示：
//          m == dungeon.length
//          n == dungeon[i].length
//          1 <= m, n <= 200
//          -1000 <= dungeon[i][j] <= 1000

int CalculateMinimumHP_A(int **dungeon, int dungeonSize, int *dungeonColSize);
int DFSCalculateMinimumHP_A(int **vec, int row, int col, int i, int j);
int CalculateMinimumHP_B(int **dungeon, int dungeonSize, int *dungeonColSize);
int DFSCalculateMinimumHP_B(int **vec, int row, int col, int i, int j, int **mem);
int CalculateMinimumHP_C(int **dungeon, int dungeonSize, int *dungeonColSize);
int CalculateMinimumHP_D(int **dungeon, int dungeonSize, int *dungeonColSize);

int main()
{
    int r1 = 3;
    int c1 = 3;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = -2;
    vec1[0][1] = -3;
    vec1[0][2] = 3;
    vec1[1][0] = -5;
    vec1[1][1] = -10;
    vec1[1][2] = 1;
    vec1[2][0] = 10;
    vec1[2][1] = 30;
    vec1[2][2] = -5;
    PrintVecElement2D(vec1, r1, c1);
    int ans1 = CalculateMinimumHP_A((int **)vec1, r1, &c1);
    printf("(暴力递归)确保骑士能够拯救到公主所需的最低初始健康点数为：%d。\n", ans1);
    int ans2 = CalculateMinimumHP_B((int **)vec1, r1, &c1);
    printf("(记忆化搜索)确保骑士能够拯救到公主所需的最低初始健康点数为：%d。\n", ans2);
    int ans3 = CalculateMinimumHP_C((int **)vec1, r1, &c1);
    printf("(动态规划)确保骑士能够拯救到公主所需的最低初始健康点数为：%d。\n", ans3);
    int ans4 = CalculateMinimumHP_D((int **)vec1, r1, &c1);
    printf("(动态规划[空间优化])确保骑士能够拯救到公主所需的最低初始健康点数为：%d。\n", ans4);
    FreeVec2D(vec1, r1);
}

int DFSCalculateMinimumHP_A(int **vec, int row, int col, int i, int j)
{
    if (i >= row || j >= col)
    {
        return INT_MAX;
    }
    if (i == row - 1 && j == col - 1)
    {
        return max(1, 1 - vec[i][j]);
    }
    int rightPart = DFSCalculateMinimumHP_A(vec, row, col, i, j + 1);
    int downPart = DFSCalculateMinimumHP_A(vec, row, col, i + 1, j);
    int ans = max(1, min(rightPart, downPart) - vec[i][j]);
    return ans;
}

// 暴力递归
// Time: O(N^2)
// Space: O(N)
int CalculateMinimumHP_A(int **dungeon, int dungeonSize, int *dungeonColSize)
{
    int row = dungeonSize;
    int col = *dungeonColSize;
    return DFSCalculateMinimumHP_A(dungeon, row, col, 0, 0);
}

int DFSCalculateMinimumHP_B(int **vec, int row, int col, int i, int j, int **mem)
{
    if (i >= row || j >= col)
    {
        return INT_MAX;
    }
    if (i == row - 1 && j == col - 1)
    {
        return fmax(1, 1 - vec[i][j]);
    }
    if (mem[i][j] != 0)
    {
        return mem[i][j];
    }
    int rightPart = DFSCalculateMinimumHP_B(vec, row, col, i, j + 1, mem);
    int downPart = DFSCalculateMinimumHP_B(vec, row, col, i + 1, j, mem);
    int ans = fmax(1, fmin(rightPart, downPart) - vec[i][j]);
    mem[i][j] = ans;
    return ans;
}

// 记忆化搜索
// Time:O(N^2)
// Space:O(N)
int CalculateMinimumHP_B(int **dungeon, int dungeonSize, int *dungeonColSize)
{
    int row = dungeonSize;
    int col = *dungeonColSize;
    int **mem = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        mem[i] = (int *)malloc(sizeof(int *) * col);
        memset(mem[i], 0, sizeof(int) * col);
    }
    int ans = DFSCalculateMinimumHP_B(dungeon, row, col, 0, 0, mem);
    for (int i = 0; i < row; i++)
    {
        free(mem[i]);
    }
    return ans;
}

// 动态规划
// Time:O(N*M)
// Space:O(N*M)
int CalculateMinimumHP_C(int **dungeon, int dungeonSize, int *dungeonColSize)
{
    int row = dungeonSize;
    int col = *dungeonColSize;
    int **dp = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        dp[i] = (int *)malloc(sizeof(int *) * col);
        memset(dp[i], 0, sizeof(int) * col);
    }
    dp[row - 1][col - 1] = fmax(1, 1 - dungeon[row - 1][col - 1]);
    for (int i = row - 2; i >= 0; i--)
    {
        dp[i][col - 1] = fmax(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);
    }
    for (int j = col - 2; j >= 0; j--)
    {
        dp[row - 1][j] = fmax(1, dp[row - 1][j + 1] - dungeon[row - 1][j]);
    }
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 2; j >= 0; j--)
        {
            dp[i][j] = fmax(1, fmin(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    int ans = dp[0][0];
    for (int i = 0; i < row; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)
// Time:O(N*M)
// Space:O(N*M)
int CalculateMinimumHP_D(int **dungeon, int dungeonSize, int *dungeonColSize)
{
    int row = dungeonSize;
    int col = *dungeonColSize;
    int *dp = (int *)malloc(sizeof(int) * col);
    memset(dp, 0, sizeof(int) * col);
    dp[col - 1] = fmax(1, 1 - dungeon[row - 1][col - 1]);
    for (int j = col - 2; j >= 0; j--)
    {
        dp[j] = fmax(1, dp[j + 1] - dungeon[row - 1][j]);
    }
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            if (j == col - 1)
            {
                dp[j] = fmax(1, dp[j] - dungeon[i][j]);
            }
            else
            {
                dp[j] = fmax(1, fmin(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }
    }
    int ans = dp[0];
    free(dp);
    return ans;
}