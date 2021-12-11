/*

给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。

对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。

那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。

 
示例 1：

输入：arr = [1,2,3,5], k = 3
输出：[2,5]
解释：已构造好的分数,排序后如下所示:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3
很明显第三个最小的分数是 2/5
示例 2：

输入：arr = [1,7], k = 1
输出：[1,7]
 

提示：

2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 104
arr[0] == 1
arr[i] 是一个 素数 ，i > 0
arr 中的所有数字 互不相同 ，且按 严格递增 排序
1 <= k <= arr.length * (arr.length - 1) / 2

链接：https://leetcode-cn.com/problems/k-th-smallest-prime-fraction

vector<int> arr = { 1,2,3,5 };
    int k = 3;
    Solution temp;
    vector<int> result = temp.kthSmallestPrimeFraction(arr, k);
    Print<int>::PrintOneDemionVector(result);

*/
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//class Solution {
//public:
//    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//        int n = arr.size();
//        vector<pair<int, int>> frac;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                frac.emplace_back(arr[i], arr[j]);
//            }
//        }
//        sort(frac.begin(), frac.end(), [&](const auto& x, const auto& y) {
//            return x.first * y.second < x.second* y.first;
//            });
//        return { frac[k - 1].first, frac[k - 1].second };
//    }
//};


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[a.second] * arr[b.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue(cmp);
        for (int i = 0; i < arr.size() - 1; ++i)
            queue.emplace(i, arr.size() - 1);
        pair<int, int> poi;
        for (int i = 0; i < k; ++i) {
            poi = queue.top();
            queue.pop();
            if (poi.second - poi.first > 1)
                queue.emplace(poi.first, poi.second - 1);
        }
        return { arr[poi.first], arr[poi.second] };
    }
};
