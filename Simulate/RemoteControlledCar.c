#include "../Mybasic/mybasic.h"

//      Huawei: 遥控小车

//      假设在平面直角坐标系中（上北下南左西右东），
//      一个小车最初位于原点(0，0) 处，且面朝北方，遥控小车可以接受下列三条指令之一：
//          “G”: 直走一个单位
//          “L”: 左转90度
//          “R”: 右转90度
//      给定一批指令，遥控小车按顺序执行每个指令后，请计算遥控小车最终所处的位置。
//      输入：
//          字符串表示的一批遥控指令，仅由字符 G, L, R, 组成。
//      输出：
//          小车最终所处位置的坐标
//      输入样例1:
//          GG
//      输出样例1:
//          (0, 2)

int *RemoteControlledCar(char *s, int l);

int main()
{
    int num = GenerateRandomNum(1, 10);
    char arr[] = {'G', 'L', 'R', 'G'};
    char *s = GenerateRandomString(num, arr, 4);
    int *ans_A = RemoteControlledCar(s, num);
    printf("遥控指令 为: \n");
    PrintString(s);
    printf("小车最终所处位置的坐标 为 (%d, %d)。\n", ans_A[0], ans_A[1]);
    FreeVec(ans_A);
    FreeString(s);
}

int *RemoteControlledCar(char *s, int l)
{
    int x = 0;
    int y = 0;
    int *arr = (int *)malloc(sizeof(int) * 2);
    int direction = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'L')
        {
            if (direction == 0)
            {
                direction = 3;
            }
            else
            {
                direction--;
            }
        }
        else if (s[i] == 'R')
        {
            direction = (direction + 1) % 4;
        }
        else if (s[i] == 'G')
        {
            if (direction == 0)
            {
                y++;
            }
            else if (direction == 1)
            {
                x++;
            }
            else if (direction == 2)
            {
                y--;
            }
            else if (direction == 3)
            {
                x--;
            }
        }
    }
    int *arr = (int *)malloc(sizeof(int) * 2);
    arr[0] = x;
    arr[1] = y;
    return arr;
}