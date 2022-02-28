/*

Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize 张连续的牌组成。

给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true ；否则，返回 false 。

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
输出：true
解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], groupSize = 4
输出：false
解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
 

提示：

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length

链接：https://leetcode-cn.com/problems/hand-of-straights

    vector<int> hand = { 1, 2, 3, 6, 2, 3, 4, 7, 8 };
    int groupSize = 3;
    Solution temp;
    bool ret = temp.isNStraightHand(hand, groupSize);
    cout << ret << endl;

*/

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//class Solution {
//public:
//    bool isNStraightHand(vector<int>& hand, int groupSize) {
//        int len = hand.size();
//        if (len % groupSize)
//            return false;
//        sort(hand.begin(), hand.end());
//        while (hand.size()) {
//            auto iter = hand.begin();
//            int temp = *iter -1;
//            for (int i = 0; i < groupSize; ++i) {
//                while (iter != hand.end() && *(iter) != temp + 1)
//                    iter++;
//                if (iter == hand.end())
//                    return false;
//                temp++;
//                iter = hand.erase(iter);
//            }
//        }
//        return true;
//    }
//};


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();
        if (len % groupSize)
            return false;
        map<int, int> order_map;
        for (int han : hand)
            order_map[han]++;
        for (auto iter = order_map.begin(); iter != order_map.end(); ++iter) {
            if (iter->second == 0)
                continue;
            auto iter_temp = iter;
            iter_temp++;
            int num_temp = iter->first;
            int num_count = iter->second;
            iter->second = 0;
            for (int i = 1; i < groupSize; ++i) {
                if (iter_temp == order_map.end() || iter_temp->first != num_temp + 1)
                    return false;
                iter_temp->second -= num_count;
                if (iter_temp->second < 0)
                    return false;
                iter_temp++;
                num_temp++;
                while (iter_temp != order_map.end() && iter_temp->second == 0)
                    iter_temp++;
            }
        }
        return true;
        
    }
};