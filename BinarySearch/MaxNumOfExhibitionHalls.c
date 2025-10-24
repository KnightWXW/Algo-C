#include "../Mybasic/mybasic.h"

//      Huawei: 最大展厅人数

//      MWCS 展共有 N 个展厅，每个展厅的报名人数记于数组 nums。
//      因疫情原因，所有展厅参展总人数上限为 cnt
//      若报名人数之和大于 cnt, 则需限制参展人数，
//      请计算单个展厅的最大参展人数 limit, 使得参展总人数不超过 cnt,
//      参展限制规则为：
//          对于报名人数 不超过 limit 的展厅，凡报名即参展；
//          对于报名人数 超过 limit 的展厅，则均要求 limit 名人员参展；
//          若报名人数之和 小于等于 cnt, 此时不需要限制参展人数，请返回-1
//      请返回 limit 的最大值或 -1
//      示例一：
//          输入：
//              nums = [1,4,2,5,5,1,6]
//              cnt = 13
//          输出：2
//      示例二：
//          输入：
//              nums = [1,3,2,1]
//              cnt = 197
//          输出：-1
//      示例三：
//          输入：
//              nums = [1,1]
//              cnt = 1
//          输出：0
//      提示：
//          0 <= nums.size() <= 10^5
//          0 <= nums[i] <= 10^5
//          0 <= cnt <= 10^5

int MaxNumOfExhibitionHalls(int *nums, int l, int cnt);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *nums = GenerateRandomVec(1, 100, n);
    int cnt = GenerateRandomNum(0, 300);
    printf("每个展厅的报名人数 为: \n");
    PrintVecElement(nums, n);
    int limit = MaxNumOfExhibitionHalls(nums, n, cnt);
    printf("单个展厅的最大参展人数 为 %d, 使得参展总人数不超过 %d\n", limit, cnt);
    FreeVec(nums);
}

int CompareInt(const void *a, const void *b)
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return (*tema) - (*temb);
}

bool JudgeExhibitionHalls(int *nums, int l, int cnt, int mid)
{
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += min(nums[i], mid);
    }
    return sum <= cnt;
}

// 二分查找：
// Time：O(NlogN)
// Space: O(logN)
int MaxNumOfExhibitionHalls(int *nums, int l, int cnt)
{
    qsort(nums, l, sizeof(int), CompareInt);
    int ans = 0;
    int left = 0;
    int right = nums[l - 1] + 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeExhibitionHalls(nums, l, cnt, mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right - 1;
}