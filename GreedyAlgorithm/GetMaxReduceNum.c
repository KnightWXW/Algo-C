#include "../Mybasic/mybasic.h"

//      一个活跃的开源项目，如果某段时间内出现代码量减少，
//      这可能意味着项目的需求或架构发生了重大变化。
//      对于代码量减少进行研究有助于了解开源项目的演进历程。
//      现按代码修改的先后顺序，给出某开源项目每次修改后统计的代码总量，记录于数组records中。
//      请找出在哪段时间内代码总量减少最大，并返回这个最大值
//      （即records[i]-records[j]的最大值，i<j）。
//      如果代码总量一直递增，则输出0。
//      输入
//          首行一个整数num，表示records长度，1<=num<=10^5
//          第二行是数组records，1<=records[i]<=10^6
//      输出
//          一个整数，表示代码总量减少的最大值。
//      样例
//          输入样例1
//              8
//              365 400 350 410 350 340 420 370
//          输出样例1
//              70
//          输入样例2
//              4
//              15000 17000 17000 22000
//          输出样例2
//              0

int GetMaxReduceNum(int* records, int l);

int main()
{
    int n = GenerateRandomNum(1, 100);
    int* records = GenerateRandomVec(1, 100, n);
    PrintVecElement(records, n);
    int ans = GetMaxReduceNum(records, n);
    printf("找出在哪段时间内代码总量减少最大，并返回这个最大值 为 %d\n", ans);
}

int GetMaxReduceNum(int* records, int l)
{

}