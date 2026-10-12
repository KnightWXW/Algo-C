#include "../Mybasic/mybasic.h"

//      LeetCode 718. 最长重复子数组

//      链接: https://leetcode.cn/problems/maximum-length-of-repeated-subarray/

//      给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
//      示例 1：
//          输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//          输出：3
//          解释：长度最长的公共子数组是 [3,2,1] 。
//      示例 2：
//          输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//          输出：5
//      提示：
//          1 <= nums1.length, nums2.length <= 1000
//          0 <= nums1[i], nums2[i] <= 100

int FindLength_A(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main()
{
    int n1 = GenerateRandomNum(0, 20);
    int *vec1 = GenerateRandomVec(0, 5, n1);
    int n2 = GenerateRandomNum(0, 10);
    int *vec2 = GenerateRandomVec(0, 5, n1);
    PrintVecElement(vec1, n1);
    int ansA = DeleteAndEarn_A(vec1, n1, vec2, n2);
    int ansB = DeleteAndEarn_B(vec1, n1, vec2, n2);
    int ansC = DeleteAndEarn_C(vec1, n1, vec2, n2);
    int ansD = DeleteAndEarn_D(vec1, n1, vec2, n2);
    printf("(暴力递归) 最长重复子数组 长度 为 %d\n", ansA);
    printf("(记忆化搜索) 最长重复子数组 长度 为 %d\n", ansB);
    printf("(动态规划) 最长重复子数组 长度 为 %d\n", ansC);
    printf("(动态规划[空间优化]) 最长重复子数组 长度 为 %d\n", ansD);
    FreeVec(vec1);
    FreeVec(vec2);
}

int FindLength_A(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    
}