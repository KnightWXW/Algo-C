#include "../Mybasic/mybasic.h"

//      Huawei: 通讯录系统

//      请你设计一个通讯录系统，实现以下功能：
//      void Add(string name, string number): 添加联系人：
//          姓名为 name, 电话号码为 number, 若已存在则不作处理:
//      string Update(string name, string number): 更新联系人：
//          若已存在联系人name, 则将此联系人的电话号码改为 number, 返回之前的number;
//          若不存在联系人name, 则不做处理并返回 “No Such Person”；
//      string Delete(string name): 删除联系人：
//          若已存在联系人name, 则删除此联系人记录，并返回其电话号码；
//          若不存在联系人name, 则返回 “No Such Person”；
//      vector<string> Prefer(string s): 过滤联系人：
//          把前缀为 s 的联系人过滤出来(区分大小写),
//          并把记录按照名字的字典序返回;

#define MAX_BOOK_NAME_LEN 100
#define MAX_BOOK_NUMBER_LEN 100

typedef struct
{
    char name[MAX_BOOK_NAME_LEN];
    char number[MAX_BOOK_NAME_LEN];
    UT_hash_handle hh;
} AddressBookSystem;

AddressBookSystem *AddressBookSystemCreate()
{
    AddressBookSystem *obj = NULL;
    return obj;
}

void AddressBookSystemAdd(AddressBookSystem **obj, char *name, char *number)
{
    AddressBookSystem *cur;
    HASH_FIND_STR(*obj, name, cur);
    if (cur == NULL)
    {
        cur = (AddressBookSystem *)malloc(sizeof(AddressBookSystem));
        memset(cur->name, 0, sizeof(cur->name));
        memset(cur->number, 0, sizeof(cur->number));
        strcpy(cur->name, name);
        strcpy(cur->number, number);
        HASH_ADD_STR(*obj, name, cur);
    }
    return;
}

char *AddressBookSystemUpdate(AddressBookSystem *obj, char *name, char *number)
{
    AddressBookSystem *cur;
    HASH_FIND_STR(obj, name, cur);
    char *ans = (char *)malloc(sizeof(char) * MAX_BOOK_NAME_LEN);
    memset(ans, 0, sizeof(char) * MAX_BOOK_NAME_LEN);
    if (cur == NULL)
    {
        strcpy(ans, "No Such Person");
        return ans;
    }
    else
    {
        strcpy(ans, cur->number);
        strcpy(cur->number, number);
    }
    return ans;
}

char *AddressBookSystemDelete(AddressBookSystem **obj, char *name)
{
    AddressBookSystem *cur;
    HASH_FIND_STR(*obj, name, cur);
    char *ans = (char *)malloc(sizeof(char) * MAX_BOOK_NAME_LEN);
    memset(ans, 0, sizeof(char) * MAX_BOOK_NAME_LEN);
    if (cur == NULL)
    {
        strcpy(ans, "No Such Person");
        return ans;
    }
    else
    {
        strcpy(ans, cur->number);
        HASH_DEL(*obj, cur);
    }
    return ans;
}

int CompareStr(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b) < 0;
}

char **AddressBookSystemPrefer(AddressBookSystem *obj, char *s, int* returnSize)
{
    int c = HASH_COUNT(obj);
    AddressBookSystem *a = NULL;
    AddressBookSystem *b = NULL;
    char **nameArr = (char **)malloc(sizeof(char *) * c);
    int index = 0;
    HASH_ITER(hh, obj, a, b)
    {
        if (strncmp(a->name, s, strlen(s)) == 0)
        {
            nameArr[index] = (char *)malloc(sizeof(char) * MAX_BOOK_NAME_LEN);
            strcpy(nameArr[index], a->name);
            index++;
        }
    }
    qsort(nameArr,   index, sizeof(char*),CompareStr);
    *returnSize = index;
    return nameArr;
}

void AddressBookSystemFree(AddressBookSystem **obj)
{
    HASH_CLEAR(hh, *obj);
    free(*obj);
    return;
}

int main()
{
    AddressBookSystem *addressBookSystem = AddressBookSystemCreate();
    AddressBookSystemAdd(&addressBookSystem, "Herry", "123");
    AddressBookSystemAdd(&addressBookSystem, "Merry", "456");
    char *a1 = AddressBookSystemUpdate(addressBookSystem, "Merry", "789"); // 456
    printf("更新结果为:\n");
    PrintString(a1);
    FreeString(a1);
    int l2 = 0;
    char **a2 = AddressBookSystemPrefer(addressBookSystem, "Me", &l2); // {"Merry", "789"}
    printf("查询结果为:\n");
    PrintStringVec(a2, l2);
    FreeStringVec(a2, l2);
    char *a3 = AddressBookSystemDelete(&addressBookSystem, "Merry"); // 789
    printf("删除结果为:\n");
    PrintString(a3);
    FreeString(a3);
    AddressBookSystemAdd(&addressBookSystem, "Herry", "234");
    AddressBookSystemAdd(&addressBookSystem, "Henry", "2564");
    char *a4 = AddressBookSystemUpdate(addressBookSystem, "Merry", "111"); // No Such Person
    printf("更新结果为:\n");
    PrintString(a4);
    FreeString(a4);
    int l5 = 0;
    char **a5 = AddressBookSystemPrefer(addressBookSystem, "He", &l5); // {{"Henry", "2564"},{"Herry", "234"}}
    printf("查询结果为:\n");
    PrintStringVec(a5, l5);
    FreeStringVec(a5, l5);
    AddressBookSystemFree(&addressBookSystem);
}