#include "../Mybasic/mybasic.h"

//      Huawei: 鱼缸难题

//      最近小华买了 N 条鱼，小华想买一些鱼缸去装他们，
//      商店有两种鱼缸：
//          第一种：每个鱼缸价格是 C1 元，可以装 N1 条鱼
//          第二种：每个鱼缸价格是 C2 元，可以装 N2 条鱼
//      小华想把所有的鱼都养在买的那些鱼缸里，
//      而且每个鱼缸都要装满鱼，
//      小华很难计算出两种鱼缸各买多少个最实惠(总花费最小)，
//      请你使用程序帮小华计算出最实惠方案。
//      输入：
//          共三行:
//              整数 N
//              C1 N1
//              C2 N2
//              所有数范围 [1, 2000000000]
//      输出：
//          每个用例占一行，对于不存在解的情况输出Failed
//          (即不能满足所有的鱼都装在鱼缸中且每个鱼缸都装满)
//          否则，请输出两个整数 M1, M2
//          (表示第一种鱼缸买 M1 个，第二种鱼缸买 M2 个，保证是唯一解)
//      输入样例1：
//          43
//          1 3
//          2 4
//      输出样例1：
//          13 1

char *FishTankChallenge(int fishes, int c1, int n1, int c2, int n2);

int main()
{
    int fishes = GenerateRandomNum(1, 100);
    int c1 = GenerateRandomNum(1, 5);
    int n1 = GenerateRandomNum(10, 15);
    int c2 = GenerateRandomNum(1, 6);
    int n2 = GenerateRandomNum(9, 14);
    int ansL = 0;
    char *ans_A = FishTankChallenge(fishes, c1, n1, c2, n2);
    printf("fishes == %d, c1 == %d, n1 == %d, c2 == %d, n2 == %d, \n最小花费为:\n", fishes, c1, n1, c2, n2);
    PrintString(ans_A);
    FreeString(ans_A);
}

// 数学：
// Time: O(N)
// Space: O(1)
char *FishTankChallenge(int fishes, int c1, int n1, int c2, int n2)
{
    int bigC = c1;
    int bigN = n1;
    int smallC = c2;
    int smallN = n2;
    if ((c1 / n1) < (c2 / n2))
    {
        bigC = c2;
        bigN = n2;
        smallC = c1;
        smallN = n1;
    }
    int a = fishes / bigN;
    int b = (fishes - (a * bigN)) / smallC;
    char *ans = (char *)malloc(sizeof(char) * 32);
    memset(ans, 0, sizeof(char) * 32);
    if ((fishes - (a * bigN)) % smallC != 0)
    {
        strcpy(ans, "Failed");
        return ans;
    }
    else
    {
        sprintf(ans, "%d %d", a, b);
        return ans;
    }
}