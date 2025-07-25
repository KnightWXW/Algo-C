#include "../Mybasic/mybasic.h"

//      LeetCode 2126. 摧毁小行星

//      链接：https://leetcode.cn/problems/destroying-asteroids/

//      给你一个整数 mass ，它表示一颗行星的初始质量。
//      再给你一个整数数组 asteroids ，其中 asteroids[i] 是第 i 颗小行星的质量。
//      你可以按 任意顺序 重新安排小行星的顺序，然后让行星跟它们发生碰撞。
//      如果行星碰撞时的质量 大于等于 小行星的质量，那么小行星被 摧毁，
//      并且行星会 获得 这颗小行星的质量。否则，行星将被摧毁。
//      如果所有小行星 都 能被摧毁，请返回 true ，否则返回 false 。
//      示例 1：
//          输入：mass = 10, asteroids = [3,9,19,5,21]
//          输出：true
//          解释：一种安排小行星的方式为 [9,19,5,3,21] ：
//              - 行星与质量为 9 的小行星碰撞。新的行星质量为：10 + 9 = 19
//              - 行星与质量为 19 的小行星碰撞。新的行星质量为：19 + 19 = 38
//              - 行星与质量为 5 的小行星碰撞。新的行星质量为：38 + 5 = 43
//              - 行星与质量为 3 的小行星碰撞。新的行星质量为：43 + 3 = 46
//              - 行星与质量为 21 的小行星碰撞。新的行星质量为：46 + 21 = 67
//              所有小行星都被摧毁。
//      示例 2：
//          输入：mass = 5, asteroids = [4,9,23,4]
//          输出：false
//          解释：
//              行星无论如何没法获得足够质量去摧毁质量为 23 的小行星。
//              行星把别的小行星摧毁后，质量为 5 + 4 + 9 + 4 = 22 。
//              它比 23 小，所以无法摧毁最后一颗小行星。
//      提示：
//          1 <= mass <= 105
//          1 <= asteroids.length <= 105
//          1 <= asteroids[i] <= 105

bool AsteroidsDestroyed(int mass, int *asteroids, int asteroidsSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(1, 30, n);
    int mass = GenerateRandomNum(1, 30);
    PrintVecElement(vec, n);
    int ans = AsteroidsDestroyed(mass, vec);
    printf("所有小行星 能否 都 被摧毁?\n");
    PrintBool(ans);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

// 贪心：
// Time: O(NlogN)
// Space: O(logN)
bool AsteroidsDestroyed(int mass, int *asteroids, int asteroidsSize)
{
    qsort(asteroids, asteroidsSize, sizeof(int), CompareInt);
    long cur = mass;
    for (int i = 0; i < asteroidsSize; i++)
    {
        if (cur >= asteroids[i])
        {
            cur += asteroids[i];
        }
        else
        {
            return false;
        }
    }
    return true;
}