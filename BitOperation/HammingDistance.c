#include "../Mybasic/mybasic.h"

//      LeetCode 461. 汉明距离

//      链接: https://leetcode.cn/problems/hamming-distance/

//      两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
//      给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
//      示例 1：
//          输入：x = 1, y = 4
//          输出：2
//          解释：
//              1   (0 0 0 1)
//              4   (0 1 0 0)
//                     ↑   ↑
//              上面的箭头指出了对应二进制位不同的位置。
//      示例 2：
//          输入：x = 3, y = 1
//          输出：1
//      提示：
//          0 <= x, y <= 231 - 1

int HammingDistance(int x, int y);

int main()
{
    int x = GenerateRandomNum(0, 500);
    int y = GenerateRandomNum(0, 1000);
    int ansA = MaxProduct(vec, n);
    printf("%d 和 %d 的 汉明距离是: %d\n", x, y, ansA);
}

// 位运算
// Time: O(1)
// Space: O(1)
int HammingDistance(int x, int y)
{
    int a = x ^ y;
    int ans = 0;
    while (a != 0)
    {
        a = a & (a - 1);
        ans++;
    }
    return ans;
}