#include "../Mybasic/mybasic.h"

//      LeetCode 525. 连续数组

//      链接: https://leetcode.cn/problems/contiguous-array/

//      给定一个二进制数组 nums,
//      找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
//      示例 1：
//          输入：nums = [0,1]
//          输出：2
//          说明：[0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
//      示例 2：
//          输入：nums = [0,1,0]
//          输出：2
//          说明：[0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
//      示例 3：
//          输入：nums = [0,1,1,1,1,1,0,0,0]
//          输出：6
//          解释：[1,1,1,0,0,0] 是具有相同数量 0 和 1 的最长连续子数组。
//      提示：
//          1 <= nums.length <= 105
//          nums[i] 不是 0 就是 1

int FindMaxLength(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 1, n);
    PrintVecElement(vec, n);
    int ans = FindMaxLength(vec, n);
    printf("最长连续子数组 为: %d\n", ans);
    FreeVec(vec);
}

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} HashMap;

// 前缀和 + 哈希
// Time: O(N)
// Space: O(N)
int FindMaxLength(int *nums, int numsSize)
{
    HashMap *hmap = NULL;
    HashMap *cur = NULL;
    cur = (HashMap *)malloc(sizeof(HashMap));
    cur->key = 0;
    cur->val = -1;
    HASH_ADD_INT(hmap, key, cur);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            cnt--;
        }
        else
        {
            cnt++;
        }
        HASH_FIND_INT(hmap, &cnt, cur);
        if (cur == NULL)
        {
            HashMap *new = (HashMap *)malloc(sizeof(HashMap));
            new->key = cnt;
            new->val = i;
            HASH_ADD_INT(hmap, key, new);
        }
        else
        {
            ans = max(ans, i - cur->val);
        }
    }
    return ans;
}