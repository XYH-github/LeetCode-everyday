﻿/*

给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。

 

示例 1：



输入：isWater = [[0,1],[0,0]]
输出：[[1,0],[2,1]]
解释：上图展示了给各个格子安排的高度。
蓝色格子是水域格，绿色格子是陆地格。
示例 2：



输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
输出：[[1,1,0],[0,1,1],[1,2,2]]
解释：所有安排方案中，最高可行高度为 2 。
任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
 

提示：

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] 要么是 0 ，要么是 1 。
至少有 1 个水域格子。

链接：https://leetcode-cn.com/problems/map-of-highest-peak

    vector<vector<int>> isWater = { {0,0,1},{1,0,0},{0,0,0} };
    Solution temp;
    vector<vector<int>> result = temp.highestPeak(isWater);
    Print<int>::PrintTwoDemionVector(result);

*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    const int direction[5] = { 0, 1, 0, -1, 0 };
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int higth = isWater.size();
        int width = isWater[0].size();
        queue<pair<int, int>> point_queue;
        vector<vector<int>> ans(higth, vector<int>(width, -1));
        for (int i = 0; i < higth; ++i)
            for (int j = 0; j < width; ++j)
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    point_queue.emplace(i, j);
                }
        while (!point_queue.empty()) {
            auto point = point_queue.front();
            point_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int poi_x = point.first + direction[i];
                int poi_y = point.second + direction[i + 1];
                if (poi_x >= 0 && poi_x < higth && poi_y >= 0 && poi_y < width && ans[poi_x][poi_y] == -1) {
                    ans[poi_x][poi_y] = ans[point.first][point.second] + 1;
                    point_queue.emplace(poi_x, poi_y);
                }
            }
        }
        return ans;
    }
};