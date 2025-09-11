#include "../Mybasic/mybasic.h"

//      LeetCode 1854. 人口最多的年份

//      链接: https://leetcode.cn/problems/maximum-population-year/

//      给你一个二维整数数组 logs ，其中每个 logs[i] = [birthi, deathi] 表示第 i 个人的出生和死亡年份。

//      年份 x 的 人口 定义为这一年期间活着的人的数目。
//      第 i 个人被计入年份 x 的人口需要满足：x 在闭区间 [birthi, deathi - 1] 内。
//      注意，人不应当计入他们死亡当年的人口中。
//      返回 人口最多 且 最早 的年份。
//      示例 1：
//          输入：logs = [[1993,1999],[2000,2010]]
//          输出：1993
//          解释：人口最多为 1 ，而 1993 是人口为 1 的最早年份。
//      示例 2：
//          输入：logs = [[1950,1961],[1960,1971],[1970,1981]]
//          输出：1960
//          解释：
//              人口最多为 2 ，分别出现在 1960 和 1970 。
//              其中最早年份是 1960 。
//      提示：
//          1 <= logs.length <= 100
//          1950 <= birthi < deathi <= 2050

#define MAX_POPULATION_LEN 101

int MaximumPopulation(int **logs, int logsSize, int *logsColSize);

int main()
{
    int r1 = 2;
    int c1 = 2;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1993;
    vec1[0][1] = 1999;
    vec1[1][0] = 2000;
    vec1[1][1] = 2010;
    PrintVecElement2D(vec1, r1, c1);
    int ans1 = MaximumPopulation((int **)vec1, r1, &c1);
    printf("人口最多 且 最早 的年份为：%d\n", ans1);
    FreeVec2D(vec1, r1);
}

// 前缀和：
// Time: O(N)
// Space: O(1)
int MaximumPopulation(int **logs, int logsSize, int *logsColSize)
{
    int ans = 0;
    int cnt[MAX_POPULATION_LEN] = {0};
    for (int i = 0; i < logsSize; i++)
    {
        int birth = logs[i][0];
        int death = logs[i][1];
        cnt[birth - 1950]++;
        cnt[death - 1950]--;
    }
    int maxPeople = 0;
    int people = 0;
    int year = 0;
    for (int i = 0; i < MAX_POPULATION_LEN; i++)
    {
        people += cnt[i];
        if (people > maxPeople)
        {
            maxPeople = people;
            year = i + 1950;
        }
    }
    return year;
}