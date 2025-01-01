#include "../Mybasic/mybasic.h"

//      Huawei: 破冰船的破冰次数

//      一艘破冰船在极地考察，航行区域视作一个矩阵（由若干个纵横排列的格子组成），
//      初始时破冰船周围均是冰层，船可以上下左右方向航行。
//      由于破冰船可以通过船头部分压碎冰，因此前进方向的一个格子的冰层压碎成【可通行的水域】。
//      【可通行的水域】在船离开limit时长后，将立刻重新结冻为冰层。
//      注意：当重复通过【可通行的水域】时，再次结冰时间会重置
//      船的初始位置是【可通行的水域】，现在给定航线route,其中U,D,L,R 表示上下左右的行驶方向：
//      每次行驶前进一格，问在行驶路线中，破冰船共破了多少次？(航行区域边界 最长为2000)
//      示例 1：
//          输入：route = "URDLR", limit = 3
//          输出：4
//      示例 2：
//          输入：route = "RDDUURDLLURU", limit = 4
//          输出：9

#define ICE_AREA_LEN 6

int NumOfIceBreaking_A(char *route, int n, int limit);
int NumOfIceBreaking_B(char *route, int n, int limit);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int limit = GenerateRandomNum(1, 7);
    char arr[] = {'U', 'D', 'L', 'R'};
    char *str = GenerateRandomString(n, arr, 4);
    printf("给定航线为：\n");
    PrintString(str);
    int ans = NumOfIceBreaking_B(str, n, limit);
    printf("在行驶路线中，破冰船共破了 %d 次。\n", ans);
    FreeString(str);
}

typedef struct
{
    int x;
    int y;
} Coordinate;

Coordinate *CoordinateCreate(int x, int y)
{
    Coordinate *obj = (Coordinate *)malloc(sizeof(Coordinate));
    obj->x = x;
    obj->y = y;
    return obj;
}

typedef struct
{
    Coordinate *coor;
    int time;
    UT_hash_handle hh;
} CoordinateSet;

CoordinateSet *CoordinateSetCreate(int x, int y, int time)
{
    CoordinateSet *obj = (CoordinateSet *)malloc(sizeof(CoordinateSet));
    obj->coor = CoordinateCreate(x, y);
    obj->time = time;
    return obj;
}

int CoordinateSetFindNode(CoordinateSet **obj, int x, int y, int t, int limit)
{
    CoordinateSet *cur = NULL;
    CoordinateSet *tem = NULL;
    int cnt = 0;
    bool flag = false;
    HASH_ITER(hh, *obj, cur, tem)
    {
        if (cur->coor->x == x && cur->coor->y == y)
        {
            if ((t - cur->time) > limit)
            {
                cnt++;
            }
            flag = true;
            cur->time = t;
            if (flag = true)
            {
                break;
            }
        }
    }
    if (flag == false)
    {
        cur = CoordinateSetCreate(x, y, t);
        HASH_ADD(hh, *obj, coor, sizeof(Coordinate), cur);
        cnt++;
    }
    return cnt;
}
// 哈希 + 模拟：
// Time: O(N)
// Space: O(N)
int NumOfIceBreaking_A(char *route, int n, int limit)
{
    int x = 0;
    int y = 0;
    int ans = 0;
    CoordinateSet *set = NULL;
    CoordinateSet *cur = CoordinateSetCreate(x, y, limit);
    HASH_ADD(hh, set, coor, sizeof(Coordinate), cur);
    int t = limit + 1;
    for (int i = 0; i < n; i++)
    {
        switch (route[i])
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        default:
            break;
        }
        ans += CoordinateSetFindNode(&set, x, y, t, limit);
        t++;
    }
    return ans;
}

// 二维数组 模拟：
// Time: O(N^2)
// Space: O(N^2)
int NumOfIceBreaking_B(char *route, int n, int limit)
{
    int ans = 0;
    int(*area)[ICE_AREA_LEN] = (int(*)[ICE_AREA_LEN])malloc(sizeof(int) * ICE_AREA_LEN * ICE_AREA_LEN);
    for (int i = 0; i < ICE_AREA_LEN; i++)
    {
        for (int j = 0; j < ICE_AREA_LEN; j++)
        {
            area[i][j] = 0;
        }
    }
    int x = ICE_AREA_LEN / 2;
    int y = ICE_AREA_LEN / 2;
    int t = limit;
    for (int i = 0; i < n; i++)
    {
        area[x][y] = t;
        t++;
        if (route[i] == 'U')
        {
            y++;
        }
        else if (route[i] == 'D')
        {
            y--;
        }
        else if (route[i] == 'L')
        {
            x--;
        }
        else if (route[i] == 'R')
        {
            x++;
        }
        if ((t - area[x][y]) > limit)
        {
            ans++;
        }
    }
    free(area);
    return ans;
}