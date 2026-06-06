#include "../Mybasic/mybasic.h"

//      LeetCode 118. 杨辉三角

//      链接: https://leetcode.cn/problems/pascals-triangle/

//      给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//      在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//      示例 1:
//          输入: numRows = 5
//          输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//      示例 2:
//          输入: numRows = 1
//          输出: [[1]]
//      提示:
//          1 <= numRows <= 30

int** PascalsTriangle1(int numRows, int* returnSize, int** returnColumnSizes);

int main() 
{
    int numRows = 5;
    int returnSize = 0;
    int* returnColumnSizes;
    int** res = PascalsTriangle1(numRows, &returnSize, &returnColumnSizes);
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < numRows; i++)
    {
        free(res[i]);
    }
}

int** PascalsTriangle1(int numRows, int* returnSize, int** returnColumnSizes)
{

}