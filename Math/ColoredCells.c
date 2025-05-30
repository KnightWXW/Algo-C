#include "../Mybasic/mybasic.h"

//      LeetCode 2579. 统计染色格子数

//      链接：https://leetcode.cn/problems/count-total-number-of-colored-cells/

//      有一个无穷大的二维网格图，一开始所有格子都未染色。
//      给你一个正整数 n ，表示你需要执行以下步骤 n 分钟：
//      第一分钟，将 任一 格子染成蓝色。
//      之后的每一分钟，将与蓝色格子相邻的 所有 未染色格子染成蓝色。
//      下图分别是 1、2、3 分钟后的网格图。
//      请你返回 n 分钟之后 被染色的格子 数目。
//      示例 1：
//          输入：n = 1
//          输出：1
//          解释：1 分钟后，只有 1 个蓝色的格子，所以返回 1 。
//      示例 2：
//          输入：n = 2
//          输出：5
//          解释：2 分钟后，有 4 个在边缘的蓝色格子和 1 个在中间的蓝色格子，所以返回 5 。
//      提示：
//          1 <= n <= 105

long long ColoredCells_A(int n);
long long ColoredCells_B(int n);

int main()
{
    int n = GenerateRandomNum(1, 10000);
    long long ans1 = ColoredCells_A(n);
    printf("%u 分钟之后 被染色的格子 数目 为 %llu。", n, ans1);
    long long ans2 = ColoredCells_B(n);
    printf("%u 分钟之后 被染色的格子 数目 为 %llu。", n, ans2);
}

// 模拟
// Time: O(N)
// Space: O(1)
long long ColoredCells_A(int n)
{
    long long ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans += 4 * (i - 1);
    }
    return ans;
}

// 数学：
// Time: O(1)
// Space: O(1)
long long ColoredCells_B(int n)
{
    long long ans = (long long)2 * n * (n - 1) + 1;
    return ans;
}