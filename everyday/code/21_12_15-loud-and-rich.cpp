/*

有一组 n 个人作为实验对象，从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。为了方便起见，我们将编号为 x 的人简称为 "person x "。

给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi 更有钱。另给你一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值。richer 中所给出的数据 逻辑自洽（也就是说，在 person x 比 person y 更有钱的同时，不会出现 person y 比 person x 更有钱的情况 ）。

现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。

 

示例 1：

输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
输出：[5,5,2,5,4,5,6,7]
解释：
answer[0] = 5，
person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
但是目前还不清楚他是否比 person 0 更有钱。
answer[7] = 7，
在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
最安静（有较低安静值 quiet[x]）的人是 person 7。
其他的答案也可以用类似的推理来解释。
示例 2：

输入：richer = [], quiet = [0]
输出：[0]
 
提示：

n == quiet.length
1 <= n <= 500
0 <= quiet[i] < n
quiet 的所有值 互不相同
0 <= richer.length <= n * (n - 1) / 2
0 <= ai, bi < n
ai != bi
richer 中的所有数对 互不相同

链接：https://leetcode-cn.com/problems/loud-and-rich

    vector<vector<int>> richer = { {1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3} };
    vector<int> quiet = { 3, 2, 5, 4, 6, 1, 7, 0 };
    Solution temp;
    vector<int> ret = temp.loudAndRich(richer, quiet);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>
#include <numeric>
using namespace std;

//class Solution {
//public:
//    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//        int len = quiet.size();
//        vector<vector<int>> edges(len);
//        queue<int> peo_queue;
//        vector<int> ret;
//        for (vector<int> index : richer)
//            edges[index[1]].emplace_back(index[0]);
//        for (int i = 0; i < len; ++i) {
//            peo_queue.emplace(i);
//            int people = i;
//            int min_quite = quiet[i];
//            vector<vector<int>> graph(edges);
//            while (!peo_queue.empty()) {
//                int front = peo_queue.front();
//                peo_queue.pop();
//                for (int index : graph[front]) {
//                    if (quiet[index] < min_quite)
//                        min_quite = quiet[index], people = index;
//                    peo_queue.emplace(index);
//                }
//                graph[i].clear();
//            }
//            ret.emplace_back(people);
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//        int len = quiet.size();
//        edges.resize(len);
//        visited.resize(len, vector<int>(len));
//        vector<int> ret;
//        for (vector<int> index : richer)
//            edges[index[1]].emplace_back(index[0]), visited[index[1]][index[0]] = 1;
//        for (int i = 0; i < len; ++i) {
//            int min_quite = quiet[i];
//            int people = i;
//            for (int j = 0; j < len; ++j)
//                if (dfs(i, j) && quiet[j] < min_quite)
//                    people = j, min_quite = quiet[j];
//            ret.emplace_back(people);
//        }
//        return ret;
//        
//    }
//
//    bool dfs(int start, int end) {
//        if (visited[start][end] == 1)
//            return true;
//        if (visited[start][end] == -1)
//            return false;
//        for (int index : edges[start])
//            if (dfs(index, end)) {
//                visited[start][end] = 1;
//                return true;
//            }
//        visited[start][end] = -1;
//        return false;
//    }
//
//private:
//    vector<vector<int>> edges;
//    vector<vector<int>> visited;
//};



//class Solution {
//public:
//    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//        int len = quiet.size();
//        vector<vector<bool>> dp(len, vector<bool>(len));
//        vector<int> ret;
//        for (vector<int> index : richer)
//            dp[index[1]][index[0]] = true;
//        for (int i = 0; i < len; ++i)
//            for (int j = 0; j < len; ++j)
//                for (int k = 0; k < len; ++k)
//                    dp[j][k] = dp[j][k] || (dp[j][i] && dp[i][k]);
//        for (int i = 0; i < len; ++i) {
//            int min_quiet = quiet[i];
//            int people = i;
//            for (int j = 0; j < len; ++j)
//                if (dp[i][j] && quiet[j] < min_quiet)
//                    min_quiet = quiet[j], people = j;
//            ret.emplace_back(people);
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//        int len = quiet.size();
//        vector<vector<int>> edges(len);
//        vector<int> ret(len, -1);
//        for (vector<int> index : richer)
//            edges[index[1]].emplace_back(index[0]);
//        function<void(int)> dfs = [&](int x) {
//            if (ret[x] != -1)
//                return;
//            ret[x] = x;
//            for (int index : edges[x]) {
//                dfs(index);
//                if (quiet[ret[index]] < quiet[ret[x]])
//                    ret[x] = ret[index];
//            }
//            return;
//        };
//        for (int i = 0; i < len; ++i)
//            dfs(i);
//        return ret;
//    }
//};


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int len = quiet.size();
        vector<vector<int>> edges(len);
        vector<int> into_nums(len);
        vector<int> ret(len);
        iota(ret.begin(), ret.end(), 0);
        for (vector<int> index : richer)
            edges[index[0]].emplace_back(index[1]), ++into_nums[index[1]];
        queue<int> queue;
        for (int i = 0; i < len; ++i) 
            if (into_nums[i] == 0)
                queue.emplace(i);
        while (!queue.empty()) {
            int x = queue.front();
            queue.pop();
            for (int index : edges[x]) {
                if (quiet[ret[x]] < quiet[ret[index]])
                    ret[index] = ret[x];
                if (--into_nums[index] == 0)
                    queue.emplace(index);
            }
        }
        return ret;
    }
};