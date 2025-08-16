#include "../Mybasic/mybasic.h"

//      LeetCode 136. 只出现一次的数字

//      链接：https://leetcode.cn/problems/single-number/

//      给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。
//      找出那个只出现了一次的元素。
//      你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
//      示例 1 ：
//          输入：nums = [2,2,1]
//          输出：1
//      示例 2 ：
//          输入：nums = [4,1,2,1,2]
//          输出：4
//      示例 3 ：
//          输入：nums = [1]
//          输出：1
//      提示：
//          1 <= nums.length <= 3 * 104
//          -3 * 104 <= nums[i] <= 3 * 104
//          除了某个元素只出现一次以外，其余每个元素均出现两次。

int SingleNumber_A(int *nums, int numsSize);

int main()
{
    int n1 = 9;
    int arr1[] = {1, 2, 1, 2, 3, 3, 8, 5, 8};
    int ans1 = SingleNumber_A(arr1, n1);
    printf("只出现了一次的元素为 %d\n", ans1);
}

// 位运算：
// Time: O(N)
// Space: O(1)
int SingleNumber_A(int *nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}