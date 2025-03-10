#include "../Mybasic/mybasic.h"

//      LeetCode 231. 2 的幂

//      链接：https://leetcode.cn/problems/power-of-two/

//      给你一个整数 n，请你判断该整数是否是 2 的幂次方。
//      如果是，返回 true ；否则，返回 false 。
//      如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
//      示例 1：
//          输入：n = 1
//          输出：true
//          解释：20 = 1
//      示例 2：
//          输入：n = 16
//          输出：true
//          解释：24 = 16
//      示例 3：
//          输入：n = 3
//          输出：false
//      提示：
//          -231 <= n <= 231 - 1

bool IsPowerOfTwo_A(int n);
bool IsPowerOfTwo_B(int n);
bool IsPowerOfTwo_C(int n);

int main()
{
    int n = GenerateRandomNum(1, 65536);
    bool ans_A = IsPowerOfTwo_A(n);
    printf("%d 是否是 2 的幂次方 ? \n", n);
    PrintBool(ans_A);
    bool ans_B = IsPowerOfTwo_B(n);
    printf("%d 是否是 2 的幂次方 ? \n", n);
    PrintBool(ans_B);
    bool ans_C = IsPowerOfTwo_C(n);
    printf("%d 是否是 2 的幂次方 ? \n", n);
    PrintBool(ans_C);
}

// 循环：
// Time：O(N)
// Space: O(1)
bool IsPowerOfTwo_A(int n)
{
    if (n <= 0)
    {
        return false;
    }
    n--;
    while (n != 0)
    {
        if ((n & 1) != 1)
        {
            return false;
        }
        n >>= 1;
    }
    return true;
}

// 最高的 1 是否是唯一的 1
// Time：O(1)
// Space: O(1)
bool IsPowerOfTwo_B(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return (n - 1) & (n) == 0;
}

// 是否是 2^30的因数
// Time：O(1)
// Space: O(1)
bool IsPowerOfTwo_C(int n)
{
    const int M = 1 << 30;
    if (n <= 0)
    {
        return false;
    }
    return M % n == 0;
}