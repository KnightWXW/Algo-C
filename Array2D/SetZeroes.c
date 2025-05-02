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
//                 [1,0,3,1,0]]
//      提示：
//          m == matrix.length
//          n == matrix[0].length
//          1 <= m, n <= 200
//          -231 <= matrix[i][j] <= 231 - 1
//      进阶：
//          一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//          一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//          你能想出一个仅使用常量空间的解决方案吗？

void SetZeroes_A(int** matrix, int matrixSize, int* matrixColSize);
void SetZeroes_B(int** matrix, int matrixSize, int* matrixColSize);
void SetZeroes_C(int** matrix, int matrixSize, int* matrixColSize);

int main()
{
    int row = GenerateRandomNum(1, 10);
    int col = GenerateRandomNum(1, 10);
    int** vec = GenerateRandomVec2D(0, 10, row, col);
    printf("数组元素为：\n");
    PrintVecElement2D(vec, row, col);
    SetZeroes_A(vec, row, col);
    SetZeroes_B(vec, row, col);
    SetZeroes_C(vec, row, col);
    printf("数组置零后为：\n");
    print2DVecElement(ans_A);
    print2DVecElement(ans_B);
    print2DVecElement(ans_C);
}

void SetZeroes_A(int** matrix, int matrixSize, int* matrixColSize)
{

}