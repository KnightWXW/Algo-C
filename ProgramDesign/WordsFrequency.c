#include "../mybasic.h"
#include "uthash.h"

//      LeetCode 面试题 16.02. 单词频率

//      链接：https://leetcode.cn/problems/words-frequency-lcci/

//      设计一个方法，找出任意指定单词在一本书中的出现频率。
//      你的实现应该支持如下操作：
//          WordsFrequency(book)构造函数，参数为字符串数组构成的一本书
//          get(word)查询指定单词在书中出现的频率
//      示例：
//          WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
//          wordsFrequency.get("you"); //返回0，"you"没有出现过
//          wordsFrequency.get("have"); //返回2，"have"出现2次
//          wordsFrequency.get("an"); //返回1
//          wordsFrequency.get("apple"); //返回1
//          wordsFrequency.get("pen"); //返回1
//      提示：
//          book[i]中只包含小写字母
//          1 <= book.length <= 100000
//          1 <= book[i].length <= 10
//          get函数的调用次数不会超过100000

typedef struct
{

} WordsFrequency;

WordsFrequency *wordsFrequencyCreate(char **book, int bookSize)
{
}

int wordsFrequencyGet(WordsFrequency *obj, char *word)
{
}

void wordsFrequencyFree(WordsFrequency *obj)
{
}

int main()
{
    char **book = {"i", "have", "an", "apple", "he", "have", "a", "pen"};
    int bookSize = 8;
    WordsFrequency *obj = wordsFrequencyCreate(book, bookSize);
    char *word1 = "you";
    int g1 = wordsFrequencyGet(obj, word1);
    printf("该单词频率为 %d\n", g1); // 返回 0，"you"没有出现过
    char *word2 = "have";
    int g2 = wordsFrequencyGet(obj, word2);
    printf("该单词频率为 %d\n", g2); // 返回 2，"have"出现2次
    char *word3 = "an";
    int g3 = wordsFrequencyGet(obj, word3);
    printf("该单词频率为 %d\n", g3); // 返回 1
    char *word4 = "apple";
    int g4 = wordsFrequencyGet(obj, word4);
    printf("该单词频率为 %d\n", g4); // 返回 1
    char *word5 = "pen";
    int g5 = wordsFrequencyGet(obj, word5);
    printf("该单词频率为 %d\n", g5); // 返回 1
}