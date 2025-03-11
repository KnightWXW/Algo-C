#include "../Mybasic/mybasic.h"

//      Huawei: 坐电梯

//      公司员工坐电梯，电梯有一个容量限制 K, 电梯从第 a 层到第 b 层，花费时间 |a - b|,
//      给定员工目标楼层的数组，请问花费最少的时间，电梯从1层出发，最后回到1层。

int TakeLift(int *vec, int size, int k);

int main()
{
    int size = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 30, size);
    int k = GenerateRandomNum(1, 6);
    printf("员工目标楼层 为:\n");
    PrintVecElement(vec, size);
    int ans_A = TakeLift(vec, size, k);
    printf("电梯的容量限制 为 %d 时，花费最少的时间 为 %d \n", k, ans_A);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
// 贪心：
// Time: O(NlogN)
// Space: O(logN)
int TakeLift(int *vec, int size, int k)
{
    qsort(vec, size, sizeof(int), CompareInt);
    int floor = 0;
    int i = size - 1;
    while (i >= 0)
    {
        floor += 2 * (vec[i] - 1);
        i = i - k;
    }
    return floor;
}