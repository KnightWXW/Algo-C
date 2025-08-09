#include "../Mybasic/mybasic.h"

//      LeetCode 73. 矩阵置零

//      链接：https://leetcode.cn/problems/set-matrix-zeroes/

//      给定一个m x n的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0。
//      请使用 原地 算法。
//      示例 1：
//          输入：matrix = [[1,1,1],
//                          [1,0,1],
//                          [1,1,1]]
//          输出：[[1,0,1],
//                 [0,0,0],
//                 [1,0,1]]
//      示例 2：
//          输入：matrix = [[0,1,2,0],
//                          [3,4,5,2],
//                          [1,3,1,5]]
//          输出：[[0,0,0,0],
//                 [0,4,5,0],
//                 [0,3,1,0]]
//      提示：
//          m == matrix.length
//          n == matrix[0].length
//          1 <= m, n <= 200
//          -231 <= matrix[i][j] <= 231 - 1
//      进阶：
//          一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//          一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//          你能想出一个仅使用常量空间的解决方案吗？

void SetZeroes_A(int **matrix, int matrixSize, int *matrixColSize);
void SetZeroes_B(int **matrix, int matrixSize, int *matrixColSize);
void SetZeroes_C(int **matrix, int matrixSize, int *matrixColSize);

int main()
{
    int row0 = GenerateRandomNum(1, 10);
    int col0 = GenerateRandomNum(1, 10);
    int **vec0 = GenerateRandomVec2D(0, 10, row0, col0);
    // int row1 = GenerateRandomNum(1, 10);
    // int col1 = GenerateRandomNum(1, 10);
    // int **vec1 = GenerateRandomVec2D(0, 10, row1, col1);
    // int row2 = GenerateRandomNum(1, 10);
    // int col2 = GenerateRandomNum(1, 10);
    // int **vec2 = GenerateRandomVec2D(0, 10, row2, col2);
    printf("二维数组元素为：\n");
    PrintVecElement2D(vec0, row0, col0);
    // PrintVecElement2D(vec1, row1, col1);
    // PrintVecElement2D(vec2, row2, col2);
    SetZeroes_A(vec0, row0, &col0);
    // SetZeroes_B(vec1, row1, &col1);
    // SetZeroes_C(vec2, row2, &col2);
    printf("数组置零后为：\n");
    PrintVecElement2D(vec0, row0, col0);
}

// 标记数组：
// Time: O(M * N)
// Space: O(M + N)
void SetZeroes_A(int **matrix, int matrixSize, int *matrixColSize)
{
    int *rowVec = (int *)malloc(sizeof(int) * matrixSize);
    memset(rowVec, -1, sizeof(int) * matrixSize);
    int *colVec = (int *)malloc(sizeof(int) * (*matrixColSize));
    memset(colVec, -1, sizeof(int) * (*matrixColSize));
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < (*matrixColSize); j++)
        {
            if (matrix[i][j] == 0)
            {
                rowVec[i] = 0;
                colVec[j] = 0;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < (*matrixColSize); j++)
        {
            if (rowVec[i] == 0 || colVec[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    free(rowVec);
    free(colVec);
    return;
}