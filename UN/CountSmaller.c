#include "../Mybasic/mybasic.h"

//      LeetCode 315. 计算右侧小于当前元素的个数

//      链接：https://leetcode.cn/problems/count-of-smaller-numbers-after-self/

//      给你一个整数数组 nums ，按要求返回一个新数组 counts 。
//      数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
//      示例 1：
//          输入：nums = [5,2,6,1]
//          输出：[2,1,1,0] 
//      解释：
//          5 的右侧有 2 个更小的元素 (2 和 1)
//          2 的右侧仅有 1 个更小的元素 (1)
//          6 的右侧有 1 个更小的元素 (1)
//          1 的右侧有 0 个更小的元素
//      示例 2：
//          输入：nums = [-1]
//          输出：[0]
//      示例 3：
//          输入：nums = [-1,-1]
//          输出：[0,0]
//      提示：
//          1 <= nums.length <= 105
//          -104 <= nums[i] <= 104

int* CountSmaller(int* nums, int numsSize, int* returnSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(-100, 100, n);
    PrintVecElement(vec, n);
    int rs = 0;
    int* ans = CountSmaller(vec, n);
    printf("右侧小于当前元素的个数 为:\n");
    PrintVecElement(ans, rs);
    FreeVec(vec);
    FreeVec(ans);
}

int* CountSmaller(int* nums, int numsSize, int* returnSize)
{

}