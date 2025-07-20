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

int UniquePathsWithObstacles_A(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);

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
int UniquePathsWithObstacles_A(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);
{
    
}