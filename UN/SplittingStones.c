#include "../Mybasic/mybasic.h"

//      Huawei: 分石子

//      几块石子排成一行，每块石子都有一个关联值，关联值为整数，由数组stonevalue 输出。
//      游戏中的每一轮，a会将这行石子分成两个非空行（左侧行和右侧行）。
//      b负责计算每一行的值，即此行中所有石子的值的总和。
//      b会丢弃值最大的行，a的得分为剩下那行的值（每轮累加）。
//      如果两行的值相等，b让a决定丢弃哪一行。下一轮从剩下的那一行开始。
//      只剩下一行石子时，游戏结束。a的分数最初为0.。
//      返回a能够获得的最大分数。 
//      输入：
//          stones数组
//      输出：
//          a能够获取的最大分数
//      输入样例1:
//          6 2 3 4 5 5
//      输出样例1:
//          18

int SplittingStones(int* stones, int l);
