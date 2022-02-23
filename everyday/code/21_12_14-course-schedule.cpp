/*

你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

 

示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
示例 2：

输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 

提示：

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
prerequisites[i] 中的所有课程对 互不相同

链接：https://leetcode-cn.com/problems/course-schedule

链接：https://leetcode-cn.com/problems/course-schedule-ii/

    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1, 0},{2, 0},{3, 1},{3, 2} };
    Solution temp;
    vector<int> ret = temp.findOrder(numCourses, prerequisites);
    Print<int>::PrintOneDemionVector(ret);

    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1, 0},{2, 0},{3, 1},{3, 2} };
    Solution temp;
    bool ret = temp.canFinish(numCourses, prerequisites);
    cout << ret << endl;

*/

#include <vector>
#include <queue>
using namespace std;

//class Solution {
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        vector<vector<int>> edges(numCourses);
//        vector<int> into_nums(numCourses);
//        vector<int> ret;
//        queue<int> queue;
//        for (vector<int> index : prerequisites) {
//            edges[index[1]].emplace_back(index[0]);
//            into_nums[index[0]]++;
//        }
//        for (int i = 0; i < numCourses; ++i)
//            if (into_nums[i] == 0) 
//                queue.emplace(i);
//        while (!queue.empty()) {
//            int temp = queue.front();
//            queue.pop();
//            ret.emplace_back(temp);
//            for (int index : edges[temp])
//                if (--into_nums[index] == 0)
//                    queue.emplace(index);
//        }
//        if (ret.size() != numCourses)
//            return {};
//        else
//            return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        edges.resize(numCourses);
//        visited.resize(numCourses);
//        cool = false;
//        for (vector<int> index : prerequisites)
//            edges[index[1]].emplace_back(index[0]);
//        for (int i = 0; i < numCourses && !cool; ++i)
//            if (!visited[i])
//                dfs(i);
//        if (cool)
//            return {};
//        reverse(result.begin(), result.end());
//        return result;
//    }
//
//    void dfs(int node) {
//        if (visited[node] == -1 || cool) 
//            return;
//        if (visited[node] == 1) {
//            cool = true;
//            return;
//        }
//        visited[node] = 1;
//        for (int index : edges[node])
//            dfs(index);
//        visited[node] = -1;
//        result.emplace_back(node);
//    }
//
//private:
//    vector<vector<int>> edges;
//    vector<int> result;
//    vector<int> visited;
//    bool cool;
//};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        cool = false;
        for (vector<int> index : prerequisites)
            edges[index[1]].emplace_back(index[0]);
        for (int i = 0; i < numCourses && !cool; ++i)
            if (!visited[i])
                dfs(i);
        if (cool)
            return false;
        reverse(result.begin(), result.end());
        return true;
    }

    void dfs(int node) {
        if (visited[node] == -1 || cool)
            return;
        if (visited[node] == 1) {
            cool = true;
            return;
        }
        visited[node] = 1;
        for (int index : edges[node])
            dfs(index);
        visited[node] = -1;
        result.emplace_back(node);
    }

private:
    vector<vector<int>> edges;
    vector<int> result;
    vector<int> visited;
    bool cool;
};