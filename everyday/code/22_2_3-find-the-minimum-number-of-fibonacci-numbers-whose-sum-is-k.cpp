/*

给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。

 

示例 1：

输入：k = 7
输出：2
解释：斐波那契数字为：1，1，2，3，5，8，13，……
对于 k = 7 ，我们可以得到 2 + 5 = 7 。
示例 2：

输入：k = 10
输出：2
解释：对于 k = 10 ，我们可以得到 2 + 8 = 10 。
示例 3：

输入：k = 19
输出：3
解释：对于 k = 19 ，我们可以得到 1 + 5 + 13 = 19 。
 

提示：

1 <= k <= 10^9

链接：https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k

    int k = 19;
    Solution temp;
    int ret = temp.findMinFibonacciNumbers(k);
    cout << ret << endl;

*/
#include <vector>
#include <iterator>
using namespace std;

//class Solution {
//public:
//    vector<int> fb;
//    int findMinFibonacciNumbers(int k) {
//        fb.emplace_back(1);
//        fb.emplace_back(1);
//        while (*prev(fb.end()) <= k)
//            fb.emplace_back(*prev(fb.end()) + *(prev(prev(fb.end()))));
//        return dfs(k);
//    }
//
//    int dfs(int cout) {
//        for (auto iter = fb.rbegin(); iter != fb.rend(); ++iter) {
//
//            if (*iter > cout)
//                continue;
//            else if (*iter == cout)
//                return 1;
//            else
//                return 1 + dfs(cout - *iter);
//        }
//    }
//};

class Solution {
public:
    vector<int> fb;
    int findMinFibonacciNumbers(int k) {
        fb.emplace_back(1);
        fb.emplace_back(1);
        while (*prev(fb.end()) <= k)
            fb.emplace_back(*prev(fb.end()) + *(prev(prev(fb.end()))));
        int ret = 0;
        while (k) {
            int left = 0;
            int right = fb.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2 + 1;
                if (fb[mid] <= k)
                    left = mid;
                else
                    right = mid - 1;
            }
            k -= fb[left];
            ret++;
        }
        return ret;
    }
};