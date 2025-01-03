#include "../Mybasic/mybasic.h"

//      LeetCode 551. 学生出勤记录 I

//      链接：https://leetcode.cn/problems/student-attendance-record-i/

//      给你一个字符串 s 表示一个学生的出勤记录，
//      其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。
//      记录中只含下面三种字符：
//          'A'：Absent，缺勤
//          'L'：Late，迟到
//          'P'：Present，到场
//      如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
//      按 总出勤 计，学生缺勤（'A'）严格 少于两天。
//      学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
//      如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。
//      示例 1：
//          输入：s = "PPALLP"
//          输出：true
//          解释：学生缺勤次数少于 2 次，且不存在 3 天或以上的连续迟到记录。
//      示例 2：
//          输入：s = "PPALLL"
//          输出：false
//          解释：学生最后三天连续迟到，所以不满足出勤奖励的条件。
//      提示：
//          1 <= s.length <= 1000
//          s[i] 为 'A'、'L' 或 'P'

bool CheckRecord(char *s);

int main()
{
    int n = GenerateRandomNum(1, 10);
    char arr1[] = {'A', 'L', 'P'};
    char *str = GenerateRandomString(n, arr1, strlen(arr1));
    PrintString(str);
    bool ans_A = CheckRecord(str);
    FreeString(str);
    printf("学生是否可以获得出勤奖励？\n");
    PrintBool(ans_A);
}

// 字符串遍历:
// Space: O(N)
// Time: O(1)
bool CheckRecord(char *s)
{
    int absent = 0;
    int late = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'A')
        {
            absent++;
        }
        if (s[i] == 'L')
        {
            late++;
        }
        else
        {
            late = 0;
        }
        if (late >= 3)
        {
            return false;
        }
    }
    return absent < 2;
}