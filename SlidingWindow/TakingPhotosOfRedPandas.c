#include "../Mybasic/mybasic.h"

//      Huawei: 大熊猫拍照

//      卧龙大熊猫基地要对今年新出生的大熊猫进行拍照合影。
//      但是熊猫不太听话，有的面向前方，有的面向后方。
//      为了拍到所有熊猫的正脸，使用了一台自动给熊猫转向的机器。
//      通过用户预先设定一个数值K，可以给连续的K个熊猫进行转向
//      (单次操作翻转的数量必须为K个)。
//      请求出在不同K值下，让所有熊猫都面朝前方的最小操作数。
//      输入：
//          第一行为熊猫个数N，
//          第二行为每个熊猫的面向：F为向前，B为向后
//      输出：
//          最少的操作次数
//      输入样例:
//          7
//          BBFBFBB
//      输出样例 3

int TakingPhotosOfRedPandas(char* s);

int main()
{
    int n = GenerateRandomNum(1, 30);
    char* str = GenerateRandomString(n);
    PrintString(str);
    int ans_A = TakingPhotosOfRedPandas(str);
    printf("让所有熊猫都面朝前方的最小操作数为：%d\n", ans_A);
}

int TakingPhotosOfRedPandas(char* s)
{
    
}