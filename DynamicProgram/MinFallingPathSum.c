#include "../Mybasic/mybasic.h"

//      931. 下降路径最小和

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

int MinFallingPathSum_A(int** matrix, int matrixSize, int* matrixColSize);

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
int MinFallingPathSum_A(int** matrix, int matrixSize, int* matrixColSize)
{

}