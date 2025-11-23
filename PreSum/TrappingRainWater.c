#include "../Mybasic/mybasic.h"

//      LeetCode 42. 接雨水

//      链接：https://leetcode.cn/problems/trapping-rain-water/

//      给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
//      计算按此排列的柱子，下雨之后能接多少雨水。
//      示例 1：
//          输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//          输出：6
//          解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，
//              在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
//      示例 2：
//          输入：height = [4,2,0,3,2,5]
//          输出：9
//      提示：
//          n == height.length
//          1 <= n <= 2 * 104
//          0 <= height[i] <= 105

int TrappingRainWater(int *height, int heightSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ans_A = DistributeCandy(vec, n);
    printf("按此排列的柱子, 下雨之后能接 %d 雨水 \n", ans_A);
    FreeVec(vec);
}

// 贪心 + 双指针：
// Time: O(NlogN)
// Space: O(logN)
int TrappingRainWater(int *height, int heightSize)
{
    int ans = 0;
    int *left = (int *)malloc(sizeof(int) * heightSize);
    int *right = (int *)malloc(sizeof(int) * heightSize);
    left[0] = height[0];
    for (int i = 1; i < heightSize; i++)
    {
        left[i] = max(height[i], left[i - 1]);
    }
    right[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--)
    {
        right[i] = max(height[i], right[i + 1]);
    }
    for (int i = 0; i < heightSize; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    free(left);
    free(right);
    return ans;
}