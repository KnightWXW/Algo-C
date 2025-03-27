#include "../Mybasic/mybasic.h"

//      LeetCode 453. 最小操作次数使数组元素相等

//      链接：https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

//      给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。
//      返回让数组所有元素相等的最小操作次数。
//      示例 1：
//          输入：nums = [1,2,3]
//          输出：3
//          解释：
//              只需要3次操作（注意每次操作会增加两个元素的值）：
//              [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
//      示例 2：
//          输入：nums = [1,1,1]
//          输出：0
//      提示：
//          n == nums.length
//          1 <= nums.length <= 105
//          -109 <= nums[i] <= 109
//          答案保证符合 32-bit 整数

int MinMovesToEqualArrayElements(int* nums, int l);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int* vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ans_A = MinMovesToEqualArrayElements(vec, n);
    printf("让数组所有元素相等的最小操作次数为: %d\n", ans_A);
}

// 每次操作既可以理解为使 n−1 个元素增加 1，也可以理解使 1 个元素减少 1
int MinMovesToEqualArrayElements(int* nums, int l)
{
    
}