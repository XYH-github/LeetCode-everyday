/*

在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。

当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。

另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。

 

示例 1：


输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
输出：[1,0]
解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1] 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。

第 1 次查询检查 grid[1][0] 是否被照亮（蓝色方框）。该单元格没有被照亮，所以 ans[1] = 0 。然后，关闭红色矩形中的所有灯。

示例 2：

输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
输出：[1,1]
示例 3：

输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
输出：[1,1,0]
 

提示：

1 <= n <= 109
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
lamps[i].length == 2
0 <= rowi, coli < n
queries[j].length == 2
0 <= rowj, colj < n

链接：https://leetcode-cn.com/problems/grid-illumination

	int n = 5;
	vector<vector<int>> lamps = { {0, 0}, {0, 4} };
	vector<vector<int>> queries = { {0, 4}, {0, 1}, {1, 4} };
	Solution temp;
	vector<int> ret = temp.gridIllumination(n, lamps, queries);
	Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    const int direct[10] = { -1, 0, 0, 1, 0, -1, -1, 1, 1, -1 };
//    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
//        vector<vector<int>> vector_lamps(n, vector<int>(n, 0));
//        lamps.erase(unique(lamps.begin(), lamps.end()), lamps.end());
//        for (auto index : lamps) {
//            for (int i = 0; i < n; ++i) {
//                vector_lamps[index[0]][i] += 1;
//                vector_lamps[i][index[1]] += 1;
//            }
//            for (int i = 1; i < n; ++i) {
//                if (index[0] + i >= 0 && index[1] + i >= 0 &&
//                    index[0] + i < n && index[1] + i < n)
//                    vector_lamps[index[0] + i][index[1] + i] += 1;
//                if (index[0] + i >= 0 && index[1] - i >= 0 &&
//                    index[0] + i < n && index[1] - i < n)
//                    vector_lamps[index[0] + i][index[1] - i] += 1;
//                if (index[0] - i >= 0 && index[1] + i >= 0 &&
//                    index[0] - i < n && index[1] + i < n)
//                    vector_lamps[index[0] - i][index[1] + i] += 1;
//                if (index[0] - i >= 0 && index[1] - i >= 0 &&
//                    index[0] - i < n && index[1] - i < n)
//                    vector_lamps[index[0] - i][index[1] - i] += 1;
//            }
//            vector_lamps[index[0]][index[1]] -= 1;
//        }
//        vector<int> ret;
//        for (auto index1 : queries) {
//            if (vector_lamps[index1[0]][index1[1]] > 0)
//                ret.emplace_back(1);
//            else
//                ret.emplace_back(0);
//            for (int i = 0; i < 9; ++i)
//                if (index1[0] + direct[i] >= 0 && index1[1] + direct[i + 1] >= 0 &&
//                    index1[0] + direct[i] < n && index1[1] + direct[i + 1] < n) {
//                    int pos_x = index1[0] + direct[i];
//                    int pos_y = index1[1] + direct[i + 1];
//                    for (auto iter = lamps.begin(); iter != lamps.end();) {
//                        vector<int> index = *iter;
//                        if (index[0] == pos_x && index[1] == pos_y) {
//                            iter = lamps.erase(iter);
//                            for (int i = 0; i < n; ++i) {
//                                vector_lamps[index[0]][i] -= 1;
//                                vector_lamps[i][index[1]] -= 1;
//                            }
//                            for (int i = 1; i < n; ++i) {
//                                if (index[0] + i >= 0 && index[1] + i >= 0 &&
//                                    index[0] + i < n && index[1] + i < n)
//                                    vector_lamps[index[0] + i][index[1] + i] -= 1;
//                                if (index[0] + i >= 0 && index[1] - i >= 0 &&
//                                    index[0] + i < n && index[1] - i < n)
//                                    vector_lamps[index[0] + i][index[1] - i] -= 1;
//                                if (index[0] - i >= 0 && index[1] + i >= 0 &&
//                                    index[0] - i < n && index[1] + i < n)
//                                    vector_lamps[index[0] - i][index[1] + i] -= 1;
//                                if (index[0] - i >= 0 && index[1] - i >= 0 &&
//                                    index[0] - i < n && index[1] - i < n)
//                                    vector_lamps[index[0] - i][index[1] - i] -= 1;
//                            }
//                            vector_lamps[index[0]][index[1]] += 1;
//                        }
//                        else
//                            ++iter;
//                    }
//                }
//        }
//        return ret;
//    }
//};

//namespace std {
//    template <> struct hash<pair<int, int>> {
//        inline size_t operator() (const pair<int, int> v)const {
//            hash<int> h;
//            return (h(v.first) << 32) + h(v.second);
//        }
//    };
//}

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, diagonal, ant_diagonal;
        auto hash_p = [](const pair<int, int>& v) {
            hash<int> h;
            return (h(v.first) << 32) + h(v.second);
        };
        //unordered_set<pair<int, int>> points;
        unordered_set<pair<int, int>, decltype(hash_p)> points(0, hash_p);
        for (auto lamp : lamps) {
            if (points.count({ lamp[0], lamp[1] }) == 0) {
                points.emplace(lamp[0], lamp[1]);
                row[lamp[0]]++;
                col[lamp[1]]++;
                diagonal[lamp[0] - lamp[1]]++;
                ant_diagonal[lamp[0] + lamp[1]]++;
            }
        }
        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int r = queries[i][0], c = queries[i][1];
            if (row.count(r) > 0 && row[r] > 0) {
                ret[i] = 1;
            }
            else if (col.count(c) > 0 && col[c] > 0) {
                ret[i] = 1;
            }
            else if (diagonal.count(r - c) > 0 && diagonal[r - c] > 0) {
                ret[i] = 1;
            }
            else if (ant_diagonal.count(r + c) > 0 && ant_diagonal[r + c] > 0) {
                ret[i] = 1;
            }
            for(int x = r - 1; x <= r + 1; ++x)
                for (int y = c - 1; y <= c + 1; ++y) {
                    if (x < 0 || y < 0 || x >= n || y >= n)
                        continue;
                    auto p = points.find({x, y});
                    if (p != points.end()) {
                        points.erase(p);
                        row[x]--;
                        col[y]--;
                        diagonal[x - y]--;
                        ant_diagonal[x + y]--;
                    }
                }
        }
        return ret;
    }
};

