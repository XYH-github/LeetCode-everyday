/*

你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

0 表示障碍，无法触碰
1 表示地面，可以行走
比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

 

示例 1：


输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
输出：6
解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
示例 2：


输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
输出：-1
解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
示例 3：

输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
输出：6
解释：可以按与示例 1 相同的路径来砍掉所有的树。
(0,0) 位置的树，可以直接砍去，不用算步数。
 

提示：

m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109

链接：https://leetcode.cn/problems/cut-off-trees-for-golf-event

    vector<vector<int>> forest = {{63750247,40643210,95516857,89928134,66334829,58741187,76532780,45104329},{3219401,97566322,9135413,75944198,93735601,33923288,50116695,83660397},{64460750,53045740,31903386,78155821,90848739,38769489,99349027,85982891},{30628785,51077683,70534803,67460877,91077770,74197235,5696362,91459886},{56105195,82479378,45937951,52817583,2768114,43329099,28189138,21418604}};
    Solution temp;
    int ret = temp.cutOffTree(forest);
    cout << ret << endl;

*/

#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

//class Solution {
//public:
//    int len_m;
//    int len_n;
//    vector<vector<int>> edges;
//    const int direction[5] = {1, 0, -1, 0, 1};
//    int cutOffTree(vector<vector<int>>& forest) {
//        edges = forest;
//        len_m = edges.size();
//        len_n = edges[0].size();
//        int ret = 0;
//        vector<pair<int, pair<int, int>>> pos_vec;
//        for (int i = 0; i < len_m; ++i) {
//            for (int j = 0; j < len_n; ++j) {
//                if (edges[i][j] > 1)
//                    pos_vec.emplace_back(edges[i][j], make_pair(i, j));
//            }
//        }
//        sort(pos_vec.begin(), pos_vec.end());
//        int len = pos_vec.size();
//        pair<int, int> pre = {0, 0};
//        for (int i = 0; i < len; ++i) {
//            int temp = bfs(pre, pos_vec[i].second);
//            if (temp == -1)
//                return -1;
//            ret += temp;
//            pre = pos_vec[i].second;
//        }
//        return ret;
//    }
//
//    int bfs(pair<int, int> start, pair<int, int> end) {
//        if (start == end)
//            return 0;
//        int step = 1;
//        queue<pair<int, int>> que;
//        vector<vector<bool>> visited(len_m, vector<bool>(len_n));
//        que.emplace(start.first, start.second);
//        visited[start.first][start.second] = true;
//        int nums = 1;
//        while (!que.empty()) {
//            nums--;
//            auto front = que.front();
//            que.pop();
//            for (int i = 0; i < 4; ++i) {
//                int new_x = front.first + direction[i];
//                int new_y = front.second + direction[i + 1];
//                if (new_x >= 0 && new_x < len_m && new_y >= 0 && new_y < len_n && 
//                    !visited[new_x][new_y] && edges[new_x][new_y] > 0) {
//                    if (new_x == end.first && new_y == end.second) {
//                        return step;
//                    }
//                    que.emplace(new_x, new_y);
//                    visited[new_x][new_y] = true;
//                }
//            }
//            if (nums == 0) {
//                nums = que.size();
//                step++;
//            }
//        }
//        return -1;
//    }
//};

//class Solution {
//public:
//    int len_m;
//    int len_n;
//    vector<vector<int>> edges;
//    const int direction[5] = { 1, 0, -1, 0, 1 };
//    int cutOffTree(vector<vector<int>>& forest) {
//        edges = forest;
//        len_m = edges.size();
//        len_n = edges[0].size();
//        int ret = 0;
//        vector<pair<int, int>> pos_vec;
//        for (int i = 0; i < len_m; ++i) {
//            for (int j = 0; j < len_n; ++j) {
//                if (edges[i][j] > 1)
//                    pos_vec.emplace_back(edges[i][j], i * len_n + j);
//            }
//        }
//        sort(pos_vec.begin(), pos_vec.end());
//        int len = pos_vec.size();
//        int pre = 0;
//        for (int i = 0; i < len; ++i) {
//            int temp = bfs(pre, pos_vec[i].second);
//            if (temp == -1)
//                return -1;
//            ret += temp;
//            pre = pos_vec[i].second;
//        }
//        return ret;
//    }
//
//    int bfs(int start, int end) {
//        if (start == end)
//            return 0;
//        int step = 1;
//        queue<int> que;
//        vector<vector<bool>> visited(len_m, vector<bool>(len_n));
//        que.emplace(start);
//        visited[start / len_n][start % len_n] = true;
//        int nums = 1;
//        while (!que.empty()) {
//            nums--;
//            auto front = que.front();
//            que.pop();
//            for (int i = 0; i < 4; ++i) {
//                int new_x = front / len_n + direction[i];
//                int new_y = front % len_n + direction[i + 1];
//                if (new_x >= 0 && new_x < len_m && new_y >= 0 && new_y < len_n &&
//                    !visited[new_x][new_y] && edges[new_x][new_y] > 0) {
//                    if (new_x * len_n + new_y == end) {
//                        return step;
//                    }
//                    que.emplace(new_x * len_n + new_y);
//                    visited[new_x][new_y] = true;
//                }
//            }
//            if (nums == 0) {
//                nums = que.size();
//                step++;
//            }
//        }
//        return -1;
//    }
//};


//class Solution {
//public:
//    int len_m;
//    int len_n;
//    vector<vector<int>> edges;
//    const int direction[5] = { 1, 0, -1, 0, 1 };
//    int cutOffTree(vector<vector<int>>& forest) {
//        edges = forest;
//        len_m = edges.size();
//        len_n = edges[0].size();
//        int ret = 0;
//        vector<pair<int, int>> pos_vec;
//        for (int i = 0; i < len_m; ++i) {
//            for (int j = 0; j < len_n; ++j) {
//                if (edges[i][j] > 1)
//                    pos_vec.emplace_back(edges[i][j], i * len_n + j);
//            }
//        }
//        sort(pos_vec.begin(), pos_vec.end());
//        int len = pos_vec.size();
//        int pre = 0;
//        for (int i = 0; i < len; ++i) {
//            int temp = bfs(pre, pos_vec[i].second);
//            if (temp == -1)
//                return -1;
//            ret += temp;
//            pre = pos_vec[i].second;
//        }
//        return ret;
//    }
//
//    int bfs(int start, int end) {
//        if (start == end)
//            return 0;
//        int step = 1;
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prio_que;
//        vector<vector<bool>> visited(len_m, vector<bool>(len_n));
//        prio_que.emplace(0, start);
//        visited[start / len_n][start % len_n] = true;
//        while (!prio_que.empty()) {
//            auto front = prio_que.top();
//            prio_que.pop();
//            int dist = front.first;
//            int loc = front.second;
//            for (int i = 0; i < 4; ++i) {
//                int new_x = loc / len_n + direction[i];
//                int new_y = loc % len_n + direction[i + 1];
//                if (new_x >= 0 && new_x < len_m && new_y >= 0 && new_y < len_n &&
//                    !visited[new_x][new_y] && edges[new_x][new_y] > 0) {
//                    if (new_x * len_n + new_y == end) {
//                        return dist + 1;
//                    }
//                    prio_que.emplace(dist + 1, new_x * len_n + new_y);
//                    visited[new_x][new_y] = true;
//                }
//            }
//        }
//        return -1;
//    }
//};



class Solution {
public:
    int len_m;
    int len_n;
    vector<vector<int>> edges;
    const int direction[5] = { 1, 0, -1, 0, 1 };
    int cutOffTree(vector<vector<int>>& forest) {
        edges = forest;
        len_m = edges.size();
        len_n = edges[0].size();
        int ret = 0;
        vector<pair<int, int>> pos_vec;
        for (int i = 0; i < len_m; ++i) {
            for (int j = 0; j < len_n; ++j) {
                if (edges[i][j] > 1)
                    pos_vec.emplace_back(edges[i][j], i * len_n + j);
            }
        }
        sort(pos_vec.begin(), pos_vec.end());
        int len = pos_vec.size();
        int pre = 0;
        for (int i = 0; i < len; ++i) {
            int temp = bfs(pre, pos_vec[i].second);
            if (temp == -1)
                return -1;
            ret += temp;
            pre = pos_vec[i].second;
        }
        return ret;
    }

    int bfs(int start, int end) {
        if (start == end)
            return 0;
        int step = 1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> prio_que;
        vector<vector<int>> costed(len_m, vector<int>(len_n, INT_MAX));
        costed[start / len_n][start % len_n] = abs(start / len_n - end / len_n) + abs(start % len_n - end % len_n);
        prio_que.emplace(costed[start / len_n][start % len_n], 0, start);
        while (!prio_que.empty()) {
            auto front = prio_que.top();
            prio_que.pop();
            int cost = get<0>(front);
            int dist = get<1>(front);
            int loc = get<2>(front);
            for (int i = 0; i < 4; ++i) {
                int new_x = loc / len_n + direction[i];
                int new_y = loc % len_n + direction[i + 1];
                if (new_x >= 0 && new_x < len_m && new_y >= 0 && new_y < len_n &&
                    edges[new_x][new_y] > 0) {
                    if (new_x * len_n + new_y == end) {
                        return dist + 1;
                    }
                    int ncost = dist + 1 + abs(new_x - end / len_n) + abs(new_y - end % len_n);
                    if (ncost < costed[new_x][new_y]) {
                        prio_que.emplace(ncost, dist + 1, new_x * len_n + new_y);
                        costed[new_x][new_y] = ncost;
                    }
                }
            }
        }
        return -1;
    }
};