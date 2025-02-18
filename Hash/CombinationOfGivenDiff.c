#include "../Mybasic/mybasic.h"

//      Huawei: 给定差值的组合

//      给定一个数组，每个元素的值是唯一的，
//      找出其中两个元素相减等于给定差值diff的所有不同组合的个数。
//      组合是无序的：如(1,4) 和 (4,1) 表示同一个组合。
//      示例1：
//          输入：
//              3
//              1 3 2 5 4
//          输出:
//              2
//      示例2：
//          输入：
//              -1
//              1 2 3
//          输出:
//              2

int CombinationOfGivenDiff(int *vec, int n, int diff);

int main()
{
    int n = GenerateRandomNum(0, 10);
    int *vec = GenerateRandomVec(0, 20 ,n);
    int diff = GenerateRandomNum(1, 5);
    int ans_A = CombinationOfGivenDiff(vec, n, diff);
    PrintVecElement(vec, n);
    printf("数组中两个元素相减等于给定差值 %d 的所有不同组合的个数为 %d\n", diff, ans_A);
}

typedef struct
{
    int num;
    UT_hash_handle hh;
} HashSet;

// 哈希表：
// Time: O(N)
// Space: O(N)
int CombinationOfGivenDiff(int *vec, int n, int diff)
{
    int ans = 0;
    HashSet *set = NULL;
    HashSet *cur = NULL;
    for (int i = 0; i < n; i++)
    {
        cur = (HashSet *)malloc(sizeof(HashSet));
        cur->num = vec[i];
        HASH_ADD_INT(set, num, cur);
    }
    cur = NULL;
    for (int i = 0; i < n; i++)
    {
        int target = vec[i] + diff;
        HASH_FIND_INT(set, &target, cur);
        if (cur != NULL)
        {
            HASH_DEL(set, cur);
            ans++;
        }
    }
    HASH_CLEAR(hh, set);
    free(set);
    return ans;
}