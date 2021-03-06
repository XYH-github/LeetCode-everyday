/*
 
 
给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。

 

示例 1：

输入：
["Solution","pickIndex"]
[[[1]],[]]
输出：
[null,0]
解释：
Solution solution = new Solution([1]);
solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。
示例 2：

输入：
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
输出：
[null,1,1,1,1,0]
解释：
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。

由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
诸若此类。

    vector<int> w = {1, 3};
    Solution temp(w);
    cout << temp.pickIndex() << endl;
    cout << temp.pickIndex() << endl;
    cout << temp.pickIndex() << endl;

*/

#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

//class Solution {
//public:
//    //std::default_random_engine random{ time(NULL) };
//    //std::uniform_int_distribution<int> dis1{ 1, sum_vector };
//    int sum_vector;
//    vector<int> temp_list;
//    Solution(vector<int>& w) {
//        sum_vector = accumulate(w.begin(), w.end(), 0);
//        for (int i = 1; i < w.size(); ++i)
//            w[i] += w[i - 1];
//        temp_list = w;
//    }
//
//    int pickIndex() {
//        srand(time(0));
//        int temp = rand() % sum_vector + 1;
//        for (int i = 0; i < temp_list.size(); ++i)
//            if (temp <= temp_list[i])
//                return i;
//    }
//};


class Solution {
public:
    Solution(vector<int>& w) {
        srand((unsigned)time(NULL));
        int len = w.size();
        prefix_sum.resize(len + 1);
        for (int i = 1; i <= len; ++i)
            prefix_sum[i] = prefix_sum[i - 1] + w[i - 1];
        _len = prefix_sum[len];
    }

    int pickIndex() {
        int index = rand() % _len;
        // int left = 0;
        // int right = prefix_sum.size() - 1;
        // while(left < right){
        //     int mid = left + (right - left + 1) / 2;
        //     if (prefix_sum[mid] <= index)
        //         left = mid;
        //     else
        //         right = mid - 1;
        // }
        // return left;

        //return upper_bound(prefix_sum.begin(), prefix_sum.end(), index) - prefix_sum.begin() - 1;

        return prefix_sum.rend() - upper_bound(prefix_sum.rbegin(), prefix_sum.rend(), index, [&](const int val, const int mid) {
            return mid <= val;
            }) - 1;
    }

private:
    vector<int> prefix_sum;
    int _len;
};