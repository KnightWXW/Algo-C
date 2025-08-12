#include "../Mybasic/mybasic.h"

//      LeetCode 475. 供暖器

//      链接：https://leetcode.cn/problems/heaters/

//      冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
//      在加热器的加热半径范围内的每个房屋都可以获得供暖。
//      现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，
//      请你找出并返回可以覆盖所有房屋的最小加热半径。
//      注意：所有供暖器 heaters 都遵循你的半径标准，加热的半径也一样。
//      示例 1:
//          输入: houses = [1,2,3], heaters = [2]
//          输出: 1
//          解释: 仅在位置 2 上有一个供暖器。如果我们将加热半径设为 1，那么所有房屋就都能得到供暖。
//      示例 2:
//          输入: houses = [1,2,3,4], heaters = [1,4]
//          输出: 1
//          解释: 在位置 1, 4 上有两个供暖器。我们需要将加热半径设为 1，这样所有房屋就都能得到供暖。
//      示例 3：
//          输入：houses = [1,5], heaters = [2]
//          输出：3
//      提示：
//          1 <= houses.length, heaters.length <= 3 * 104
//          1 <= houses[i], heaters[i] <= 109

int Heaters_A(int *houses, int housesSize, int *heaters, int heatersSize);
int Heaters_B(int *houses, int housesSize, int *heaters, int heatersSize);

int main()
{
    int houses1[] = {1, 2, 3};
    int housesSize1 = 3;
    int heaters1[] = {2};
    int heatersSize1 = 1;
    int ans1a = Heaters_A(houses1, housesSize1, heaters1, heatersSize1);
    printf("供暖器位置为：\n");
    PrintVecElement(houses1, housesSize1);
    printf("房屋位置为：\n");
    PrintVecElement(heaters1, heatersSize1);
    printf(" 可以覆盖所有房屋的最小加热半径为：%d\n", ans1a);

    int houses2[] = {1, 2, 3, 4};
    int housesSize2 = 4;
    int heaters2[] = {1, 4};
    int heatersSize2 = 2;
    int ans2a = Heaters_A(houses1, housesSize1, heaters1, heatersSize1);
    printf("供暖器位置为：\n");
    PrintVecElement(houses2, housesSize2);
    printf("房屋位置为：\n");
    PrintVecElement(heaters2, heatersSize2);
    printf(" 可以覆盖所有房屋的最小加热半径为：%d\n", ans2a);

    int houses3[] = {1, 5};
    int housesSize3 = 2;
    int heaters3[] = {2};
    int heatersSize3 = 1;
    int ans3a = Heaters_A(houses3, housesSize3, heaters3, heatersSize3);
    printf("供暖器位置为：\n");
    PrintVecElement(houses3, housesSize3);
    printf("房屋位置为：\n");
    PrintVecElement(heaters3, heatersSize3);
    printf(" 可以覆盖所有房屋的最小加热半径为：%d\n", ans3a);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

// 贪心 + 双指针：
//    对于每个house:在其前后的heater的最短距离比较后，取最大值
// Time：O(NlogN)
// Space: O(N)
int Heaters_A(int *houses, int housesSize, int *heaters, int heatersSize)
{
    qsort(houses, housesSize, sizeof(int), CompareInt);
    qsort(heaters, heatersSize, sizeof(int), CompareInt);
    int j = 0;
    int ans = 0;
    for (int i = 0; i < housesSize; i++)
    {
        int tem = abs(houses[i] - heaters[j]);
        while (j < heatersSize - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]))
        {
            j++;
            tem = min(tem, abs(houses[i] - heaters[j]));
        }
        ans = max(ans, tem);
    }
    return ans;
}

bool JudgeOfHeaters(int *houses, int housesSize, int *heaters, int heatersSize, int k)
{
    int j = 0;
    for (int i = 0; i < housesSize; i++)
    {
        while (j < heatersSize && abs(houses[i] - heaters[j]) > k)
        {
            j++;
        }
        if (j == heatersSize)
        {
            return false;
        }
    }
    return true;
}

// 贪心 + 二分查找：
// Time：O(NlogN)
// Space: O(logN)
int Heaters_B(int *houses, int housesSize, int *heaters, int heatersSize)
{
    qsort(houses, housesSize, sizeof(int), CompareInt);
    qsort(heaters, heatersSize, sizeof(int), CompareInt);
    if (heatersSize == 1)
    {
        return max(abs(houses[0] - heaters[0]), abs(houses[housesSize - 1] - heaters[0]));
    }
    int ans = 0;
    int left = 0;
    int right = houses[housesSize - 1];
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeOfHeaters(houses, housesSize, heaters, heatersSize, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}