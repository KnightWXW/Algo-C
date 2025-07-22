#include "../Mybasic/mybasic.h"

//      LeetCode 931. 下降路径最小和

//      链接：https://leetcode.cn/problems/minimum-falling-path-sum/

//      给你一个 n x n 的 方形 整数数组 matrix，
//      请你找出并返回通过 matrix 的下降路径 的 最小和 。
//      下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
//      在下一行选择的元素和当前行所选元素最多相隔一列
//      （即位于正下方或者沿对角线向左或者向右的第一个元素）。
//      具体来说，位置 (row, col) 的下一个元素应当是
//       (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
//      示例 1：
//          输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
//          输出：13
//          解释：如图所示，为和最小的两条下降路径
//      示例 2：
//          输入：matrix = [[-19,57],[-40,-5]]
//          输出：-59
//          解释：如图所示，为和最小的下降路径
//      提示：
//          n == matrix.length == matrix[i].length
//          1 <= n <= 100
//          -100 <= matrix[i][j] <= 100

int MinFallingPathSum_A(int **matrix, int matrixSize, int *matrixColSize);
int DFSMinFallingPathSum_A(int **matrix, int col, int i, int j);
int MinFallingPathSum_B(int **matrix, int matrixSize, int *matrixColSize);
int DFSMinFallingPathSum_B(int **matrix, int col, int i, int j, int **mem);
int MinFallingPathSum_C(int **matrix, int matrixSize, int *matrixColSize);
int MinFallingPathSum_D(int **matrix, int matrixSize, int *matrixColSize);
int MinFallingPathSum_E(int **matrix, int matrixSize, int *matrixColSize);
int main()
{
    int r1 = 3;
    int c1 = 3;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 2;
    vec1[0][1] = 1;
    vec1[0][2] = 3;
    vec1[1][0] = 6;
    vec1[1][1] = 5;
    vec1[1][2] = 4;
    vec1[2][0] = 7;
    vec1[2][1] = 8;
    vec1[2][2] = 9;
    PrintVecElement2D(vec1, r1, c1);
    int ansA = MinFallingPathSum_A(vec1, r1, &c1);
    int ansB = MinFallingPathSum_B(vec1, r1, &c1);
    int ansC = MinFallingPathSum_C(vec1, r1, &c1);
    int ansD = MinFallingPathSum_D(vec1, r1, &c1);
    int ansE = MinFallingPathSum_E(vec1, r1, &c1);
    printf("暴力递归: 矩阵的下降路径最小和 为 %d\n", ansA);
    printf("记忆化搜索: 矩阵的下降路径最小和 为 %d\n", ansB);
    printf("动态规划: 矩阵的下降路径最小和 为 %d\n", ansC);
    printf("动态规划(空间优化1): 矩阵的下降路径最小和 为 %d\n", ansD);
    printf("动态规划(空间优化2): 矩阵的下降路径最小和 为 %d\n", ansE);
    FreeVec2D(vec1, r1);
}

// 暴力递归：
// Time: O(2^(M*N))
// Space: O((M*N))
int MinFallingPathSum_A(int **matrix, int matrixSize, int *matrixColSize)
{
    int ans = INT_MAX;
    for (int i = 0; i < (*matrixColSize); i++)
    {
        ans = min(ans, DFSMinFallingPathSum_A(matrix, *matrixColSize, matrixSize - 1, i));
    }
    return ans;
}

int DFSMinFallingPathSum_A(int **matrix, int col, int i, int j)
{
    if (i == 0)
    {
        return matrix[i][j];
    }
    if (j == 0)
    {
        int a1 = DFSMinFallingPathSum_A(matrix, col, i - 1, j);
        int a2 = DFSMinFallingPathSum_A(matrix, col, i - 1, j + 1);
        return min(a1, a2) + matrix[i][j];
    }
    if (j == col - 1)
    {
        int a1 = DFSMinFallingPathSum_A(matrix, col, i - 1, j);
        int a2 = DFSMinFallingPathSum_A(matrix, col, i - 1, j - 1);
        return min(a1, a2) + matrix[i][j];
    }
    int a1 = DFSMinFallingPathSum_A(matrix, col, i - 1, j);
    int a2 = DFSMinFallingPathSum_A(matrix, col, i - 1, j - 1);
    int a3 = DFSMinFallingPathSum_A(matrix, col, i - 1, j + 1);
    int ans = min(a1, min(a2, a3)) + matrix[i][j];
    return ans;
}

// 记忆化搜索：
// Time: O(2^(M*N))
// Space: O((M*N))
int MinFallingPathSum_B(int **matrix, int matrixSize, int *matrixColSize)
{
    int ans = INT_MAX;
    int **mem = (int **)malloc(sizeof(int *) * (matrixSize));
    for (int i = 0; i < matrixSize; i++)
    {
        mem[i] = (int *)malloc(sizeof(int) * (*matrixColSize));
        memset(mem[i], -1, sizeof(int) * (*matrixColSize));
    }
    for (int i = 0; i < (*matrixColSize); i++)
    {
        ans = min(ans, DFSMinFallingPathSum_B(matrix, *matrixColSize, matrixSize - 1, i, mem));
    }
    for (int i = 0; i < matrixSize; i++)
    {
        free(mem[i]);
    }
    return ans;
}

int DFSMinFallingPathSum_B(int **matrix, int col, int i, int j, int **mem)
{
    if (i == 0)
    {
        mem[i][j] = matrix[i][j];
        return matrix[i][j];
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    if (j == 0)
    {
        int a1 = DFSMinFallingPathSum_B(matrix, col, i - 1, j, mem);
        int a2 = DFSMinFallingPathSum_B(matrix, col, i - 1, j + 1, mem);
        mem[i][j] = min(a1, a2) + matrix[i][j];
        return mem[i][j];
    }
    if (j == col - 1)
    {
        int a1 = DFSMinFallingPathSum_B(matrix, col, i - 1, j, mem);
        int a2 = DFSMinFallingPathSum_B(matrix, col, i - 1, j - 1, mem);
        mem[i][j] = min(a1, a2) + matrix[i][j];
        return mem[i][j];
    }
    int a1 = DFSMinFallingPathSum_B(matrix, col, i - 1, j, mem);
    int a2 = DFSMinFallingPathSum_B(matrix, col, i - 1, j - 1, mem);
    int a3 = DFSMinFallingPathSum_B(matrix, col, i - 1, j + 1, mem);
    mem[i][j] = min(a1, min(a2, a3)) + matrix[i][j];
    return mem[i][j];
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int MinFallingPathSum_C(int **matrix, int matrixSize, int *matrixColSize)
{
    int ans = INT_MAX;
    int **dp = (int **)malloc(sizeof(int *) * (matrixSize));
    for (int i = 0; i < matrixSize; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (*matrixColSize));
        memset(dp[i], -1, sizeof(int) * (*matrixColSize));
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < (*matrixColSize); j++)
        {
            if (i == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else
            {
                if (j == 0)
                {
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j]) + matrix[i][j];
                }
                else if (j == (*matrixColSize) - 1)
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + matrix[i][j];
                }
            }
        }
    }
    for (int j = 0; j < (*matrixColSize); j++)
    {
        ans = min(ans, dp[matrixSize - 1][j]);
    }
    for (int i = 0; i < matrixSize; i++)
    {
        free(dp[i]);
    }
    return ans;
}

// 动态规划(空间优化)：
// Time: O(M * N)
// Space: O(N)
int MinFallingPathSum_D(int **matrix, int matrixSize, int *matrixColSize)
{
    int ans = INT_MAX;
    int *dp = (int *)malloc(sizeof(int) * (*matrixColSize));
    memset(dp, 0, sizeof(int) * (*matrixColSize));
    int *dp1 = (int *)malloc(sizeof(int) * (*matrixColSize));
    memset(dp1, 0, sizeof(int) * (*matrixColSize));
    for (int i = 0; i < (*matrixColSize); i++)
    {
        dp[i] = matrix[0][i];
    }
    for (int i = 1; i < matrixSize; i++)
    {
        memcpy(dp1, dp, sizeof(int) * (*matrixColSize));
        for (int j = 0; j < (*matrixColSize); j++)
        {
            if (j == 0)
            {
                dp[j] = min(dp1[j + 1], dp1[j]) + matrix[i][j];
            }
            else if (j == (*matrixColSize) - 1)
            {
                dp[j] = min(dp1[j - 1], dp1[j]) + matrix[i][j];
            }
            else
            {
                dp[j] = min(dp1[j], min(dp1[j - 1], dp1[j + 1])) + matrix[i][j];
            }
        }
    }
    for (int j = 0; j < (*matrixColSize); j++)
    {
        ans = min(ans, dp[j]);
    }
    free(dp);
    free(dp1);
    return ans;
}

// 动态规划(空间优化[原地修改])：
// Time: O(M * N)
// Space: O(1)
int MinFallingPathSum_E(int **matrix, int matrixSize, int *matrixColSize)
{
    int ans = INT_MAX;
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 0; j < (*matrixColSize); j++)
        {
            if (j == 0)
            {
                matrix[i][j] = min(matrix[i - 1][j + 1], matrix[i - 1][j]) + matrix[i][j];
            }
            else if (j == (*matrixColSize) - 1)
            {
                matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i - 1][j]) + matrix[i][j];
            }
            else
            {
                matrix[i][j] = min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i - 1][j + 1])) + matrix[i][j];
            }
        }
    }
    for (int j = 0; j < (*matrixColSize); j++)
    {
        ans = min(ans, matrix[matrixSize - 1][j]);
    }
    return ans;
}
