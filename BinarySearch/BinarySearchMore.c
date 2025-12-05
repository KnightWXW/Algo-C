#include "../Mybasic/mybasic.h"

//      在有序(升序)数组中查找 大于等于目标值 target 的元素 所在的索引位置。
//      如果存在,返回索引;不存在返回 -1

int BinarySearchMore_A(int *vec, int l, int target);
int BinarySearchMore_B(int *vec, int l, int target);
int CompareInt(const void *a, const void *b);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 100, n);
    int target = vec[0];
    qsort(vec, n, sizeof(int), CompareInt);
    PrintVecElement(vec, n);
    int ansA = BinarySearchMore_A(vec, n, target);
    int ansB = BinarySearchMore_B(vec, n, target);
    printf("数组中查找 大于 %d 的元素 所在的索引位置 为: %d\n", target, ansA);
    printf("数组中查找 大于 %d 的元素 所在的索引位置 为: %d\n", target, ansB);
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
int BinarySearchMore_A(int *vec, int l, int target)
{
    int left = 0;
    int right = l - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

// 二分查找
// Time: O(logN)
// Space: O(1)
int BinarySearchMore_B(int *vec, int l, int target)
{
    int left = -1;
    int right = l;
    int ans = -1;
    while (left + 1 != right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] <= target)
        {
            left = mid;
        }
        else
        {
            ans = mid;
            right = mid;
        }
    }
    return ans;
}