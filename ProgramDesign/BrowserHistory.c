#include "../mybasic.h"

//      Huawei：浏览器历史系统

//      打开一个浏览器，此浏览器窗口一般具有浏览历史的特性，请实现如下功能：
//      BrowserHistorySys(char * homepage, int maxCount):
//          初始化：homepage 作为当前页，并缓存到浏览历史中；
//              浏览历史中最多可以缓存maxCount个网页
//      int Visit(char * url): 跳转访问页面 url, 返回访问后浏览历史中的缓存页面数量
//          如果入参 url 仍然是 当前页，则继续浏览此页面，即：
//          当前页不变，且浏览历史也不变
//          如果入参 url 不是 当前页，则跳转到此 url, 并把此 url 页面作为当前页；
//          同时清除 浏览历史中 原当前页的前进记录，再将此 url 缓存 到浏览器历史中。
//          如果新增缓存后，浏览历史缓存页面数量超过maxCount，则清除浏览器历史中最早的记录。
//      char * Back(): 在浏览器历史中从当前页中当前页面后退一步，
//          返回停留页面的 url, 并作为当前页。
//          注：如果已退无可退，则不再后退，继续停留在当前当前页。
//      char * Forward(): 在浏览历史中当前页前进一步，返回停留页面的url, 并作为当前页。
//          注：如果已进无可进，则不再前进，继续停留在当前当前页。

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

typedef struct {
    
} BrowserHistory;

BrowserHistory* BrowserHistoryCreate(char* homepage) {
    
}

void BrowserHistoryVisit(BrowserHistory* obj, char* url) {
    
}

char* BrowserHistoryBack(BrowserHistory* obj, int steps) {
    
}

char* BrowserHistoryForward(BrowserHistory* obj, int steps) {
    
}

void BrowserHistoryFree(BrowserHistory* obj) {
    
}

int main()
{
    char s1[] = "leetcode.com";
    BrowserHistory *obj = BrowserHistoryCreate((char *)s1);
    char s2[] = "google.com";
    BrowserHistoryVisit(obj, s2);
    char s3[] = "facebook.com";
    BrowserHistoryVisit(obj, s3);
    char s4[] = "youtube.com";
    BrowserHistoryVisit(obj, s4);
    char* a1 = BrowserHistoryBack(obj, 1);
    printf("后退一步 页面 为：\n");
    PrintString(a1); // facebook.com
    char* a2 = BrowserHistoryBack(obj, 1);
    printf("后退一步 页面 为：\n");
    PrintString(a2); // google.com
    char* a3 = BrowserHistoryForward(obj, 1);
    printf("前进一步 页面 为：\n");
    PrintString(a3); // facebook.com
    char s5[] = "linkedin.com";
    BrowserHistoryVisit(obj, s5);
    char* a4 = BrowserHistoryForward(obj, 2);
    printf("前进一步 页面 为：\n");
    PrintString(a4); // linkedin.com
    char* a5 = BrowserHistoryBack(obj, 2);
    printf("后退一步 页面 为：\n");
    PrintString(a5); // google.com
    char* a6 = BrowserHistoryBack(obj, 7);
    printf("后退一步 页面 为：\n");
    PrintString(a6); // leetcode.com
    
}

