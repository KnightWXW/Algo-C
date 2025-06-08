#include "../Mybasic/mybasic.h"

//      LeetCode 757. 设置交集大小至少为2

//      链接：

//      给你一个二维整数数组 intervals ，其中 intervals[i] = [starti, endi]
//      表示从 starti 到 endi 的所有整数，包括 starti 和 endi 。
//      包含集合 是一个名为 nums 的数组，
//      并满足 intervals 中的每个区间都 至少 有 两个 整数在 nums 中。
//      例如，如果 intervals = [[1,3], [3,7], [8,9]] ，
//      那么 [1,2,4,7,8,9] 和 [2,3,4,8,9] 都符合 包含集合 的定义。
//      返回包含集合可能的最小大小。
//      示例 1：
//          输入：intervals = [[1,3],[3,7],[8,9]]
//          输出：5
//          解释：nums = [2, 3, 4, 8, 9].
//              可以证明不存在元素数量为 4 的包含集合。
//      示例 2：
//          输入：intervals = [[1,3],[1,4],[2,5],[3,5]]
//          输出：3
//          解释：nums = [2, 3, 4].
//              可以证明不存在元素数量为 2 的包含集合。
//      示例 3：
//          输入：intervals = [[1,2],[2,3],[2,4],[4,5]]
//          输出：5
//          解释：nums = [1, 2, 3, 4, 5].
//              可以证明不存在元素数量为 4 的包含集合。
//      提示：
//          1 <= intervals.length <= 3000
//          intervals[i].length == 2
//          0 <= starti < endi <= 108

int IntersectionSizeTwo(int **intervals, int intervalsSize, int *intervalsColSize);

int main()
{
    int r1 = 3;
    int c1 = 2;
    int** vec1 = (int**)malloc(sizeof(int*) * r1);
    for(int i = 0; i < r1; i++)
    {
        vec1[i] = (int*)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 3;
    vec1[1][0] = 3;
    vec1[1][1] = 7;
    vec1[2][0] = 8;
    vec1[2][1] = 9;
    PrintVecElement2D(vec1, r1, c1);
    int ans1 = IntersectionSizeTwo((int **)vec1, r1, &c1);
    printf("包含集合可能的最小大小为：%d。\n", ans1);
    FreeVec2D(vec1, r1);

    int r2 = 4;
    int c2= 2;
    int** vec2 = (int**)malloc(sizeof(int*) * r2);
    for(int i = 0; i < r2; i++)
    {
        vec2[i] = (int*)malloc(sizeof(int) * c2);
    }
    vec2[0][0] = 1;
    vec2[0][1] = 3;
    vec2[1][0] = 1;
    vec2[1][1] = 4;
    vec2[2][0] = 2;
    vec2[2][1] = 5;
    vec2[3][0] = 3;
    vec2[3][1] = 5;
    PrintVecElement2D(vec2, r2, c2);
    int ans1 = IntersectionSizeTwo((int **)vec2, r2, &c2);
    printf("包含集合可能的最小大小为：%d。\n", ans3);
    FreeVec2D(vec2, r2);

    int r3 = 4;
    int c3= 2;
    int** vec3 = (int**)malloc(sizeof(int*) * r3);
    for(int i = 0; i < r3; i++)
    {
        vec3[i] = (int*)malloc(sizeof(int) * c3);
    }
    vec3[0][0] = 1;
    vec3[0][1] = 3;
    vec3[1][0] = 1;
    vec3[1][1] = 4;
    vec3[2][0] = 2;
    vec3[2][1] = 4;
    vec3[3][0] = 4;
    vec3[3][1] = 5;
    PrintVecElement2D(vec3, r3, c3);
    int ans3 = IntersectionSizeTwo((int **)vec3, r3, &c3);
    printf("包含集合可能的最小大小为：%d。\n", ans3);
    FreeVec2D(vec3, r3);
}

int IntersectionSizeTwo(int **intervals, int intervalsSize, int *intervalsColSize)
{
    
}