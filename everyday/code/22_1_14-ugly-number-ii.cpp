/*

给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。

 

示例 1：

输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：

输入：n = 1
输出：1
解释：1 通常被视为丑数。
 

提示：

1 <= n <= 1690

链接：https://leetcode-cn.com/problems/ugly-number-ii

    int n = 10;
    Solution temp;
    int ret = temp.nthUglyNumber(n);
    cout << ret << endl;

*/

#include <queue>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    const int factors[3] = { 2, 3, 5};
//    int nthUglyNumber(int n) {
//        int ret = 0;
//        priority_queue<long, vector<long>, greater<long>> queue;
//        unordered_set<long> set;
//        queue.emplace(1);
//        set.emplace(1);
//        while (n--) {
//            long min_now = queue.top();
//            ret = (int)min_now;
//            queue.pop();
//            for (int i = 0; i < 3; ++i) {
//                long temp = factors[i] * min_now;
//                if (!set.count(temp)) {
//                    set.insert(temp);
//                    queue.emplace(temp);
//                }
//            }
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int factors[3] = {2, 3, 5};
    int nthUglyNumber(int n) {
        int ret = 1;
        vector<int> ugly_vec(n);
        ugly_vec[0] = 1;
        vector<vector<int>::iterator> iter_vec(3, ugly_vec.begin());
        int k = 1;
        while (--n) {
            ret = min({(*iter_vec[0]) * factors[0], (*iter_vec[1]) * factors[1],* (iter_vec[2])* factors[2] });
            ugly_vec[k++] = ret;
            for (int i = 0; i < 3; ++i)
                if ((*iter_vec[i]) * factors[i] == ret)
                    iter_vec[i]++;
        }
        return ret;
    }
};