#include "../Mybasic/mybasic.h"

//      Huawei: 商城促销系统

//      设计一个电子商城促销系统，功能如下：
//      bool AddPromotion(int activityId, int startDate, int endTime, int Category,
//         int number, int priceLimit, int discount):
//          创建一个编号为activityId的优惠活动, 若不存在，则创建活动并返回true, 否则不做处理返回false
//          优惠活动要求：(1) 优惠有效期[startDate, endTime]
//                       (2) 商品属于category 品类并且价格 >= priceLimit
//                       (3) 前number笔享受discount 的优惠减免
//      int ProcessPromotion(int date, int category, int price)
//          在时间date购买一件品类为 category，价格为price的商品，进行优惠处理，返回最终处理价格。
//          若满足多个优惠，仅可享受一次。
//          选择规则如下：
//              (1) 优先选择减免值最大的
//              (2) 其次选择最接近endDate的
//              (3) 再选择activityId最小的
//          若享受优惠，最终价格 = 原价 - 减免，且优惠次数减一，不满足条件则按原价支付
//      int QueryRemainingNum(int date, int activityId):
//          查询时间为date, 活动activityId的剩余优惠次数。
typedef struct
{

} Activity;

typedef struct
{

} PromotionSys;

PromotionSys *PromotionSysCreate()
{
}

bool PromotionSysAddPromotion(PromotionSys *obj, int activityId, int startDate,
                              int endTime, int Category, int number, int priceLimit, int discount)
{
}

bool IsCategoryOK()
{
}

int PromotionSysProcessPromotion(PromotionSys *obj, int date, int category, int price)
{
}

int PromotionSysQueryRemainingNum(PromotionSys *obj, int date, int activityId)
{
}

void PromotionSysFree(PromotionSys *obj)
{
}

int main()
{
    PromotionSys *obj = PromotionSysCreate();
    bool b1 = PromotionSysAddpromotion(obj, 0, 1, 3, 5, 1, 20, 10);
    printf("添加优惠结果为：\n");
    PrintBool(b1); // true
    int p1 = PromotionSysProcessPromotion(obj, 1, 5, 16);
    printf("最终处理价格为：%d\n", p1); // 16
    int p2 = PromotionSysProcessPromotion(obj, 2, 5, 25);
    printf("最终处理价格为：%d\n", p2); // 15
    int p3 = PromotionSysProcessPromotion(obj, 2, 2, 50);
    printf("最终处理价格为：%d\n", p3); // 50
    bool b2 = PromotionSysAddpromotion(obj, 1, 2, 7, 5, 2, 10, 6);
    printf("添加优惠结果为：\n");
    PrintBool(b2); // true
    int q1 = QueryPromotion(obj, 2, 0);
    printf("剩余优惠次数为：%d\n", q1); // 0
    int p4 = PromotionSysProcessPromotion(obj, 2, 5, 22);
    printf("最终处理价格为：%d\n", p4); // 16
    bool b3 = PromotionSysAddpromotion(obj, 15, 4, 5, 5, 2, 7, 6);
    printf("添加优惠结果为：\n");
    PrintBool(b3); // true
    bool b4 = PromotionSysAddpromotion(obj, 2, 4, 5, 5, 20, 7, 6);
    printf("添加优惠结果为：\n");
    PrintBool(b4); // true
    int p5 = PromotionSysProcessPromotion(obj, 4, 5, 30);
    printf("最终处理价格为：%d\n", p5); // 24
    int q2 = QueryPromotion(obj, 5, 2);
    printf("剩余优惠次数为：%d\n", q2); // 19
    int q3 = QueryPromotion(obj, 8, 1);
    printf("剩余优惠次数为：%d\n", q3); // 0
    bool b5 = PromotionSysAddpromotion(obj, 0, 2, 2, 4, 3, 10, 5);
    printf("添加优惠结果为：\n");
    PrintBool(b5); // false
    PromotionSysFree(obj);
}