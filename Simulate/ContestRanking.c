#include "../Mybasic/mybasic.h"

//      Huawei: 参赛排名

//      小明发现他参加Online Judge的比赛表现极不稳定，于是他翻开历史记录，
//      发现他在每一轮的比赛中他的排名R都能整除参赛人数N(包括他自己)，
//      于是他每次参赛都会预测他的排名情况，以给自己更大的自信。
//      输入：
//          参赛人数 N
//      输出：
//          在一行输出小明参赛可能获得的排名数S
//          以及从小到大输出各个排名Ri(0< i < S)
//      输入样例1：
//          10
//      输出样例1：
//          4 
//          1 2 5 10

int* ContestRanking(int num, int l);

int main()
{
    int n = GenerateRandomNum(1, 999999);
    int l = 1;
    int* vec = ContestRanking(n, l);
    printf("当有 %d 名选手参赛时,小明参赛可能获得的排名为:\n", n);
    PrintVecElement(vec, l);
    FreeVec(vec);
}

// 模拟: 
// Time: O(N^1/2)
// Space: O(1)
int* ContestRanking(int num, int l)
{
    
    return ans;
}