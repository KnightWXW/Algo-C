#include "../Mybasic/mybasic.h"

//      Huawei：订单预定

//      公司内部每interval天将举办一次技术讲座，相关信息如下：
//          (1) 第 k 次讲座在第 k * interval 天举办, k≥1；其开放购票时间为讲座前的interval天，
//              即时间段为[(k − 1) * interval, k * interval − 1]（左闭右闭）
//          (2) 每次讲座均有 100 * 100 个座位，每次讲座的座位独立预定，行列均从 0 开始编号；
//      现提供按购票时间升序的订单信息列表 orders，
//      每一个订单orders[i] = [day, row0, col0, row1,col1, … ,rowM,colM]表示预定一个座位：
//          (1) 按订单的先后顺序依次处理，“先定先得”；
//          (2) day为购票时间，假如day在时间段[(k−1) × interval, k × interval − 1] 内，
//              则预定的是第k次讲座；
//          (3) 每一个订单只能定一个座位，有多个可选座位，依次预定直到成功、
//              或直到无座位可预订而失败。即优先预定座位[row0, col0]；
//              若座位[row0,col0未订票成功，则预定[row1 ,col1]；
//              若座位[row1 ,col1]未订票成功，则预定[row2 ,col2]，以此类推。
//      请返回共有多少个订单预定成功。
//      示例1：
//          输入：
//              interval = 3
//              orders = [[0,1,1],[0,0,2],[1,1,1],[1,0,2,0,0],[3,0,2]]
//          输出：4
//          解释：
//              第1次讲座开放购票时间为[0,2]，第2次讲座开放购票时间为[3,5]，以此类推...
//              按订单的先后顺序一次处理：
//                  [0,1,1]，第0天预定第1次讲座，1行1列的座位成功；
//                  [0,0,2]，第0天预定第1次讲座，0行2列的座位成功；
//                  [1,1,1]，第1天预定第1次讲座，1行1列的座位失败；
//                  [1,0,2,0,0]，第1天预定第1次讲座，0行2列的座位失败（orders[1]已占用），
//                          预定0行0列的座位成功；
//                  [3,0,2]，第3天预定第2次讲座，0行2列的座位成功；
//              因此共有4个预订单预定成功。
//      提示：
//          1 ≤ interval ≤ 100；
//          1 ≤ orders.length ≤ 1000；
//          3 ≤ orders[i].length ≤ 11，且为奇数；
//          0 ≤ orders[i][0] ≤ 10^6
//          0 ≤ orders[i][2×j+1] < 100；
//          0 ≤ orders[i][2×j+2] < 100；
//          对于0 ≤ i< j < orders.length，orders[i][0] ≤ orders[j][0]；

int OrderReservation_A(int interval, int **orders, int row, int *col);
int OrderReservation_B(int interval, int **orders, int row, int *col);

int main()
{
    int interval = 3;
    int row = 5;
    int **vec = (int *)malloc(sizeof(int *) * row);
    int *col = (int *)malloc(sizeof(int) * row);
    memset(col, 0, sizeof(int) * row);
    col[0] = 3;
    col[1] = 3;
    col[2] = 3;
    col[3] = 5;
    col[4] = 3;
    for (int i = 0; i < row; i++)
    {
        vec[i] = (int *)malloc(sizeof(int) * col[i]);
        memset(vec[i], 0, sizeof(int) * col[i]);
    }
    vec[0][0] = 0;
    vec[0][1] = 1;
    vec[0][2] = 1;
    vec[1][0] = 0;
    vec[1][1] = 0;
    vec[1][2] = 2;
    vec[2][0] = 1;
    vec[2][1] = 1;
    vec[2][2] = 1;
    vec[3][0] = 1;
    vec[3][1] = 0;
    vec[3][2] = 2;
    vec[3][3] = 0;
    vec[3][4] = 0;
    vec[4][0] = 3;
    vec[4][1] = 0;
    vec[4][2] = 2;
    for (int i = 0; i < row; i++)
    {
        PrintVecElement(vec, col[i]);
    }
    int ans_11 = OrderReservation_A(interval, vec, row, col);
    int ans_12 = OrderReservation_B(interval, vec, row, col);
    printf("共有 %d 个订单预定成功\n", ans_11);
    printf("共有 %d 个订单预定成功\n", ans_12);
    FreeVec2D(vec, row);
    FreeVec(col);
}

// 哈希：
// Time: O(N * M)
// Space: O(M)
int OrderReservation_A(int interval, int **orders, int row, int *col)
{
}