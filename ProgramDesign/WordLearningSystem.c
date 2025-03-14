#include "../Mybasic/mybasic.h"

//      Huawei: 单词学习系统

//      请你设计一个单词学习系统：
//      WordLearningSystem(int wordNum, int learningCnt):
//          初始化函数，总共 wordNum个单词，按照序号录入，每个单词固定学习 learningCnt 遍
//      vector<int> Learn(int num):
//          选取 num 个单词进行背诵，如果不满足num个，则按照不足数量处理，返回序号数列
//          按照单词还没背诵的次数，从大到小排序，如果没有背诵次数相同的，
//          则按照单词序号从小到大排序
//          单词背诵一次需要次数减一，直到为零
//      void Reset(vector<int> wordList)
//          重置 wordList 数组中的 需要背诵的次数为 learningCnt 次数
//      int Query():
//          查询还需要背诵的单词总量，(背诵次数大于0的个数)

typedef struct
{
    int index;
    int cnt;
} WordItem;

typedef struct
{
    WordItem *wordVec;
} WordLearningSystem;

int wordNum;
int learningCnt;

WordLearningSystem *WordLearningSystemCreate(int wordNum, int learningCnt)
{
    WordLearningSystem *obj = (WordLearningSystem *)malloc(sizeof(WordLearningSystem));
    obj->wordVec = (WordItem *)malloc(sizeof(WordItem) * wordNum);
    wordNum = wordNum;
    learningCnt = learningCnt;
    for (int i = 0; i < wordNum; i++)
    {
        obj->wordVec[i].index = i;
        obj->wordVec[i].cnt = learningCnt;
    }
    return obj;
}

int CompareWordItem(const void *a, const void *b)
{
    if (((WordItem *)a)->cnt == ((WordItem *)b)->cnt)
    {
        return ((WordItem *)a)->index - ((WordItem *)b)->index;
    }
    return ((WordItem *)b)->cnt - ((WordItem *)a)->index;
}

int *WordLearningSystemLearn(WordLearningSystem **obj, int num, int *l)
{
    qsort((*obj)->wordVec, wordNum, sizeof(WordItem), CompareWordItem);
    int index = 0;
    int k = min(wordNum, num);
    int *ans = (int *)malloc(sizeof(int) * k);
    memset(ans, 0, sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        if ((*obj)->wordVec[i].cnt > 0)
        {
            (*obj)->wordVec[i].cnt--;
            ans[i] = (*obj)->wordVec[i].index;
            index++;
        }
    }
    *l = index;
    return ans;
}

void WordLearningSystemReset(WordLearningSystem *obj, int *wordList, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < wordNum; j++)
        {
            if (wordList[j] == obj->wordVec[i].index)
            {
                obj->wordVec[j].cnt = learningCnt;
            }
        }
    }
    return;
}

int WordLearningSystemQuery(WordLearningSystem *obj)
{
    int ans = 0;
    for (int i = 0; i < wordNum; i++)
    {
        ans += (obj->wordVec[i].cnt > 0) ? 1 : 0;
    }
    return ans;
}

void WordLearningSystemFree(WordLearningSystem *obj)
{
    free(obj->wordVec);
    free(obj);
    return;
}

int main()
{
    WordLearningSystem *obj = WordLearningSystemCreate(6, 2);
    int a1 = WordLearningSystemQuery(obj); // 6
    printf("还需要背诵的单词总量 为：%d\n", a1);
    int l2 = 1;
    int *a2 = WordLearningSystemLearn(&obj, 3, &l2);
    printf("序号数列 为:");
    PrintVecElement(a2, l2); // 0 1 2
    int l3 = 1;
    int *a3 = WordLearningSystemLearn(&obj, 5, &l3);
    printf("序号数列 为:");
    PrintVecElement(a3, l3); // 3 4 5 0 1
    int a4 = WordLearningSystemQuery(obj);
    printf("还需要背诵的单词总量 为：%d\n", a4); // 4
    int l5 = 1;
    int *a5 = WordLearningSystemLearn(&obj, 6, &l5);
    printf("序号数列 为:");
    PrintVecElement(a5, l5); // 2 3 4 5
    int l6 = 1;
    int *a6 = WordLearningSystemLearn(&obj, 2, &l6);
    printf("序号数列 为:");
    PrintVecElement(a6, l6); // 空
    int arr1[] = {0, 2};
    WordLearningSystemReset(obj, arr1, 2);
    int l7 = 1;
    int *a7 = WordLearningSystemLearn(&obj, 1, &l7);
    printf("序号数列 为:");
    PrintVecElement(a7, l7); // 0
    int arr2[] = {0, 2};
    WordLearningSystemReset(obj, arr2, 1);
    int a8 = WordLearningSystemQuery(obj);
    printf("还需要背诵的单词总量 为：%d\n", a8); // 3
    WordLearningSystemFree(obj);
}