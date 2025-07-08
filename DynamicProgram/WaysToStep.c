#include "../Mybasic/mybasic.h"

//      LeetCode 面试题 08.01. 三步问题

//      链接: https://leetcode.cn/problems/three-steps-problem-lcci/

//      三步问题。有个小孩正在上楼梯，楼梯有 n 阶台阶，小孩一次可以上 1 阶、2 阶或 3 阶。
//      实现一种方法，计算小孩有多少种上楼梯的方式。
//      结果可能很大，你需要对结果模 1000000007。
//      示例 1：
//          输入：n = 3 
//          输出：4
//          说明：有四种走法
//      示例 2：
//          输入：n = 5
//          输出：13
//      提示:
//          n 范围在[1, 1000000]之间

int WaysToStep_A(int n);

int main()
{
    int num = GenerateRandomNum(1, 47);
    printf("(暴力递归): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_A(num));
    printf("(记忆化搜索): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_B(num));
    printf("(动态规划): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_C(num));
    printf("(动态规划-空间压缩): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_D(num));
    printf("(矩阵快速幂): 楼梯有 %d 阶台阶,小孩 %d 种上楼梯的方式\n", num, WaysToStep_E(num));
}

