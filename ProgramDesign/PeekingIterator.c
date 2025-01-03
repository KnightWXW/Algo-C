#include "../Mybasic/mybasic.h"

//      LeetCode 284. 窥视迭代器

//      链接：https://leetcode.cn/problems/peeking-iterator/

//      请你在设计一个迭代器，在集成现有迭代器拥有的 hasNext 和 next 操作的基础上，
//      还额外支持 peek 操作。
//      实现 PeekingIterator 类：
//          PeekingIterator(Iterator<int> nums) 使用指定整数迭代器 nums 初始化迭代器。
//          int next() 返回数组中的下一个元素，并将指针移动到下个元素处。
//          bool hasNext() 如果数组中存在下一个元素，返回 true ；否则，返回 false 。
//          int peek() 返回数组中的下一个元素，但 不 移动指针。
//      注意：每种语言可能有不同的构造函数和迭代器 Iterator，
//          但均支持 int next() 和 boolean hasNext() 函数。
//      示例 1：
//          输入：
//              ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
//              [[[1, 2, 3]], [], [], [], [], []]
//          输出：
//              [null, 1, 2, 2, 3, false]
//          解释：
//              PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
//              peekingIterator.next();    // 返回 1 ，指针移动到下一个元素 [1,2,3]
//              peekingIterator.peek();    // 返回 2 ，指针未发生移动 [1,2,3]
//              peekingIterator.next();    // 返回 2 ，指针移动到下一个元素 [1,2,3]
//              peekingIterator.next();    // 返回 3 ，指针移动到下一个元素 [1,2,3]
//              peekingIterator.hasNext(); // 返回 False
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 1000
//          对 next 和 peek 的调用均有效
//          next、hasNext 和 peek 最多调用  1000 次

struct PeekingIterator {
    
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasPeeked = false;
    return piter;
}

int peek(struct PeekingIterator* obj) {
    
}

int next(struct PeekingIterator* obj) {
    
}

bool hasNext(struct PeekingIterator* obj) {
    
}

 