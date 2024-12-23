#include "../Mybasic/mybasic.h"

//      LeetCode 1711. 大餐计数

//      链接：https://leetcode.cn/problems/count-good-meals/

//      大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。
//      你可以搭配 任意 两道餐品做一顿大餐。
//      给你一个整数数组 deliciousness ，其中 deliciousness[i] 是第 i​​​​​​​​​​​​​​ 道餐品的美味程度，
//      返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 109 + 7 取余。
//      注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。
//      示例 1：
//          输入：deliciousness = [1,3,5,7,9]
//          输出：4
//          解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
//              它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
//      示例 2：
//          输入：deliciousness = [1,1,1,3,3,3,7]
//          输出：15
//          解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。
//      提示：
//          1 <= deliciousness.length <= 105
//          0 <= deliciousness[i] <= 220

const int MOD = 1000000007;

int CountPairs_A(int *deliciousness, int deliciousnessSize);
int CountPairs_B(int *deliciousness, int deliciousnessSize);
int CountPairs_C(int *deliciousness, int deliciousnessSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ans_A = CountPairs(vec, n);
    int ans_B = CountPairs(vec, n);
    int ans_C = CountPairs(vec, n);
    printf("数组中的餐品做出的不同 大餐 的数量 为: %d \n", ans_A);
    printf("数组中的餐品做出的不同 大餐 的数量 为: %d \n", ans_B);
    printf("数组中的餐品做出的不同 大餐 的数量 为: %d \n", ans_C);
    FreeVec(vec);
}

typedef struct
{
    int key; 
    int val;
    UT_hash_handle hh;
} HashMap;

void HashMapAddNode(HashMap **hmap, int num)
{
    HashMap *cur = NULL;
    HASH_FIND_INT(*hmap, &num, cur);
    if (cur == NULL)
    {
        cur = (HashMap *)malloc(sizeof(HashMap));
        cur->key = num;
        cur->val = 1;
        HASH_ADD_INT(*hmap, key, cur);
    }
    else
    {
        cur->val++;
    }
    return;
}

void HashMapRemoveNode(HashMap **hmap, int num)
{
    HashMap *cur = NULL;
    HASH_FIND_INT(*hmap, &num, cur);
    if (cur != NULL)
    {
        HASH_DEL(*hmap, cur);
        free(cur);
    }
    return;
}

int HashMapFindNode(HashMap *hmap, int num)
{
    HashMap *cur = NULL;
    HASH_FIND_INT(hmap, &num, cur);
    if (cur == NULL)
    {
        return 0;
    }
    else
    {
        return cur->val;
    }
}

// 暴力双循环: 超时
//      求和之后再判断是否为2次幂
// Time: O(N^2)
// Space: O(N)
int CountPairs_A(int *deliciousness, int deliciousnessSize)
{
    int ans = 0;
    int maxVal = 0;
    HashMap *hmap = NULL;
    for (int i = 0; i < deliciousnessSize; i++)
    {
        for (int j = i + 1; j < deliciousnessSize; j++)
        {
            int curVal = deliciousness[i] + deliciousness[j];
            maxVal = max(maxVal, curVal);
            HashMapAddNode(&hmap, curVal);
        }
    }
    int k = 1;
    while (k <= maxVal)
    {
        ans += HashMapFindNode(hmap, k);
        ans %= MOD;
        k <<= 1;
    }
    HASH_CLEAR(hh, hmap);
    return ans;
}

// 单循环:
//      哈希表[K:数值; V: 次数]
//      作差求个数：
// Time: O(N * M)
// Space: O(N)
int CountPairs_B(int *deliciousness, int deliciousnessSize)
{
    int ans = 0;
    int maxVal = 0;
    HashMap *hmap = NULL;
    for (int i = 0; i < deliciousnessSize; i++)
    {
        maxVal = max(maxVal, deliciousness[i]);
        HashMapAddNode(&hmap, deliciousness[i]);
    }
    maxVal <<= 1;
    for (int i = 0; i < deliciousnessSize; i++)
    {
        int k = 1;
        while (k <= maxVal)
        {
            int dif = k - deliciousness[i];
            int cntA = HashMapFindNode(hmap, deliciousness[i]);
            int cntB = HashMapFindNode(hmap, dif);
            if (dif == deliciousness[i])
            {
                ans += (cntA * (cntA - 1)) / 2;
            }
            else
            {
                ans += cntA * cntB;
            }
            ans %= MOD;
            k <<= 1;
        }
        HashMapRemoveNode(&hmap, deliciousness[i]);
    }
    HASH_CLEAR(hh, hmap);
    return ans;
}

// 单循环:
//      哈希表[K:数值; V: 次数]
//      作差求个数，添加节点与求差同时进行：
// Time: O(N)
// Space: O(N)
int CountPairs_C(int *deliciousness, int deliciousnessSize)
{
    int ans = 0;
    int maxVal = 0;
    HashMap *hmap = NULL;
    HashMap *a = NULL;
    for (int i = 0; i < deliciousnessSize; i++)
    {
        maxVal = max(maxVal, deliciousness[i]);
    }
    maxVal <<= 1;
    for (int i = 0; i < deliciousnessSize; i++)
    {
        int k = 1;
        while (k <= maxVal)
        {
            int dif = k - deliciousness[i];
            HASH_FIND_INT(hmap, &dif, a);
            int cnt = (a == NULL) ? 0 : a->val;
            ans = (ans + cnt) % MOD;
            k <<= 1;
        }
        HashMapAddNode(&hmap, deliciousness[i]);
    }
    HASH_CLEAR(hh, hmap);
    return ans;
}