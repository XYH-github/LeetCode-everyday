/*

在一个 106 x 106 的网格中，每个网格上方格的坐标为 (x, y) 。

现在从源方格 source = [sx, sy] 开始出发，意图赶往目标方格 target = [tx, ty] 。数组 blocked 是封锁的方格列表，其中每个 blocked[i] = [xi, yi] 表示坐标为 (xi, yi) 的方格是禁止通行的。

每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格 不 在给出的封锁列表 blocked 上。同时，不允许走出网格。

只有在可以通过一系列的移动从源方格 source 到达目标方格 target 时才返回 true。否则，返回 false。

 

示例 1：

输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
输出：false
解释：
从源方格无法到达目标方格，因为我们无法在网格中移动。
无法向北或者向东移动是因为方格禁止通行。
无法向南或者向西移动是因为不能走出网格。
示例 2：

输入：blocked = [], source = [0,0], target = [999999,999999]
输出：true
解释：
因为没有方格被封锁，所以一定可以到达目标方格。
 

提示：

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= xi, yi < 106
source.length == target.length == 2
0 <= sx, sy, tx, ty < 106
source != target
题目数据保证 source 和 target 不在封锁列表内

链接：https://leetcode-cn.com/problems/escape-a-large-maze

vector<vector<int>> blocked = { {1, 2503}, {3583, 515}, {1513, 15285} };
    vector<int> source = { 0, 0 }, target = { 999999, 999999 };
    Solution temp;
    bool result = temp.isEscapePossible(blocked, source, target);
    cout << result << endl;

*/
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//class Solution {
//private:
//    // 在包围圈中
//    static constexpr int BLOCKED = -1;
//    // 不在包围圈中
//    static constexpr int VALID = 0;
//    // 无论在不在包围圈中，但在n(n-1)/2步搜索中经过了target
//    static constexpr int FOUND = 1;
//
//    static constexpr int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//    static constexpr int BOUNDARY = 1000000;
//
//
//public:
//    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
//        if (blocked.size() < 2)
//            return true;
//        auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o)->size_t {
//            auto& x = o;
//            return fn((long long)x.first << 20 | x.second);
//        };
//        unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
//        for (const auto& pos : blocked)
//            hash_blocked.emplace(pos[0], pos[1]);
//
//        auto check = [&](vector<int>& start, vector<int>& finish)-> int {
//            int sx = start[0], sy = start[1];
//            int fx = finish[0], fy = finish[1];
//            int countdown = blocked.size() * (blocked.size() - 1) / 2;
//            queue<pair<int, int>> q;
//            q.emplace(sx, sy);
//            unordered_set<pair<int, int>, decltype(hash_fn)> visited(0, hash_fn);
//            visited.emplace(sx, sy);
//            while (!q.empty() && countdown > 0) {
//                auto x = q.front();
//                q.pop();
//                for (int d = 0; d < 4; ++d) {
//                    int nx = x.first + dirs[d][0], ny = x.second + dirs[d][1];
//                    if (nx >= 0 && nx < BOUNDARY && ny >= 0 && ny < BOUNDARY &&
//                        !hash_blocked.count({ nx, ny }) && !visited.count({ nx, ny })) {
//                        if (nx == fx && ny == fy)
//                            return FOUND;
//                        --countdown;
//                        q.emplace(nx, ny);
//                        visited.emplace(nx, ny);
//                    }
//                }
//            }
//            if (countdown > 0)
//                return BLOCKED;
//            return VALID;
//        };
//
//        int result = check(source, target);
//        if (result == FOUND)
//            return true;
//        else if (result == BLOCKED)
//            return false;
//        else {
//            result = check(target, source);
//            if (result == BLOCKED)
//                return false;
//            return true;
//        }
//    }
//};

class Solution {
private:
    static constexpr int BOUNDARY = 1000000;
    static constexpr int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() < 2) {
            return true;
        }
        vector<int> rows, columns;
        for (const auto& pos : blocked) {
            rows.push_back(pos[0]);
            columns.push_back(pos[1]);
        }
        rows.push_back(source[0]);
        rows.push_back(target[0]);
        columns.push_back(source[1]);
        columns.push_back(target[1]);

        sort(rows.begin(), rows.end());
        sort(columns.begin(), columns.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        columns.erase(unique(columns.begin(), columns.end()), columns.end());
        unordered_map<int, int> r_mapping, c_mapping;

        int r_id = (rows[0] == 0 ? 0 : 1);
        r_mapping[rows[0]] = r_id;
        for (int i = 1; i < rows.size(); ++i) {
            r_id += (rows[i] == rows[i - 1] + 1 ? 1 : 2);
            r_mapping[rows[i]] = r_id;
        }
        if (rows.back() != BOUNDARY - 1)
            ++r_id;

        int c_id = (columns[0] == 0 ? 0 : 1);
        c_mapping[columns[0]] = c_id;
        for (int i = 1; i < columns.size(); ++i) {
            c_id += (columns[i] == columns[i - 1] + 1 ? 1 : 2);
            c_mapping[columns[i]] = c_id;
        }
        if (columns.back() != BOUNDARY - 1) {
            ++c_id;
        }

        vector<vector<int>> grid(r_id + 1, vector<int>(c_id + 1));
        for (const auto& pos : blocked) {
            int x = pos[0], y = pos[1];
            grid[r_mapping[x]][c_mapping[y]] = 1;
        }

        int sx = r_mapping[source[0]], sy = c_mapping[source[1]];
        int tx = r_mapping[target[0]], ty = c_mapping[target[1]];

        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        grid[sx][sy] = 1;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x.first + dirs[d][0], ny = x.second + dirs[d][1];
                if (nx >= 0 && nx <= r_id && ny >= 0 && ny <= c_id && grid[nx][ny] != 1) {
                    if (nx == tx && ny == ty) {
                        return true;
                    }
                    q.emplace(nx, ny);
                    grid[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};
