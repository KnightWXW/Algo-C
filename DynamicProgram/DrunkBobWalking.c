#include "../Mybasic/mybasic.h"

//      醉酒的 Bob

//      给定 五 个参数，n，m，row，col，k。
//      表示在 n × m 的区域上，醉汉Bob 初始在 (row,col) 位置。
//      Bob一共要迈出k步，且每步都会等概率向上下左右四个方向走一个单位。
//      任何时候Bob只要离开 n × m的区域，就直接死亡。
//      返回 k步 之后，Bob 还在 n × m 的区域的概率。

double DrunkBobWalking_A(int n, int m, int ow, int col, int k);
double DFSDrunkBobWalking_A(int n, int m, int row, int col, int k);
double DrunkBobWalking_B(int n, int m, int ow, int col, int k);
double DFSDrunkBobWalking_B(int n, int m, int row, int col, int k, double ***arr);
double DrunkBobWalking_C(int n, int m, int row, int col, int k);
double PickElementFromArr(double ***arr, int i, int j, int cnt, int n, int m);

int main()
{
    int n = 30;
    int m = 10;
    int row = 2;
    int col = 8;
    int k = 7;
    int ansA = DrunkBobWalking_A(n, m, row, col, k);
    int ansB = DrunkBobWalking_B(n, m, row, col, k);
    int ansC = DrunkBobWalking_C(n, m, row, col, k);
    printf("暴力递归：%lf\n", ansA);
    printf("记忆化搜索：%lf\n", ansB);
    printf("动态规划：%lf\n", ansC); // 可计算k达到500
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
double DrunkBobWalking_A(int n, int m, int row, int col, int k)
{
    
}

double DFSDrunkBobWalking_A(int n, int m, int row, int col, int k)
{
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
double DrunkBobWalking_B(int n, int m, int row, int col, int k)
{
}

double DFSDrunkBobWalking_B(int n, int m, int row, int col, int k, double ***arr)
{
}

// 动态规划：
// Time: O(n * m * k)
// Space: O(n * m * k)
double DrunkBobWalking_C(int n, int m, int row, int col, int k)
{
}

double PickElementFromArr(double ***arr, int i, int j, int cnt, int n, int m)
{
}