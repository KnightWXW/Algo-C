#include "../Mybasic/mybasic.h"

//      LeetCode 506. 相对名次

//      链接：https://leetcode.cn/problems/relative-ranks/

//      给你一个长度为 n 的整数数组 score ，
//      其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。
//      运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，
//      名次第 2 的运动员得分第 2 高，依此类推。运动员的名次决定了他们的获奖情况：
//          名次第 1 的运动员获金牌 "Gold Medal" 。
//          名次第 2 的运动员获银牌 "Silver Medal" 。
//          名次第 3 的运动员获铜牌 "Bronze Medal" 。
//          从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得编号 "x"）。
//      使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。
//      示例 1：
//          输入：score = [5,4,3,2,1]
//          输出：["Gold Medal","Silver Medal","Bronze Medal","4","5"]
//          解释：名次为 [1st, 2nd, 3rd, 4th, 5th] 。
//      示例 2：
//          输入：score = [10,3,8,9,4]
//          输出：["Gold Medal","5","Bronze Medal","Silver Medal","4"]
//          解释：名次为 [1st, 5th, 3rd, 2nd, 4th] 。
//      提示：
//          n == score.length
//          1 <= n <= 104
//          0 <= score[i] <= 106
//          score 中的所有值 互不相同

#define MAX_PRICE_SIZE 20

char **FindRelativeRanks(int *score, int scoreSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(1, 30, n);
    int l = 1;
    char **strs = FindRelativeRanks(vec, n, &l);
    printf("运动员在比赛中的得分 为:\n");
    PrintVecElement(vec, n);
    printf("运动员的获奖情况为:\n");
    PrintStringVec(strs, l);
    FreeStringVec(strs, l);
}

typedef struct
{
    int val;
    int index;
} ScoreUnit;

int CompareScore(const void *a, const void *b)
{
    return ((ScoreUnit *)b)->val - ((ScoreUnit *)a)->val;
}

// 排序:
// Time: O()
// Space: O()
char **FindRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    ScoreUnit *arr = (ScoreUnit *)malloc(sizeof(ScoreUnit) * scoreSize);
    memset(arr, 0, sizeof(ScoreUnit) * scoreSize);
    for (int i = 0; i < scoreSize; i++)
    {
        arr[i].val = score[i];
        arr[i].index = i;
    }
    qsort(arr, scoreSize, sizeof(ScoreUnit), CompareScore);
    char **ans = (char **)malloc(sizeof(char *) * scoreSize);
    for (int i = 0; i < scoreSize; i++)
    {
        ans[arr[i].index] = (char *)malloc(sizeof(char) * MAX_PRICE_SIZE);
        memset(ans[arr[i].index], 0, sizeof(char) * MAX_PRICE_SIZE);
        switch (i)
        {
        case 0:
            sprintf(ans[arr[i].index], "Gold Medal");
            break;
        case 1:
            sprintf(ans[arr[i].index], "Silver Medal");
            break;
        case 2:
            sprintf(ans[arr[i].index], "Bronze Medal");
            break;
        default:
            sprintf(ans[arr[i].index], "%d", i + 1);
            break;
        }
    }
    *returnSize = scoreSize;
    return ans;
}