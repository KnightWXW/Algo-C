#include "../Mybasic/mybasic.h"

//      Huawei: 通讯录系统

//      请你设计一个通讯录系统，实现以下功能：
//      void Add(string name, string number): 添加联系人：
//          姓名为 name, 电话号码为 number, 若已存在则不作处理:
//      string Update(string name, string number): 更新联系人：
//          若已存在联系人name, 则将此联系人的电话号码改为 number；
//          若不存在联系人name, 则不做处理并返回 “No Such Person”；
//      string Delete(string name): 删除联系人：
//          若已存在联系人name, 则删除此联系人记录，并返回其电话号码；
//          若不存在联系人name, 则返回 “No Such Person”；
//      vector<string> Prefer(string s): 过滤联系人：
//          把前缀为 s 的联系人过滤出来(区分大小写),
//          并把记录按照名字的字典序返回;

typedef struct
{

} AddressBookSystem;

AddressBookSystem *AddressBookSystemCreate()
{
}

void AddressBookSystemAdd(AddressBookSystem *obj, char *name, char *number)
{

    return;
}

char *AddressBookSystemUpdate(char *name, char *number)
{
}

char *AddressBookSystemDelete(char *name)
{
}

char **AddressBookSystemPrefer(char *s)
{
}

void AddressBookSystemFree()
{
}

int main()
{
    AddressBookSystem *addressBookSystem = AddressBookSystemCreate();
    AddressBookSystemAdd(addressBookSystem, "Herry", "123");
    AddressBookSystemAdd(addressBookSystem, "Merry", "456");
    char* a1 = AddressBookSystemUpdate(addressBookSystem,"Merry", "789"); // 456
    printf("更新结果为:\n");
    PrintString(a1);
    FreeString(a1);
    int l2 = 0;
    char** a2 = AddressBookSystemPrefer(addressBookSystem,"Me", &l2); // {"Merry", "789"}
    printf("查询结果为:\n");
    PrintStringVec(a2, l2);
    FreeStringVec(a2, l2);
    char* a3 = AddressBookSystemDelete(addressBookSystem,"Merry"); // 789
    printf("删除结果为:\n");
    PrintString(a3);
    FreeString(a3);
    AddressBookSystemAdd(addressBookSystem,"Herry", "234");
    AddressBookSystemAdd(addressBookSystem,"Henry", "2564");
    char* a4 = AddressBookSystemUpdate(addressBookSystem,"Merry", "111"); // No Such Person
    printf("更新结果为:\n");
    printString(a4);
    FreeString(a4);
    int l5 = 0;
    char** a5 = AddressBookSystemPrefer(addressBookSystem,"He", &l5); // {{"Henry", "2564"},{"Herry", "234"}}
    printf("查询结果为:\n");
    PrintStringVec(a5, l5);
    FreeStringVec(a5, l5);
}