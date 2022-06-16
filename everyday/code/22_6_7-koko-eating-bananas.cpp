﻿/*

珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。

 

示例 1：

输入：piles = [3,6,7,11], h = 8
输出：4
示例 2：

输入：piles = [30,11,23,4,20], h = 5
输出：30
示例 3：

输入：piles = [30,11,23,4,20], h = 6
输出：23
 

提示：

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

链接：https://leetcode.cn/problems/koko-eating-bananas

    vector<int> piles = { 312884470 };
    int h = 312884469;
    Solution temp;
    int ret = temp.minEatingSpeed(piles, h);
    cout << ret << endl;

*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int getHour(int rate) {
//        int ret = 0;
//        for (int pile : _vec) {
//            ret += (pile + rate - 1) / rate;
//        }
//        return ret;
//    }
//
//    int minEatingSpeed(vector<int>& piles, int h) {
//        _vec = piles;
//        int left = 1;
//        int right = *max_element(piles.begin(), piles.end());
//        while (left < right) {
//            int mid = left + ((right - left) >> 1);
//            int temp = getHour(mid);
//            if (temp > h)
//                left = mid + 1;
//            else
//                right = mid;
//        }
//        return left;
//    }
//private:
//    vector<int> _vec;
//};


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        vector<int> ret_vec(right - left + 1);
        int k = -1;
        for (int i = left; i <= right; ++i)
            ret_vec[++k] = i;

        //int ret = *lower_bound(ret_vec.begin(), ret_vec.end(), h, [&](const int b, const int h) {
        //    int ret_b = 0;
        //    for (int pile : piles) {
        //        ret_b += (pile + b - 1) / b;
        //    }
        //    return h < ret_b;
        //    });

         int ret = *upper_bound(ret_vec.begin(), ret_vec.end(), h, [&](const int h, const int b){
             long ret_b = 0;
             for (int pile : piles) {
                 ret_b += (long)(pile + b - 1) / b;
             }
             return h >= ret_b;
         });
        return ret;
    }
};

