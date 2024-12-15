#include "../Mybasic/mybasic.h"

//      Huawei: 挑七

//      输出 1 到 n 之间 的与 7 有关数字的个数。
//      一个数与 7 有关是指这个数是 7 的倍数，或者是包含 7 的数字
//      (如 17 ，27 ，37 ... 70 ，71 ，72 ，73 ... )
//      数据范围： 1 ≤ n ≤ 30000
//      输入描述：一个正整数 n 。(n 不大于 30000)
//      输出描述：
//          一个整数，表示 1 到 n 之间的与 7 有关的数字个数。
//      示例1
//          输入： 20
//          输出： 3
//          说明： 输入20，1 到 20 之间有关的数字包括 7,14,17 共 3 个

bool ContainsSeven(int cur);
int PickSeven(int num);

int main()
{
    int n = GenerateRandomNum(1, 1000);
    int ans = PickSeven(n);
    printf("1 ~ %d 之间的 与 7 有关的数字个数为 %d 。\n", n, ans);
}

bool ContainsSeven(int cur)
{
    int tem = cur;
    while (tem != 0)
    {
        int k = tem % 10;
        if (k == 7)
        {
            return true;
        }
        tem /= 10;
    }
    return cur % 7 == 0;
}

int PickSeven(int num)
{
    int cnt = 0;
    for (int i = 1; i <= num; i++)
    {
        cnt += ContainsSeven(i) ? 1 : 0;
    }
    return cnt;
}