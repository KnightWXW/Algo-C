#include "../Mybasic/mybasic.h"

//      LeetCode 9. 回文数

//      链接：https://leetcode.cn/problems/palindrome-number/

//      给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//      回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//      例如，121 是回文，而 123 不是。
//      示例 1：
//          输入：x = 121
//          输出：true
//      示例 2：
//          输入：x = -121
//          输出：false
//          解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
//      示例 3：
//          输入：x = 10
//          输出：false
//          解释：从右向左读, 为 01 。因此它不是一个回文数。
//      提示：
//          -231 <= x <= 231 - 1
//      进阶：你能不将整数转为字符串来解决这个问题吗？

bool IsPalindrome_A(int x);
bool IsPalindrome_B(int x);

int main()
{
    int n = GenerateRandomNum(0, 1000);
    bool ans_A = IsPalindrome_A(n);
    bool ans_B = IsPalindrome_B(n);
    printf("%d 为回文数？\n", n);
    PrintBool(ans_A);
    PrintBool(ans_B);
}

// 转换为字符串：
// Time：O(N)
// Space: O(1)
bool IsPalindrome_A(int x)
{
    char arr[32];
    sprintf(arr, "%d", x);
    int left = 0;
    int right = strlen(arr) - 1;
    while (left <= right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 模拟：反转一半数字
// Time：O(N)
// Space: O(1)
bool IsPalindrome_B(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int k = 0;
    while (k < x)
    {
        int tem = x % 10;
        k *= 10;
        k += tem;
        x /= 10;
    }
    return (k == x) | ((k / 10) == x);
}