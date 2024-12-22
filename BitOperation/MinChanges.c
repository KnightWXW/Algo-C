#include "../Mybasic/mybasic.h"

//      LeetCode 3226. 使两个整数相等的位更改次数

//      链接：https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/

//      给你两个正整数 n 和 k。
//      你可以选择 n 的 二进制表示 中任意一个值为 1 的位，并将其改为 0。
//      返回使得 n 等于 k 所需要的更改次数。如果无法实现，返回 -1。
//      示例 1：
//          输入： n = 13, k = 4
//          输出： 2
//          解释：
//              最初，n 和 k 的二进制表示分别为 n = (1101)2 和 k = (0100)2，
//              我们可以改变 n 的第一位和第四位。结果整数为 n = (0100)2 = k。
//      示例 2：
//          输入： n = 21, k = 21
//          输出： 0
//          解释：
//              n 和 k 已经相等，因此不需要更改。
//      示例 3：
//          输入： n = 14, k = 13
//          输出： -1
//          解释：
//              无法使 n 等于 k。
//      提示：
//          1 <= n, k <= 106

int MinChanges_A(int n, int k);
int MinChanges_B(int n, int k);

int main()
{
    int n = GenerateRandomNum(0, 10000);
    int k = GenerateRandomNum(0, 100);
    int ans_A = MinChanges_A(n, k);
    int ans_B = MinChanges_B(n, k);
    printf("使得 %d 等于 %d 所需要的更改次数为 %d.\n", n, k, ans_A);
    printf("使得 %d 等于 %d 所需要的更改次数为 %d.\n", n, k, ans_B);
}

// 位运算：
// Time: O(N)
// Space: O(1)
int MinChanges_A(int n, int k)
{
    if (n < k)
    {
        return -1;
    }
    int ans = 0;
    while (n != 0 || k != 0)
    {
        int a = (n & 1);
        int b = (k & 1);
        if (a == 0 && b == 1)
        {
            return -1;
        }
        else if (a == 1 && b == 0)
        {
            ans++;
        }
        n >>= 1;
        k >>= 1;
    }
    return ans;
}

// 位运算 内置函数：
// Time: O(N)
// Space: O(1)
int MinChanges_B(int n, int k)
{
    return (n & k) == k ? __builtin_popcount(n ^ k) : -1;
}