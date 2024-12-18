#include "../Mybasic/mybasic.h"

//      LeetCode LCR 125. 图书整理 II

//      链接： https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

//      读者来到图书馆排队借还书，图书管理员使用两个书车来完成整理借还书的任务。
//      书车中的书从下往上叠加存放，图书管理员每次只能拿取书车顶部的书。
//      排队的读者会有两种操作：
//          push(bookID)：把借阅的书籍还到图书馆。
//          pop()：从图书馆中借出书籍。
//      为了保持图书的顺序，图书管理员每次取出供读者借阅的书籍是 最早 归还到图书馆的书籍。
//      你需要返回 每次读者借出书的值 。
//      如果没有归还的书可以取出，返回 -1 。
//      示例 1：
//          输入：
//              ["BookQueue", "push", "push", "pop"]
//              [[], [1], [2], []]
//          输出：[null,null,null,1]
//          解释：
//              MyQueue myQueue = new MyQueue();
//              myQueue.push(1); // queue is: [1]
//              myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//              myQueue.pop(); // return 1, queue is [2]
//      提示：
//          1 <= bookID <= 10000
//          最多会对 push、pop 进行 10000 次调用

#define STACK_LENGTH 4

typedef struct
{
    int *arr;
    int top;
    int capacity;
} Stack;

Stack *StackCreate()
{
    Stack *obj = (Stack *)malloc(sizeof(Stack));
    assert(obj);
    obj->arr = calloc(STACK_LENGTH, sizeof(int));
    obj->top = 0;
    obj->capacity = STACK_LENGTH;
    return obj;
}

bool StackIsEmpty(Stack *obj)
{
    assert(obj);
    return obj->top == 0;
}

bool StackIsFull(Stack *obj)
{
    assert(obj);
    return obj->top == obj->capacity;
}
void StackPush(Stack *obj, int val)
{
    assert(obj);
    if (StackIsFull(obj))
    {
        int newCapacity = obj->capacity * 2;
        int *newArr = (int *)realloc(obj->arr, newCapacity * sizeof(int));
        assert(newArr);
        obj->arr = newArr;
        obj->capacity = newCapacity;
    }
    obj->arr[obj->top] = val;
    obj->top++;
    return;
}

int StackPop(Stack *obj)
{
    assert(obj);
    if (StackIsEmpty(obj))
    {
        return -1;
    }
    int topVal = obj->arr[obj->top - 1];
    obj->top--;
    return topVal;
}

int StackGetTop(Stack *obj)
{
    assert(obj);
    if (StackIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->top];
}

void StackFree(Stack *obj)
{
    free(obj->arr);
    obj->arr == NULL;
    obj->top = 0;
    obj->capacity = 0;
    return;
}

typedef struct
{
    Stack *stk1;
    Stack *stk2;
} CQueue;

CQueue *cQueueCreate()
{
    CQueue *obj = (CQueue *)malloc(sizeof(CQueue));
    obj->stk1 = StackCreate();
    obj->stk2 = StackCreate();
    return obj;
}

void cQueueAppendTail(CQueue *obj, int value)
{
    assert(obj);
    StackPush(obj->stk2, value);
    return;
}

int cQueueDeleteHead(CQueue *obj)
{
    if (StackIsEmpty(obj->stk1) && StackIsEmpty(obj->stk2))
    {
        return -1;
    }
    int ans = -1;
    if (!StackIsEmpty(obj->stk1))
    {
        ans = StackPop(obj->stk1);
    }
    else
    {
        while (!StackIsEmpty(obj->stk2))
        {
            int tem = StackPop(obj->stk2);
            StackPush(obj->stk1, tem);
        }
        ans = StackPop(obj->stk1);
    }
    return ans;
}

void cQueueFree(CQueue *obj)
{
    StackFree(obj->stk1);
    StackFree(obj->stk2);
    free(obj);
    obj = NULL;
}

int main()
{
    CQueue *obj1 = cQueueCreate();
    cQueueAppendTail(obj1, 1);
    cQueueAppendTail(obj1, 2);
    cQueueAppendTail(obj1, 3);
    cQueueAppendTail(obj1, 4);
    cQueueAppendTail(obj1, 5);
    int a1 = cQueueDeleteHead(obj1);
    printf("从图书馆中借出书籍为 %d。\n", a1); // 1
    int a2 = cQueueDeleteHead(obj1);
    printf("从图书馆中借出书籍为 %d。\n", a2); // 2
    cQueueAppendTail(obj1, 6);
    cQueueAppendTail(obj1, 7);
    cQueueAppendTail(obj1, 8);
    cQueueAppendTail(obj1, 9);
    int a3 = cQueueDeleteHead(obj1);
    printf("从图书馆中借出书籍为 %d。\n", a3); // 3
    int a4 = cQueueDeleteHead(obj1);
    printf("从图书馆中借出书籍为 %d。\n", a4); // 4
    int a5 = cQueueDeleteHead(obj1);
    printf("从图书馆中借出书籍为 %d。\n", a5); // 5
    cQueueFree(obj1);
}