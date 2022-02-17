/*

你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为?m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
?

示例 1：

输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
示例 2：

输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
?

提示：

1 <= grid.length,?grid[i].length <= 15
0 <= grid[i][j] <= 100
最多 25 个单元格中有黄金。

链接：https://leetcode-cn.com/problems/path-with-maximum-gold

    vector<vector<int>> grid = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    Solution temp;
    int ret = temp.getMaximumGold(grid);
    cout << ret << endl;

*/
#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    const int direct[5] = { 0, 1, 0, -1, 0};
//    vector<vector<int>> grid;
//    int hight;
//    int width;
//    int temp_ret = 0;
//    int max_ret = INT_MIN;
//    int getMaximumGold(vector<vector<int>>& grid) {
//        this->grid = grid;
//        this->hight = grid.size();
//        this->width = grid[0].size();
//        int ret = INT_MIN;
//        for (int i = 0; i < hight; ++i)
//            for (int j = 0; j < width; ++j)
//                ret = max(ret, dfs(i, j));
//        return ret;
//    }
//    int dfs(int pos_x, int pos_y) {
//        if (pos_x < 0 || pos_x >= hight || pos_y >= width ||
//            pos_y < 0 || grid[pos_x][pos_y] == 0)
//            return temp_ret;
//        else {
//            temp_ret += grid[pos_x][pos_y];
//            int tmp = grid[pos_x][pos_y];
//            grid[pos_x][pos_y] = 0;
//            for (int i = 0; i < 4; ++i) {
//                int new_x = pos_x + direct[i];
//                int new_y = pos_y + direct[i + 1];
//                max_ret = max(max_ret, dfs(new_x, new_y));
//            }
//            temp_ret -= tmp;
//            grid[pos_x][pos_y] = tmp;
//            return max_ret;
//        }
//    }
//};

class Solution {
public:
    const int direct[5] = { 0, 1, 0, -1, 0 };
    int getMaximumGold(vector<vector<int>>& grid) {
        stack<vector<int>> stk;
        int hight = grid.size();
        int width = grid[0].size();
        int ret_temp = 0;
        int ret_max = 0;
        for (int i = 0; i < hight; ++i)
            for (int j = 0; j < width; ++j)
                if (grid[i][j] > 0)
                    stk.push({i, j, grid[i][j]});
        while (!stk.empty()) {
            vector<int> temp = stk.top();
            if (grid[temp[0]][temp[1]] == 0) {
                ret_max = max(ret_max, ret_temp);
                grid[temp[0]][temp[1]] = temp[2];
                ret_temp -= temp[2];
                stk.pop();
                continue;
            }
            ret_temp += temp[2];
            grid[temp[0]][temp[1]] = 0;
            for (int i = 0; i < 4; ++i) {
                int new_x = temp[0] + direct[i];
                int new_y = temp[1] + direct[i + 1];
                if (new_x >= 0 && new_x < hight && new_y >= 0 &&
                    new_y < width && grid[new_x][new_y] != 0)
                    stk.push({new_x, new_y, grid[new_x][new_y] });
            }
        }
        return ret_max;
    }
};