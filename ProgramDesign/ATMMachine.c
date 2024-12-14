#include "../mybasic.h"

//      LeetCode 2241. 设计一个 ATM 机器

//      链接：https://leetcode.cn/problems/design-an-atm-machine/

//      一个 ATM 机器，存有 5 种面值的钞票：20 ，50 ，100 ，200 和 500 美元。
//      初始时，ATM 机是空的。用户可以用它存或者取任意数目的钱。
//      取款时，机器会优先取 较大 数额的钱。
//      比方说，你想取 $300 ，并且机器里有 2 张 $50 的钞票，1 张 $100 的钞票和1 张 $200 的钞票，
//      那么机器会取出 $100 和 $200 的钞票。
//      但是，如果你想取 $600 ，机器里有 3 张 $200 的钞票和1 张 $500 的钞票，
//      那么取款请求会被拒绝，因为机器会先取出 $500 的钞票，然后无法取出剩余的 $100 。
//      注意，因为有 $500 钞票的存在，机器 不能 取 $200 的钞票。
//      请你实现 ATM 类：
//          ATM(): 初始化 ATM 对象。
//          void deposit(int[] banknotesCount) :
//              分别存入 $20 ，$50，$100，$200 和 $500 钞票的数目。
//          int[] withdraw(int amount) :
//              返回一个长度为 5 的数组，分别表示 $20 ，$50，$100 ，$200 和 $500 钞票的数目，
//              并且更新 ATM 机里取款后钞票的剩余数量。如果无法取出指定数额的钱，
//              请返回 [-1] （这种情况下 不 取出任何钞票）。
//      示例 1：
//          输入：
//          ["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
//          [[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
//          输出：
//          [null, null, [0,0,1,0,1], null, [-1], [0,1,0,0,1]]
//          解释：
//          ATM atm = new ATM();
//          atm.deposit([0,0,1,2,1]); // 存入 1 张 $100 ，2 张 $200 和 1 张 $500 的钞票。
//          atm.withdraw(600);        // 返回 [0,0,1,0,1] 。
//                                      机器返回 1 张 $100 和 1 张 $500 的钞票。
//                                      机器里剩余钞票的数量为 [0,0,0,2,0] 。
//          atm.deposit([0,1,0,1,1]); // 存入 1 张 $50 ，1 张 $200 和 1 张 $500 的钞票。
//                                      // 机器中剩余钞票数量为 [0,1,0,3,1] 。
//          atm.withdraw(600);        // 返回 [-1] 。
//                                      机器会尝试取出 $500 的钞票，然后无法得到剩余的 $100 ，
//                                      所以取款请求会被拒绝。
//                                      由于请求被拒绝，机器中钞票的数量不会发生改变。
//          atm.withdraw(550);        // 返回 [0,1,0,0,1] ，
//                                      机器会返回 1 张 $50 的钞票和 1 张 $500 的钞票。
//      提示：
//          banknotesCount.length == 5
//          0 <= banknotesCount[i] <= 109
//          1 <= amount <= 109
//          总共 最多有 5000 次 withdraw 和 deposit 的调用。
//          函数 withdraw 和 deposit 至少各有 一次 调用。

#define ATM_PRICES_LEN 5

int money[ATM_PRICES_LEN] = {20, 50, 100, 200, 500};

typedef struct
{
    unsigned long long *storage;
} ATM;

ATM *aTMCreate()
{
    ATM *obj = (ATM *)malloc(sizeof(ATM));
    obj->storage = malloc(ATM_PRICES_LEN * sizeof(unsigned long long));
    memset(obj->storage, 0, ATM_PRICES_LEN * sizeof(unsigned long long));
    return obj;
}

void aTMDeposit(ATM *obj, int *banknotesCount, int banknotesCountSize)
{
    for (int i = 0; i < banknotesCountSize; i++)
    {
        obj->storage[i] += banknotesCount[i];
    }
    return;
}

int *aTMWithdraw(ATM *obj, int amount, int *retSize)
{
    int *ans = (int *)malloc(ATM_PRICES_LEN * sizeof(int));
    int *err = (int *)malloc(sizeof(int));
    memset(ans, 0, ATM_PRICES_LEN * sizeof(int));
    for (int i = ATM_PRICES_LEN - 1; i >= 0; i--)
    {
        if (obj->storage[i] <= amount / money[i])
        {
            ans[i] = obj->storage[i];
        }
        else
        {
            ans[i] = amount / money[i];
        }
        amount -= ans[i] * money[i];
    }
    if (amount != 0)
    {
        err[0] = -1;
        *retSize = 1;
        return err;
    }
    else
    {
        for (int i = 0; i < ATM_PRICES_LEN; i++)
        {
            obj->storage[i] -= ans[i];
        }
        *retSize = ATM_PRICES_LEN;
        return ans;
    }
}

void aTMFree(ATM *obj)
{
    free(obj->storage);
    free(obj);
    return;
}

int main()
{
    ATM *obj = aTMCreate();

    int banknotesCountSize1 = 5;
    int banknotesCount1[] = {0, 0, 1, 2, 1};
    aTMDeposit(obj, banknotesCount1, banknotesCountSize1);

    int amount1 = 600;
    int retSize1 = 0;
    int *a1 = aTMWithdraw(obj, amount1, &retSize1);
    printf("更新 ATM 机里取款后钞票的剩余数量为:\n");
    PrintVecElement(a1, retSize1);
    FreeVec(a1);

    int banknotesCountSize2 = 5;
    int banknotesCount2[] = {0, 1, 0, 1, 1};
    aTMDeposit(obj, banknotesCount2, banknotesCountSize2);

    int amount2 = 600;
    int retSize2 = 0;
    int *a2 = aTMWithdraw(obj, amount2, &retSize2);
    printf("更新 ATM 机里取款后钞票的剩余数量为:\n");
    PrintVecElement(a2, retSize2);
    FreeVec(a2);

    int amount3 = 550;
    int retSize3 = 0;
    int *a3 = aTMWithdraw(obj, amount3, &retSize3);
    printf("更新 ATM 机里取款后钞票的剩余数量为:\n");
    PrintVecElement(a3, retSize3);
    FreeVec(a3);

    aTMFree(obj);
}