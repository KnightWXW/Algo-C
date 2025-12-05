#include "../Mybasic/mybasic.h"

//      在有序(升序)数组中查找 等于目标值 target 的元素 所在的索引位置。
//      如果存在,返回索引;不存在返回 -1

int BinarySearch(int *vec, int l, int target);
int CompareInt(const void *a, const void *b);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 100, n);
    int target = vec[0];
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int ans = BinarySearch(vec, n, target);
    printf("数组中查找 等于 %d 的元素 所在的索引位置 为: %d\n", target, ans);
    FreeVec(vec);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

// 二分查找
// Time: O(logN)
// Space: O(1)
int BinarySearch(int *vec, int l, int target)
{
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] < target)
        {
            left = mid + 1;
        }
        else if (vec[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}