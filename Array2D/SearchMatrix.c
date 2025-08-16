#include ".../../Mybasic/mybasic.h"

//      LeetCode 74. 搜索二维矩阵

//      链接：https://leetcode.cn/problems/search-a-2d-matrix/

//      给你一个满足下述两条属性的 m x n 整数矩阵：
//          每行中的整数从左到右按非严格递增顺序排列。
//          每行的第一个整数大于前一行的最后一个整数。
//      给你一个整数 target，如果 target 在矩阵中，返回 true；否则，返回 false
//      示例 1：
//          输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//          输出：true
//      示例 2：
//          输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//          输出：false
//      提示：
//          m == matrix.length
//          n == matrix[i].length
//          1 <= m, n <= 100
//          -104 <= matrix[i][j], target <= 104

bool SearchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target);

int main()
{
    int r1 = 3;
    int c1 = 4;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 3;
    vec1[0][2] = 5;
    vec1[0][3] = 7;
    vec1[1][0] = 10;
    vec1[1][1] = 11;
    vec1[1][2] = 16;
    vec1[1][3] = 20;
    vec1[2][0] = 23;
    vec1[2][1] = 30;
    vec1[2][2] = 34;
    vec1[2][3] = 60;
    PrintVecElement2D(vec1, r1, c1);
    int target1 = 3;
    bool ans1 = SearchMatrix(vec1, r1, &c1, target1);
    printf("%d 在矩阵中吗？\n", target1);
    PrintfBool(ans1);
    FreeVec2D(vec1, r1);
}


bool SearchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{

}
