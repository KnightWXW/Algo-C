#include "../Mybasic/mybasic.h"

//      网易: 环形分发糖果

//      给定一个正数数组arr，表示每个小朋友的得分
//      任何两个相邻的小朋友，如果得分一样，怎么分糖果无所谓，
//      但如果得分不一样，分数大的一定要比分数少的多拿一些糖果
//      假设所有的小朋友坐成一个环形，返回在不破坏上一条规则的情况下，
//      需要的最少糖果数

int CandyDistributionOfLooped(int* ratings, int l);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int* vec = GenerateRandomVec(1, 100, n);
    PrintVec(vec, l);
    int ans = CandyDistributionOfLooped(vec, l);
    printf("需要准备的 最少糖果数目为 %d\n", ans);
    FreeVec(vec);
}

int CandyDistributionOfLooped(int* ratings, int l)
{
   
}