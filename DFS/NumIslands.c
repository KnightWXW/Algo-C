#include "../Mybasic/mybasic.h"

//      LeetCode 200. 岛屿数量

//      链接：https://leetcode.cn/problems/number-of-islands/

//      给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//      岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//      此外，你可以假设该网格的四条边均被水包围。
//      示例 1：
//          输入：grid = [
//                  ["1","1","1","1","0"],
//                  ["1","1","0","1","0"],
//                  ["1","1","0","0","0"],
//                  ["0","0","0","0","0"]
//              ]
//          输出：1
//      示例 2：
//          输入：grid = [
//                  ["1","1","0","0","0"],
//                  ["1","1","0","0","0"],
//                  ["0","0","1","0","0"],
//                  ["0","0","0","1","1"]
//              ]
//          输出：3
//      提示：
//          m == grid.length
//          n == grid[i].length
//          1 <= m, n <= 300
//          grid[i][j] 的值为 '0' 或 '1'

void DFSNumIslands(int **grid, int row, int col, int x, int y);
int NumIslands(int **grid, int gridSize, int *gridColSize);

int main(void)
{
    int row0 = GenerateRandomNum(1, 6);
    int col0 = GenerateRandomNum(1, 6);
    int **vec0 = GenerateRandomVec2D(0, 1, row0, col0);
    printf("二维数组元素为：\n");
    PrintVecElement2D(vec0, row0, col0);
    int ansA = NumIslands(vec0, row0, &col0);
    printf("岛屿数量为：%d\n", ansA);
    FreeVec2D(vec0, row0);
}

void DFSNumIslands(int **grid, int row, int col, int x, int y)
{
    if (grid[x][y] == 1)
    {
        grid[x][y] = 0;
    }
    else
    {
        return;
    }

    if (x != 0)
    {
        DFSNumIslands(grid, row, col, x - 1, y);
    }
    if (x != row - 1)
    {
        DFSNumIslands(grid, row, col, x + 1, y);
    }
    if (y != 0)
    {
        DFSNumIslands(grid, row, col, x, y - 1);
    }
    if (y != col - 1)
    {
        DFSNumIslands(grid, row, col, x, y + 1);
    }
    return;
}

// BFS
// Time: O(M * N)
// Space: O(1)
int NumIslands(int **grid, int gridSize, int *gridColSize)
{
    int ans = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < (*gridColSize); j++)
        {
            if (grid[i][j] == 1)
            {
                DFSNumIslands(grid, gridSize, (*gridColSize), i, j);
                ans++;
            }
        }
    }
    return ans;
}