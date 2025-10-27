#include "../Mybasic/mybasic.h"

//      Huawei: 完美答案收集

//      考生在在线平台考试结束后，可以查看自己每道题的结果
//      (包括题干、选项、答案、回答正确或错误)，
//      针对回答错误的题目并没有给出正确答案。
//      这是需要综合多个考生的正确答案才能得到一份该试卷的完美答案
//      (即包含所有题目的正确答案)。
//      假设共有 questionCount 道题，题目编号从 1 到 questionCount。
//      现在给出每个考生的答对题目的编号，
//      格式如 1 3, 表示答对第1到3题;
//      格式如 9 9, 表示答对第9题;
//      输入：
//          题目的总数量 questionCount  ([1, 1024])
//          考生的总数量 peopleCount    ([1, 1024])
//          peopleCount行，每行两个整数 start end，1 <= start <= end <= questionCount
//      输出：
//          综合到完美答案的最少人值
//          如果无法综合到完美答案，输出 -1
//      示例1：
//          输入：
//              10
//              6
//              1  3
//              4  6
//              1  6
//              6  10
//              5  8
//              10 10
//          输出:
//              2

int PerfectAnswerCollection_A(int questionCount, int **people, int row, int col);
int PerfectAnswerCollection_B(int questionCount, int **people, int row, int col);

int main()
{
    int questionCount = 10;
    int r1 = 6;
    int c1 = 2;
    int **vec1 = (int **)malloc(sizeof(int *) * r1);
    for (int i = 0; i < r1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * c1);
    }
    vec1[0][0] = 1;
    vec1[0][1] = 3;
    vec1[1][0] = 4;
    vec1[1][1] = 6;
    vec1[2][0] = 1;
    vec1[2][1] = 6;
    vec1[3][0] = 6;
    vec1[3][1] = 10;
    vec1[4][0] = 5;
    vec1[4][1] = 8;
    vec1[5][0] = 10;
    vec1[5][1] = 10;
    PrintVecElement2D(vec1, r1, c1);
    int ans_A = PerfectAnswerCollection_A(questionCount, vec1, r1, c1);
    printf("综合到完美答案的最少人值 为 %d 。\n", ans_A);
    int ans_B = PerfectAnswerCollection_A(questionCount, vec1, r1, c1);
    printf("综合到完美答案的最少人值 为 %d 。\n", ans_B);
    FreeVec2D(vec1, r1);
}

int PerfectAnswerCollection_A(int questionCount, int **people, int row, int col)
{
    
}