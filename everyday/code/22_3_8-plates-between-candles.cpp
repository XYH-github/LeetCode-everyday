/*

给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。

 

示例 1:



输入：s = "**|**|***|", queries = [[2,5],[5,9]]
输出：[2,3]
解释：
- queries[0] 有两个盘子在蜡烛之间。
- queries[1] 有三个盘子在蜡烛之间。
示例 2:



输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
输出：[9,0,0,0,0]
解释：
- queries[0] 有 9 个盘子在蜡烛之间。
- 另一个查询没有盘子在蜡烛之间。
 

提示：

3 <= s.length <= 105
s 只包含字符 '*' 和 '|' 。
1 <= queries.length <= 105
queries[i].length == 2
0 <= lefti <= righti < s.length

链接：https://leetcode-cn.com/problems/plates-between-candles

    string s = "**|**|***|";
    vector<vector<int>> queries = { {2,5},{5,9} };
    Solution temp;
    vector<int> ret = temp.platesBetweenCandles(s, queries);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> ret;
        int len = s.size();
        vector<int> left_vec(len);
        vector<int> right_vec(len);
        vector<int> front_sum(len);
        if (s[0] == '*')
            left_vec[0] = -1, front_sum[0] = 1;
        else
            left_vec[0] = 0, front_sum[0] = 0;
        for (int i = 1; i < len; ++i)
            if (s[i] == '|')
                left_vec[i] = i, front_sum[i] = front_sum[i - 1];
            else
                left_vec[i] = left_vec[i - 1], front_sum[i] = front_sum[i - 1] + 1;

        if (s[len - 1] == '|')
            right_vec[len - 1] = len - 1;
        else
            right_vec[len - 1] = len;
        for (int i = len - 2; i >= 0; --i)
            if (s[i] == '|')
                right_vec[i] = i;
            else
                right_vec[i] = right_vec[i + 1];
        for (auto query : queries) {
            if (left_vec[query[1]] > right_vec[query[0]])
                ret.emplace_back(front_sum[left_vec[query[1]]] - front_sum[right_vec[query[0]]]);
            else
                ret.emplace_back(0);
        }
        return ret;
    }
};