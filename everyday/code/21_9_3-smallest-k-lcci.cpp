/*

设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))

链接：https://leetcode.cn/problems/smallest-k-lcci

    vector<int> arr = { 1, 3, 5, 7, 2, 4, 6, 8 };
    int k = 4;
    Solution temp;
    vector<int> ret = temp.smallestK(arr, k);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <time.h>
using namespace std;

//class Solution {
//public:
//    vector<int> smallestK(vector<int>& arr, int k) {
//        if (k == 0)
//            return {};
//        _vec = arr;
//        srand((unsigned)time(NULL));
//        dfs(0, arr.size() - 1, k);
//        return vector<int>(_vec.begin(), _vec.begin() + k);
//    }
//
//    void dfs(int left, int right, int k) {
//        int start = left;
//        int end = right;
//        int index = left + rand() % (right - left + 1);
//        swap(_vec[left], _vec[index]);
//        int cmp_val = _vec[left];
//        while (start < end) {
//            while (start < end && _vec[end] >= cmp_val)
//                --end;
//            _vec[start] = _vec[end];
//            while (start < end && _vec[start] <= cmp_val)
//                ++start;
//            _vec[end] = _vec[start];
//        }
//        _vec[start] = cmp_val;
//        if (start == k)
//            return;
//        if (start < k)
//            dfs(start + 1, right, k);
//        else
//            dfs(left, start - 1, k);
//    }
//
//
//private:
//    vector<int> _vec;
//};

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ret;
        _vec = arr;
        int len = _vec.size();
        buildHeap(len);
        int i = 1;
        while (k--) {
            ret.emplace_back(_vec[0]);
            swap(_vec[0], _vec[_vec.size() - i++]);
            adjustHeap(0, --len);
        }
        return ret;
    }

private:
    vector<int> _vec;

    void adjustHeap(int node, int len) {
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int min_pos = node;
        if (left < len && _vec[node] > _vec[left])
            min_pos = left;
        if (right < len && _vec[min_pos] > _vec[right])
            min_pos = right;
        if (min_pos != node) {
            swap(_vec[node], _vec[min_pos]);
            adjustHeap(min_pos, len);
        }
    }

    void buildHeap(int len) {
        for (int i = len / 2; i >= 0; --i)
            adjustHeap(i, len);
    }
};