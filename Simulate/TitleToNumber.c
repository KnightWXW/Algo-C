#include "../Mybasic/mybasic.h"

//      LeetCode 171. Excel 表列序号

//      链接：https://leetcode.cn/problems/excel-sheet-column-number/

//      给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。
//      返回 该列名称对应的列序号 。
//      例如：
//          A -> 1
//          B -> 2
//          C -> 3
//          ...
//          Z -> 26
//          AA -> 27
//          AB -> 28
//          ...
//      示例 1:
//          输入: columnTitle = "A"
//          输出: 1
//      示例 2:
//          输入: columnTitle = "AB"
//          输出: 28
//      示例 3:
//          输入: columnTitle = "ZY"
//          输出: 701
//      提示：
//          1 <= columnTitle.length <= 7
//          columnTitle 仅由大写英文组成
//          columnTitle 在范围 ["A", "FXSHRXW"] 内

int TitleToNumber_A(char *columnTitle);

int main()
{
    int num = GenerateRandomNum(1, 10);
    char arr[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *s = GenerateRandomString(num, arr, 26);
    int ans_A = TitleToNumber_A(s);
    int ans_B = TitleToNumber_B(s);
    printf("字符串 columnTitle 为: \n");
    PrintString(s);
    printf("该列名称对应的列序号 为 %d。\n", ans_A);
    FreeVec(s);
}

// 模拟：
// Time：O(N)
// Space: O(1)
int TitleToNumber_A(char *columnTitle)
{
    int l = strlen(columnTitle);
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        int tem = (columnTitle[i] - 'A' + 1);
        ans += tem * pow(26, l - i - 1);
    }
    return ans;
}