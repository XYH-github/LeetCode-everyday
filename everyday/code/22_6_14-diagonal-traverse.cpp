/*

给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

 

示例 1：


输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,4,7,5,3,6,8,9]
示例 2：

输入：mat = [[1,2],[3,4]]
输出：[1,2,3,4]
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105

链接：https://leetcode.cn/problems/diagonal-traverse

    vector<vector<int>> mat = { {1,2,3},{4,5,6},{7,8,9} };
    Solution temp;
    vector<int> ret = temp.findDiagonalOrder(mat);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret;
        int len_m = mat.size();
        int len_n = mat[0].size();
        int len = len_m + len_n - 1;
        int i = 0;
        int start_x = 0, start_y = 0;
        int dir_up = -1, dir_right = 1;
        while (i < len) {
            ret.emplace_back(mat[start_x][start_y]);
            while (start_x + dir_up >= 0 && start_x + dir_up < len_m &&
                start_y + dir_right >= 0 && start_y + dir_right < len_n) {
                start_x += dir_up;
                start_y += dir_right;
                ret.emplace_back(mat[start_x][start_y]);
            }
            if (dir_up == -1 && start_y != len_n - 1) {
                start_y++;
            }
            else if (dir_up == -1 && start_y == len_n - 1) {
                start_x++;
            }
            else if (dir_up == 1 && start_x != len_m - 1) {
                start_x++;
            }
            else {
                start_y++;
            }
            dir_up = -dir_up;
            dir_right = -dir_right;
            ++i;
        }
        return ret;
    }
};