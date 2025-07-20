#include "../Mybasic/mybasic.h"

//      LeetCode 221. 最大正方形

//      链接：https://leetcode.cn/problems/maximal-square/

//      在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
//      示例 1：
//          输入：matrix = [["1","0","1","0","0"],
//                          ["1","0","1","1","1"],
//                          ["1","1","1","1","1"],
//                          ["1","0","0","1","0"]]
//          输出：4
//      示例 2：
//          输入：matrix = [["0","1"],["1","0"]]
//          输出：1
//      示例 3：
//          输入：matrix = [["0"]]
//          输出：0
//      提示：
//          m == matrix.length
//          n == matrix[i].length
//          1 <= m, n <= 300
//          matrix[i][j] 为 '0' 或 '1'

int MaximalSquare_A(char **matrix, int matrixSize, int *matrixColSize);

int main()
{
    int r1 = 4;
    int c1 = 5;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 0;
    vec1[0][2] = 1;
    vec1[0][3] = 0;
    vec1[0][4] = 0;
    vec1[1][0] = 1;
    vec1[1][1] = 0;
    vec1[1][2] = 1;
    vec1[1][3] = 1;
    vec1[1][4] = 1;
    vec1[2][0] = 1;
    vec1[2][1] = 1;
    vec1[2][2] = 1;
    vec1[2][3] = 1;
    vec1[2][4] = 1;
    vec1[3][0] = 1;
    vec1[3][1] = 0;
    vec1[3][2] = 0;
    vec1[3][3] = 1;
    vec1[3][4] = 0;
    PrintVecElement2D(vec1, r1, c1);
    int ansA = MaximalSquare_A(vec1, r1, &c1);
    int ansB = MaximalSquare_B(vec1, r1, &c1);
    int ansC = MaximalSquare_C(vec1, r1, &c1);
    int ansD = MaximalSquare_D(vec1, r1, &c1);
    int ansE = MaximalSquare_E(vec1, r1, &c1);
    printf("暴力递归: 只包含 '1' 的最大正方形 的面积 为 %d\n", ansA);
    printf("记忆化搜索: 只包含 '1' 的最大正方形 的面积  为 %d\n", ansB);
    printf("动态规划: 只包含 '1' 的最大正方形 的面积  为 %d\n", ansC);
    printf("动态规划(空间优化1): 只包含 '1' 的最大正方形 的面积  为 %d\n", ansD);
    printf("动态规划(空间优化2): 只包含 '1' 的最大正方形 的面积  为 %d\n", ansE);
    FreeVec2D(vec1, r1);
}

int MaximalSquare_A(char **matrix, int matrixSize, int *matrixColSize)
{
    
}