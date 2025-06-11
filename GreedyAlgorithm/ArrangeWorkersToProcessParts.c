#include "../Mybasic/mybasic.h"

//      Huawei: 安排加工零件的工人

//      某工厂有 n 个零件加工的师傅，每位师傅每天能够加工出不同数量的零件
//      现有 m 个零件要求一天加工完，请问该工厂最少需要派几个师傅来完成这次零件加工任务，
//      如果安排所有的师傅都参与加工也不能在一天内完成任务，请输出-1。
//      输入
//          第一行有两个整数，用空格隔开;
//              第一个整数代表要加工的总零件个数，
//              第二个整数代表工厂的零件加工师傅的数量
//          第二行有 n 个整数，分别代表每个师傅每天能够加工出来的零件数量
//              (每个师傅每天加工的零件数量n <= 10^4)。
//      输出
//          输出工厂在1天时间内加工所有零件需要的师傅数量，或者输出-1
//      输入
//          10 5
//          1 3 2 4 2
//      输出
//          4

int ArrangeWorkersToProcessParts(int *vec, int l, int num);

int main()
{
    int n = GenerateRandomNum(1, 50);
    int *vec = GenerateRandomVec(1, 300, n);
    int m = GenerateRandomNum(1, 1000);
    PrintVecElement(vec, n);
    int ans = ArrangeWorkersToProcessParts(vec, n, m);
    printf("工厂在1天时间内加工 %d 个零件需要的师傅数量 %d\n", m, ans);
    FreeVec(vec);
}

int ArrangeWorkersToProcessParts(int *vec, int l, int num)
{
}