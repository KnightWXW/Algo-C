#include "../Mybasic/mybasic.h"

//      LeetCode 881. 救生艇

//      链接：https://leetcode.cn/problems/boats-to-save-people/

//      给定数组 people 。people[i]表示第 i 个人的体重 ，船的数量不限，
//      每艘船可以承载的最大重量为 limit。
//      每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
//      返回 承载所有人所需的最小船数 。
//      示例 1：
//          输入：people = [1,2], limit = 3
//          输出：1
//          解释：1 艘船载 (1, 2)
//      示例 2：
//          输入：people = [3,2,2,1], limit = 3
//          输出：3
//          解释：3 艘船分别载 (1, 2), (2) 和 (3)
//      示例 3：
//          输入：people = [3,5,3,4], limit = 5
//          输出：4
//          解释：4 艘船分别载 (3), (3), (4), (5)
//      提示：
//          1 <= people.length <= 5 * 104
//          1 <= people[i] <= limit <= 3 * 104

int NumRescueBoats_A(int *people, int peopleSize, int limit);
int NumRescueBoats_B(int *people, int peopleSize, int limit);

int main()
{
    int n = GenerateRandomNum(1, 50);
    int limit = GenerateRandomNum(1, 101);
    int *vec_A = GenerateRandomVec(0, 100, n);
    int *vec_B = (int *)malloc(sizeof(int) * n);
    memcpy(vec_B, vec_A, sizeof(int) * n);
    PrintVecElement(vec_A, n);
    int ans_A = NumRescueBoats_A(vec_A, n, limit);
    int ans_B = NumRescueBoats_B(vec_B, n, limit);
    printf("承载所有人所需的最小船数 为 %d.\n", ans_A);
    printf("承载所有人所需的最小船数 为 %d.\n", ans_B);
}

int Compare(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

// 贪心 + 双指针：
// Time: O(NlogN)
// Space: O(logN)
int NumRescueBoats_A(int *people, int peopleSize, int limit)
{
    qsort(people, peopleSize, sizeof(int), Compare);
    int ans = 0;
    int left = 0;
    int right = peopleSize - 1;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            ans++;
            left++;
            right--;
        }
        else
        {
            ans++;
            right--;
        }
    }
    return ans;
}

// 贪心 + 双指针(简写)：
// Time: O(NlogN)
// Space: O(logN)
int NumRescueBoats_B(int *people, int peopleSize, int limit)
{
    qsort(people, peopleSize, sizeof(int), Compare);
    int ans = 0;
    int left = 0;
    int right = peopleSize - 1;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
        }
        ans++;
        right--;
    }
    return ans;
}