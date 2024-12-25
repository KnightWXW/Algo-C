#include "../Mybasic/mybasic.h"

//      LeetCode 676. 实现一个魔法字典

//      链接： https://leetcode.cn/problems/implement-magic-dictionary/

//      设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。
//      如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，
//      使得所形成的新单词存在于你构建的字典中。
//      实现 MagicDictionary 类：
//      MagicDictionary(): 初始化对象
//      void buildDict(String[] dictionary)：
//           使用字符串数组 dictionary 设定该数据结构，dictionary 中的字符串互不相同
//      bool search(String searchWord)：
//           给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，
//           使得所形成的新字符串能够与字典中的任一字符串匹配。
//           如果可以，返回 true ；否则，返回 false 。
//      示例：
//          输入
//              ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
//              [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
//          输出
//              [null, null, false, true, false, false]
//          解释
//              MagicDictionary magicDictionary = new MagicDictionary();
//              magicDictionary.buildDict(["hello", "leetcode"]);
//              magicDictionary.search("hello"); // 返回 False
//              magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
//              magicDictionary.search("hell"); // 返回 False
//              magicDictionary.search("leetcoded"); // 返回 False
//      提示：
//          1 <= dictionary.length <= 100
//          1 <= dictionary[i].length <= 100
//          dictionary[i] 仅由小写英文字母组成
//          dictionary 中的所有字符串 互不相同
//          1 <= searchWord.length <= 100
//          searchWord 仅由小写英文字母组成
//          buildDict 仅在 search 之前调用一次
//          最多调用 100 次 search

#define MAGIC_DICTIONARY_WORD_SIZE 101

// 全局变量:

typedef struct
{
    char word[MAGIC_DICTIONARY_WORD_SIZE];
    UT_hash_handle hh;
} MagicDictionary_A;

MagicDictionary_A *md = NULL;

void MagicDictionaryAddNode_A(char *word)
{
    MagicDictionary_A *cur = NULL;
    HASH_FIND_STR(md, word, cur);
    if (cur == NULL)
    {
        cur = (MagicDictionary_A *)malloc(sizeof(MagicDictionary_A));
        strcpy(cur->word, word);
        HASH_ADD_STR(md, word, cur);
    }
    return;
}

MagicDictionary_A *MagicDictionaryCreate_A()
{
    return md;
}

void MagicDictionaryBuildDict_A(MagicDictionary_A *obj, char **dictionary, int dictionarySize)
{
    for (int i = 0; i < dictionarySize; i++)
    {
        MagicDictionaryAddNode_A(dictionary[i]);
    }
    return;
}

bool MagicDictionarySearch_A(MagicDictionary_A *obj, char *searchWord)
{
    int l = strlen(searchWord);
    for (int i = 0; i < l; i++)
    {
        char tem = searchWord[i];
        for (int j = 0; j < 26; j++)
        {
            MagicDictionary_A *cur;
            if ((char)('a' + j) != tem)
            {
                searchWord[i] = (char)('a' + j);
            }
            else
            {
                continue;
            }
            HASH_FIND_STR(md, searchWord, cur);
            if (cur != NULL)
            {
                return true;
            }
        }
        searchWord[i] = tem;
    }
    return false;
}

void MagicDictionaryFree_A(MagicDictionary_A *obj)
{
    HASH_CLEAR(hh, md);
    return;
}

// 非全局变量, 函数传参
typedef struct
{
    char word[MAGIC_DICTIONARY_WORD_SIZE];
    UT_hash_handle hh;
} MagicWordSet;

typedef struct
{
    MagicWordSet *hSet;
} MagicDictionary_B;

MagicDictionary_B *MagicDictionaryCreate_B()
{
    MagicDictionary_B *obj = (MagicDictionary_B *)malloc(sizeof(MagicDictionary_B));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->hSet = NULL;
    return obj;
}

void MagicDictionaryBuildDict_B(MagicDictionary_B *obj, char **dictionary, int dictionarySize)
{
    for (int i = 0; i < dictionarySize; i++)
    {
        MagicWordSet *set = (MagicWordSet *)malloc(sizeof(MagicWordSet));
        if (set == NULL)
        {
            return;
        }
        strcpy(set->word, dictionary[i]);
        HASH_ADD_STR(obj->hSet, word, set);
    }
    return;
}

bool MagicDictionarySearch_B(MagicDictionary_B *obj, char *searchWord)
{
    int l = strlen(searchWord);
    for (int i = 0; i < l; i++)
    {
        char tem = searchWord[i];
        for (int j = 0; j < 26; j++)
        {
            MagicWordSet *cur;
            if ((char)('a' + j) != tem)
            {
                searchWord[i] = (char)('a' + j);
            }
            else
            {
                continue;
            }
            HASH_FIND_STR(obj->hSet, searchWord, cur);
            if (cur != NULL)
            {
                return true;
            }
        }
        searchWord[i] = tem;
    }
    return false;
}

void MagicDictionaryFree_B(MagicDictionary_B *obj)
{
    HASH_CLEAR(hh, obj->hSet);
    free(obj);
    return;
}

int main()
{
    MagicDictionary_A *obj_A = MagicDictionaryCreate_A();
    char *arr_A[] = {"hello", "leetcode"};
    MagicDictionaryBuildDict_A(obj_A, arr_A, 2);
    bool b_A1 = MagicDictionarySearch_A(obj_A, "hello"); // 返回 False
    printf("匹配结果为：\n");
    PrintBool(b_A1);
    bool b_A2 = MagicDictionarySearch_A(obj_A, "hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    printf("匹配结果为：\n");
    PrintBool(b_A2);
    bool b_A3 = MagicDictionarySearch_A(obj_A, "hell"); // 返回 False
    printf("匹配结果为：\n");
    PrintBool(b_A3);
    bool b_A4 = MagicDictionarySearch_A(obj_A, "leetcode"); // 返回 False
    printf("匹配结果为：\n");
    PrintBool(b_A4);
    MagicDictionaryFree_A(obj_A);

    MagicDictionary_B *obj_B = MagicDictionaryCreate_B();
    char *arr[] = {"hello", "leetcode"};
    MagicDictionaryBuildDict_B(&obj_B, arr, 2);
    bool b_B1 = MagicDictionarySearch_B(obj_B, "hello"); // 返回 False
    printf("匹配结果为：\n");
    PrintBool(b_B1);
    bool b_B2 = MagicDictionarySearch_B(obj_B, "hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    printf("匹配结果为：\n");
    PrintBool(b_B2);
    bool b_B3 = MagicDictionarySearch_B(obj_B, "hell"); // 返回 False
    printf("匹配结果为：\n");
    PrintBool(b_B3);
    bool b_B4 = MagicDictionarySearch_B(obj_B, "leetcode"); // 返回 False
    printf("匹配结果为：\n");
    PrintBool(b_B4);
    MagicDictionaryFree_B(&obj_B);
}