#include "../Mybasic/mybasic.h"

//      Huawei: 合法MAC地址

//      给定一个字符串，从中按如下规则找出所有的合法mac地址的数量：
//      合法mac地址以字符串表示时，由12位十六进制字符组成，每两个字符之间被用 - 或: 分割
//      合法的十六进制字符包括0-9，a-f，A-F，同一个mac中出现的字母可以大小写混用-字母不区分大小写
//      一个mac地址中，- 与 : 不能混用
//      相同mac地址需去重统计：注意，仅大小写、分割符不同的两个mac地址字符串视为相同，
//      如aa-bb-12-cc-dd-ee 与 Aa-bB:12:CC:dd:ee 视为相同
//      如下地址都不是合法地址：
//          aa-bb-2-cc-dd-ee-ll。 不是，因为 2 不是两个字符
//          aa-bb-22-cc-dd-eG-11. 不是，因为 G 不在十六进制字符范围内
//          如aa-bb-22-09808980-12-12.  不是，09808980 超过两个字符了
//      输入样例1:
//          01-02-03-04-05-06-07
//      输出样例1:
//          2
//      输入样例2
//          01:02:03:002-03-04-05-06-07
//      输出样例2
//          1
//      输入样例3
//          0a-0a-0a-0a-0a-0a-0A
//      输出样例3
//          1

int LegitimateMACAddress(char* str);

int main()
{
    char s1[] = "01-02-03-04-05-06-07";
    PrintString(s1);
    int ans1 = LegitimateMACAddress(s1);
    printf("所有的合法mac地址的数量为 %d \n", ans1);
    
    char s2[] = "01:02:03:002-03-04-05-06-07";
    PrintString(s2);
    int ans2 = LegitimateMACAddress(s2);
    printf("所有的合法mac地址的数量为 %d \n", ans2);

    char s3[] = "0a-0a-0a-0a-0a-0a-0A";
    PrintString(s3);
    int ans3 = LegitimateMACAddress(s3);
    printf("所有的合法mac地址的数量为 %d \n", ans3);
}
