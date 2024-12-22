#include "../Mybasic/mybasic.h"

//      Huawei 集五福

//      作为近年来大家喜闻乐见迎新春活动，
//      集合爱国福、富强福、和谐福、友善福、敬业福即可分享超大红包。
//      以 0 和 1 组成的长度为 5 的字符串代表每个人所得到的福卡，
//      每一位代表一种福卡，1 表示已经获得该福卡，单类型福卡不超过 1 张，
//      随机抽取一个小于 10 人团队，求该团队最多可以集齐多少套五福？
//      输入描述
//          输入若干个由0、1组成的长度等于5的字符串，代表团队中每个人福卡获得情况。
//          注意1：1人也可以是一个团队
//          注意2：1人可以有0到5张福卡，但福卡不能重复
//      输出描述
//          输出该团队最多能凑齐多少套五福
//      示例一
//          输入
//              11001,11101
//          输出
//              0
//      示例二
//          输入
//              11101,10111
//          输出
//              1

#define NUM_FIVE 5

int GatheringFiveBlessings(char **vec, int n);

int main()
{
    int n = GenerateRandomNum(1, 10);
    char arr1[] = {'0', '1'};
    char **strs = GenerateRandomStringVecFixed(n, 5, arr1, 2);
    PrintStringVec(strs, n);
    int ans_A = GatheringFiveBlessings(strs, n);
    printf("该团队最多可以集齐 %d 套五福 ", ans_A);
    FreeStringVec(strs, n);
}

int GatheringFiveBlessings(char **vec, int n)
{
    int ans = n + 1;
    int *cnt = (int *)malloc(NUM_FIVE * sizeof(int));
    memset(cnt, 0, NUM_FIVE * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NUM_FIVE; j++)
        {
            cnt[j] += (vec[i][j] == '0' ? 0 : 1);
        }
    }
    PrintVecElement(cnt, 5);
    for (int i = 0; i < NUM_FIVE; i++)
    {
        ans = min(ans, cnt[i]);
    }
    return ans;
}