#include "../Mybasic/mybasic.h"

//      LeetCode 1. 两数之和

//      链接: https://leetcode.cn/problems/two-sum/

//      给定一个整数数组 nums 和一个整数目标值 target，
//      请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//      你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
//      你可以按任意顺序返回答案。
//      示例 1：
//          输入：nums = [2,7,11,15], target = 9
//          输出：[0,1]
//          解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
//      示例 2：
//          输入：nums = [3,2,4], target = 6
//          输出：[1,2]
//      示例 3：
//          输入：nums = [3,3], target = 6
//          输出：[0,1]
//      提示：
//          2 <= nums.length <= 104
//          -109 <= nums[i] <= 109
//          -109 <= target <= 109
//          只会存在一个有效答案

int *TwoSum_A(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(-100, 100, n);
    int target = GenerateRandomNum(-100, 100);
    PrintVecElement(vec, n);
    int returnSizeA = 0;
    int *ans_A = TwoSum_A(vec, n, target, &returnSizeA);
    printf("该数组中找出 和为目标值 %d 的 下标 为：\n");
    PrintVecElement(ans_A, returnSizeA);
    int returnSizeB = 0;
    int *ans_B = TwoSum_B(vec, n, target, &returnSizeB);
    printf("该数组中找出 和为目标值 %d 的 下标 为：\n");
    PrintVecElement(ans_B, returnSizeB);
    FreeVec(ans_A);
    FreeVec(ans_B);
    FreeVec(vec);
}

// 双重遍历
// Time: O(n^2)
// Space: O(1)
int *TwoSum_A(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }
    return ans;
}

typedef struct
{
    int val;
    int index;
    UT_hash_handle hh;
} HashMap;

// 哈希表
// Time: O(n)
// Space: O(n)
int *TwoSum_B(int *nums, int numsSize, int target, int *returnSize)
{
    HashMap *map = NULL;
    HashMap *cur = NULL;

    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
    {
        int tem = target - nums[i];
        HASH_FIND_INT(map, &tem, cur);
        if (cur != NULL)
        {
            ans[0] = cur->index;
            ans[1] = i;
            break;
        }
        cur = NULL;
        cur = (HashMap *)malloc(sizeof(HashMap));
        cur->val = nums[i];
        cur->index = i;
        HASH_ADD_INT(map, val, cur);
    }
    HASH_CLEAR(hh, map);
    return ans;
}