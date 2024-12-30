#include "../Mybasic/mybasic.h"

//      Huawei: 文件名生成器

//      假设从浏览器下载若干个文件，保存到本地硬盘的同一个目录(初始目录为空)，
//      需要对文件名进行处理，处理规则如下：
//          1、如果已经存在同名文件，则后面生成的文件名加后缀(k),
//             其中k为从2开始递增的整数，表示该文件名已出现的次数(含本次)；
//          2、如果无同名文件，则文件名不变。
//      给定一批被下载的文件名，请输出按顺序下载后生成的文件名。
//      样例1：
//          输入：
//              4
//              myfile yourfile myfile myfile
//          输出：
//              myfile yourfile myfile(2) myfile(3)
//      样例2：
//          输入：
//              4
//              filea filea fileb fileb
//          输出：
//              filea filea(2) fileb fileb(2)

char **GenerateFileName(char **vec, int l);

int main()
{
    char *vec1[] = {"myfile", "yourfile", "myfile", "myfile"};
    int l1 = 4;
    printf("文件名初始值：\r\n");
    PrintStringVec(vec1, l1);
    char **ans1 = GenerateFileName(vec1, l1);
    printf("文件名更新值：\r\n");
    PrintStringVec(ans1, l1);

    char *vec2[] = {"filea", "filea", "fileb", "fileb"};
    int l2 = 4;
    printf("文件名初始值：\r\n");
    PrintStringVec(vec2, l2);
    char **ans2 = GenerateFileName(vec2, l2);
    printf("文件名更新值：\r\n");
    PrintStringVec(ans2, l2);
}

char **GenerateFileName(char **vec, int l)
{
}