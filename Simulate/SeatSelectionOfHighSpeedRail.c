#include "../Mybasic/mybasic.h"

//      Huawei: 高铁选座

//      在某趟高铁列车上，每个车厢内共有rows行座位，
//      每行/列座位的序号和分布如图一所示
//          窗口      1A   1B   1C   通道   1D    1F
//          窗口      2A   2B   2C   通道   2D    2F
//          窗口      3A   3B   3C   通道   3D    3F
//      列表seats中保存了此车厢已被购买的座位。若列表为空，
//      表示该车厢内的座位还未被购买，且每个座位只能被购买一次
//      根据seats显示的售卖情况，
//      请问可以订到多少对(2张)同一行并且相邻的座位("C" 和 "D"跨过道不相邻)
//      座位编号 从 1 开始
//      示例1：
//          输入: rows = 4, seats = ["3A", "4F", "3B"]
//          输出：6
//      注意：
//          1 <= rows <= 10^9
//          0 <= seats.size() <= 10^5

#define MAX_SEAT_LEN 6

int SeatSelectionOfHighSpeedRail_A(int rows, char **seats, int l);
int SeatSelectionOfHighSpeedRail_B(int rows, char **seats, int l);
int main()
{
    char *vec_A[] = {"3A", "4F", "3B"};
    int rows_A = 4;
    int ans_A = SeatSelectionOfHighSpeedRail_A(rows_A, vec_A, 3);
    int ans_B = SeatSelectionOfHighSpeedRail_B(rows_A, vec_A, 3);
    PrintStringVec(vec_A, 3);
    printf("订到 %d 对(2张)同一行并且相邻的座位.\n", ans_A);
    printf("订到 %d 对(2张)同一行并且相邻的座位.\n", ans_B);
}

typedef struct
{
    int rowId;
    int *seat;
    UT_hash_handle hh;
} SeatSet;

// 模拟 + 哈希:
// Time: O(N)
// Space: O(N)
int SeatSelectionOfHighSpeedRail_A(int rows, char **seats, int l)
{
    int ans = 0;
    SeatSet *seatSet = NULL;
    for (int i = 0; i < l; i++)
    {
        int id = seats[i][0] - '0';
        int seat = seats[i][1] - 'A';
        SeatSet *cur = NULL;
        HASH_FIND_INT(seatSet, &id, cur);
        if (cur == NULL)
        {
            cur = (SeatSet *)malloc(sizeof(*seatSet));
            cur->seat = (int *)malloc(sizeof(int) * MAX_SEAT_LEN);
            memset(cur->seat, 0, sizeof(int) * MAX_SEAT_LEN);
            cur->rowId = id;
            HASH_ADD_INT(seatSet, rowId, cur);
        }
        cur->seat[seat] = 1;
    }
    for (int i = 1; i <= rows; i++)
    {
        SeatSet *cur = NULL;
        HASH_FIND_INT(seatSet, &i, cur);
        if (cur == NULL)
        {
            ans += 2;
        }
        else
        {
            if (cur->seat[3] == 0 && cur->seat[5] == 0)
            {
                ans++;
            }
            if (cur->seat[1] == 0 && (cur->seat[2] == 0 || cur->seat[0] == 0))
            {
                ans++;
            }
        }
    }
    HASH_CLEAR(hh, seatSet);
    free(seatSet);
    return ans;
}

// 模拟 + 数组统计:
// Time: O(N)
// Space: O(N)
int SeatSelectionOfHighSpeedRail_B(int rows, char **seats, int l)
{
    int ans = 0;
    int *abc = (int *)malloc(sizeof(int) * (rows + 1));
    memset(abc, 0, sizeof(int) * (rows + 1));
    int *df = (int *)malloc(sizeof(int) * (rows + 1));
    memset(df, 0, sizeof(int) * (rows + 1));
    for (int i = 0; i < l; i++)
    {
        int id = seats[i][0] - '0';
        char seat = seats[i][1];
        if (seat == 'D' || seat == 'F')
        {
            df[id] += 2;
        }
        else if (seat == 'A' || seat == 'C')
        {
            abc[id]++;
        }
        else if (seat == 'B')
        {
            abc[id] += 2;
        }
    }
    for (int i = 1; i <= rows; i++)
    {
        ans += abc[i] <= 1 ? 1 : 0;
        ans += df[i] <= 1 ? 1 : 0;
    }
    free(abc);
    free(df);
    return ans;
}