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

*/

#include <vector>
using namespace std;

class Solution {
public:
    const int direct[5] = { 0, 1, 0, -1, 0};
    int numEnclaves(vector<vector<int>>& grid) {
        this->grid_ = grid;
        int m = grid_.size();
        int n = grid_[0].size();
        for (int i = 0; i < m; ++i)
            grid_[0][n - 1] = 2;
        for (int i = 1; i < n - 1; ++i)
            grid_[m - 1][0] = 2;

    }
    int dfs(int pos_x, int pos_y) {
        for (int i = 0; i < 4; ++i) {
            int new_x = pos_x + direct[i];
            int new_y = pos_y + direct[i + 1];
            if (new_x)
            if (grid_[new_x][new_y] == 2)
                return 2;
            else if (grid_[new_x][new_y] == -1)
                return -1;
        }
        for (int i = 0; i < 4; ++i) {
            int new_x = pos_x + direct[i];
            int new_y = pos_y + direct[i + 1];
            if (grid_[new_x][new_y] == 1)
                return dfs(new_x, new_x);
        }
        return -1;
    }
private:
    vector<vector<int>> grid_;
};