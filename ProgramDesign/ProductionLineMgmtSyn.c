#include "../Mybasic/mybasic.h"

//      Huawei: 工厂流水线系统

//      有一个工厂具有多条流水线，流水线上均可生产多种产品，
//      产品生产有一定的周期，完成 ProductionLineMgmtSyn 类:
//          ProductionLineMgmtSyn(int num, vector<int> periods): 初始化函数，
//              入参是流水条数num, 以及各编号产品的生产周期，在一个数组中 periods 中。
//          int Production(int date, int assemblyId, int productId): 生产函数，
//              入参是开始生产时间date, 流水线编号assemblyId, 以及产品编号productId，规则是:
//                  (1) 若该流水线未被占用，则从此开始生产时间生产该编号的产品，并返回1；
//                  (2) 若该流水线正在被占用，且恰好是同一产品。
//                      则该流水线继续生产该产品，并返回0；
//                  (3) 若该流水线正在被占用，并且是另外一种产品。
//                      则直接在此开始生产时间开始生产新的产品，并返回-1；
//                  (4) 切换规则，比如上个产品在时刻2开始生产，其生产周期为3，
//                      则在时刻8切换生产新的产品时，上个产品已经生产了2个；
//                      而在时刻10切换生产新的产品时，由于最后一个还没有生产完全，
//                      丢弃最后一个，仍然只算成功生产2个；
//          int GetProductCount(int date, int productId): 统计函数
//              入参是 时间date, 以及产品编号productId，
//              统计的是时间date时，工厂生产编号productId的产品的总数量，返回这个值
//              保证 date 是递增的
//      示例：
//          输入：
//              ["ProductionLineMgmtSyn", "Production", "Production",
//              "Production", "GetProductCount"]
//              [[2, [1, 3, 5]], [1, 0, 1], [1, 1, 0], [9, 0, 2], [10, 1]]
//          输出：
//              [null, 1, 1, -1, 2]

int lineSize;
int periodSize;

typedef struct
{
    int productId;
    int startDate;
} Line;

typedef struct
{
    int period;
    int num;
} Production;
typedef struct
{
    Line *lineVec;
    Production *prodectionVec;
} ProductionLineMgmtSyn;

ProductionLineMgmtSyn *ProductionLineMgmtSynCreate(int num, int *periods, int size)
{
    ProductionLineMgmtSyn *obj = (ProductionLineMgmtSyn *)malloc(sizeof(ProductionLineMgmtSyn));
    lineSize = num;
    periodSize = size;
    obj->lineVec = (Line *)malloc(sizeof(Line) * lineSize);
    for (int i = 0; i < lineSize; i++)
    {
        obj->lineVec[i].productId = -1;
        obj->lineVec[i].startDate = -1;
    }
    obj->prodectionVec = (Production *)malloc(sizeof(Production) * periodSize);
    for (int i = 0; i < periodSize; i++)
    {
        obj->prodectionVec[i].period = periods[i];
        obj->prodectionVec[i].num = 0;
    }
    return obj;
}

int ProductionLineMgmtSynProduction(ProductionLineMgmtSyn *obj, int date, int assemblyId, int productId)
{
    if (obj->lineVec[assemblyId].productId == -1)
    {
        obj->lineVec[assemblyId].productId = productId;
        obj->lineVec[assemblyId].startDate = date;
        return 1;
    }
    else if (obj->lineVec[assemblyId].productId == productId)
    {
        return 0;
    }
    else
    {
        int preProductId = obj->lineVec[assemblyId].productId;
        obj->prodectionVec[preProductId].num += (date - obj->lineVec[assemblyId].startDate) / obj->prodectionVec[preProductId].period;
        obj->lineVec[assemblyId].productId = productId;
        obj->lineVec[assemblyId].startDate = date;
        return -1;
    }
}

int ProductionLineMgmtSynGetProductCount(ProductionLineMgmtSyn *obj, int date, int productId)
{
    int ans = obj->prodectionVec[productId].num;
    for (int i = 0; i < lineSize; i++)
    {
        if (obj->lineVec[i].productId == productId)
        {
            ans += (date - obj->lineVec[i].startDate) / obj->prodectionVec[productId].period;
        }
    }
    return ans;
}

void ProductionLineMgmtSynFree(ProductionLineMgmtSyn *obj)
{
    free(obj->lineVec);
    free(obj->prodectionVec);
    free(obj);
    return;
}

int main()
{
    int num1 = 2;
    int arr1[] = {1, 3, 5};
    int size1 = 3;
    ProductionLineMgmtSyn *productionLineMgmtSyn = ProductionLineMgmtSynCreate(num1, arr1, size1);
    int p1 = ProductionLineMgmtSynProduction(productionLineMgmtSyn, 1, 0, 1);
    printf("工厂生产结果 为 %d:\n", p1);
    int p2 = ProductionLineMgmtSynProduction(productionLineMgmtSyn, 1, 1, 0);
    printf("工厂生产结果 为 %d:\n", p2);
    int p3 = ProductionLineMgmtSynProduction(productionLineMgmtSyn, 9, 0, 2);
    printf("工厂生产结果 为 %d:\n", p3);
    int g2 = ProductionLineMgmtSynGetProductCount(productionLineMgmtSyn, 10, 1);
    printf("工厂统计结果 为 %d:\n", g2);
    ProductionLineMgmtSynFree(productionLineMgmtSyn);
}