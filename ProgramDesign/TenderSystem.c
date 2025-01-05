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
} TenderInfo;

TenderInfo *TenderInfoCreate(int userId, int projectId)
{
    TenderInfo *obj = (TenderInfo *)malloc(sizeof(TenderInfo));
    obj->userId = userId;
    obj->projectId = projectId;
    return obj;
}
typedef struct
{
    TenderInfo *tenderInfo;
    int price;
    int time;
    UT_hash_handle hh;
} TenderSystem;

TenderSystem *tsObj = NULL;
int tenderTime = 0;

TenderSystem *TenderSystemCreate()
{
    return tsObj;
}

void TenderSystemAddTender(TenderSystem *obj, int userId, int projectId, int price)
{
    TenderSystem *a = NULL;
    TenderSystem *b = NULL;
    HASH_ITER(hh, tsObj, a, b)
    {
        if (a->tenderInfo->userId == userId && a->tenderInfo->projectId == projectId)
        {
            return;
        }
    }
    TenderSystem *cur = (TenderSystem *)malloc(sizeof(TenderSystem));
    cur->tenderInfo = TenderInfoCreate(userId, projectId);
    cur->price = price;
    cur->time = tenderTime;
    HASH_ADD(hh, tsObj, tenderInfo, sizeof(TenderSystem), cur);
    return;
}

int TenderSystemUpdateTender(TenderSystem *obj, int userId, int projectId, int price)
{
    TenderSystem *a = NULL;
    TenderSystem *b = NULL;
    HASH_ITER(hh, tsObj, a, b)
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

int TenderSystemRemoveTender(TenderSystem *obj, int userId, int projectId)
{
    TenderSystem *a = NULL;
    TenderSystem *b = NULL;
    HASH_ITER(hh, tsObj, a, b)
    {
        if (a->tenderInfo->userId == userId && a->tenderInfo->projectId == projectId)
        {
            int prePrice = a->price;
            HASH_DEL(tsObj, a);
            free(a);
            return prePrice;
        }
    }
    return -1;
}

int TenderSystemQueryTender(TenderSystem *obj, int projectId, int price)
{
    TenderSystem *a = NULL;
    TenderSystem *b = NULL;
    int ansUserId = -1;
    int ansPrice = INT_MAX;
    int ansTime = -1;
    HASH_ITER(hh, tsObj, a, b)
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

int main()
{
    TenderSystem *tenderSystem = TenderSystemCreate();
    tenderTime = 0;
    TenderSystemAddTender(tenderSystem, 1, 1, 10);
    tenderTime++;
    TenderSystemAddTender(tenderSystem, 2, 2, 20);
    tenderTime++;
    TenderSystemAddTender(tenderSystem, 2, 2, 30);
    tenderTime++;
    int u1 = TenderSystemUpdateTender(tenderSystem, 1, 1, 40);
    tenderTime++;
    printf("更新投标结果为 %d\n", u1); // 10
    int u2 = TenderSystemUpdateTender(tenderSystem, 1, 3, 40);
    tenderTime++;
    printf("更新投标结果为 %d\n", u2); // -1
    int r1 = TenderSystemRemoveTender(tenderSystem, 1, 1);
    printf("删除投标结果为 %d\n", r1); // 40
    int r2 = TenderSystemRemoveTender(tenderSystem, 1, 3);
    printf("删除投标结果为 %d\n", r2); // -1
    TenderSystemAddTender(tenderSystem, 1, 2, 20);
    tenderTime++;
    TenderSystemAddTender(tenderSystem, 3, 2, 10);
    tenderTime++;
    TenderSystemAddTender(tenderSystem, 4, 2, 40);
    tenderTime++;
    int q1 = TenderSystemQueryTender(tenderSystem, 2, 15);
    printf("查询投标结果为 %d\n", q1); // 2
    int q2 = TenderSystemQueryTender(tenderSystem, 5, 10);
    printf("查询投标结果为 %d\n", q2); // -1
}