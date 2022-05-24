/*

几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？

给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

例 1：

输入: m = 3, n = 3, k = 5
输出: 3
解释:
乘法表:
1	2	3
2	4	6
3	6	9

第5小的数字是 3 (1, 2, 2, 3, 3).
例 2：

输入: m = 2, n = 3, k = 6
输出: 6
解释:
乘法表:
1	2	3
2	4	6

第6小的数字是 6 (1, 2, 2, 3, 4, 6).
注意：

m 和 n 的范围在 [1, 30000] 之间。
k 的范围在 [1, m * n] 之间。

链接：https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table

    int m = 2, n = 3, k = 6;
    Solution temp;
    int ret = temp.findKthNumber(m, n, k);
    cout << ret << endl;

*/

#include <queue>
using namespace std;

//class Solution {
//public:
//    int findKthNumber(int m, int n, int k) {
//        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
//            return a.first > b.first;
//        };
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue(cmp);
//        // struct cmp {
//        //     bool operator ()(const pair<int, int> &a, const pair<int, int> &b){
//        //         return a.first > b.first;
//        //     }
//        // };
//        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> queue;
//        for (int i = 1; i <= m; ++i) {
//            queue.emplace(i, i);
//        }
//        pair<int, int> ret;
//        while (k--) {
//            ret = queue.top();
//            queue.pop();
//            if (ret.first < n * ret.second)
//                queue.emplace(ret.first + ret.second, ret.second);
//        }
//        return ret.first;
//    }
//};


class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = mid / n * n;
            for (int i = mid / n + 1; i <= m; ++i) {
                count += mid / i;
            }
            if (count < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};