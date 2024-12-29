#include "../Mybasic/mybasic.h"

//      Huawei: 简易日志系统

//      在一个简易日志系统中，每条日志有唯一的 ID,
//      以及它的生成时间 timeStamp(ID 和 timeStamp均为正整数)。
//      根据给出的函数框架，请实现以下功能：
//          void Add(int id, int timeStamp):
//              增加一条新的日志记录，将这条日志记录存到系统中。
//          int Delete(int id):
//              在日志系统中尝试删除这个 ID 对应的日志记录。
//              如果该 日志ID 在系统中不存在，返回 -1；
//              否则删除这条日志，并返回 0。
//          int Query(int startTime, int endTime):
//              返回日志系统中生成时间 大于等于startTime 且 小于等于endTime 的日志数量
//              如果没有，请返回 0;
//      注：同一时间 可能 有 多条日志，函数定义以对应语言 的 右侧 实际框架 为准。
//      示例1：
//         输入：["LogSystem", "Add", "Add", "Add", "Query", "Delete",
//                  "Delete", "Query"]
//              [[], [1, 5], [2, 5], [3, 6], [5, 6], [2], [4], [5, 6]]
//         输出：[null, null, null, null, 3, 0, -1, 2]
//         解释：
//              第一个操作是初始化, 没有返回值
//              前三个Add操作加入了 ID 为 1,2,3 的日志，timeStamp 分别为 5,5,6
//              第一次Query操作查询timeStamp范围为[5,6]的日志数量，返回3;
//              第一次Delete操作删除了ID为2的日志，删除成功，返回0；
//              第二次Delete操作试图删除ID为4的日志，没有该日志，删除失败，返回-1；
//              最后一次Query操作查询timeStamp范围为[5,6]的日志数量，
//                  由于该范围中已经有一条日志被删除了，故返回2。

typedef struct
{
    int id;
    int timeStamp;
    UT_hash_handle hh;
} SimpleLogSystem_A;

SimpleLogSystem_A *obj_A = NULL;

SimpleLogSystem_A *SimpleLogSystemCreate_A()
{
    return obj_A;
}

void SimpleLogSystemAdd_A(int id, int timeStamp)
{
    SimpleLogSystem_A *cur = NULL;
    HASH_FIND_INT(obj_A, &id, cur);
    if (cur == NULL)
    {
        cur = (SimpleLogSystem_A *)malloc(sizeof(SimpleLogSystem_A));
        cur->id = id;
        cur->timeStamp = timeStamp;
        HASH_ADD_INT(obj_A, id, cur);
    }
    return;
}

int SimpleLogSystemDelete_A(int id)
{
    SimpleLogSystem_A *cur = NULL;
    HASH_FIND_INT(obj_A, &id, cur);
    if (cur == NULL)
    {
        return -1;
    }
    else
    {
        HASH_DEL(obj_A, cur);
        free(cur);
        return 0;
    }
}

int SimpleLogSystemQuery_A(int startTime, int endTime)
{
    SimpleLogSystem_A *cur;
    SimpleLogSystem_A *tem;
    int cnt = 0;
    HASH_ITER(hh, obj_A, cur, tem)
    {
        if (cur->timeStamp >= startTime && cur->timeStamp <= endTime)
        {
            cnt++;
        }
    }
    return cnt;
}

void SimpleLogSystemFree_A()
{
    HASH_CLEAR(hh, obj_A);
    free(obj_A);
    return;
}

typedef struct
{
    int id;
    int timeStamp;
    UT_hash_handle hh;
} SimpleLogSystem_B;

SimpleLogSystem_B *SimpleLogSystemCreate_B()
{
    SimpleLogSystem_B *obj = NULL;
    return obj;
}

void SimpleLogSystemAdd_B(SimpleLogSystem_B **obj, int id, int timeStamp)
{

    SimpleLogSystem_B *cur = NULL;
    HASH_FIND_INT((*obj), &id, cur);
    if (cur == NULL)
    {
        cur = (SimpleLogSystem_B *)malloc(sizeof(SimpleLogSystem_B));
        cur->id = id;
        cur->timeStamp = timeStamp;
        HASH_ADD_INT((*obj), id, cur);
    }
    return;
}

int SimpleLogSystemDelete_B(SimpleLogSystem_B **obj, int id)
{
    SimpleLogSystem_B *cur = NULL;
    HASH_FIND_INT((*obj), &id, cur);
    if (cur == NULL)
    {
        return -1;
    }
    else
    {
        HASH_DEL((*obj), cur);
        free(cur);
        return 0;
    }
}

int SimpleLogSystemQuery_B(SimpleLogSystem_B *obj, int startTime, int endTime)
{
    SimpleLogSystem_B *cur;
    SimpleLogSystem_B *tem;
    int cnt = 0;
    HASH_ITER(hh, obj, cur, tem)
    {
        if (cur->timeStamp >= startTime && cur->timeStamp <= endTime)
        {
            cnt++;
        }
    }
    return cnt;
}

void SimpleLogSystemFree_B(SimpleLogSystem_B **obj)
{
    HASH_CLEAR(hh, (*obj));
    free(*obj);
    return;
}

int main()
{
    SimpleLogSystem_A *objA = SimpleLogSystemCreate_A();
    SimpleLogSystemAdd_A(1, 5);
    SimpleLogSystemAdd_A(2, 5);
    SimpleLogSystemAdd_A(3, 6);
    int q1A = SimpleLogSystemQuery_A(5, 6);
    printf("查询到的日志记录数量为 %d\n", q1A); // 3
    int d1A = SimpleLogSystemDelete_A(2);
    printf("删除日志结果为 %d\n", d1A); // 0
    int d2A = SimpleLogSystemDelete_A(4);
    printf("删除日志结果为 %d\n", d2A); //-1
    int q2A = SimpleLogSystemQuery_A(5, 6);
    printf("查询到的日志记录数量为 %d\n", q2A); // 2
    SimpleLogSystemFree_A();

    SimpleLogSystem_B *objB = SimpleLogSystemCreate_B();
    SimpleLogSystemAdd_B(&objB, 1, 5);
    SimpleLogSystemAdd_B(&objB, 2, 5);
    SimpleLogSystemAdd_B(&objB, 3, 6);
    int q1B = SimpleLogSystemQuery_B(objB, 5, 6);
    printf("查询到的日志记录数量为 %d\n", q1B); // 3
    int d1B = SimpleLogSystemDelete_B(&objB, 2);
    printf("删除日志结果为 %d\n", d1B); // 0
    int d2B = SimpleLogSystemDelete_B(&objB, 4);
    printf("删除日志结果为 %d\n", d2B); //-1
    int q2B = SimpleLogSystemQuery_B(objB, 5, 6);
    printf("查询到的日志记录数量为 %d\n", q2B); // 2
    SimpleLogSystemFree_B(&objB);
}