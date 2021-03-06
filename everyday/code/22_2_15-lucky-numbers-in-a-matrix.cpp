/*

给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
 

示例 1：

输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
输出：[15]
解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 2：

输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
输出：[12]
解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 3：

输入：matrix = [[7,8],[1,2]]
输出：[7]
 

提示：

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5
矩阵中的所有元素都是不同的

链接：https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix

    vector<vector<int>> matrix = { {3,7,8},{9,11,13},{15,16,17} };
    Solution temp;
    vector<int> ret = temp.luckyNumbers(matrix);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> cnt(matrix.size(), 0);
        vector<int> pos;
        vector<int> ret;
        for (int i = 0; i < matrix[0].size(); ++i) {
            int max_col = 0;
            for (int j = 0; j < matrix.size(); ++j)
                if (max_col < matrix[j][i])
                    max_col = matrix[j][i], pos.clear(), pos.emplace_back(j);
                else if (max_col == matrix[j][i])
                    pos.emplace_back(j);
            for (auto index : pos) {
                if (cnt[index] == 0)
                    cnt[index] = *min_element(matrix[index].begin(), matrix[index].end());
                if (cnt[index] == max_col) {
                    ret.emplace_back(max_col);
                    break;
                }
            }
        }
        //ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};