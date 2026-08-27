#include "../Mybasic/mybasic.h"

//      一个数组中只有两种字符 'G' 和 'B' ,
//      想让所有的 'G' 都放在左侧，所有的 'B' 都放在右侧,
//      但是只能在相邻字符之间进行交换操作，
//      返回至少需要交换几次

int SwapCnt(char* s);

int main()
{
    int n = GenerateRandomNum(0, 20);
    char arr[2] = "GB";
    char *str = GenerateRandomString(n, arr, 2);
    PrintString(str);
    int ans_A = LengthOfLongestSubstring(str);
    printf("至少需要交换 %d 次", ans_A);
    FreeString(str);
}

int SwapCnt(char* s)
{
    int l = strlen(s);
    
}