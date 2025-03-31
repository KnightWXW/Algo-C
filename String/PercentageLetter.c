#include "../Mybasic/mybasic.h"

//      LeetCode 2278. 字母在字符串中的百分比

//      链接：https://leetcode.cn/problems/percentage-of-letter-in-string/

//      给你一个字符串 s 和一个字符 letter ，
//      返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。
//      示例 1：
//          输入：s = "foobar", letter = "o"
//          输出：33
//          解释：
//              等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33% ，向下取整，所以返回 33 。
//      示例 2：
//          输入：s = "jjjj", letter = "k"
//          输出：0
//          解释：
//              等于字母 'k' 的字符在 s 中占到的百分比是 0% ，所以返回 0 。
//      提示：
//          1 <= s.length <= 100
//          s 由小写英文字母组成
//          letter 是一个小写英文字母

int PercentageLetter(char *s, char letter);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int k = GenerateRandomNum(1, n);
    char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
    char *s = GenerateRandomString(n, arr1, strlen(arr1));
    char letter = s[k - 1];
    PrintString(s);
    char *ans_A = RemoveDigit_A(s, letter);
    printf("在 s 中等于 %c 字符所占的 百分比 为：%d\n", letter, ans_A);
    FreeString(s);
}

int PercentageLetter(char *s, char letter)
{
}