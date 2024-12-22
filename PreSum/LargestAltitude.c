#include "../Mybasic/mybasic.h"

//      LeetCode 1732. 找到最高海拔

//      链接：https://leetcode.cn/problems/find-the-highest-altitude/

//      有一个自行车手打算进行一场公路骑行，这条路线总共由 n + 1 个不同海拔的点组成。
//      自行车手从海拔为 0 的点 0 开始骑行。
//      给你一个长度为 n 的整数数组 gain，
//      其中 gain[i] 是点 i 和点 i + 1 的 净海拔高度差（0 <= i < n）。
//      请你返回 最高点的海拔 。
//      示例 1：
//          输入：gain = [-5,1,5,0,-7]
//          输出：1
//          解释：海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
//      示例 2：
//          输入：gain = [-4,-3,-2,-1,4,3,2]
//          输出：0
//          解释：海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
//      提示：
//          n == gain.length
//          1 <= n <= 100
//          -100 <= gain[i] <= 100

int LargestAltitude(int *gain, int gainSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(-100, 100, n);
    PrintVecElement(vec, n);
    int ans_A = LargestAltitude(vec, n);
    printf("最高点的海拔 为: %d \n", ans_A);
    FreeVec(vec);
}

// 前缀和：
// Time: O(N)
// Space: O(1)
int LargestAltitude(int *gain, int gainSize)
{
    int ans = 0;
    int altitude = 0;
    for (int i = 0; i < gainSize; i++)
    {
        altitude += gain[i];
        ans = max(ans, altitude);
    }
    return ans;
}