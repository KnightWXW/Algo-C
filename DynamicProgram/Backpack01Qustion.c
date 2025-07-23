#include "../Mybasic/mybasic.h"

//      0-1 背包问题

//      有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
//      第 i 件物品的重量是 weight[i]，价值是 value[i]
//      求解将哪些物品装入背包，可使这些物品的总体积不超过背包重量，且总价值最大。
//      输出最大价值。

int Backpack01Qustion_A(int *value, int *weight, int l, int v);

int main()
{
    int n = GenerateRandomNum(0, 10);
    int v = GenerateRandomNum(0, 100);
    int *value = GenerateRandomVec(0, 100, n);
    int *weight = GenerateRandomVec(0, 20, n);
    int ansA = Backpack01Qustion_A(value, weight, n, v);
    int ansB = Backpack01Qustion_B(value, weight, n, v);
    int ansC = Backpack01Qustion_C(value, weight, n, v);
    printf("物品的价值数组为:");
    PrintVecElement(value, n);
    printf("物品的重量数组为:");
    PrintVecElement(weight, n);
    printf("暴力递归: 0-1 背包的最大价值为 %d \n", ansA);
    printf("记忆化搜索: 0-1 背包的最大价值为 %d \n", ansB);
    printf("动态规划: 0-1 背包的最大价值为 %d \n", ansC);
    FreeVec(value);
    FreeVec(weight);
}


int Backpack01Qustion_A(int *value, int *weight, int l, int v)
{

}