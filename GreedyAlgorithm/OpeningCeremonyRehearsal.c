#include "../Mybasic/mybasic.h"

//      得物：开幕式排练

//      导演在组织进行大运会开幕式的排练，
//      其中一个环节是需要参演人员围成一个环形。演出人员站成了一圈，
//      出于美观度的考虑，导演不希望某一个演员身边的其他人比他低太多或者高太多。
//      现在给出n个参演人员的身高，问在他们站成一圈时，相邻演员的身高差的最大值至少是多少?
//      请你帮忙计算。
//      输入描述
//          输入包括两行，第一行有1个正整数，代表人数 n。
//          第二行有n个空格隔开的正整数h表示第i个演员的身高。
//      输出描述
//          输出包括一个正整数，表示答案。
//      输入：
//          5
//          2 1 1 3 2
//      输出：
//          1
//      输入：
//          2
//          10 20
//      输出：
//          10
//      样例1中排为1, 2, 3, 2, 1即可；样例2中排为10, 20即可

int OpeningCeremonyRehearsal(int* vec, int l);

int main()
{
    int n = generateRandomNum(1, 30);
    int* vec = generateRandomVec(1, 1000, n);
    PrintVecElement(vec, n);
    int ans_A = OpeningCeremonyRehearsal(vec, n);
    printf("相邻演员的身高差的最大值至少为：%d\n", ans_A);
    FreeVec(vec);
}

// 贪心: 排序后最大的在中间，左右递减，山形排列
// Time: O(N)
// Space: O(N)
int OpeningCeremonyRehearsal(int* vec, int l)
{
    
}