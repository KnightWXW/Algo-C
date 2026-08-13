#include "../Mybasic/mybasic.h"

//      LeetCode 560. 和为 K 的子数组

//      链接: https://leetcode.cn/problems/subarray-sum-equals-k/

//      给你一个整数数组 nums 和一个整数 k，请你统计并返回 该数组中和为 k 的子数组的个数。
//      子数组是数组中元素的连续非空序列。
//      示例 1：
//          输入：nums = [1,1,1], k = 2
//          输出：2
//      示例 2：
//          输入：nums = [1,2,3], k = 3
//          输出：2
//      提示：
//          1 <= nums.length <= 2 * 104
//          -1000 <= nums[i] <= 1000
//          -107 <= k <= 107

int SubarraySum_A(int *nums, int numsSize, int k);
int SubarraySum_B(int *nums, int numsSize, int k);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *arr = GenerateRandomVec(-10, 10, n);
    int k = GenerateRandomNum(-5, 20);
    int ans_A = SubarraySum_A(arr, n, k);
    int ans_B = SubarraySum_B(arr, n, k);
    PrintVecElement(arr, n);
    printf("和为 %d 的子数组 个数 为: %d\n", k, ans_A);
    printf("和为 %d 的子数组 个数 为: %d\n", k, ans_B);
    FreeVec(arr);
}

// 双重遍历
// Time: O(N^2)
// Space: O(1)
int SubarraySum_A(int *nums, int numsSize, int k)
{
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int s = 0;
        for (int j = i; j < numsSize; j++)
        {
            s += nums[j];
            if (s == k)
            {
                ans++;
            }
        }
    }
    return ans;
}

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} HashMap;

// 哈希 + 前缀和:
// Time: O(N)
// Space: O(N)
int SubarraySum_B(int *nums, int numsSize, int k)
{
    int ans = 0;
    HashMap *hmap = NULL;
    HashMap *cur = NULL;
    int sum = 0;
    cur = (HashMap *)(malloc)(sizeof(HashMap));
    cur->key = 0;
    cur->val = 1;
    HASH_ADD_INT(hmap, key, cur);
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        int dif = sum - k;
        HASH_FIND_INT(hmap, &dif, cur);
        if (cur != NULL)
        {
            ans += cur->val;
        }
        HASH_FIND_INT(hmap, &sum, cur);
        if (cur != NULL)
        {
            cur->val++;
        }
        else
        {
            HashMap *tem = NULL;
            tem = (HashMap *)(malloc)(sizeof(HashMap));
            tem->key = sum;
            tem->val = 1;
            HASH_ADD_INT(hmap, key, tem);
        }
    }
    HASH_CLEAR(hh, hmap);
    return ans;
}