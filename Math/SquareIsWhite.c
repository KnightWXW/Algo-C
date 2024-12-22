#include "../Mybasic/mybasic.h"

//      LeetCode 1812. 判断国际象棋棋盘中一个格子的颜色

//      链接：https://leetcode.cn/problems/determine-color-of-a-chessboard-square/

//      给你一个坐标 coordinates ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。
//      下图是国际象棋棋盘示意图。
//      如果所给格子的颜色是白色，请你返回 true，如果是黑色，请返回 false 。
//      给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。
//      示例 1：
//          输入：coordinates = "a1"
//          输出：false
//          解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
//      示例 2：
//          输入：coordinates = "h3"
//          输出：true
//          解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
//      示例 3：
//          输入：coordinates = "c7"
//          输出：false
//      提示：
//          coordinates.length == 2
//          'a' <= coordinates[0] <= 'h'
//          '1' <= coordinates[1] <= '8'

bool SquareIsWhite(char *coordinates);

int main()
{
    char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char arr2[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char *c1 = GenerateRandomString(1, arr1, 8);
    char *c2 = GenerateRandomString(1, arr2, 8);
    char str[2];
    sprintf(str, "%s%s", c1, c2);
    printf("国际象棋棋盘中格子的坐标为：\n");
    PrintString(str);
    bool ans = SquareIsWhite(str);
    printf("所给格子的颜色是白色吗？\n");
    PrintBool(ans);
    FreeString(c1);
    FreeString(c2);
}

// 数学
// Time: O(1)
// Space: O(1)
bool SquareIsWhite(char *coordinates)
{
    int i = coordinates[0] - 'a';
    int j = coordinates[1] - '1';
    if (((i + j) & 1) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}