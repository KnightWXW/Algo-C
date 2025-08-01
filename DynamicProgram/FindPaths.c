#include "../Mybasic/mybasic.h"

//      LeetCode 576. 出界的路径数

//      链接: https://leetcode.cn/problems/out-of-boundary-paths/

//      给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。
//      你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。
//      你 最多 可以移动 maxMove 次球。
//      给你五个整数 m、n、maxMove、startRow 以及 startColumn，
//      找出并返回可以将球移出边界的路径数量。
//      因为答案可能非常大，返回对 109 + 7 取余 后的结果。
//      示例 1：
//          输入：m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
//          输出：6
//      示例 2：
//          输入：m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
//          输出：12
//      提示：
//          1 <= m, n <= 50
//          0 <= maxMove <= 50
//          0 <= startRow < m
//          0 <= startColumn < n

int FindPaths_A(int m, int n, int maxMove, int startRow, int startColumn);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int m = GenerateRandomNum(1, 21);
    int maxMove = GenerateRandomNum(0, 30);
    int startRow = GenerateRandomNum(0, m);
    int startCol = GenerateRandomNum(0, n);
    int ansA = FindPaths_A(m, n, maxMove, startRow, startCol);
    printf("暴力递归: %d × %d网格, 起始坐标为[%d, %d], 球移动 %d 次, 移出边界的路径数量为 %d\n", m, n, startRow,startCol, maxMove, ansA);
}

