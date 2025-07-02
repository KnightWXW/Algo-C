#include "../Mybasic/mybasic.h"

//      LeetCode 790. 多米诺和托米诺平铺

//      链接：https://leetcode.cn/problems/domino-and-tromino-tiling/

//      有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。
//      两种形状都可以旋转。
//      给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值。
//      平铺指的是每个正方形都必须有瓷砖覆盖。
//      两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，
//      使得恰好有一个平铺有一个瓷砖占据两个正方形。
//      示例 1:
//          输入: n = 3
//          输出: 5
//              解释: 五种不同的方法如上所示。
//      示例 2:
//          输入: n = 1
//          输出: 1
//      提示：
//          1 <= n <= 1000

int NumTilings_A(int n);

int main(){
    int num = GenerateRandomNum(0, 40);
    int ansA = NumTilings_A(num);
    printf("随机数字为：%d\n", num);
    printf("(暴力递归): 平铺 2 x %d 的面板的方法的数量 为 %d\n", num, ansA);
}
