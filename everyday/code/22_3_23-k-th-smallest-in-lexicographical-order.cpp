/*

给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

 

示例 1:

输入: n = 13, k = 2
输出: 10
解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
示例 2:

输入: n = 1, k = 1
输出: 1
 

提示:

1 <= k <= n <= 109

链接：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order

    int n = 13, k = 2;
    Solution temp;
    int ret = temp.findKthNumber(n, k);
    cout << ret << endl;

*/

#include <algorithm>
using namespace std;

class Solution {
public:
    int getSteps(int curr, long long n) {
        long long first = curr;
        long long last = curr;
        int ret = 0;
        while (first <= n) {
            ret += min(n, last) - first + 1;
            first = first * 10;
            last = 10 * last + 9;
        }
        return ret;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k) {
            int steps = getSteps(curr, n);
            if (k >= steps) {
                curr++;
                k -= steps;
            }
            else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};