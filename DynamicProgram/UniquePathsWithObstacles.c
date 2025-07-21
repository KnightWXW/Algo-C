#include "../Mybasic/mybasic.h"

//      LeetCode 63. 不同路径 II

//      链接：https://leetcode.cn/problems/unique-paths-ii/

//      给定一个 m x n 的整数数组 grid。
//      一个机器人初始位于 左上角（即 grid[0][0]）。
//      机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。
//      机器人每次只能向下或者向右移动一步。
//      网格中的障碍物和空位置分别用 1 和 0 来表示。
//      机器人的移动路径中不能包含 任何 有障碍物的方格。
//      返回机器人能够到达右下角的不同路径数量。
//      测试用例保证答案小于等于 2 * 109。
//      示例 1：
//          输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//          输出：2
//          解释：3x3 网格的正中间有一个障碍物。
//              从左上角到右下角一共有 2 条不同的路径：
//              1. 向右 -> 向右 -> 向下 -> 向下
//              2. 向下 -> 向下 -> 向右 -> 向右
//      示例 2：
//          输入：obstacleGrid = [[0,1],[0,0]]
//          输出：1
//      提示：
//          m == obstacleGrid.length
//          n == obstacleGrid[i].length
//          1 <= m, n <= 100
//          obstacleGrid[i][j] 为 0 或 1

int UniquePathsWithObstacles_A(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize);
int DFSUniquePathsWithObstacles_A(int **mat, int i, int j);
int UniquePathsWithObstacles_B(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize);
int DFSUniquePathsWithObstacles_B(int **mat, int i, int j, int**mem);
int UniquePathsWithObstacles_C(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize);
int UniquePathsWithObstacles_D(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize);

int UniquePathsWithObstacles_E(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize);

int main()
{
    int r1 = 3;
    int c1 = 3;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 0;
    vec1[0][1] = 0;
    vec1[0][2] = 0;
    vec1[1][0] = 0;
    vec1[1][1] = 1;
    vec1[1][2] = 0;
    vec1[2][0] = 0;
    vec1[2][1] = 0;
    vec1[2][2] = 0;
    PrintVecElement2D(vec1, r1, c1);
    int ansA = UniquePathsWithObstacles_A(vec1, r1, &c1);
    int ansB = UniquePathsWithObstacles_B(vec1, r1, &c1);
    int ansC = UniquePathsWithObstacles_C(vec1, r1, &c1);
    int ansD = UniquePathsWithObstacles_D(vec1, r1, &c1);
    int ansE = UniquePathsWithObstacles_E(vec1, r1, &c1);
    printf("暴力递归: 机器人能够到达右下角的不同路径数量 为 %d\n", ansA);
    printf("记忆化搜索: 机器人能够到达右下角的不同路径数量 为 %d\n", ansB);
    printf("动态规划: 机器人能够到达右下角的不同路径数量 为 %d\n", ansC);
    printf("动态规划(空间优化1): 机器人能够到达右下角的不同路径数量 为 %d\n", ansD);
    printf("动态规划(空间优化2): 机器人能够到达右下角的不同路径数量 为 %d\n", ansE);
    FreeVec2D(vec1, r1);
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N))
int UniquePathsWithObstacles_A(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    return DFSUniquePathsWithObstacles_A(obstacleGrid, obstacleGridSize - 1, *obstacleGridColSize - 1);
}

int DFSUniquePathsWithObstacles_A(int **mat, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return mat[i][j] == 0 ? 1 : 0;
    }
    if (i == 0)
    {
        return mat[0][j] == 0 ? DFSUniquePathsWithObstacles_A(mat, i, j - 1) : 0;
    }
    if (j == 0)
    {
        return mat[i][0] == 0 ? DFSUniquePathsWithObstacles_A(mat, i - 1, j) : 0;
    }
    if (mat[i][j] == 0)
    {
        return DFSUniquePathsWithObstacles_A(mat, i, j - 1) + DFSUniquePathsWithObstacles_A(mat, i - 1, j);
    }
    else
    {
        return 0;
    }
}

// 记忆化搜索：
// Time: O(2^(M*N))
// Space: O((M*N))
int UniquePathsWithObstacles_B(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int **mem = (int **)malloc(sizeof(int *) * obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (*obstacleGridColSize));
        memset(mem[i], -1, sizeof(int) * (*obstacleGridColSize));
    }
    int ans = DFSUniquePathsWithObstacles_B(obstacleGrid, obstacleGridSize - 1, *obstacleGridColSize - 1, mem);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSUniquePathsWithObstacles_B(int **mat, int i, int j, int **mem)
{
    if (i == 0 && j == 0)
    {
        mem[i][j] = (mat[i][j] == 0 ? 1 : 0);
        return mem[i][j];
    }
    if (i == 0)
    {
        mem[i][j] = (mat[0][j] == 0 ? DFSUniquePathsWithObstacles_B(mat, i, j - 1, mem) : 0);
        return mem[i][j];
    }
    if (j == 0)
    {
        mem[i][j] = (mat[i][0] == 0 ? DFSUniquePathsWithObstacles_B(mat, i - 1, j, mem) : 0);
        return mem[i][j];
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    if (mat[i][j] == 0)
    {
        mem[i][j] = DFSUniquePathsWithObstacles_B(mat, i, j - 1, mem) + DFSUniquePathsWithObstacles_B(mat, i - 1, j, mem);
        return mem[i][j];
    }
    else
    {
        mem[i][j] = 0;
        return 0;
    }
}

// 动态规划:
// Time: O(M * N)
// Space: O(M * N)
int UniquePathsWithObstacles_C(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int **dp = (int **)malloc(sizeof(int *) * obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (*obstacleGridColSize));
        memset(dp[i], 0, sizeof(int) * (*obstacleGridColSize));
    }
    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 1; i < obstacleGridSize; i++)
    {
        dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
    }
    for (int j = 1; j < (*obstacleGridColSize); j++)
    {
        dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j - 1] : 0;
    }
    for (int i = 1; i < obstacleGridSize; i++)
    {
        for (int j = 1; j < (*obstacleGridColSize); j++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int ans = dp[obstacleGridSize - 1][(*obstacleGridColSize) - 1];
    for (int i = 0; i < obstacleGridSize; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化1)：
// Time: O(M * N)
// Space: O(N)
int UniquePathsWithObstacles_D(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int *dp = (int *)malloc(sizeof(int) * (*obstacleGridColSize));
    memset(dp, 0, sizeof(int) * (*obstacleGridColSize));
    dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int j = 1; j < (*obstacleGridColSize); j++)
    {
        dp[j] = obstacleGrid[0][j] == 0 ? dp[j - 1] : 0;
    }
    for (int i = 1; i < obstacleGridSize; i++)
    {
        for (int j = 0; j < (*obstacleGridColSize); j++)
        {
            if (j == 0)
            {
                dp[0] = obstacleGrid[i][0] == 0 ? dp[0] : 0;
            }
            else
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[j] += dp[j - 1];
                }
                else
                {
                    dp[j] = 0;
                }
            }
        }
    }
    int ans = dp[(*obstacleGridColSize) - 1];
    free(dp);
    return ans;
}

// 动态规划(空间优化2[原地修改])：
// Time: O(M * N)
// Space: O(1)
int UniquePathsWithObstacles_E(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    obstacleGrid[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 1; i < obstacleGridSize; i++)
    {
        obstacleGrid[i][0] = obstacleGrid[i][0] == 0 ? obstacleGrid[i - 1][0] : 0;
    }
    for (int j = 1; j < (*obstacleGridColSize); j++)
    {
        obstacleGrid[0][j] = obstacleGrid[0][j] == 0 ? obstacleGrid[0][j - 1] : 0;
    }
    for (int i = 1; i < obstacleGridSize; i++)
    {
        for (int j = 1; j < (*obstacleGridColSize); j++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
            else
            {
                obstacleGrid[i][j] = 0;
            }
        }
    }
    int ans = obstacleGrid[obstacleGridSize - 1][(*obstacleGridColSize) - 1];
    return ans;
}