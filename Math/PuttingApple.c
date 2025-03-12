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
    printf("买 %d 个苹果, 至少使用 %d 个袋子。\n", n, PuttingApple_A(n));
    printf("买 %d 个苹果, 至少使用 %d 个袋子。\n", n, PuttingApple_B(n));
}

// 模拟：
// Time: O(n)
// Space: O(1)
int PuttingApple_A(int n)
{
    
}

// 打表 找规律：
// Time: O(n)
// Space: O(1)
int PuttingApple_B(int n)
{
    
}