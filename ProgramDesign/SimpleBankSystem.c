#include "../mybasic.h"

//      LeetCode2043. 简易银行系统

//      链接：https://leetcode.cn/problems/simple-bank-system/

//      你的任务是为一个很受欢迎的银行设计一款程序，以自动化执行所有传入的交易（转账，存款和取款）。
//      银行共有 n 个账户，编号从 1 到 n 。
//      每个账号的初始余额存储在一个下标从 0 开始的整数数组 balance 中，
//      其中第 (i + 1) 个账户的初始余额是 balance[i] 。
//      请你执行所有 有效的 交易。如果满足下面全部条件，则交易 有效 ：
//          指定的账户数量在 1 和 n 之间，且
//          取款或者转账需要的钱的总数 小于或者等于 账户余额。
//      实现 Bank 类：
//          Bank(long[] balance):
//              使用下标从 0 开始的整数数组 balance 初始化该对象。
//          boolean transfer(int account1, int account2, long money):
//              从编号为 account1 的账户向编号为 account2 的账户转帐 money 美元。
//              如果交易成功，返回 true ，否则，返回 false。
//          boolean deposit(int account, long money):
//              向编号为 account 的账户存款 money 美元。
//              如果交易成功，返回 true ；否则，返回 false。
//          boolean withdraw(int account, long money):
//              从编号为 account 的账户取款 money 美元。
//              如果交易成功，返回 true ；否则，返回 false。
//      示例：
//          输入：
//          ["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
//          [[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
//          输出：
//          [null, true, true, true, false, false]
//      解释：
//          Bank bank = new Bank([10, 100, 20, 50, 30]);
//          bank.withdraw(3, 10);   // 返回 true ，账户 3 的余额是 $20 ，所以可以取款 $10 。
//                                  // 账户 3 余额为 $20 - $10 = $10 。
//          bank.transfer(5, 1, 20);// 返回 true ，账户 5 的余额是 $30 ，所以可以转账 $20 。
//                                  // 账户 5 的余额为 $30 - $20 = $10 ，账户 1 的余额为 $10 + $20 = $30 。
//          bank.deposit(5, 20);    // 返回 true ，可以向账户 5 存款 $20 。
//                                  // 账户 5 的余额为 $10 + $20 = $30 。
//          bank.transfer(3, 4, 15);// 返回 false ，账户 3 的当前余额是 $10 。
//                                  // 所以无法转账 $15 。
//          bank.withdraw(10, 50);  // 返回 false ，交易无效，因为账户 10 并不存在。
//      提示：
//          n == balance.length
//          1 <= n, account, account1, account2 <= 105
//          0 <= balance[i], money <= 1012
//          transfer, deposit, withdraw 三个函数，每个 最多调用 104 次

typedef struct
{
    long long *account;
    int accountNum;
} Bank;

Bank *BankCreate(long long *balance, int balanceSize)
{
    Bank *obj = (Bank *)malloc(sizeof(Bank));
    obj->account = (long long *)malloc(sizeof(long long) * balanceSize);
    memcpy(obj->account, balance, balanceSize * sizeof(long long));
    obj->accountNum = balanceSize;
    return obj;
}

bool BankTransfer(Bank *obj, int account1, int account2, long long money)
{
    if (account1 < 1 || account1 > obj->accountNum || account2 < 1 || account2 > obj->accountNum)
    {
        return false;
    }
    if (obj->account[account1 - 1] >= money)
    {
        obj->account[account1 - 1] -= money;
        obj->account[account2 - 1] += money;
        return true;
    }
    return false;
}

bool BankDeposit(Bank *obj, int account, long long money)
{
    if (account < 1 || account > obj->accountNum)
    {
        return false;
    }
    obj->account[account - 1] += money;
    return true;
}

bool BankWithdraw(Bank *obj, int account, long long money)
{
    if (account < 1 || account > obj->accountNum)
    {
        return false;
    }
    if (obj->account[account - 1] >= money)
    {
        obj->account[account - 1] -= money;
        return true;
    }
    return false;
}

void BankFree(Bank *obj)
{
    free(obj);
}

int main()
{
    long long arr[5] = {10, 100, 20, 50, 30};
    Bank *obj = BankCreate(arr, 5);
    bool w1 = BankWithdraw(obj, 3, 10);
    printf("取款结果 为:\n");
    PrintBool(w1); // True
    bool t1 = BankTransfer(obj, 5, 1, 20);
    printf("转帐结果 为:\n");
    PrintBool(t1); // True
    bool d1 = BankDeposit(obj, 5, 20);
    printf("存款结果 为:\n");
    PrintBool(d1); // True
    bool t2 = BankTransfer(obj, 3, 4, 15);
    printf("转账结果 为:\n");
    PrintBool(t2); // False
    bool w2 = BankWithdraw(obj, 10, 50);
    printf("取款结果 为:\n");
    PrintBool(w2); // False
    BankFree(obj);
}