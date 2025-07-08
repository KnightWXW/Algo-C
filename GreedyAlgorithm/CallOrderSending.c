#include "../Mybasic/mybasic.h"

//      Huawei: 话单发送

//      某核心网设备向计费网关发送话单(一个话单指一条通话记录的信息), 发送规则如下：
//      每个话单具有长度和优先级两个属性，
//      优先级值越小表示优先级越高，高优先级的发送完，才能发送低优先级的。
//      设备有一个承载规格，表示发送话单总容量的阈值。
//      发送话单的总长度不能超过承载规格。
//      现给定设备的承载规格和待发送话单(长度和优先级)列表，请计算最多可以发送多少个话单。
//      样例1：
//          输入：
//              110
//              {{50, 2}, {20, 2}, {30, 1}, {10, 3}, {50, 1}}
//          输出：
//              3

int CallOrderSending(int **arr, int row, int col, int k);

int main()
{
    int k = 110;
    int row = 5;
    int col = 2;
    int **vec = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        vec[i] = (int *)malloc(sizeof(int) * col);
    }
    vec[0][0] = 50;
    vec[0][1] = 2;
    vec[1][0] = 20;
    vec[1][1] = 2;
    vec[2][0] = 30;
    vec[2][1] = 1;
    vec[3][0] = 10;
    vec[3][1] = 3;
    vec[4][0] = 50;
    vec[4][1] = 1;
    PrintVecElement2D(vec, row, col);
    int ans_A = CallOrderSending(vec, row, col, k);
    printf("阈值为 %d 时, 最多可以发送 %d 个话单 。\n", k, ans_A);
    FreeVec2D(vec, row);
}

int Compare2dInt(const void *a, const void *b)
{
    int **tema = (int **)a;
    int **temb = (int **)b;
    if (tema[1] == temb[1])
    {
        return tema[0] - temb[0];
    }
    return tema[1] - temb[1];
}

int CallOrderSending(int **arr, int row, int col, int k)
{
    qsort(arr, row, sizeof(int *), Compare2dInt);
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        if (sum > k)
        {
            return cnt;
        }
        sum += arr[i][0];
        cnt++;
    }
    return cnt;
}