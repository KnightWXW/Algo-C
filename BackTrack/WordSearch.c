#include "../Mybasic/mybasic.h"

//      LeetCode 79. 单词搜索

//      链接：https://leetcode.cn/problems/word-search/

//      给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
//      如果 word 存在于网格中，返回 true ；否则，返回 false 。
//      单词必须按照字母顺序，通过相邻的单元格内的字母构成，
//      其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
//      同一个单元格内的字母不允许被重复使用。
//      示例 1：
//          输入：board = [["A","B","C","E"],
//                        ["S","F","C","S"],
//                        ["A","D","E","E"]],
//              word = "ABCCED"
//          输出：true
//      示例 2：
//          输入：board = [["A","B","C","E"],
//                         ["S","F","C","S"],
//                         ["A","D","E","E"]],
//              word = "SEE"
//          输出：true
//      示例 3：
//          输入：board = [["A","B","C","E"],
//                         ["S","F","C","S"],
//                         ["A","D","E","E"]],
//              word = "ABCB"
//          输出：false
//      提示：
//          m == board.length
//          n = board[i].length
//          1 <= m, n <= 6
//          1 <= word.length <= 15
//          board 和 word 仅由大小写英文字母组成
//      进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？

bool WordSearch(char **board, int boardSize, int *boardColSize, char *word);

int main()
{
    int r1 = 3;
    int c1 = 4;
    char **vec1 = (char **)malloc(sizeof(char *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (char *)malloc(sizeof(char *) * c1);
        memset(vec1[i], 0, sizeof(char *) * c1);
    }
    vec1[0][0] = 'A';
    vec1[0][1] = 'B';
    vec1[0][2] = 'C';
    vec1[0][3] = 'E';
    vec1[1][0] = 'S';
    vec1[1][1] = 'F';
    vec1[1][2] = 'C';
    vec1[1][3] = 'S';
    vec1[2][0] = 'A';
    vec1[2][1] = 'D';
    vec1[2][2] = 'E';
    vec1[2][3] = 'E';
    char word1[] = "ABCCED";
    PrintStringVec(vec1, r1);
    bool ans1 = WordSearch(vec1, r1, &c1, word1);
    printf("%s存在于网格?\n", word1);
    PrintBool(ans1);
    FreeStringVec(vec1, r1);
}

bool JudgeWordSearch(char **board, int row, int col, char *word, int i, int j, int k)
{
    if (k >= strlen(word))
    {
        return true;
    }
    if (i < 0 || i >= row || j < 0 || j >= col || word[k] != board[i][j])
    {
        return false;
    }
    board[i][j] = ' '; // 防止路径回头
    int a1 = JudgeWordSearch(board, row, col, word, i + 1, j, k + 1);
    int a2 = JudgeWordSearch(board, row, col, word, i - 1, j, k + 1);
    int a3 = JudgeWordSearch(board, row, col, word, i, j + 1, k + 1);
    int a4 = JudgeWordSearch(board, row, col, word, i, j - 1, k + 1);
    board[i][j] = word[k]; // 场景还原
    return a1 || a2 || a3 || a4;
}

// 深度优先搜索：
// Time: O(2^(M * N))
// Space: O(M * N)
bool WordSearch(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            if (JudgeWordSearch(board, boardSize, *boardColSize, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}