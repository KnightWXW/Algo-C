#include "../Mybasic/mybasic.h"

//      LeetCode 1338. 数组大小减半

//      链接:  https://leetcode.cn/problems/reduce-array-size-to-the-half/

//      给你一个整数数组 arr。你可以从中选出一个整数集合，
//      并删除这些整数在数组中的每次出现。
//      返回 至少 能删除数组中的一半整数的整数集合的最小大小。
//      示例 1：
//          输入：arr = [3,3,3,3,5,5,5,2,2,7]
//          输出：2
//          解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
//              大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
//              选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
//      示例 2：
//          输入：arr = [7,7,7,7,7,7]
//          输出：1
//          解释：我们只能选择集合 {7}，结果数组为空。
//      提示：
//          1 <= arr.length <= 105
//          arr.length 为偶数
//          1 <= arr[i] <= 105

int MinSetSize(int *arr, int arrSize);

int main()
{
    int n = 2 * GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ans_A = MinSetSize(vec, n);
    printf("至少 能删除数组中的一半整数的整数集合的最小大小 为 %d.\n", ans_A);
    FreeVec(vec);
}

// 贪心：
// Time: O(NlogN)
// Space: O(logN)
int MinSetSize(int *arr, int arrSize)
{
}