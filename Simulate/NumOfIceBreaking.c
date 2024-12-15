#include "../Mybasic/mybasic.h"

//      Huawei: 破冰船的破冰次数

//      一艘破冰船在极地考察，航行区域视作一个矩阵（由若干个纵横排列的格子组成），
//      初始时破冰船周围均是冰层，船可以上下左右方向航行。
//      由于破冰船可以通过船头部分压碎冰，因此前进方向的一个格子的冰层压碎成【可通行的水域】。
//      【可通行的水域】在船离开limit时长后，将立刻重新结冻为冰层。
//      注意：当重复通过【可通行的水域】时，再次结冰时间会重置
//      船的初始位置是【可通行的水域】，现在给定航线route,其中U,D,L,R 表示上下左右的行驶方向：
//      每次行驶前进一格，问在行驶路线中，破冰船共破了多少次？
//      示例 1：
//          输入：route = "URDLR", limit = 3
//          输出：4
//      示例 2：
//          输入：route = "RDDUURDLLURU", limit = 4
//          输出：9

int NumOfIceBreaking(char *route, int n, int limit);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int limit = GenerateRandomNum(1, 7);
    char arr[] = {'U', 'D', 'L', 'R'};
    char *str = GenerateRandomString(n, arr, 4);
    printf("给定航线为：\n");
    printString(str);
    int ans = NumOfIceBreaking(str, limit);
    printf("在行驶路线中，破冰船共破了 %d 次。\n", ans);
}

// 模拟：
// Time: O(N)
// Space: O(1)
int NumOfIceBreaking(char *route, int n, int limit)
{
    
}
