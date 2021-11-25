﻿/*

给你一个整数数组 distance 。

从 X-Y 平面上的点 (0,0) 开始，先向北移动 distance[0] 米，然后向西移动 distance[1] 米，向南移动 distance[2] 米，向东移动 distance[3] 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。

判断你所经过的路径是否相交。如果相交，返回 true ；否则，返回 false 。

 

示例 1：


输入：distance = [2,1,1,2]
输出：true
示例 2：


输入：distance = [1,2,3,4]
输出：false
示例 3：


输入：distance = [1,1,1,1]
输出：true
 

提示：

1 <= distance.length <= 105
1 <= distance[i] <= 105

链接：https://leetcode-cn.com/problems/self-crossing

*/
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//class Solution {
//public:
//    bool isSelfCrossing(vector<int>& distance) {
//        int length = distance.size();
//        map<int, vector<vector<int>>> vertival_map;
//        map<int, vector<vector<int>>> horizontal_map;
//        vector<int> pre = { 0, 0, 0 };
//        pair<int, int> point = make_pair(0, 0);
//        for (int i = 0; i < length; ++i) {
//            vector<int> cur;
//            if (i % 4 == 0) {
//                cur = { point.first, point.second, point.second + distance[i] };
//                point.second += distance[i];
//            }
//            else if (i % 4 == 1) {
//                cur = { point.second, point.first - distance[i], point.first };
//                point.first -= distance[i];
//            }
//            else if (i % 4 == 2) {
//                cur = { point.first, point.second - distance[i], point.second };
//                point.second -= distance[i];
//            }
//            else{
//                cur = { point.second, point.first, point.first + distance[i] };
//                point.first += distance[i];
//            }
//            if (i % 2 == 0) {
//                map<int, vector<vector<int>>>::iterator iter = horizontal_map.begin();
//                while (iter != horizontal_map.end() && iter->first < cur[1])
//                    iter++;
//                while (iter != horizontal_map.end() && iter->first <= cur[2]) {
//                    for (auto index : iter->second)
//                        if (index[0] <= cur[0] && index[1] >= cur[0])
//                            return true;
//                    iter++;
//                }
//                if (horizontal_map.count(pre[0]))
//                    horizontal_map[pre[0]].push_back({pre[1], pre[2]});
//                else {
//                    vector<vector<int>> lines;
//                    lines.push_back({ pre[1], pre[2] });
//                    horizontal_map[pre[0]] = lines;
//                }
//                pre = cur;
//            }
//            else {
//                map<int, vector<vector<int>>>::iterator iter = vertival_map.begin();
//                while (iter != vertival_map.end() && iter->first < cur[1])
//                    iter++;
//                while (iter != vertival_map.end() && iter->first <= cur[2]) {
//                    for (auto index : iter->second)
//                        if (index[0] <= cur[0] && index[1] >= cur[0])
//                            return true;
//                    iter++;
//                }
//                if (vertival_map.count(pre[0]))
//                    vertival_map[pre[0]].push_back({ pre[1], pre[2] });
//                else {
//                    vector<vector<int>> lines;
//                    lines.push_back({ pre[1], pre[2] });
//                    vertival_map[pre[0]] = lines;
//                }
//                pre = cur;
//            }
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//	bool isSelfCrossing(vector<int>& distance) {
//		int n = distance.size();
//		for (int i = 3; i < n; ++i) {
//			if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
//				return true;
//			if (i == 4 && (distance[3] == distance[1]
//				&& distance[4] >= distance[2] - distance[0]))
//				return true;
//			if (i >= 5 && (distance[i - 3] - distance[i - 5] <= distance[i - 1]
//				&& distance[i - 1] <= distance[i - 3]
//				&& distance[i] >= distance[i - 2] - distance[i - 4]
//				&& distance[i - 2] > distance[i - 4]))
//				return true;
//		}
//		return false;
//	}
//};

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();

        // 处理第 1 种情况
        int i = 0;
        while (i < n && (i < 2 || distance[i] > distance[i - 2])) {
            ++i;
        }

        if (i == n) {
            return false;
        }

        // 处理第 j 次移动的情况
        if ((i == 3 && distance[i] == distance[i - 2])
            || (i >= 4 && distance[i] >= distance[i - 2] - distance[i - 4])) {
            distance[i - 1] -= distance[i - 3];
        }
        ++i;

        // 处理第 2 种情况
        while (i < n && distance[i] < distance[i - 2]) {
            ++i;
        }

        return i != n;
    }
};
