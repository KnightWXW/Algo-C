#include "../Mybasic/mybasic.h"

//      Huawei: 通断性测试

//      实验室对一个设备进行通断性测试，实验室可以操纵开关进行通断，有两种情况：
//      当开关 1 断开，或开关2, 3均被断开，设备不工作
//      当开关 1 闭合，且开关2和开关3至少有一个闭合时，设备工作
//              --------||-----/ 1-----------
//              |                           |
//              |                           |
//              |                           |
//              |           ----/ 2----     |
//              |           |         |     |
//              -----X-----------------------
//                          |         |
//                          ----/ 3----
//      初始时，3个开关的状态均为断开;
//      现给定实验员操控记录的数组records, records[i] = [time, switchId],
//      表示在时刻 time 更改了开关 switchId 的状态。
//      开关 switchId 仅为 1,2,3, 状态是从断开变为闭合，或从闭合变成断开。
//      测试中为了避免设备过热，若开关在时刻 time 闭合,
//      且在[time, time + limit] 闭合内未接收到指令,
//      则：在时刻 time + limit 该开关自动变为断开；
//      若此时恰好收到指令，则该开关再次变为闭合
//      请返回完成最后一次操作，且所有开关状态变为断开后，设备的累计工作时长。
//      示例1：
//          输入：
//              records = {{0, 1}, {1, 3}, {2, 2}, {3, 3}, {4, 1}, {4, 3}};
//              limit = 3
//          输出: 5
//      示例1：
//          输入：
//              records = {{3, 3}, {4, 1}, {5, 2}, {6, 1}, {7, 3}, {8, 1}, {11, 3}};
//              limit = 4
//          输出: 6

int ControlCircuit(int** records, int row, int col, int limit);

int main()
{
    int row1 = 6;
    int col1 = 2;
    int** v1 = (int**)malloc(sizeof(int*) * row1);
    for(int i = 0; i < row1; i++)
    {
        v1[i] = (int*)malloc(sizeof(int) * col1);
    }
    v1[0][0] = 0;
    v1[0][1] = 1;
    v1[1][0] = 1;
    v1[1][1] = 3;
    v1[2][0] = 2;
    v1[2][1] = 2;
    v1[3][0] = 3;
    v1[3][1] = 3;
    v1[4][0] = 4;
    v1[4][1] = 1;
    v1[5][0] = 4;
    v1[5][1] = 3;
    int limit1 = 3;
    int ans1 = ControlCircuit(v1, row1, col1, limit1);
    PrintVecElement2D(v1, row1, col1);
    printf("limit 为 %d 时, 设备的累计工作时长为 %d\n", limit1, ans1);
    int row2 = 7;
    int col2 = 2;
    int** v2 = (int**)malloc(sizeof(int*) * row1);
    for(int i = 0; i < row1; i++)
    {
        v2[i] = (int*)malloc(sizeof(int) * col1);
    }
    v2[0][0] = 3;
    v2[0][1] = 3;
    v2[1][0] = 4;
    v2[1][1] = 1;
    v2[2][0] = 5;
    v2[2][1] = 2;
    v2[3][0] = 6;
    v2[3][1] = 1;
    v2[4][0] = 7;
    v2[4][1] = 3;
    v2[5][0] = 8;
    v2[5][1] = 1;
    v2[5][0] = 11;
    v2[5][1] = 3;
    int limit2 = 4;
    int ans2 = ControlCircuit(v2, row2, col2, limit2);
    PrintVecElement2D(v2, row2, col2);
    printf("limit = %d 时, 设备的累计工作时长为 %d\n", limit2, ans2);
}


int ControlCircuit(int** records, int row, int col, int limit)
{
   
}