/*

给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。

 

示例 1：


输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
输出：3
解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
示例 2：


输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
输出：0
解释：所有 1 都在边界上或可以到达边界。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] 的值为 0 或 1

链接：https://leetcode-cn.com/problems/number-of-enclaves

    vector<vector<int>> grid = { {0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0} };
    Solution temp;
    int ret = temp.numEnclaves(grid);
    cout << ret << endl;

*/

#include <vector>
#include <queue>
using namespace std;

//class Solution {
//public:
//    const int direct[5] = { 0, 1, 0, -1, 0};
//    int numEnclaves(vector<vector<int>>& grid) {
//        this->grid_ = grid;
//        len_m_ = grid_.size();
//        len_n_ = grid_[0].size();
//        int ret = 0;
//        for (int i = 0; i < len_m_; ++i)
//            dfs(i, 0), dfs(i, len_n_ - 1);
//        for (int i = 1; i < len_n_ - 1; ++i)
//            dfs(0, i), dfs(len_m_ - 1, i);
//        for (int i = 0; i < len_m_; ++i)
//            for (int j = 0; j < len_n_; ++j)
//                if (grid_[i][j])
//                    ++ret;
//        return ret;
//    }
//    void dfs(int pos_x, int pos_y) {
//        if (grid_[pos_x][pos_y] == 0)
//            return;
//        grid_[pos_x][pos_y] = 0;
//
//        for (int i = 0; i < 4; ++i) {
//            int new_x = pos_x + direct[i];
//            int new_y = pos_y + direct[i + 1];
//            if (new_x >= 0 && new_x < len_m_ &&
//                new_y >= 0 && new_y < len_n_)
//                dfs(new_x, new_y);
//        }
//    }
//    
//private:
//    vector<vector<int>> grid_;
//    int len_m_;
//    int len_n_;
//};


class Solution {
public:
    const int direct[5] = { 0, 1, 0, -1, 0 };
    int numEnclaves(vector<vector<int>>& grid) {
        int ret = 0;
        int len_m = grid.size();
        int len_n = grid[0].size();
        queue<pair<int, int>> pos_queue;
        for (int i = 0; i < len_m; ++i) {
            if (grid[i][0])
                grid[i][0] = 0, pos_queue.emplace(i, 0);
            if (grid[i][len_n - 1])
                grid[i][len_n - 1] = 0, pos_queue.emplace(i, len_n - 1);
        }
        for (int i = 0; i < len_n; ++i) {
            if (grid[0][i])
                grid[0][i] = 0, pos_queue.emplace(0, i);
            if (grid[len_m - 1][i])
                grid[len_m - 1][i] = 0, pos_queue.emplace(len_m - 1, i);
        }
        while (!pos_queue.empty()) {
            auto pos_front = pos_queue.front();
            pos_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int new_x = pos_front.first + direct[i];
                int new_y = pos_front.second + direct[i + 1];
                if (new_x >= 0 && new_x < len_m &&
                    new_y >= 0 && new_y < len_n)
                    if (grid[new_x][new_y] == 1)
                        grid[new_x][new_y] = 0, pos_queue.emplace(new_x, new_y);
            }
        }
        for (int i = 0; i < len_m; ++i)
            for (int j = 0; j < len_n; ++j)
                if (grid[i][j])
                    ++ret;
        return ret;
    }
};