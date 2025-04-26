#include "../Mybasic/mybasic.h"

//      LeetCode 168. Excel 表列名称

//      链接：https://leetcode.cn/problems/excel-sheet-column-title/

//      给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
//      例如：
//          A -> 1
//          B -> 2
//          C -> 3
//          ...
//          Z -> 26
//          AA -> 27
//          AB -> 28
//          ...
//      示例 1：
//          输入：columnNumber = 1
//          输出："A"
//      示例 2：
//          输入：columnNumber = 28
//          输出："AB"
//      示例 3：
//          输入：columnNumber = 701
//          输出："ZY"
//      示例 4：
//          输入：columnNumber = 2147483647
//          输出："FXSHRXW"
//      提示：
//          1 <= columnNumber <= 231 - 1

char *ConvertToTitle(int columnNumber);

int main()
{
    int n = GenerateRandomNum(1, 1000);
    char * ans = ConvertToTitle(n);
    printf("%d 在 Excel 表中相对应的列名称为\n", n);
    PrintString(ans);
    FreeString(ans);
}

void ReverseString(char *s, int len)
{
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        char tem = s[left];
        s[left] = s[right];
        s[right] = tem;
        left++;
        right--;
    }
    return;
}

// 模拟：
// Time：O(N)
// Space: O(N)
char *ConvertToTitle(int columnNumber)
{
    char *ans = (char *)malloc(sizeof(char) * 8);
    memset(ans, 0, sizeof(char) * 8);
    int index = 0;
    while (columnNumber != 0)
    {
        columnNumber--;
        int cur = (columnNumber) % 26;
        ans[index++] = 'A' + cur;
        columnNumber /= 26;
    }
    ans[index] = '\0';
    ReverseString(ans, index);
    return ans;
}
