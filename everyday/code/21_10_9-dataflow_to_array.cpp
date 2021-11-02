/*

给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。

实现 SummaryRanges 类：

SummaryRanges() 使用一个空数据流初始化对象。
void addNum(int val) 向数据流中加入整数 val 。
int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
 

示例：

输入：
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
输出：
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

解释：
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // 返回 [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]

*/
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class SummaryRanges {
private:
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int val) {
        // 找到 l1 最小的且满足 l1 > val 的区间 interval1 = [l1, r1]
        // 如果不存在这样的区间，interval1 为尾迭代器
        auto interval1 = intervals.upper_bound(val);
        // 找到 l0 最大的且满足 l0 <= val 的区间 interval0 = [l0, r0]
        // 在有序集合中，interval0 就是 interval1 的前一个区间
        // 如果不存在这样的区间，interval0 为尾迭代器
        auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));

        if (interval0 != intervals.end() && interval0->first <= val && val <= interval0->second) {
            // 情况一
            return;
        }
        else {
            bool left_aside = (interval0 != intervals.end() && interval0->second + 1 == val);
            bool right_aside = (interval1 != intervals.end() && interval1->first - 1 == val);
            if (left_aside && right_aside) {
                // 情况四
                int left = interval0->first, right = interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(left, right);
            }
            else if (left_aside) {
                // 情况二
                ++interval0->second;
            }
            else if (right_aside) {
                // 情况三
                int right = interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val, right);
            }
            else {
                // 情况五
                intervals.emplace(val, val);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (const auto& iter : intervals) {
            ans.push_back({ iter.first, iter.second });
        }
        return ans;
    }
};