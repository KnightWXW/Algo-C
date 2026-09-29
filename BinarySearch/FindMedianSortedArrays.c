#include "../Mybasic/mybasic.h"

//      LeetCode 4. 寻找两个正序数组的中位数

//      链接: https://leetcode.cn/problems/median-of-two-sorted-arrays/

//      给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//      请你找出并返回这两个正序数组的 中位数 。
//      算法的时间复杂度应该为 O(log (m+n)) 。
//      示例 1：
//          输入：nums1 = [1,3], nums2 = [2]
//          输出：2.00000
//          解释：合并数组 = [1,2,3] ，中位数 2
//      示例 2：
//          输入：nums1 = [1,2], nums2 = [3,4]
//          输出：2.50000
//          解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//      提示：
//          nums1.length == m
//          nums2.length == n
//          0 <= m <= 1000
//          0 <= n <= 1000
//          1 <= m + n <= 2000
//          -106 <= nums1[i], nums2[i] <= 106

double FindMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
int CompareInt(const void *a, const void *b);

int main()
{
    int n1 = GenerateRandomNum(1, 16);
    int *vec1 = GenerateRandomVec(0, 100, n1);
    qsort(vec1, n1, sizeof(int), CompareInt);
    PrintVecElement(vec1, n1);
    int n2 = GenerateRandomNum(1, 20);
    int *vec2 = GenerateRandomVec(0, 100, n2);
    qsort(vec2, n2, sizeof(int), CompareInt);
    PrintVecElement(vec2, n2);
    double ans = FindMedianSortedArrays(vec1, n1, vec2, n2);
    printf("寻找两个正序数组的中位数 为: %f\n", ans);
    FreeVec(vec1);
    FreeVec(vec2);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

double FindMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{

}