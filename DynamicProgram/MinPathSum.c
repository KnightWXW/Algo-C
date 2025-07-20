#include "../Mybasic/mybasic.h"

//      LeetCode 64. 最小路径和

//      链接: https://leetcode.cn/problems/minimum-path-sum/

//      给定一个包含非负整数的 m x n 网格 grid ，
//      请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//      说明：每次只能向下或者向右移动一步。
//      示例 1：
//          输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//          输出：7
//      解释：因为路径 1→3→1→1→1 的总和最小。
//      示例 2：
//          输入：grid = [[1,2,3],[4,5,6]]
//          输出：12
//      提示：
//          m == grid.length
//          n == grid[i].length
//          1 <= m, n <= 200
//          0 <= grid[i][j] <= 100

int MinPathSum_A(int **grid, int gridSize, int *gridColSize);
int DFSMinPathSum_A(int **grid, int i, int j);
int MinPathSum_B(int **grid, int gridSize, int *gridColSize);
int DFSMinPathSum_B(int **grid, int i, int j, int **mem);
int MinPathSum_C(int **grid, int gridSize, int *gridColSize);
int MinPathSum_D(int **grid, int gridSize, int *gridColSize);
int MinPathSum_E(int **grid, int gridSize, int *gridColSize);

int main()
{
    int r1 = 3;
    int c1 = 3;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 3;
    vec1[0][2] = 1;
    vec1[1][0] = 1;
    vec1[1][1] = 5;
    vec1[1][2] = 1;
    vec1[2][0] = 4;
    vec1[2][1] = 2;
    vec1[2][2] = 1;
    PrintVecElement2D(vec1, r1, c1);
    int ansA = MinPathSum_A(vec1, r1, &c1);
    int ansB = MinPathSum_B(vec1, r1, &c1);
    int ansC = MinPathSum_C(vec1, r1, &c1);
    int ansD = MinPathSum_D(vec1, r1, &c1);
    int ansE = MinPathSum_E(vec1, r1, &c1);
    printf("暴力递归: 矩阵的最小路径和 为 %d\n", ansA);
    printf("记忆化搜索: 矩阵的最小路径和 为 %d\n", ansB);
    printf("动态规划: 矩阵的最小路径和 为 %d\n", ansC);
    printf("动态规划(空间优化1): 矩阵的最小路径和 为 %d\n", ansD);
    printf("动态规划(空间优化2): 矩阵的最小路径和 为 %d\n", ansE);
    FreeVec2D(vec1, r1);
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N))
int MinPathSum_A(int **grid, int gridSize, int *gridColSize)
{
    return DFSMinPathSum_A(grid, gridSize - 1, *gridColSize - 1);
}

int DFSMinPathSum_A(int **grid, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }
    if (i == 0)
    {
        return DFSMinPathSum_A(grid, i, j - 1) + grid[i][j];
    }
    if (j == 0)
    {
        return DFSMinPathSum_A(grid, i - 1, j) + grid[i][j];
    }
    int a1 = DFSMinPathSum_A(grid, i - 1, j);
    int a2 = DFSMinPathSum_A(grid, i, j - 1);
    return min(a1, a2) + grid[i][j];
}

// 记忆化搜索:
// Time: O(2^(M*N))
// Space: O(M*N)
int MinPathSum_B(int **grid, int gridSize, int *gridColSize)
{
    int **mem = (int **)malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (*gridColSize));
        memset(mem[i], -1, sizeof(int) * (*gridColSize));
    }
    int ans = DFSMinPathSum_B(grid, gridSize - 1, *gridColSize - 1, mem);
    for (int i = 0; i < gridSize; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSMinPathSum_B(int **grid, int i, int j, int **mem)
{
    if (i == 0 && j == 0)
    {
        mem[i][j] = grid[i][j];
        return grid[i][j];
    }
    if (i == 0)
    {
        mem[i][j] = DFSMinPathSum_B(grid, i, j - 1, mem) + grid[i][j];
        return mem[i][j];
    }
    if (j == 0)
    {
        mem[i][j] = DFSMinPathSum_B(grid, i - 1, j, mem) + grid[i][j];
        return mem[i][j];
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int a1 = DFSMinPathSum_B(grid, i - 1, j, mem);
    int a2 = DFSMinPathSum_B(grid, i, j - 1, mem);
    mem[i][j] = min(a1, a2) + grid[i][j];
    return mem[i][j];
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int MinPathSum_C(int **grid, int gridSize, int *gridColSize)
{
    int **dp = (int **)malloc(sizeof(int *) * (gridSize));
    for (int i = 0; i < gridSize; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (*gridColSize));
        memset(dp[i], 0, sizeof(int) * (*gridColSize));
    }
    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < (*gridColSize); j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = 1; j < (*gridColSize); j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    int ans = dp[gridSize - 1][*gridColSize - 1];
    for (int i = 0; i < gridSize; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化):
// Time: O(M * N)
// Space: O(N)
int MinPathSum_D(int **grid, int gridSize, int *gridColSize)
{
    int *dp = (int *)malloc(sizeof(int) * (*gridColSize + 1));
    memset(dp, 0, sizeof(int) * (*gridColSize + 1));
    for (int i = 0; i <= (*gridColSize); i++)
    {
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < (*gridColSize); j++)
        {
            dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j];
        }
    }
    int ans = dp[*gridColSize];
    free(dp);
    return ans;
}

// 动态规划(空间优化[原地修改]):
// Time: O(M * N)
// Space: O(1)
int MinPathSum_E(int **grid, int gridSize, int *gridColSize)
{
    for (int i = 1; i < gridSize; i++)
    {
        grid[i][0] += grid[i - 1][0];
    }
    for (int j = 1; j < (*gridColSize); j++)
    {
        grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = 1; j < (*gridColSize); j++)
        {
            grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
    }
    int ans = grid[gridSize - 1][*gridColSize - 1];
    return ans;
}