#include "../Mybasic/mybasic.h"

//      LeetCode 812. 最大三角形面积

//      链接：https://leetcode.cn/problems/largest-triangle-area/

//      给你一个由 X-Y 平面上的点组成的数组 points ，其中 points[i] = [xi, yi] 。
//      从其中取任意三个不同的点组成三角形，返回能组成的最大三角形的面积。
//      与真实值误差在 10-5 内的答案将会视为正确答案。
//      示例 1：
//          输入：points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
//          输出：2.00000
//          解释：输入中的 5 个点如上图所示，红色的三角形面积最大。
//      示例 2：
//          输入：points = [[1,0],[0,0],[0,1]]
//          输出：0.50000
//      提示：
//          3 <= points.length <= 50
//          -50 <= xi, yi <= 50
//          给出的所有点 互不相同

double LargestTriangleArea(int **points, int pointsSize, int *pointsColSize);

int main()
{
    int r1 = 5;
    int c1 = 2;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 0;
    vec1[1][0] = 0;
    vec1[1][1] = 0;
    vec1[2][0] = 0;
    vec1[2][1] = 1;
    vec1[3][0] = 0;
    vec1[3][1] = 2;
    vec1[4][0] = 2;
    vec1[4][1] = 0;
    PrintVecElement2D(vec1, r1, c1);
    double ans1 = LargestTriangleArea(vec1, r1, &c1);
    printf("能组成的最大三角形的面积 为 %f\n", ans1);
    FreeVec2D(vec1, r1);

    int r2 = 3;
    int c2 = 2;
    int **vec2 = (int **)malloc(sizeof(int *) * r2);
    for (int i = 0; i < r2; i++)
    {
        vec2[i] = (int *)malloc(sizeof(int) * c2);
    }
    vec2[0][0] = 1;
    vec2[0][1] = 0;
    vec2[1][0] = 0;
    vec2[1][1] = 0;
    vec2[2][0] = 0;
    vec2[2][1] = 1;
    PrintVecElement2D(vec2, r2, c2);
    double ans2 = LargestTriangleArea(vec2, r2, &c2);
    printf("能组成的最大三角形的面积 为 %f\n", ans2);
    FreeVec2D(vec2, r2);
}

// 暴力循环:
// Time:O(N^3)
// Space:O(1)
double TriangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}

double LargestTriangleArea(int **points, int pointsSize, int *pointsColSize)
{
    double ans = 0;
    for (int i = 0; i < pointsSize; i++)
    {
        for (int j = i + 1; j < pointsSize; j++)
        {
            for (int k = j + 1; k < pointsSize; k++)
            {
                double tem = TriangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                ans = max(ans, tem);
            }
        }
    }
    return ans;
}