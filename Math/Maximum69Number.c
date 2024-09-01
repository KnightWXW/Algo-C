#include "../mybasic.h"

//      LeetCode 1323. 6 和 9 组成的最大数字

//      链接：https://leetcode.cn/problems/maximum-69-number/

//      给你一个仅由数字 6 和 9 组成的正整数 num。
//      你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。
//      请返回你可以得到的最大数字。
//      示例 1：
//          输入：num = 9669
//          输出：9969
//          解释：
//              改变第一位数字可以得到 6669 。
//              改变第二位数字可以得到 9969 。
//              改变第三位数字可以得到 9699 。
//              改变第四位数字可以得到 9666 。
//              其中最大的数字是 9969 。
//      示例 2：
//          输入：num = 9996
//          输出：9999
//          解释：将最后一位从 6 变到 9，其结果 9999 是最大的数。
//      示例 3：
//          输入：num = 9999
//          输出：9999
//          解释：无需改变就已经是最大的数字了。
//      提示：
//          1 <= num <= 10^4
//          num 每一位上的数字都是 6 或者 9 。

int Maximum69Number_A(int num);
int Maximum69Number_B(int num);

int main()
{
    int n1 = 9996;
    int ans1a = Maximum69Number_A(n1);
    int ans1b = Maximum69Number_B(n1);
    printf("%d 翻转一位数字, 可以得到的最大数字为: %d\n", n1, ans1a);
    printf("%d 翻转一位数字, 可以得到的最大数字为: %d\n", n1, ans1b);

    int n2 = 9999;
    int ans2a = Maximum69Number_A(n2);
    int ans2b = Maximum69Number_B(n2);
    printf("%d 翻转一位数字, 可以得到的最大数字为: %d\n", n2, ans2a);
    printf("%d 翻转一位数字, 可以得到的最大数字为: %d\n", n2, ans2b);
}

// 字符串操作：
// Time: O(N)
// Space：O(N)
int Maximum69Number_A(int num)
{
    char str[5];
    // sprintf(str, "%d", num);
    itoa(num, str, 10);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '6')
        {
            str[i] = '9';
            break;
        }
    }
    int ans = atoi(str);
    return ans;
}

// 数学：
// Time: O(N)
// Space：O(N)
int Maximum69Number_B(int num)
{
    int pos = -1;
    int index = 0;
    int ans = num;
    while (num != 0)
    {
        int tem = num % 10;
        if (tem == 6)
        {
            pos = index;
        }
        num /= 10;
        index++;
    }
    if (pos == -1)
    {
        return ans;
    }
    else
    {
        ans += pow(10, pos) * 3;
        return ans;
    }
}