#include "../Mybasic/mybasic.h"

//      LeetCode 1304. 和为零的 N 个不同整数

//      链接：https://leetcode.cn/problems/find-n-unique-integers-sum-up-to-zero/

//      给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，
//      并且这 n 个数相加和为 0 。
//      示例 1：
//          输入：n = 5
//          输出：[-7,-1,1,3,4]
//          解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
//      示例 2：
//          输入：n = 3
//          输出：[-1,0,1]
//      示例 3：
//          输入：n = 1
//          输出：[0]
//      提示：
//          1 <= n <= 1000

int *SumZero(int n, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 100);
    int returnSize = 0;
    int *ans_A = SumZero(n, &returnSize);
    printf("和为零的 %n 个不同整数数组为:\n", n);
    PrintVecElement(ans_A, returnSize);
    FreeVec(ans_A);
}

int *SumZero(int n, int *returnSize)
{
    *returnSize = n;
    int *ans = (int *)malloc(sizeof(int) * n);
    memset(ans, 0, sizeof(int) * n);
    int k = 1;
    for (int i = 0; i < n - 1; i += 2)
    {
        ans[i] = k;
        ans[i + 1] = -k;
        k++;
    }
    return ans;
}