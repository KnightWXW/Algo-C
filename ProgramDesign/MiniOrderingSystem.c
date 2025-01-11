#include "../Mybasic/mybasic.h"

//      Huawei: Mini订货系统

//      请实现一个Mini订货系统，提供订货，发货，查询功能：
//      OrderSystem(): 系统初始化
//      void Order(int customerId, vector<string> goods):
//          表示某客户的一次订货，goods每个元素表示一件商品，值为商品种类：
//          同一客户可以多次订货；单次订货，可对同一种类的商品订购多件：
//      void Deliver(vector<string> goods): 表示发货多件商品，goods含义同上，
//          每个元素表示一件商品，值为商品种类
//          依次将每件商品按照订购的先后顺序发给订购这件商品的用户
//          注：用例保证发的商品一定被某客户订购过
//      int Query():查询并返回系统中未发货件数最大的客户Id:
//          若存在并列：返回客户Id较小的；
//          若所有客户都完成发货，返回-1；
//      输入：
//          每行表示一个函数调用，初始化函数仅首行调用一行，累计函数调用不超过1000次。
//          1 <= customerId <= 1000
//          1 <= goods.size() <= 1000
//          1 <= goods[i].size() <= 1000
//      输出：
//          按顺序输出每个函数的执行结果。
//          注：无返回结果的函数，框架自动输出字符串 “null”
//      示例一：
//          输入：
//                  OrderSystem()
//                  Order(99, ["gd1000"])
//                  Order(88, ["gd666", "gd555"])
//                  Order(99, ["gd666"])
//                  Query()
//                  Deliver(["gd666"])
//                  Query()
//          输出：
//                  null
//                  null
//                  null
//                  null
//                  88
//                  null
//                  99

#define GOOD_NAME_LEN 11
#define ORDER_CUSTOMER_LEN 1001

typedef struct
{
    int id;
    UT_hash_handle hh;
} Customer;

typedef struct
{
    Customer *customer;
    char goodsname[GOOD_NAME_LEN];
    UT_hash_handle hh;
} Goods;

typedef struct
{
    int costomersArr[ORDER_CUSTOMER_LEN];
    Goods *goodslist;
} OrderSystem;

OrderSystem *OrderSystemCreate()
{
    OrderSystem *obj = (OrderSystem *)malloc(sizeof(OrderSystem));
    obj->costomersArr = (int *)malloc(sizeof(int) * ORDER_CUSTOMER_LEN);
    memset(obj->costomersArr, 0, sizeof(int) * ORDER_CUSTOMER_LEN);
    obj->goodlist = NULL;
    return obj;
}

void OrderSystemOrder(OrderSystem *obj, int customerId, char **goods, int goodsSize)
{
    for (int i = 0; i < goodsSize; i++)
    {
    }
    return;
}

void OrderSystemDeliver(OrderSystem *obj, char **goods, int goodsSize)
{
    for (int i = 0; i < goodsSize; i++)
    {
    }
    return;
}

int OrderSystemQuery(OrderSystem *obj)
{
    int ans = -1;
    int cnt = 0;
    for (int i = 0; i < ORDER_CUSTOMER_LEN; i++)
    {
        if (obj->costomersArr[i] > cnt)
        {
            cnt = obj->costomersArr[i];
            ans = i;
        }
    }
    return ans;
}

int OrderSystemFree(OrderSystem *obj)
{
    free(obj);
    return;
}

int main()
{
    OrderSystem *orderSystem = OrderSystemCreate();
    char *arr1[] = {"gd1000"};
    OrderSystemOrder(orderSystem, 99, arr1, 1);
    char *arr2[] = {"gd666", "gd555"};
    OrderSystemOrder(orderSystem, 88, arr2, 2);
    char *arr3[] = {"gd666"};
    OrderSystemOrder(orderSystem, 99, arr3, 1);
    int q1 = OrderSystemQuery(orderSystem);
    printf("系统中未发货件数最大的客户Id为 %d \n", q1);
    OrderSystemDeliver({"gd666"}, 1);
    int q2 = OrderSystemQuery(orderSystem);
    printf("系统中未发货件数最大的客户Id为 %d \n", q2);
    OrderSystemFree(orderSystem);
}
