#include "../Mybasic/mybasic.h"

//      牛客：天弃之子

//      链接：https://www.nowcoder.com/questionTerminal/ba2b7b5d318c46dda811c644d9020de6

//      有一款游戏，过关的方式是按按钮。游戏一共有几关,每一关有a[i]个按钮,
//      其中只有唯一一个按钮是可以通关的,按下其他的按钮游戏就会失败。
//      好在这个游戏可以重来,而且由于设计者的疏忽,每一关的通关按钮是不变的,
//      所以你可以记住前几关的按钮,重来时就可以直接通关。
//      但是你的运气似乎用在了其他地方,你使用了最多的按按钮次数才成功通关。
//      求这个最多的按按钮次数吧!
//      输入一维数组a[i],表示每一关的按钮数
//          1 ≤ a[i] ≤ 10^5
//          1 ≤ a[i] 数组的长度 ≤ 10^5
//      输入    [1,1,4,5,1,4]
//      输出    49
long SonOfHeavenAbandoned(int* buttons, int l);

int main()
{
    int n = GenerateRandomNum(0, 30);
    int* buttons = GenerateRandomVec(1, 20, n);
    PrintVecElement(buttons, n);
    long ans = SonOfHeavenAbandoned(buttons, n);
    printf("最多的按按钮次数 %d\n", ans);
}

// buttons[i] : 尝试 到正确按钮 通过 最少次数 为 buttons[i] - 1
// 每次走到 buttons[i] 需要 按 i + 1 次
// 加上最后完成成功通关 的 buttons.size() 次
long SonOfHeavenAbandoned(int* buttons, int l)
{
    long cnt = 0;
    for (int i = 0; i < buttons.size(); i++)
    {
        cnt += (i + 1) * (buttons[i] - 1);
    }
    cnt += buttons.size();
    return cnt;
}