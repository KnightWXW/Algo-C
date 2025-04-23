#include "../Mybasic/mybasic.h"

//      Huawei: 社区蔬菜配送

//      疫情期间，有一批社区的家庭需要配送爱心蔬菜，
//      每个社区的家庭个数用 communities 数组表示,
//      (下标表示社区编号，值表示对应社区的家庭个数,
//      例如, communities[0] == 5, 表示第 0 个社区有 5 个家庭)。
//      现有 num 个志愿者为这些社区家庭配送蔬菜，配送规则如下：
//      每个社区只能被分配一次任务，配送编号连续的若干个社区。
//      为每个家庭配送爱心蔬菜耗时均为 1 小时。
//      志愿者可以并行配送。
//      请合理分配志愿者，使得能够在最短的时间内完成配送任务，并返回所需要的小时数。
//      输入样例1:
//          2
//          40 10 20
//      输出样例 40
//      输入样例2:
//          2
//          1 1 6 2
//      输出样例 8
//      输入样例3:
//          3
//          1 2
//      输出样例 2

int CommunityVegetableDelivery(int num, int *communities, int size);

int main()
{
    // int n = GenerateRandomNum(1, 20);
    // int *communities = GenerateRandomVec(0, 50, n);
    // int num = GenerateRandomNum(1, 10);
    // int ans_A = CommunityVegetableDelivery(num, communities, n);
    int communities[] = {1, 1, 6, 2};
    int n = 4;
    int num = 2;
    int ans_A = CommunityVegetableDelivery(num, communities, n);
    PrintVecElement(communities, n);
    printf("志愿者个数为 %d 时, 完成配送任务的最少小时数是 %d\n", num, ans_A);
    FreeVec(communities);
}

bool JudgeCommunityVegetableDelivery(int num, int *communities, int size, int mid)
{
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < size; i++)
    {
        if (cur + communities[i] < mid)
        {
            cur += communities[i];
        }
        else
        {
            cnt++;
            cur = communities[i];
        }
        if (cnt > num)
        {
            return false;
        }
    }
    return true;
}

// 二分查找：
// Time: O(logN)
// Space: O(1)
int CommunityVegetableDelivery(int num, int *communities, int size)
{
    int maxVal = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += communities[i];
        maxVal = max(maxVal, communities[i]);
    }
    int left = maxVal;
    int right = sum;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeCommunityVegetableDelivery(num, communities, size, mid) == true)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}