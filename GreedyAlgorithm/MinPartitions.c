#include "../Mybasic/mybasic.h"

//      LeetCode 1689. 十-二进制数的最少数目

//      链接：https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

//      如果一个十进制数字不含任何前导零，且每一位上的数字不是 0 就是 1 ，
//      那么该数字就是一个 十-二进制数 。
//      例如，101 和 1100 都是 十-二进制数，而 112 和 3001 不是。
//      给你一个表示十进制整数的字符串 n ，返回和为 n 的 十-二进制数 的最少数目。
//      示例 1：
//          输入：n = "32"
//          输出：3
//          解释：10 + 11 + 11 = 32
//      示例 2：
//          输入：n = "82734"
//          输出：8
//      示例 3：
//          输入：n = "27346209830709182346"
//          输出：9
//      提示：
//          1 <= n.length <= 105
//          n 仅由数字组成
//          n 不含任何前导零并总是表示正整数

int MinPartitions(int n);

int main()
{
    int n = GenerateRandomNum(1, 99999);
    int ans_A = MinPartitions(n);
    printf("和为 %d 的 十-二进制数 的最少数目 %d \n", n, ans_A);
}

// 贪心：
// Time: O(N)
// Space: O(1)
int MinPartitions(int n)
{
    char str[16] = {0};
    itoa(n, str, 10);
    int ans = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        ans = max(ans, str[i] - '0');
    }
    return ans;
}