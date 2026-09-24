#include "../Mybasic/mybasic.h"

//      LeetCode 338. 比特位计数

//      链接: https://leetcode.cn/problems/counting-bits/description/

//      给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，
//      返回一个长度为 n + 1 的数组 ans 作为答案。
//      不要使用内置函数来解决（例如，C++ 中的 __builtin_popcount）。
//      示例 1：
//          输入：n = 2
//          输出：[0,1,1]
//          解释：
//              0 --> 0
//              1 --> 1
//              2 --> 10
//      示例 2：
//          输入：n = 5
//          输出：[0,1,1,2,1,2]
//          解释：
//              0 --> 0
//              1 --> 1
//              2 --> 10
//              3 --> 11
//              4 --> 100
//              5 --> 101
//      提示：
//          0 <= n <= 105
//      进阶:很容易就能实现时间复杂度为 O(n log n) 的解决方案，
//           你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？

int *CountBits_A(int n, int *returnSize);
int *CountBits_B(int n, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int returnSizeA = 0;
    int *ans_A = CountBits_A(n, &returnSizeA);
    printf("%d 的二进制表示中 1 的个数为: \n", n);
    PrintVecElement(ans_A, returnSizeA);
    int returnSizeB = 0;
    int *ans_B = CountBits_B(n, &returnSizeB);
    printf("%d 的二进制表示中 1 的个数为: \n", n);
    PrintVecElement(ans_B, returnSizeB);
    FreeVec(ans_A);
    FreeVec(ans_B);
}

int DFS_CountBits_A(int k)
{
    int cnt = 0;
    while (k != 0)
    {
        k &= (k - 1);
        cnt++;
    }
    return cnt;
}

// 位运算
// Time: O(N)
// Space: O(1)
int *CountBits_A(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *ans = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        ans[i] = DFS_CountBits_A(i);
    }
    return ans;
}

// 动态规划
// Time: O(N)
// Space: O(1)
int *CountBits_B(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *ans = (int *)malloc(sizeof(int) * (n + 1));
    memset(ans, 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}