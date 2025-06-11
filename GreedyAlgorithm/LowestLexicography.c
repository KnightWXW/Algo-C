#include "../Mybasic/mybasic.h"

//      给定一个 字符串类型 的数组 strs，找到一种拼接方式，
//      使得把 所有字符串 拼起来 之后形成的 字符串 具有 最低的字典序。

char *LowestLexicography(char **vec, int l);

int main()
{
    int l = GenerateRandomNum(1, 10);
    int a = GenerateRandomNum(1, 5);
    int b = GenerateRandomNum(6, 10);
    char arr[] = {'a','b','c','d','e','f','g'};
    char **vec = GenerateRandomStringVecUnfixed(l, a, b, arr, strlen(arr));
    PrintStringVec(vec, l);
    char* ans = lowestLexicography(vec, l);
    PrintString(ans);
    FreeStringVec(vec, l);
}

// 贪心
// Time: O(NlogN)
// Space: O(N)
char *LowestLexicography(char **vec, int l)
{
}