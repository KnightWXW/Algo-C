#include "../Mybasic/mybasic.h"

//      LeetCode 面试题 16.02. 单词频率

//      链接：https://leetcode.cn/problems/words-frequency-lcci/

//      设计一个方法，找出任意指定单词在一本书中的出现频率。
//      你的实现应该支持如下操作：
//          WordsFrequency(book): 构造函数，参数为字符串数组构成的一本书
//          get(word): 查询指定单词在书中出现的频率
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

#define WORD_LENGTH 12

typedef struct
{
    char word[WORD_LENGTH];
    int cnt;
    UT_hash_handle hh;
} WordsFrequency;

void WordsFrequencyAddNode(WordsFrequency **hMap, char *word)
{
    WordsFrequency *cur = NULL;
    HASH_FIND_STR(*hMap, word, cur);
    if (cur == NULL)
    {
        cur = (WordsFrequency *)malloc(sizeof(WordsFrequency));
        strcpy(cur->word, word);
        cur->cnt = 1;
        HASH_ADD_STR(*hMap, word, cur);
    }
    else
    {
        cur->cnt++;
    }
    return;
}

WordsFrequency *WordsFrequencyCreate(char **book, int bookSize)
{
    WordsFrequency *hMap = NULL;
    for (int i = 0; i < bookSize; i++)
    {
        WordsFrequencyAddNode(&hMap, book[i]);
    }
    return hMap;
}

int WordsFrequencyGet(WordsFrequency *obj, char *word)
{
    WordsFrequency *cur = NULL;
    HASH_FIND_STR(obj, word, cur);
    if (cur == NULL)
    {
        return 0;
    }
    else
    {
        return cur->cnt;
    }
}

void WordsFrequencyFree(WordsFrequency *obj)
{
    HASH_CLEAR(hh, obj);
    free(obj);
    return;
}

int main()
{
    int bookSize = 8;
    char *book[] = {"i", "have", "an", "apple", "he", "have", "a", "pen"};
    WordsFrequency *obj = WordsFrequencyCreate((char **)book, bookSize);
    char word1[] = "you";
    int g1 = WordsFrequencyGet(obj, word1);
    printf("该单词频率为 %d\n", g1); // 返回 0，"you"没有出现过
    char word2[] = "have";
    int g2 = WordsFrequencyGet(obj, word2);
    printf("该单词频率为 %d\n", g2); // 返回 2，"have"出现2次
    char word3[] = "an";
    int g3 = WordsFrequencyGet(obj, word3);
    printf("该单词频率为 %d\n", g3); // 返回 1
    char word4[] = "apple";
    int g4 = WordsFrequencyGet(obj, word4);
    printf("该单词频率为 %d\n", g4); // 返回 1
    char word5[] = "pen";
    int g5 = WordsFrequencyGet(obj, word5);
    printf("该单词频率为 %d\n", g5); // 返回 1
    WordsFrequencyFree(obj);
}