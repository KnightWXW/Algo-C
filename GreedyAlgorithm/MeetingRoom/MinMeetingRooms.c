#include "../Mybasic/mybasic.h"

//      LeetCode: 253 会议室 II

//      链接：https://leetcode.cn/problems/meeting-rooms-ii/

//      给定一个会议时间安排的数组，
//      每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],…] (si < ei),
//      为避免会议冲突，同时要考虑充分利用会议室资源，
//      请你计算至少需要多少间会议室，才能满足这些会议安排。
//      示例 1：
//          输入: [[0, 30],[5, 10],[15, 20]]
//          输出: 2
//      示例 2：
//          输入: [[7,10],[2,4]]
//          输出: 1

int minMeetingRooms(vector<vector<int>> &intervals);

int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    print2DVecElement(intervals1);
    int ans1 = minMeetingRooms(intervals1);
    printf("至少需要 %d 间会议室 。\n", ans1);

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    print2DVecElement(intervals2);
    int ans2 = minMeetingRooms(intervals2);
    printf("至少需要 %d 间会议室 。\n", ans2);
}

// 贪心算法：
// Time: O(NlogN)
// Space: O(N)
int minMeetingRooms(vector<vector<int>> &intervals)
{
    
}