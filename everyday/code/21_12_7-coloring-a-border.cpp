/*

给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color 。网格中的每个值表示该位置处的网格块的颜色。

当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一 连通分量 。

连通分量的边界 是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。

请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色，并返回最终的网格 grid 。

 

示例 1：

输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
输出：[[3,3],[3,2]]
示例 2：

输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
输出：[[1,3,3],[2,3,3]]
示例 3：

输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
输出：[[2,2,2],[2,1,2],[2,2,2]]
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j], color <= 1000
0 <= row < m
0 <= col < n

链接：https://leetcode-cn.com/problems/coloring-a-border

vector<vector<int>> grid = { {1, 1, 1},{1, 1, 1},{1, 1, 1} };
    int row = 1;
    int col = 1;
    int color = 2;
    Solution temp;
    vector<vector<int>> result = temp.colorBorder(grid, row, col, color);
    Print<int>::PrintTwoDemionVector(result);
*/
#include <vector>
#include <unordered_set>
using namespace std;

namespace std {
    template<> struct hash<pair<int, int>> {
        inline size_t operator()(const pair<int, int> v) const {
            hash<int> h;
            return (h(v.first) << 32) + h(v.second);
        }
    };
}

class Solution {
public:
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int height = grid.size();
        int width = grid[0].size();
        int cor = grid[row][col];
        area.insert(make_pair(row, col));
        findArea(row, col, cor, grid);
        for (auto index : area)
            grid[index.first][index.second] = color;
        return grid;
    }

    void findArea(int row, int col, int color, vector<vector<int>> grid) {
        bool flag = true;
        for (int i = 0; i < 4; ++i) {
            int row_now = row + direct[i];
            int col_now = col + direct[i + 1];
            if (row_now >= 0 && row_now < grid.size() && col_now >= 0 &&
                col_now < grid[0].size() && grid[row_now][col_now] == color) {
                if (!area.count(make_pair(row_now, col_now))) {
                    area.insert(make_pair(row_now, col_now));
                    findArea(row_now, col_now, color, grid);
                }
            }
            else
                flag = false;
        }
        if (flag)
            area.erase(make_pair(row, col));
    }
private:
    int direct[5] = { 0, 1, 0, -1, 0};
    unordered_set<pair<int, int>> area;
   
};