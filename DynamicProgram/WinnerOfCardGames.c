#include "../Mybasic/mybasic.h"

//      给定一个整型数组arr，代表数值不同的纸牌排成一条线
//      玩家A和玩家B依次拿走每张纸牌 规定玩家A先拿，玩家B后拿
//      但是每个玩家每次只能拿走最左或最右的纸牌 玩家A和玩家B都绝顶聪明
//      请返回最后获胜者的分数

int WinnerOfCardGames_A(int *arr, int l);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int ans =  WinnerOfCardGames(vec, n);
    printf("纸牌数组为:\n");
    PrintVecElement(vec, n);
    int ansA = WinnerOfCardGames_A(vec, n);
    printf("纸牌游戏的胜者为: %d\n", ansA);
    FreeVec(vec);
}