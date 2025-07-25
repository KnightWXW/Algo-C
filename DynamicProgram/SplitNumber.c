#include "../Mybasic/mybasic.h"

//      数字分裂

//      给定一个正数 n ，求 n 的裂开方法数，
//      规定：后面的数不能比前面的数小
//      比如 4 的裂开方法有： (1+1+1+1、1+1+2、1+3、2+2、4) 共 5 种，
//      所以返回 5

int SplitNumber_A(int n);

int main()
{
    int num = generateRandomNum(1, 100);
    printf("暴力递归: %d 的裂开方法数 为 %d\n", num, SplitNumber_A(num));
    printf("记忆化搜索: %d 的裂开方法数 为 %d\n", num, SplitNumber_B(num));
    printf("动态规划: %d 的裂开方法数 为 %d\n", num, SplitNumber_C(num));
    printf("动态规划(空间优化): %d 的裂开方法数 为 %d\n", num, SplitNumber_D(num));
    printf("矩阵快速幂: %d 的裂开方法数 为 %d\n", num, SplitNumber_E(num));
}

int SplitNumber_A(int n)
