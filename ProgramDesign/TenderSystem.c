#include "../Mybasic/mybasic.h"

//      Huawei: 招标系统

//      请设计一个招标系统，需要实现以下几个功能
//          void AddTender(int userId, int projectId, int price):
//              将投标方userId对项目projectId的投标金额price录入系统；
//              若系统中已存在投标方userId对项目projectId的投标金额，则不作处理
//          int UpdateTender(int userId, int projectId, int price):
//              若系统中存在投标方userId对项目projectId的投标金额，
//              则将该金额更新为price,并返回更新前的投标金额
//              否则请返回-1;
//          int RemoveTender(int userId, int projectId):
//              若系统中存在投标方userId对项目projectId的投标金额，
//              则删除该投标记录，并返回删除前的投标金额，
//              否则请返回-1;
//          int QueryTender(int projectId, int price):
//              查询并返回系统中项目projectId的投标记录中，
//              投标金额大于price且最接近于price的投标方userId
//              若有多个投标方投标金额相同，比较投标方最后一次投标时间，
//              返回投标时间最早的投标方userId;
//              (AddTender 和 UpdateTender 都是投标)
//              若不存在符合要求的投标记录，返回-1；
//      示例1：
//         输入：["TenderSystem", "AddTender", "AddTender", "AddTender",
//              "UpdateTender", "UpdateTender", "RemoveTender",
//              "RemoveTender","AddTender", "AddTender", "AddTender",
//               "QueryTender", "QueryTender"]
//              [[], [1, 1, 10], [2, 2, 20], [2, 2, 30], [1, 1, 40],
//              [1, 3, 40], [1, 1], [1, 3], [1, 2, 20], [3, 2, 10],
//              [4, 2, 40], [2, 15], [5, 10]]
//         输出：[null, null, null, null, 10, -1, 40, -1,
//              null, null, null, 2, -1]
//      示例2：
//         输入：["TenderSystem", "AddTender", "AddTender", "UpdateTender",
//               "QueryTender"]
//              [[], [1, 1, 10], [2, 1, 20], [1, 1, 20], [1, 10]]
//         输出：[null, null, null, 10, 2]

typedef struct
{
    int userId;
    int projectId;
} TenderInfo_A;

TenderInfo_A *TenderInfoCreate_A(int userId, int projectId)
{
    TenderInfo_A *obj = (TenderInfo_A *)malloc(sizeof(TenderInfo_A));
    obj->userId = userId;
    obj->projectId = projectId;
    return obj;
}
typedef struct
{
    TenderInfo_A *tenderInfo;
    int price;
    int time;
    UT_hash_handle hh;
} TenderSystem_A;

typedef struct
{
    TenderInfo_A *tenderInfo;
    int time;
    UT_hash_handle hh;
} TimeSet;

TenderSystem_A *tsA = NULL;
int tenderTime = 0;

TenderSystem_A *TenderSystemCreate_A()
{
    return tsA;
}

void TenderSystemAddTender_A(TenderSystem_A *obj, int userId, int projectId, int price)
{
    TenderSystem_A *a = NULL;
    TenderSystem_A *b = NULL;
    HASH_ITER(hh, tsA, a, b)
    {
        if (a->tenderInfo->userId == userId && a->tenderInfo->projectId == projectId)
        {
            return;
        }
    }
    TenderSystem_A *cur = (TenderSystem_A *)malloc(sizeof(TenderSystem_A));
    cur->tenderInfo = TenderInfoCreate_A(userId, projectId);
    cur->price = price;
    cur->time = tenderTime;
    HASH_ADD(hh, tsA, tenderInfo, sizeof(TenderSystem_A), cur);
    return;
}

int TenderSystemUpdateTender_A(TenderSystem_A *obj, int userId, int projectId, int price)
{
    TenderSystem_A *a = NULL;
    TenderSystem_A *b = NULL;
    HASH_ITER(hh, tsA, a, b)
    {
        if (a->tenderInfo->userId == userId && a->tenderInfo->projectId == projectId)
        {
            int prePrice = a->price;
            a->price = price;
            a->time = tenderTime;
            return prePrice;
        }
    }
    return -1;
}

int TenderSystemRemoveTender_A(TenderSystem_A *obj, int userId, int projectId)
{
    TenderSystem_A *a = NULL;
    TenderSystem_A *b = NULL;
    HASH_ITER(hh, tsA, a, b)
    {
        if (a->tenderInfo->userId == userId && a->tenderInfo->projectId == projectId)
        {
            int prePrice = a->price;
            HASH_DEL(tsA, a);
            free(a);
            return prePrice;
        }
    }
    return -1;
}

int TenderSystemQueryTender_A(TenderSystem_A *obj, int projectId, int price)
{
    TenderSystem_A *a = NULL;
    TenderSystem_A *b = NULL;
    int ansUserId = -1;
    int ansPrice = INT_MAX;
    int ansTime = -1;
    HASH_ITER(hh, tsA, a, b)
    {
        if (a->tenderInfo->projectId == projectId && a->price > price)
        {
            if (a->price < ansPrice)
            {
                ansUserId = a->tenderInfo->userId;
                ansPrice = a->price;
                ansTime = a->time;
            }
            else if (a->price == ansPrice && a->time < ansTime)
            {
                ansUserId = a->tenderInfo->userId;
                ansTime = a->time;
            }
        }
    }
    return ansUserId;
}

void TenderSystemFree_A(TenderSystem_A *obj)
{
    HASH_CLEAR(hh, tsA);
    free(tsA);
    return;
}

int main()
{
    TenderSystem_A *tenderSystem_A = TenderSystemCreate_A();
    tenderTime = 0;
    TenderSystemAddTender_A(tenderSystem_A, 1, 1, 10);
    tenderTime++;
    TenderSystemAddTender_A(tenderSystem_A, 2, 2, 20);
    tenderTime++;
    TenderSystemAddTender_A(tenderSystem_A, 2, 2, 30);
    tenderTime++;
    int uA1 = TenderSystemUpdateTender_A(tenderSystem_A, 1, 1, 40);
    tenderTime++;
    printf("更新投标结果为 %d\n", uA1); // 10
    int uA2 = TenderSystemUpdateTender_A(tenderSystem_A, 1, 3, 40);
    tenderTime++;
    printf("更新投标结果为 %d\n", uA2); // -1
    int rA1 = TenderSystemRemoveTender_A(tenderSystem_A, 1, 1);
    printf("删除投标结果为 %d\n", rA1); // 40
    int rA2 = TenderSystemRemoveTender_A(tenderSystem_A, 1, 3);
    printf("删除投标结果为 %d\n", rA2); // -1
    TenderSystemAddTender_A(tenderSystem_A, 1, 2, 20);
    tenderTime++;
    TenderSystemAddTender_A(tenderSystem_A, 3, 2, 10);
    tenderTime++;
    TenderSystemAddTender_A(tenderSystem_A, 4, 2, 40);
    tenderTime++;
    int qA1 = TenderSystemQueryTender_A(tenderSystem_A, 2, 15);
    printf("查询投标结果为 %d\n", qA1); // 2
    int qA2 = TenderSystemQueryTender_A(tenderSystem_A, 5, 10);
    printf("查询投标结果为 %d\n", qA2); // -1
    TenderSystemFree_A(tenderSystem_A);

    // TenderSystem_B *tenderSystem_B = TenderSystemCreate_B();
    // tenderTime = 0;
    // TenderSystemAddTender_B(tenderSystem_B, 1, 1, 10);
    // tenderTime++;
    // TenderSystemAddTender_B(tenderSystem_B, 2, 2, 20);
    // tenderTime++;
    // TenderSystemAddTender_B(tenderSystem_B, 2, 2, 30);
    // tenderTime++;
    // int u1 = TenderSystemUpdateTender_B(tenderSystem_B, 1, 1, 40);
    // tenderTime++;
    // printf("更新投标结果为 %d\n", u1); // 10
    // int u2 = TenderSystemUpdateTender_B(tenderSystem_B, 1, 3, 40);
    // tenderTime++;
    // printf("更新投标结果为 %d\n", u2); // -1
    // int r1 = TenderSystemRemoveTender_B(tenderSystem_B, 1, 1);
    // printf("删除投标结果为 %d\n", r1); // 40
    // int r2 = TenderSystemRemoveTender_B(tenderSystem_B, 1, 3);
    // printf("删除投标结果为 %d\n", r2); // -1
    // TenderSystemAddTender_B(tenderSystem_B, 1, 2, 20);
    // tenderTime++;
    // TenderSystemAddTender_B(tenderSystem_B, 3, 2, 10);
    // tenderTime++;
    // TenderSystemAddTender_B(tenderSystem_B, 4, 2, 40);
    // tenderTime++;
    // int q1 = TenderSystemQueryTender_B(tenderSystem_B, 2, 15);
    // printf("查询投标结果为 %d\n", q1); // 2
    // int q2 = TenderSystemQueryTender_B(tenderSystem_B, 5, 10);
    // printf("查询投标结果为 %d\n", q2); // -1
}