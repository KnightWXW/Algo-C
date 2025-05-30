#include "../Mybasic/mybasic.h"

//      LeetCode 面试题 08.11. 硬币

//      链接：https://leetcode.cn/problems/coin-lcci/

//      给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算 n分 有几种表示法。
//      (结果可能会很大，你需要将结果模上 1000000007)
//      示例 1：
//          输入：n = 5
//          输出：2
//          解释：有两种方式可以凑成总金额:
//              5=5
//              5=1+1+1+1+1
//      示例 2：
//          输入：n = 10
//          输出：4
//          解释：有四种方式可以凑成总金额:
//              10=10
//              10=5+5
//              10=5+1+1+1+1+1
//              10=1+1+1+1+1+1+1+1+1+1
//      说明：
//          注意:
//          你可以假设：
//              0 <= n (总金额) <= 1000000

int WaysToChange(int n); 

int main()
{
    int n = GenerateRandomNum(0, 1000000);
    bool ans = WaysToChange(n);
    printf("计算 %d 分有 %d 种表示法\n", n, ans);
}


int WaysToChange(int n)
{
    
}