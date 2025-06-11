#include "../Mybasic/mybasic.h"

//      得物: 不包含110的最长子串的长度

//      自从学习了计算机编程，小明就彻底差上了0和1，很多01串经常在他脑子里面浮现。
//      但是他从小就害怕警察，虽然他并没有犯过啥大错误，
//      最多就是在小花的新衣服上画朵小花，在小红的白裙子上点上几个小红点….
//      所以他很害怕110。现在给你一个01串，
//      请你编写一个程序计算在这个01串中不包含110的最长子串的长度。
//      输入描述：
//          输入一行，包含一个01串S(在S中只包含0和1，有可能输入全为0或者1的串)，
//          其长度1≤|S|≤1000000.
//      输出描述：
//          输出01串S中不包含110的最长子串的长度

int SubStringExcluding110(char* str);

int main()
{
    int n = GenerateRandomString(1, 10);
    int arr[] = {'0', '1'};
    char* str = GenerateRandomString(n, arr, strlen(arr));
    PrintString(str);
    int ans_A = SubStringExcluding110(str);
    printf("不包含110的最长子串的长度: %d\n", ans_A);
    FreeString(str);
}

// 贪心:
// Time: O(N)
// Space: O(1)
int SubStringExcluding110(char* str)
{
   
}