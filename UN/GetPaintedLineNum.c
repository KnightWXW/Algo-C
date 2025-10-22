#include "../Mybasic/mybasic.h"

//      Huawei: 贴瓷砖

//      美工想用瓷砖在墙上贴出一幅画，把墙面划分为若干大小相同的正方形小格，
//      可视墙面为 rows * cols 的二维矩阵，左上角格子位置为 [0, 0]
//      假定二维矩阵中的行与地面平行，列与地面垂直。
//      二维数组positions中的每个元素表示美工已经贴好的瓷砖所在位置，
//      现给出一组线段，记为二维数组lines中，线段仅与地面平行，垂直，或与地面呈45/135度角，
//      lines[i]的格式为[起点行下标，起点列下标，终点行下标，终点列下标]。
//      请判断lines中有多少条线段被已贴好瓷砖的格子完全覆盖，返回数量。
//      输入：rows = 3 cols = 4
//          lines = {{1, 1, 2, 2}, {2, 1, 0, 3}}
//          positions = {{0, 1}, {1, 1}, {2, 2}}
//      输出：1
//      输入：rows = 7 cols = 6
//          lines = {{3, 5, 0, 2}, {0, 3, 2, 3}, {4, 2, 6, 4}, {3, 1, 6, 4}}
//          positions = {{0, 1}, {2, 4}, {1, 3}, {3, 3}, {4, 2}, {5, 5}, {5, 3}, {6, 4}}
//      输出：1

int main()
{
    int rows1 = 3;
    int cols1 = 4;
    vector<vector<int>> lines1 = {{1, 1, 2, 2}, {2, 1, 0, 3}};
    vector<vector<int>> positions1 = {{0, 1}, {1, 1}, {2, 2}};
    int ans_A = GetPaintedLineNum(rows1, cols1, lines1, positions1);
    print2DVecElement(lines1);
    print2DVecElement(positions1);
    printf("rows为%d, cols为%d, 有 %d 条线段被已贴好瓷砖的格子完全覆盖。\n", rows1, cols1, ans_A);
    int rows2 = 7;
    int cols2 = 6;
    vector<vector<int>> lines2 = {{3, 5, 0, 2}, {0, 3, 2, 3}, {4, 2, 6, 4}, {3, 1, 6, 4}};
    vector<vector<int>> positions2 = {{0, 1}, {2, 4}, {1, 3}, {3, 3}, {4, 2}, {5, 5}, {5, 3}, {6, 4}};
    int ans_B = GetPaintedLineNum(rows2, cols2, lines2, positions2);
    print2DVecElement(lines2);
    print2DVecElement(positions2);
    printf("rows为%d, cols为%d, 有 %d 条线段被已贴好瓷砖的格子完全覆盖。\n", rows2, cols2, ans_B);
}

int GetPaintedLineNum(int rows, int cols, int** lines, int** positions)
{
    
}