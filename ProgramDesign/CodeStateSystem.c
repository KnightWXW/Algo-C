#include "../Mybasic/mybasic.h"

//      Huawei: 编程语言设计系统

//      设计一个编程语言设计系统：
//      CodeStateSystem(products[]): 初始化产品及其代码仓关系，所有代码仓的代码量初始化为0
//          products[i] = [productId, repolds[]]: 表示一个产品及其代码仓列表。
//          产品，代码仓均是全局唯一的，一个代码仓仅归属于某一产品。
//      ChangeCodeLines(int repolds, int languageId, int codeline):
//          代码仓repold中某种语言languageId的代码行的变化量为codeline
//          (正值表示增加,负值表示减少)。
//          最后返回此代码仓中该语言的代码总行数。
//          用例保证代码仓已存在，一个代码仓中某语言的代码行数不会减少为负值。
//      StatLanguage(int productId): 统计产品productId所用到的各语言的代码总行数，
//          并按要求返回语言Id列表，productId为0表示所有产品，非0表示指定产品。
//          返回要求：只返回代码量大于0的语言，优先按照语言的代码量降序，
//          若代码量相同，则再按照语言id升序

typedef struct
{
    int productId;
    int *repolds;
    int repoldsSize;
} Product;

typedef struct
{

} CodeStateSystem;

CodeStateSystem *CodeStateSystemCreate(Product *products, int ProductSize)
{
}

int CodeStateSystemChangeCodeLines(CodeStateSystem *obj, int repolds, int languageId, int codeline)
{
}

int *CodeStateSystemStatLanguage(CodeStateSystem *obj, int productId, int *returnSize)
{
}

void CodeStateSystemFree(CodeStateSystem *obj)
{
}

int main()
{
    int productSize = 3;
    Product *p = (Product *)malloc(sizeof(Product) * ProductSize);
    p[0]->productId = 10;
    p[0]->repoldsSize = 2;
    p[0]->repolds = (int *)malloc(sizeof(int) * p[0]->repoldsSize);
    p[0]->repolds[0] = 102;
    p[0]->repolds[1] = 101;
    p[1]->productId = 12;
    p[1]->repoldsSize = 1;
    p[1]->repolds = (int *)malloc(sizeof(int) * p[1]->repoldsSize);
    p[1]->repolds[0] = 122;
    p[2]->productId = 22;
    p[2]->repoldsSize = 1;
    p[2]->repolds = (int *)malloc(sizeof(int) * p[2]->repoldsSize);
    p[2]->repolds[0] = 221;
    CodeStateSystem *obj = CodeStateSystemCreate(p, productSize);
    int l1 = 3;
    int c1 = CodeStateSystemChangeCodeLines(obj, 221, l1, 2500); // 2500
    printf("代码仓中语言 %d 的代码总行数为 %d\n", l1, c1);
    int l2 = 2;
    int c2 = CodeStateSystemChangeCodeLines(obj, 102, l2, 2100); // 2100
    printf("代码仓中语言 %d 的代码总行数为 %d\n", l2, c2);
    int l3 = 1;
    int c3 = CodeStateSystemChangeCodeLines(obj, 101, l3, 2000); // 2000
    printf("代码仓中语言 %d 的代码总行数为 %d\n", l3, c3);
    int l4 = 10;
    int sr1 = 0;
    int *s1 = CodeStateSystemStatLanguage(obj, l4, &sr1); // {2, 1}
    printf("要求返回语言 %d 列表为 \n", l4);
    PrintVecElement(s1, sr1);
    int l5 = 22;
    int sr2 = 0;
    int *s2 = CodeStateSystemStatLanguage(obj, l5, &sr2); // {3}
    printf("要求返回语言 %d 列表为 \n", l5);
    PrintVecElement(s2, sr2);
    int c4 = CodeStateSystemChangeCodeLines(obj, 102, 2, -100); // 2000
    printf("代码仓中语言 %d 的代码总行数为 %d\n", l1, c1);
    int l6 = 0;
    int sr3 = 0;
    int *s3 = CodeStateSystemStatLanguage(obj, l6, &sr3); // {3, 1, 2}
    printf("要求返回语言 %d 列表为 \n", l6);
    PrintVecElement(s3, sr3);
    CodeStateSystemFree(obj);
}