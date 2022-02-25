/*

用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。

将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。
在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。

 

示例 1：



输入：grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
输出：[1,-1,-1,-1,-1]
解释：示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
示例 2：

输入：grid = [[-1]]
输出：[-1]
解释：球被卡在箱子左侧边上。
示例 3：

输入：grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
输出：[0,1,2,3,4,-1]
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] 为 1 或 -1

链接：https://leetcode-cn.com/problems/where-will-the-ball-fall

    vector<vector<int>> grid = { {1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1} };
    Solution temp;
    vector<int> ret = temp.findBall(grid);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <functional>
using namespace std;

//class Solution {
//public:
//    vector<int> findBall(vector<vector<int>>& grid) {
//        int len_m = grid.size();
//        int len_n = grid[0].size();
//        vector<int> ret(len_n);
//        vector<vector<int>> ret_vec(len_m + 1, vector<int>(len_n, -2));
//        for (int i = 0; i < len_n; ++i)
//            ret_vec[grid.size()][i] = i;
//        function<int(int, int)> dfs = [&](int x, int y) {
//            if (ret_vec[x][y] > -2)
//                return ret_vec[x][y];
//            if (grid[x][y] == 1) {
//                if (y + 1 >= len_n || grid[x][y + 1] == -1) {
//                    ret_vec[x][y] = -1;
//                    return -1;
//                }
//                else if (grid[x][y + 1] == 1) {
//                    ret_vec[x][y] = dfs(x + 1, y + 1);
//                    return  ret_vec[x][y];
//                }
//            }
//            else {
//                if (y - 1 < 0 || grid[x][y - 1] == 1) {
//                    ret_vec[x][y] = -1;
//                    return -1;
//                }
//                else if (grid[x][y - 1] == -1) {
//                    ret_vec[x][y] = dfs(x + 1, y - 1);
//                    return  ret_vec[x][y];
//                }
//            } 
//            return -1;
//        };
//        
//        for (int i = 0; i < len_n; ++i) {
//            ret[i] = dfs(0, i);
//        }
//        return ret;
//    }
//};


class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            int col = j; // 球的初始列
            for (auto& row : grid) {
                int dir = row[col];
                col += dir; // 移动球
                if (col < 0 || col == n || row[col] != dir) { // 到达侧边或 V 形
                    col = -1;
                    break;
                }
            }
            ans[j] = col; // col >= 0 为成功到达底部
        }
        return ans;
    }
};
