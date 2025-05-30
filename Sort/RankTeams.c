#include "../Mybasic/mybasic.h"

//      LeetCode 1366. 通过投票对团队排名

//      链接：https://leetcode.cn/problems/rank-teams-by-votes/

//      现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，
//      每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。
//      排名规则如下：
//          参赛团队的排名次序依照其所获「排位第一」的票的多少决定。
//          如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。
//          以此类推，直到不再存在并列的情况。
//          如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。
//      给你一个字符串数组 votes 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。
//      请你返回能表示按排名系统 排序后 的所有团队排名的字符串。
//      示例 1：
//          输入：votes = ["ABC","ACB","ABC","ACB","ACB"]
//          输出："ACB"
//          解释：
//              A 队获得五票「排位第一」，没有其他队获得「排位第一」，所以 A 队排名第一。
//              B 队获得两票「排位第二」，三票「排位第三」。
//              C 队获得三票「排位第二」，两票「排位第三」。
//              由于 C 队「排位第二」的票数较多，所以 C 队排第二，B 队排第三。
//      示例 2：
//          输入：votes = ["WXYZ","XYZW"]
//          输出："XWYZ"
//          解释：
//              X 队在并列僵局打破后成为排名第一的团队。X 队和 W 队的「排位第一」票数一样，但是 X 队有一票「排位第二」，而 W 没有获得「排位第二」。 
//      示例 3：
//          输入：votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
//          输出："ZMNAGUEDSJYLBOPHRQICWFXTVK"
//          解释：只有一个投票者，所以排名完全按照他的意愿。
//      提示：
//          1 <= votes.length <= 1000
//          1 <= votes[i].length <= 26
//          votes[i].length == votes[j].length for 0 <= i, j < votes.length
//          votes[i][j] 是英文 大写 字母
//          votes[i] 中的所有字母都是唯一的
//          votes[0] 中出现的所有字母 同样也 出现在 votes[j] 中，其中 1 <= j < votes.length

#define MAX_RANK_TEAM_LEN 26

char* RankTeams(char** votes, int votesSize);

int main()
{
    char* arr1[] = {"ABC","ACB","ABC","ACB","ACB"};
    int l1 = 5;
    char* ans1 = RankTeams(arr1, l1);
    PrintStringVec(arr1, l1);
    printf("按排名系统 排序后 的所有团队排名的字符串为:\n");
    PrintString(ans1);
    FreeString(ans1);

    char* arr2[] = {"WXYZ","XYZW"};
    int l2 =2;
    char* ans2 = RankTeams(arr2, l2);
    PrintStringVec(arr2, l2);
    printf("按排名系统 排序后 的所有团队排名的字符串为:\n");
    PrintString(ans2);
    FreeString(ans2);

    char* arr3[] = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    int l3 = 1;
    char* ans3 = RankTeams(arr3, l3);
    PrintStringVec(arr3, l3);
    printf("按排名系统 排序后 的所有团队排名的字符串为:\n");
    PrintString(ans3);
    FreeString(ans3);
}

typedef struct{
    char c;
    int* vec;
    int size;
}RankData;

char* RankTeams(char** votes, int votesSize)
{
    int n = strlen(votes[0]);
    int** arr = (int*)malloc(sizeof(int*)*MAX_RANK_TEAM_LEN);
    for(int i = 0; i < MAX_RANK_TEAM_LEN; i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*n);
        memset(arr[i], 0, sizeof(int)*n);
    }
    for(int i = 0; i < votesSize; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int index = votes[i][j] - 'A';
            arr[index][i] = j + 1;
        }
    }
    RankData* rankVec = (RankData*)malloc(sizeof(RankData)*votesSize);
    memset(rankVec, 0, sizeof(RankData)*votesSize);
    for(int i = 0; i < )

}