#include "../Mybasic/mybasic.h"

//      Huawei: 业务连通性检测

//      工程师对通信链路(包含主备链路)做 连通性检测，
//      共有 num 个站点(站点编号为 0 ~ num - 1),
//      每个站点均有主备两个设备，上一行为主设备，下一行为备设备
//      (1) 同一站点的主备设备之间物理联通，相邻站点的主备设备之间物理联通，备备设备之间物理联通
//      (2) 设备 "上电" 则该设备信号是通的，设备 "下电" 则该设备信号是不通
//          设备支持上/下电切换操作：若该设备状态为 “上电”，则变更为 “下电”；
//          若该设备状态为 “下电”，则变更为 “上电”；
//          未进行切换操作，则设备状态维持不变。
//          初始时，所有设备均为 “上电” 状态。
//          二维数组 operations 表示对设备的上下电切换操作，
//          其中每个值为操作的设备，格式[主备标识, 站点编号],
//          主备标识为 0 表示主设备, 1 表示备设备
//      现按 operations 依次操作，请计算每次操作后的 连通性检测 结果，并返回结果序列。
//      "连通性检测"方式：操作后，信号是否能从链路的发送端设备(最左侧的主或备)传输至接收端设备(最右侧的主或备),
//      若成功则结果为 1, 否则为 0
//      示例1:
//          num = 5
//          operations = {{0, 2}, {0, 1}, {1, 2}, {0, 2}, {0, 1}};
//          输出：[1, 1, 0, 0, 1]
//      示例2:
//          num = 6
//          operations = {{1, 1}, {0, 4}, {0, 1}, {1, 4}, {1, 1}, {0, 4}};
//          输出：[1, 1, 0, 0, 0, 1]
//      提示：
//          3 <= num <= 10^5
//          1 <= operations.size() <= 10^5
//          operations[i].size() == 2
//          0 <= opeartion[i][0] <= 1
//          0 < opeartion[i][1] < num - 1

int *CheckConnecttivity_A(int num, int **operations, int l, int *returnSize);

int main()
{
    int n1 = 5;
    int r1 = 5;
    int c1 = 2;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 0;
    vec1[0][1] = 2;
    vec1[1][0] = 0;
    vec1[1][1] = 1;
    vec1[2][0] = 1;
    vec1[2][1] = 2;
    vec1[3][0] = 0;
    vec1[3][1] = 2;
    vec1[4][0] = 0;
    vec1[4][1] = 1;
    PrintVecElement2D(vec1, r1, c1);
    int rs1 = 0;
    int *ans1a = CheckConnecttivity_A(n1, vec1, r1, &rs1);
    printf("结果序列为 :\n");
    printVecElement(ans1a, rs1); // [1, 1, 0, 0, 1]
    FreeVec(ans1a);
    FreeVec2D(vec1, r1);

    int n2 = 6;
    int r2 = 6;
    int c2 = 2;
    int **vec2 = (int **)malloc(sizeof(int *) * r2);
    for (int i = 0; i < r2; i++)
    {
        vec2[i] = (int *)malloc(sizeof(int) * c2);
    }
    vec2[0][0] = 1;
    vec2[0][1] = 1;
    vec2[1][0] = 0;
    vec2[1][1] = 4;
    vec2[2][0] = 0;
    vec2[2][1] = 1;
    vec2[3][0] = 1;
    vec2[3][1] = 4;
    vec2[4][0] = 1;
    vec2[4][1] = 1;
    vec2[5][0] = 0;
    vec2[5][1] = 4;
    PrintVecElement2D(vec2, r2, c2);
    int rs2 = 0;
    int *ans2a = CheckConnecttivity_A(n2, vec2, r2, &rs2);
    printf("结果序列为 :\n");
    printVecElement(ans2a); // [1, 1, 0, 0, 0, 1]
    FreeVec(ans2a);
    FreeVec2D(vec2, r2);
}

typedef struct
{
    int k;
    UT_hash_handle hh;
} StationSet;

int JudgeCheck(StationSet *s, int num)
{
    StationSet *a, *b;
    HASH_ITER(hh, *s, a, b)
    {
        if()
    }
}

int *CheckConnecttivity_A(int num, int **operations, int l, int *returnSize)
{
    *returnSize = l;
    int *ans = (int *)malloc(sizeof(int) * l);
    memset(ans, 0, sizeof(int) * l);
    StationSet *s = NULL;
    int index = 0;
    for (int i = 0; i < l; i++)
    {
        int ms = operations[i][0];
        int id = operations[i][1];
        int k = id * l + ms;
        StationSet *cur = NULL;
        HASH_FIND_INT(s, k, cur);
        if (cur == NULL)
        {
            cur = (StationSet *)malloc(sizeof(StationSet));
            cur->k = k;
        }
        else
        {
            HASH_DEL(s, cur);
        }

    }
    HASH_CLEAR(hh, s);
    free(s);
    return ans;
}

// int *CheckConnecttivity_A(int num, int **operations, int l, int *returnSize)
// {
//     *returnSize = l;
//     int *ans = (int *)malloc(sizeof(int) * l);
//     memset(ans, 0, sizeof(int) * l);
//     int **arr = (int **)malloc(sizeof(int *) * num);
//     for (int i = 0; i < num; i++)
//     {
//         arr[i] = (int *)malloc(sizeof(int) * 2);
//         memset(arr[i], 0, sizeof(int) * 2);
//     }
//     int index = 0;
//     for (int i = 0; i < l; i++)
//     {
//         int ms = operations[i][0];
//         int id = operations[i][1];
//         for (int)
//     }
//     for (int i = 0; i < num; i++)
//     {
//         free(arr[i]);
//     }
//     return ans;
// }