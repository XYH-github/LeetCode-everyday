/*

你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。

比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：

整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
请你返回记录中所有得分的总和。

链接：https://leetcode-cn.com/problems/baseball-game

    vector<string> ops = { "5", "2", "C", "D", "+" };
    Solution temp;
    int ret = temp.calPoints(ops);
    cout << ret << endl;

*/

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        int ret = 0;
        for (string op : ops) {
            if (op == "C") {
                ret -= stk.top();
                stk.pop();
            }
            else if (op == "D") {
                int temp = stk.top();
                ret += temp * 2;
                stk.emplace(temp * 2);
            }
            else if (op == "+") {
                int top = stk.top();
                stk.pop();
                int temp = stk.top();
                stk.emplace(top);
                stk.emplace(top + temp);
                ret += top + temp;
            }
            else {
                stk.emplace(atoi(op.c_str()));
                ret += atoi(op.c_str());
            }
        }
        return ret;
    }
};