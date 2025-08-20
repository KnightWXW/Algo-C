#include "../Mybasic/mybasic.h"

//      LeetCode 539. 最小时间差

//      链接：https://leetcode.cn/problems/minimum-time-difference/

//      给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，
//      找出列表中任意两个时间的最小时间差并以分钟数表示。
//      示例 1：
//          输入：timePoints = ["23:59","00:00"]
//          输出：1
//      示例 2：
//          输入：timePoints = ["00:00","23:59","00:00"]
//          输出：0
//      提示：
//          2 <= timePoints.length <= 2 * 104
//          timePoints[i] 格式为 "HH:MM"

#define MAX_TIME_LEN 6

int FindMinDifference(char** timePoints, int timePointsSize);

int main()
{
    int n1 = 2;
    char** vec_A = (char**)malloc(sizeof(char*) * n1);
    for(int i = 0; i < n1; i++)
    {
        vec_A[i] = (char*)malloc(sizeof(char) * MAX_TIME_LEN);
        memset(vec_A[i], 0, sizeof(char) * MAX_TIME_LEN);
    }
    strcpy(vec_A[0], "23:59");
    strcpy(vec_A[1], "00:00");
    PrintStringVec(vec_A, n1);
    int ans_A = FindMinDifference(vec_A);
    printf("最小时间差为：%d \n", ans_A);
    FreeStringVec(vec_A, n1);

    int n2 = 3;
    char** vec_B = (char**)malloc(sizeof(char*) * n2);
    for(int i = 0; i < n2; i++)
    {
        vec_B[i] = (char*)malloc(sizeof(char) * MAX_TIME_LEN);
        memset(vec_B[i], 0, sizeof(char) * MAX_TIME_LEN);
    }
    strcpy(vec_B[0], "23:59");
    strcpy(vec_B[1], "00:00");
    strcpy(vec_B[2], "00:00");
    PrintStringVec(vec_B, n2);
    int ans_B = FindMinDifference(vec_B);
    printf("最小时间差为：%d \n", ans_B);
    FreeStringVec(vec_B, n2);
}

int FindMinDifference(char** timePoints, int timePointsSize)
{

}