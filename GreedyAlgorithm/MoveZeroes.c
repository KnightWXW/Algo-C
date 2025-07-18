#include "../Mybasic/mybasic.h"

//      LeetCode 283. 移动零

//      链接：https://leetcode.cn/problems/move-zeroes/

//      给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，
//      同时保持非零元素的相对顺序。
//      请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//      示例 1:
//          输入: nums = [0,1,0,3,12]
//          输出: [1,3,12,0,0]
//      示例 2:
//          输入: nums = [0]
//          输出: [0]
//      提示:
//          1 <= nums.length <= 104
//          -231 <= nums[i] <= 231 - 1

void MoveZeroes(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(0, 10, n);
    PrintVecElement(vec, n);
    MoveZeroes(vec, n);
    printf("移动零后, 数组为:\n");
    PrintVecElement(vec, n);
    FreeVec(vec);
}

// 贪心：
// Time: O(N)
// Space: O(1)
void MoveZeroes(int *nums, int numsSize)
{
    int i = 0;
    int index = 0;
    while (i < numsSize)
    {
        if (nums[i] != 0)
        {
            nums[index] = nums[i];
            index++;
        }
        i++;
    }
    for (int i = index; i < numsSize; i++)
    {
        nums[i] = 0;
    }
    return;
}
