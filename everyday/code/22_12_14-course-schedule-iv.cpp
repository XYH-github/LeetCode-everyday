/*

你总共需要上 n 门课，课程编号依次为 0 到 n-1 。

有的课会有直接的先修课程，比如如果想上课程 0 ，你必须先上课程 1 ，那么会以 [1,0] 数对的形式给出先修课程数对。

给你课程总数 n 和一个直接先修课程数对列表 prerequisite 和一个查询对列表 queries 。

对于每个查询对 queries[i] ，请判断 queries[i][0] 是否是 queries[i][1] 的先修课程。

请返回一个布尔值列表，列表中每个元素依次分别对应 queries 每个查询对的判断结果。

注意：如果课程 a 是课程 b 的先修课程且课程 b 是课程 c 的先修课程，那么课程 a 也是课程 c 的先修课程。

 

示例 1：



输入：n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
输出：[false,true]
解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
示例 2：

输入：n = 2, prerequisites = [], queries = [[1,0],[0,1]]
输出：[false,false]
解释：没有先修课程对，所以每门课程之间是独立的。
示例 3：



输入：n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
输出：[true,true]
示例 4：

输入：n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
输出：[false,true]
示例 5：

输入：n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
输出：[true,false,true,false]
 

提示：

2 <= n <= 100
0 <= prerequisite.length <= (n * (n - 1) / 2)
0 <= prerequisite[i][0], prerequisite[i][1] < n
prerequisite[i][0] != prerequisite[i][1]
先修课程图中没有环。
先修课程图中没有重复的边。
1 <= queries.length <= 10^4
queries[i][0] != queries[i][1]

链接：https://leetcode-cn.com/problems/course-schedule-iv

    int n = 7;
    vector<vector<int>> prerequisites = {{2, 3}, {2, 1}, {2, 0}, {3, 4}, {3, 6}, {5, 1}, {5, 0}, {1, 4}, {1, 0}, {4, 0}, {0, 6}}, queries = {{3,0},{6,4},{5,6},{2,6},{2,3},{5,6},{4,0},{2,6},{3,5},{5,3},{1,6},{1,0},{3,5},{6,5},{2,3},{3,0},{3,4},{3,4},{2,5},{0,3},{4,0},{6,4},{5,0},{6,5},{5,6},{6,5},{1,0},{3,4},{1,5},{1,4},{3,6},{0,1},{1,2},{5,1},{5,3},{5,3},{3,4},{5,4},{5,4},{5,3}};
    Solution temp;
    vector<bool> ret = temp.checkIfPrerequisite(n, prerequisites, queries);
    Print<bool>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <queue>
#include <set>
using namespace std;


//class Solution {
//public:
//    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//        vector<bool> result(queries.size());
//        vector<vector<int>> edges(numCourses);
//        vector<int> into_nums(numCourses);
//        queue<int> queue;
//        vector<set<int>> set(numCourses);
//      
//        for (vector<int> index : prerequisites) {
//            edges[index[0]].emplace_back(index[1]);
//            into_nums[index[1]]++;
//        }
//        for (int i = 0; i < numCourses; ++i)
//            if (!into_nums[i])
//                queue.emplace(i);
//        while (!queue.empty()) {
//            int front = queue.front();
//            queue.pop();
//            for (int index : edges[front]) {
//                set[index].insert(set[front].begin(), set[front].end());
//                set[index].insert(front);
//                if (--into_nums[index] == 0)
//                    queue.emplace(index);
//            }
//        }
//        
//        for (int i = 0; i < queries.size(); ++i)
//            if (set[queries[i][1]].find(queries[i][0]) != set[queries[i][1]].end())
//                result[i] = true;
//        return result;
//    }
//};



//class Solution {
//public:
//    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//        match = vector<vector<int>>(numCourses, vector<int>(numCourses, false));
//        edges.resize(numCourses);
//        vector<bool> ret;
//        for (vector<int> index : prerequisites) {
//            edges[index[0]].emplace_back(index[1]);
//            match[index[0]][index[1]] = 1;
//        }
//        for (vector<int> index : queries)
//            ret.emplace_back(dfs(index[0], index[1]));
//        return ret;
//    }
//
//    bool dfs(int first, int second) {
//        if (match[first][second] == 1)
//            return true;
//        if (match[first][second] == -1)
//            return false;
//        for (int node : edges[first])
//            if (dfs(node, second)) {
//                match[first][second] = 1;
//                return true;
//            }
//        match[first][second] = -1;
//        return false;
//    }
//
//private:
//    vector<vector<int>> match;
//    vector<vector<int>> edges;
//};


//class Solution {
//public:
//    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//        vector<vector<int>> edges(numCourses);
//        vector<vector<bool>> match(numCourses, vector<bool>(numCourses));
//        vector<bool> ret;
//        queue<int> queue;
//        for (vector<int> index : prerequisites)
//            edges[index[0]].emplace_back(index[1]);
//        for (int i = 0; i < numCourses; ++i) {
//            queue.emplace(i);
//            while (!queue.empty()) {
//                int front = queue.front();
//                queue.pop();
//                for (int index : edges[front]) {
//                    if (!match[i][index]) {
//                        match[i][index] = true;
//                        queue.emplace(index);
//                    }
//                }
//            }
//        }
//        for (vector<int> index : queries)
//            ret.emplace_back(match[index[0]][index[1]]);
//        return ret;
//    }
//};


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> match(numCourses, vector<bool>(numCourses));
        vector<bool> ret;
        for (vector<int> index : prerequisites)
            match[index[0]][index[1]] = true;
        for (int i = 0; i < numCourses; ++i)
            for (int j = 0; j < numCourses; ++j)
                for (int k = 0; k < numCourses; ++k)
                    match[j][k] = match[j][k] || (match[j][i] && match[i][k]);
        for (vector<int> index : queries)
            ret.emplace_back(match[index[0]][index[1]]);
        return ret;
    }
};
