#include "../mybasic.h"

//      LeetCode LCR 184. 设计自助结算系统

//      链接：https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/

//      请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，
//      需要实现的功能有：
//          get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1
//          add(value)：将价格为 value 的商品加入待结算商品队列的尾部
//          remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1
//      注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1)
//      示例 1：
//          输入:
//              ["Checkout","add","add","get_max","remove","get_max"]
//              [[],[4],[7],[],[],[]]
//          输出: [null,null,null,7,4,7]
//      示例 2：
//          输入:
//              ["Checkout","remove","get_max"]
//              [[],[],[]]
//          输出: [null,-1,-1]
//      提示：
//          1 <= get_max, add, remove 的总操作数 <= 10000
//          1 <= value <= 10^5

typedef struct
{
    int *shoppingCart;
    int maxPrice;
} Checkout;

Checkout *CheckoutCreate()
{
    Checkout* obj = (Checkout*)malloc(sizeof(Checkout));
    obj->shoppingCart = (int*)malloc(sizeof(int));
}

int CheckoutGet_max(Checkout *obj)
{
}

void CheckoutAdd(Checkout *obj, int value)
{
}

int CheckoutRemove(Checkout *obj)
{
}

void CheckoutFree(Checkout *obj)
{
}

int main()
{
    Checkout *obj = CheckoutCreate();
    CheckoutAdd(obj, 4);
    CheckoutAdd(obj, 7);
    int a1 = CheckoutGet_max(obj);
    int r1 = CheckoutRemove(obj);
    printf("结算商品中的最高价格为: %d \n", a1);
    int a2 = CheckoutGet_max(obj);
    printf("结算商品中的最高价格为: %d \n", a2);
    CheckoutFree(obj);
}