#include "../Mybasic/mybasic.h"

//      Huawei: 食堂消费系统

//      设计一个食堂消费系统，一个食堂有多个餐厅，餐厅通过 餐厅ID (restaurantId) 唯一标识，
//      每个餐厅的餐食分为早餐，中餐，晚餐，每个餐厅三种餐食有自己的销售额。
//      RestaurantSystem(): 初始化食堂系统：
//      void SellMeals(int restaurantId, int mealType, int money):
//          顾客向指定餐厅购买了一份餐食，种类为 mealType, 金额为 money;
//      vector<int> QueryRestaurant(): 统计每个餐厅各种餐食的应收总额。
//          返回 餐厅Id 序列，并根据销售总额进行降序排序，
//          若销售额相同，则根据餐厅Id升序排序;
//      int GetRestaurantMoney(int restaurantId):
//          查询指定 餐厅Id 的所有餐食的销售总额并返回;
//      输入：
//          ["RestaurantSystem", "SellMeals", "SellMeals", "SellMeals",
//           "QueryRestaurant", "GetRestaurantMoney"]
//          [[], [1, 1, 20], [2, 1, 30], [1, 2, 15], [], [1]]
//      输出：
//          [null, null, null, null, null, [1, 2], [35]]

#define MEAL_LEN 4

typedef struct
{
    int restaurantId;
    int meal[MEAL_LEN];
    UT_hash_handle hh;
} RestaurantSystem;

typedef struct
{
    int restaurantId;
    int profit;
} RestaurantItem;

RestaurantSystem *RestaurantSystemCreate()
{
    RestaurantSystem *obj = NULL;
    return obj;
}

void RestaurantSystemSellMeals(RestaurantSystem **obj, int restaurantId, int mealType, int money)
{
    RestaurantSystem *cur = NULL;
    HASH_FIND_INT(*obj, &restaurantId, cur);
    if (cur == NULL)
    {
        cur = (RestaurantSystem *)malloc(sizeof(RestaurantSystem));
        cur->restaurantId = restaurantId;
        memset(cur->meal, 0, sizeof(cur->meal));
        HASH_ADD_INT(*obj, restaurantId, cur);
    }
    cur->meal[0] += money;
    cur->meal[mealType] += money;
    return;
}

int CompareInt(const void *a, const void *b)
{
    if (((RestaurantItem *)a)->profit == ((RestaurantItem *)b)->profit)
    {
        return ((RestaurantItem *)a)->restaurantId - ((RestaurantItem *)b)->restaurantId;
    }
    return ((RestaurantItem *)b)->profit - ((RestaurantItem *)a)->profit;
}

int *RestaurantSystemQueryRestaurant(RestaurantSystem *obj, int *l)
{
    int cnt = HASH_COUNT(obj);
    *l = cnt;
    int *ans = (int *)malloc(sizeof(int) * cnt);
    memset(ans, 0, sizeof(ans));
    RestaurantItem *arr = (RestaurantItem *)malloc(sizeof(RestaurantItem) * cnt);
    memset(arr, 0, sizeof(arr));
    RestaurantItem *a = NULL;
    RestaurantItem *b = NULL;
    int index = 0;
    HASH_ITER(hh, obj, a, b)
    {
        arr[index].restaurantId = a->restaurantId;
        arr[index].profit = a->profit;
        index++;
    }
    qsort(arr, cnt, sizeof(RestaurantItem), CompareInt);
    for(int i = 0; i < cnt; i++)
    {
        ans[i] = arr[i].restaurantId;
    }
    return ans;
}

int RestaurantSystemGetRestaurantMoney(RestaurantSystem *obj, int restaurantId)
{
    RestaurantSystem *cur = NULL;
    HASH_FIND_INT(*obj, &restaurantId, cur);
    if (cur == NULL)
    {
        return 0;
    }
    return cur->meal[0];
}

void RestaurantSystemFree(RestaurantSystem **obj)
{
    HASH_CLEAR(hh, *obj);
    free(*obj);
    return;
}

int main()
{
    RestaurantSystem *restaurantSystem = RestaurantSystemCreate();
    RestaurantSystemSellMeals(&restaurantSystem, 1, 1, 20);
    RestaurantSystemSellMeals(&restaurantSystem, 2, 1, 30);
    RestaurantSystemSellMeals(&restaurantSystem, 1, 2, 15);
    int al1 = 0;
    int *a1 = RestaurantSystemQueryRestaurant(restaurantSystem, &al1);
    printf("每个餐厅各种餐食的应收总额为:\n");
    PrintVecElement(a1, al1);
    int a2 = RestaurantSystemGetRestaurantMoney(restaurantSystem, 1);
    printf("餐厅 %d 的所有餐食的销售总额为: %d\n", 1, a2);
    RestaurantSystemFree(&restaurantSystem);
}