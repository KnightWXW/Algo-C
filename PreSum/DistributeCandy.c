#include "../mybasic.h"

//        LeetCode 135. 分发糖果

//        链接：https://leetcode.cn/problems/candy/

//        n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//        你需要按照以下要求，给这些孩子分发糖果：
//        每个孩子至少分配到 1 个糖果。
//        相邻两个孩子评分更高的孩子会获得更多的糖果。
//        请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
//        示例 1：
//             输入：ratings = [1,0,2]
//             输出：5
//             解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
//        示例 2：
//             输入：ratings = [1,2,2]
//             输出：4
//             解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
//                  第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
//        提示：
//             n == ratings.length
//             1 <= n <= 2 * 104
//             0 <= ratings[i] <= 2 * 104

int DistributeCandy(int *ratings, int ratingsSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ans_A = DistributeCandy(vec, n);
    printf("需要准备的 最少糖果数目: %d \n", ans_A);
}

// 前缀和：
// Time: O(N)
// Space: O(N)
int DistributeCandy(int *ratings, int ratingsSize)
{
    int ans = ratingsSize;
    int *left = (int *)malloc(sizeof(int) * ratingsSize);
    int *right = (int *)malloc(sizeof(int) * ratingsSize);
    memset(left, 0, sizeof(int) * ratingsSize);
    memset(right, 0, sizeof(int) * ratingsSize);
    for (int i = 1; i < ratingsSize; i++)
    {
        left[i] = ratings[i] > ratings[i - 1] ? left[i - 1] + 1 : left[i];
    }
    for (int i = ratingsSize - 2; i >= 0; i--)
    {
        right[i] = ratings[i] > ratings[i + 1] ? right[i + 1] + 1 : right[i];
    }
    for (int i = 0; i < ratingsSize; i++)
    {
        ans += max(left[i], right[i]);
    }
    free(left);
    free(right);
    return ans;
}