#include "../Mybasic/mybasic.h"

//      买苹果

//      小虎 去买苹果，商店只提供 两种类型的塑料袋，每种类型都有任意数量
//          1）能装下 6 个 苹果 的袋子
//          2）能装下 8 个 苹果 的袋子
//      小虎可以自由使用两种袋子来装苹果，但是小虎有强迫症，
//      他要求自己使用的袋子数量必须最少，且使用的每个袋子必须装满，
//      给定一个正整数 N，返回至少使用多少袋子。
//      如果N无法让使用的每个袋子必须装满，返回-1

int PuttingApple_A(int n);
int PuttingApple_B(int n);

int main()
{
    int n = GenerateRandomNum(1, 10000);
    int ans1 = PuttingApple_A(n);
    int ans2 = PuttingApple_B(n);
    printf("买 %d 个苹果, 至少使用 %d 个袋子。\n", n, ans1);
    printf("买 %d 个苹果, 至少使用 %d 个袋子。\n", n, ans2);
}

// 模拟：
// Time: O(n)
// Space: O(1)
int PuttingApple_A(int n)
{
    int eight = n / 8;
    int six = 0;
    int dif = n % 8;
    if (dif == 0)
    {
        return eight;
    }
    while (eight >= 0)
    {
        int tem = dif % 6;
        six = dif / 6;
        if (tem == 0)
        {
            return six + eight;
        }
        dif += 8;
        eight--;
    }
    return -1;
}

// 打表 找规律：
// Time: O(n)
// Space: O(1)
int PuttingApple_B(int n)
{
    if ((n & 1) == 1)
    {
        return -1;
    }
    else if (n < 18)
    {
        if (n == 6 || n == 8)
        {
            return 1;
        }
        else if (n == 12 || n == 14 || n == 16)
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return (n - 18) / 8 + 3;
    }
}