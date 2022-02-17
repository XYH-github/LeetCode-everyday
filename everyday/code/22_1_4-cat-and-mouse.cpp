﻿/*

两位玩家分别扮演猫和老鼠，在一张 无向 图上进行游戏，两人轮流行动。

图的形式是：graph[a] 是一个列表，由满足 ab 是图中的一条边的所有节点 b 组成。

老鼠从节点 1 开始，第一个出发；猫从节点 2 开始，第二个出发。在节点 0 处有一个洞。

在每个玩家的行动中，他们 必须 沿着图中与所在当前位置连通的一条边移动。例如，如果老鼠在节点 1 ，那么它必须移动到 graph[1] 中的任一节点。

此外，猫无法移动到洞中（节点 0）。

然后，游戏在出现以下三种情形之一时结束：

如果猫和老鼠出现在同一个节点，猫获胜。
如果老鼠到达洞中，老鼠获胜。
如果某一位置重复出现（即，玩家的位置和移动顺序都与上一次行动相同），游戏平局。
给你一张图 graph ，并假设两位玩家都都以最佳状态参与游戏：

如果老鼠获胜，则返回 1；
如果猫获胜，则返回 2；
如果平局，则返回 0 。
 
示例 1：


输入：graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
输出：0
示例 2：


输入：graph = [[1,3],[0],[3],[0,2]]
输出：1
 

提示：

3 <= graph.length <= 50
1 <= graph[i].length < graph.length
0 <= graph[i][j] < graph.length
graph[i][j] != i
graph[i] 互不相同
猫和老鼠在游戏中总是移动

链接：https://leetcode-cn.com/problems/cat-and-mouse

    vector<vector<int>> input_vector = { {1, 3}, { 0 }, { 3 }, { 0,2 }};
    Solution temp;
    int result = temp.catMouseGame(input_vector);
    cout << result << endl;

*/
#include <vector>
using namespace std;

class Solution {
    const int MOUSE_WIN = 1;
    const int CAT_WIN = 2;
    const int DRAW = 0;
    const int MAXN = 51;
public:
    int n;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> graph;
    int catMouseGame(vector<vector<int>>& graph) {
        this->n = graph.size();
        this->graph = graph;
        this->dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n * 2 + 1, -1)));
        return getResult(1, 2, 0);
    }

    int getResult(int mouse, int cat, int turns) {
        if (turns >= n << 1)
            return DRAW;
        if (dp[mouse][cat][turns] < 0)
            if (mouse == 0)
                dp[mouse][cat][turns] = MOUSE_WIN;
            else if (cat == mouse)
                dp[mouse][cat][turns] = CAT_WIN;
            else
                getNextResult(mouse, cat, turns);
        return dp[mouse][cat][turns];
    }

    void getNextResult(int mouse, int cat, int turns) {
        int cur_move = turns % 2 == 0 ? mouse : cat;
        int default_result = cur_move == mouse ? CAT_WIN : MOUSE_WIN;
        int result = default_result;
        for (int index : graph[cur_move]) {
            if (cur_move == cat && index == 0)
                continue;
            int next_mouse = cur_move == mouse ? index : mouse;
            int next_cat = cur_move == cat ? index : cat;
            int next_result = getResult(next_mouse, next_cat, turns + 1);
            if (next_result != default_result) {
                result = next_result;
                if (result != DRAW)
                    break;
            }
        }
        dp[mouse][cat][turns] = result;
    }
};