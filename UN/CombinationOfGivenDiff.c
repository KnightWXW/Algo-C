#include "../Mybasic/mybasic.h"

//      Huawei: 给定差值的组合

//      给定一个数组，每个元素的值是唯一的，
//      找出其中两个元素相减等于给定差值diff的所有不同组合的个数。
//      组合是无序的：如(1,4) 和 (4,1) 表示同一个组合。
//      示例1：
//          输入：
//              3
//              1 3 2 5 4
//          输出:
//              2
//      示例2：
//          输入：
//              -1
//              1 2 3
//          输出:
//              2

int CombinationOfGivenDiff(int *vec, int n, int diff);

int main()
{
    int n = GenerateRandomNum(0, 30);
    int *vec = GenerateRandomVec(0, 100, n);
    int diff = GenerateRandomNum(0, 10);
    int ans_A = CombinationOfGivenDiff(vec, n, diff);
    printVecElement(vec);
    FreeVec(vec);
    printf("数组中两个元素相减等于给定差值 %d 的所有不同组合的个数为 %d\n", diff, ans_A);
}

int CombinationOfGivenDiff(int *vec, int n, int diff)
{
    
}