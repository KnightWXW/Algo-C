#include "../Mybasic/mybasic.h"

//      Huawei: 手机壳库存管理

//      库存管理对于手机壳销售是否达成最大化至关重要。
//      仓库中有一批不同型号的手机壳，
//      每种型号手机壳的库存数量存在inventory中，
//      总售价存在数组 price 中，
//      每种型号的手机壳的销售收益 = 销售数量 * (price[i] / inventory[i])。
//      现给定市场上手机壳的最大需求量 demand ,
//      请制定最佳销售策略以获取最大的总销售收益，并返回该值。
//      输入：
//          M: 手机壳种类数 [1, 1000]
//          N: 市场最大需求量 [1, 500]
//          M个数字: 每种手机壳的数量 [0.0, 1000.0] (千件为单位)
//          M个数字: 每种手机壳的总售价 [0.0, 10000.0] (万元为单位)
//      输出:
//          浮点书形式的最大收益值(万元为单位)
//      输入样例1：
//          3
//          20
//          18.0 15.0 10.0
//          75.0 72.0 45.0
//      输出样例1：
//          94.50

double PhoneSellManage(double demand, double *inventory, double *price, int l);

int main()
{
    int l = 3; 
    double demand = 20;
    double inventory[] = {18.0, 15.0, 10.0};
    double price[] = {75.0, 72.0, 45.0};
    printf("每种手机壳的库存数量为：\n");
    PrintVecElementDouble(inventory, l);
    printf("每种手机壳的总售价为：\n");
    PrintVecElementDouble(price, l);
    double ans = PhoneSellManage(demand, inventory, price);
    printf("获取最大的总销售收益为 %lf\n", ans);
}

double PhoneSellManage(double demand, double *inventory, double *price, int l)
{
    
}