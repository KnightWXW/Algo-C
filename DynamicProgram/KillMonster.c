#include "../Mybasic/mybasic.h"

//      给定 3 个参数，n，m，k ,
//      怪兽有N滴血，等着英雄来砍自己,
//      英雄每一次打击，都会让怪兽流失[0 - m]的血量
//      到底流失多少？每一次在[0 - m]上等概率的获得一个值
//      求 k 次打击之后，英雄把怪兽砍死的概率

double KillMonster_A(int n, int n, int k);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int m = GenerateRandomNum(0, 30);
    int k = GenerateRandomNum(0, 10);
    int ansA = KillMonster_A(n, m, k);
    printf("暴力递归: 怪兽有 %d 滴血, %d 次打击, 每次打击让怪兽流失[0-%d]的血量, 英雄把怪兽砍死概率为 %lf\n", n, k, m, ansA);
}

double KillMonster_A(int n, int n, int k)
{
    
}