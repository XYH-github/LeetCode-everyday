﻿/*

你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。给你一个二维整数数组 properties ，其中 properties[i] = [attacki, defensei] 表示游戏中第 i 个角色的属性。

如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，那么 attackj > attacki 且 defensej > defensei 。

返回 弱角色 的数量。

 

示例 1：

输入：properties = [[5,5],[6,3],[3,6]]
输出：0
解释：不存在攻击和防御都严格高于其他角色的角色。
示例 2：

输入：properties = [[2,2],[3,3]]
输出：1
解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
示例 3：

输入：properties = [[1,5],[10,4],[4,3]]
输出：1
解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 

提示：

2 <= properties.length <= 105
properties[i].length == 2
1 <= attacki, defensei <= 105

链接：https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game

    Solution temp;
    vector<vector<int>> input_vector = { {1, 5}, { 10,4 }, { 4,3 }};
    int result = temp.numberOfWeakCharacters(input_vector);
    cout << result << endl;

*/

#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int numberOfWeakCharacters(vector<vector<int>>& properties) {
//        int ret = 0;
//        sort(properties.begin(), properties.end(), [&](const auto& x, const auto& y) {
//                return x[0] < y[0];
//            });
//        vector<int> cmp_temp = { INT_MAX, INT_MIN };
//        int max = INT_MIN;
//        for (auto iter = properties.rbegin(); iter != properties.rend(); ++iter) {
//            if ((*iter)[0] < cmp_temp[0])
//                max = cmp_temp[1];
//            if ((*iter)[1] > cmp_temp[1])
//                cmp_temp = (*iter);
//            else if ((*iter)[1] < cmp_temp[1])
//                if ((*iter)[0] < cmp_temp[0])
//                    ret++;
//                else if ((*iter)[1] < max)
//                    ret++;
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
            });

        int maxDef = 0;
        int ans = 0;
        for (auto& p : properties) {
            if (p[1] < maxDef) {
                ans++;
            }
            else {
                maxDef = p[1];
            }
        }
        return ans;
    }
};