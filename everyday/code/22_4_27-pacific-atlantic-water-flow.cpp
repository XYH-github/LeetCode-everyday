/*

有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。

 

示例 1：



输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
示例 2：

输入: heights = [[2,1],[1,2]]
输出: [[0,0],[0,1],[1,0],[1,1]]
 

提示：

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

链接：https://leetcode.cn/problems/pacific-atlantic-water-flow

    vector<vector<int>> heights = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
    Solution temp;
    vector<vector<int>> ret = temp.pacificAtlantic(heights);
    Print<int>::PrintTwoDemionVector(ret);

*/

#include <vector>
using namespace std;

class Solution {
public:
    const int direction[5] = { 0, 1, 0, -1, 0 };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ret;
        _len_m = heights.size();
        _len_n = heights[0].size();
        _heights = heights;
        _visited.resize(_len_m, vector<int>(_len_n));
        for (int i = 0; i < _len_m; ++i)
            dfs(i, 0);
        for (int i = 1; i < _len_n; ++i)
            dfs(0, i);
        for (int i = 0; i < _len_m; ++i)
            dfs2(i, _len_n - 1);
        for (int i = 0; i < _len_n; ++i)
            dfs2(_len_m - 1, i);
        for (int i = 0; i < _len_m; ++i)
            for (int j = 0; j < _len_n; ++j)
                if (_visited[i][j] == 3)
                    ret.emplace_back(vector<int>{ i,j });
        return ret;
    }

    void dfs(int pos_x, int pos_y) {
        if (_visited[pos_x][pos_y] == 1)
            return;
        _visited[pos_x][pos_y] = 1;
        for (int j = 0; j < 4; ++j) {
            int new_x = pos_x + direction[j];
            int new_y = pos_y + direction[j + 1];
            if (new_x >= 0 && new_x < _len_m && new_y >= 0 && new_y < _len_n &&
                _heights[pos_x][pos_y] <= _heights[new_x][new_y]) {
                dfs(new_x, new_y);
            }
        }
    }

    void dfs2(int pos_x, int pos_y) {
        if (_visited[pos_x][pos_y] == 2 || _visited[pos_x][pos_y] == 3)
            return;
        if (_visited[pos_x][pos_y] == 1)
            _visited[pos_x][pos_y] = 3;
        else
            _visited[pos_x][pos_y] = 2;
        for (int j = 0; j < 4; ++j) {
            int new_x = pos_x + direction[j];
            int new_y = pos_y + direction[j + 1];
            if (new_x >= 0 && new_x < _len_m && new_y >= 0 && new_y < _len_n &&
                _heights[pos_x][pos_y] <= _heights[new_x][new_y]) {
                dfs2(new_x, new_y);
            }
        }
    }

private:
    vector<vector<int>> _heights;
    vector<vector<int>> _visited;
    int _len_m, _len_n;
};