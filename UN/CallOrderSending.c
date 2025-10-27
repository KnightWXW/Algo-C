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

int CallOrderSending(int **people, int row, int col, int k);

int main()
{
    int k = 110;
    int r1 = 5;
    int c1 = 2;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 50;
    vec1[0][1] = 2;
    vec1[1][0] = 20;
    vec1[1][1] = 2;
    vec1[2][0] = 30;
    vec1[2][1] = 1;
    vec1[3][0] = 10;
    vec1[3][1] = 3;
    vec1[4][0] = 50;
    vec1[4][1] = 1;
    PrintVecElement2D(vec1, r1, c1);
    int ans_A = CallOrderSending(vec1, r1, c1, k);
    printf("阈值为 %d 时, 最多可以发送多少个话单 %d \n", k, ans_A);
    FreeVec2D(vec1, r1);
}

int CallOrderSending(int **people, int row, int col, int k)
{
    
}