#include "../mybasic.h"

//      LeetCode 1472. 设计浏览器历史记录

//      链接：https://leetcode.cn/problems/design-browser-history/

//      你有一个只支持单个标签页的 浏览器 ，最开始你浏览的网页是 homepage ，
//      你可以访问其他的网站 url ，也可以在浏览历史中后退 steps 步或前进 steps 步。
//      请你实现 BrowserHistory 类：
//          BrowserHistory(string homepage): 用 homepage 初始化浏览器类。
//          void visit(string url): 从当前页跳转访问 url 对应的页面 。
//              执行此操作会把浏览历史前进的记录全部删除。
//          string back(int steps): 在浏览历史中后退 steps 步。
//              如果你只能在浏览历史中后退至多 x 步且 steps > x ，
//              那么你只后退 x 步。请返回后退 至多 steps 步以后的 url 。
//          string forward(int steps) 在浏览历史中前进 steps 步。
//              如果你只能在浏览历史中前进至多 x 步且 steps > x ，那么你只前进 x 步。
//              请返回前进 至多 steps步以后的 url 。
//      示例：
//          输入：
//              ["BrowserHistory","visit","visit","visit","back","back","forward",
//               "visit","forward","back","back"]
//              [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],
//               [1],[1],[1],["linkedin.com"],[2],[2],[7]]
//          输出：
//              [null,null,null,null,"facebook.com","google.com","facebook.com",
//               null,"linkedin.com","google.com","leetcode.com"]
//          解释：
//              BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
//              browserHistory.visit("google.com");       // 你原本在浏览 "leetcode.com" 。访问 "google.com"
//              browserHistory.visit("facebook.com");     // 你原本在浏览 "google.com" 。访问 "facebook.com"
//              browserHistory.visit("youtube.com");      // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
//              browserHistory.back(1);                   // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
//              browserHistory.back(1);                   // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
//              browserHistory.forward(1);                // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
//              browserHistory.visit("linkedin.com");     // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
//              browserHistory.forward(2);                // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
//              browserHistory.back(2);                   // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
//              browserHistory.back(7);                   // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"
//      提示：
//          1 <= homepage.length <= 20
//          1 <= url.length <= 20
//          1 <= steps <= 100
//          homepage 和 url 都只包含 '.' 或者小写英文字母。
//          最多调用 5000 次 visit， back 和 forward 函数。

#define MAX_URL_LENGTH 21
#define MAX_STEPS_LENGTH 101

// 栈:
typedef struct
{
    char *url[MAX_STEPS_LENGTH];
    int curCnt;
    int sumCnt;
} BrowserHistory1;

BrowserHistory1 *BrowserHistoryCreate1(char *homepage)
{
    BrowserHistory1 *obj = (BrowserHistory1 *)malloc(sizeof(BrowserHistory1));
    obj->url[0] = (char *)malloc(sizeof(char) * MAX_URL_LENGTH);
    strcpy(obj->url[0], homepage);
    obj->curCnt = 1;
    obj->sumCnt = 1;
    return obj;
}

void BrowserHistoryVisit1(BrowserHistory1 *obj, char *url)
{
    obj->url[obj->curCnt] = (char *)malloc(sizeof(char) * MAX_URL_LENGTH);
    strcpy(obj->url[obj->curCnt], url);
    obj->curCnt++;
    obj->sumCnt = obj->curCnt;
    return;
}

char *BrowserHistoryBack1(BrowserHistory1 *obj, int steps)
{
    int k = obj->curCnt - steps > 0 ? obj->curCnt - steps - 1 : 0;
    obj->curCnt = k + 1;
    return obj->url[k];
}

char *BrowserHistoryForward1(BrowserHistory1 *obj, int steps)
{
    int k = obj->curCnt + steps < obj->sumCnt ? obj->curCnt + steps - 1 : obj->sumCnt - 1;
    obj->curCnt = k + 1;
    return obj->url[k];
}

void BrowserHistoryFree1(BrowserHistory1 *obj)
{
    free(obj);
    return;
}

// 双向链表:
typedef struct BrowserHistory2
{
    char url[MAX_URL_LENGTH];
    struct BrowserHistory2 *pre;
    struct BrowserHistory2 *next;
} BrowserHistory2;

BrowserHistory2 *cur;

BrowserHistory2 *BrowserHistoryCreate2(char *homepage)
{
    BrowserHistory2 *obj = (BrowserHistory2 *)malloc(sizeof(BrowserHistory2));
    strcpy(obj->url, homepage);
    obj->pre = NULL;
    obj->next = NULL;
    cur = obj;
    return obj;
}

void BrowserHistoryVisit2(BrowserHistory2 *obj, char *url)
{
    obj = cur;
    obj->next = BrowserHistoryCreate2(url);
    obj->next->pre = obj;
    return;
}

char *BrowserHistoryBack2(BrowserHistory2 *obj, int steps)
{
    while (steps != 0)
    {
        steps--;
        if (cur->pre == NULL)
        {
            break;
        }
        cur = cur->pre;
    }
    return cur->url;
}

char *BrowserHistoryForward2(BrowserHistory2 *obj, int steps)
{
    while (steps != 0)
    {
        steps--;
        if (cur->next == NULL)
        {
            break;
        }
        cur = cur->next;
    }
    return cur->url;
}

void BrowserHistoryFree2(BrowserHistory2 *obj)
{
    free(obj);
}

int main()
{
    char s1[] = "leetcode.com";
    BrowserHistory1 *obj1 = BrowserHistoryCreate1((char *)s1);
    char s2[] = "google.com";
    BrowserHistoryVisit1(obj1, s2);
    char s3[] = "facebook.com";
    BrowserHistoryVisit1(obj1, s3);
    char s4[] = "youtube.com";
    BrowserHistoryVisit1(obj1, s4);
    char *a1 = BrowserHistoryBack1(obj1, 1);
    printf("后退一步 页面 为：\n");
    PrintString(a1); // facebook.com
    char *a2 = BrowserHistoryBack1(obj1, 1);
    printf("后退一步 页面 为：\n");
    PrintString(a2); // google.com
    char *a3 = BrowserHistoryForward1(obj1, 1);
    printf("前进一步 页面 为：\n");
    PrintString(a3); // facebook.com
    char s5[] = "linkedin.com";
    BrowserHistoryVisit1(obj1, s5);
    char *a4 = BrowserHistoryForward1(obj1, 2);
    printf("前进一步 页面 为：\n");
    PrintString(a4); // linkedin.com
    char *a5 = BrowserHistoryBack1(obj1, 2);
    printf("后退一步 页面 为：\n");
    PrintString(a5); // google.com
    char *a6 = BrowserHistoryBack1(obj1, 7);
    printf("后退一步 页面 为：\n");
    PrintString(a6); // leetcode.com
    BrowserHistoryFree1(obj1);

    char t1[] = "leetcode.com";
    BrowserHistory2 *obj2 = BrowserHistoryCreate2((char *)t1);
    char t2[] = "google.com";
    BrowserHistoryVisit2(obj2, t2);
    char t3[] = "facebook.com";
    BrowserHistoryVisit2(obj2, t3);
    char t4[] = "youtube.com";
    BrowserHistoryVisit2(obj2, t4);
    char *b1 = BrowserHistoryBack2(obj2, 1);
    printf("后退一步 页面 为：\n");
    PrintString(b1); // facebook.com
    char *b2 = BrowserHistoryBack2(obj2, 1);
    printf("后退一步 页面 为：\n");
    PrintString(b2); // google.com
    char *b3 = BrowserHistoryForward2(obj2, 1);
    printf("前进一步 页面 为：\n");
    PrintString(b3); // facebook.com
    char t5[] = "linkedin.com";
    BrowserHistoryVisit2(obj2, t5);
    char *b4 = BrowserHistoryForward2(obj2, 2);
    printf("前进一步 页面 为：\n");
    PrintString(b4); // linkedin.com
    char *b5 = BrowserHistoryBack2(obj2, 2);
    printf("后退一步 页面 为：\n");
    PrintString(b5); // google.com
    char *b6 = BrowserHistoryBack2(obj2, 7);
    printf("后退一步 页面 为：\n");
    PrintString(b6); // leetcode.com
    BrowserHistoryFree2(obj2);
}
