#include "../Mybasic/mybasic.h"

//      最少灯泡数目

//      给定一个 字符串str，只由 'X' 和 '.' 两种字符构成
//      'X' 表示墙，不能放灯，也不需要点亮；
//      '.' 表示居民点，可以放灯，需要点亮
//      如果灯放在 i 位置，可以让 i-1 ，i 和 i+1 三个位置被点亮
//      返回如果点亮 str 中所有需要点亮的位置，至少需要几盏灯

int MinLightNum(char* s);

int main()
{
    int n = GenerateRandomNum(0, 50);
    char* s = GenerateRandomString(n);
    printf("STR 字符串为：");
    PrintString(s);
    int ans = MinLightNum(s);
    printf("点亮 s 中所有需要点亮的位置, 至少需要 %d 盏灯 \n", ans);
}


// 贪心：
// Time: O(N)
// Space: O(N)
int minLightNum(char* s)
{
    
}