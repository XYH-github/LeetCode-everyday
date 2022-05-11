/*

基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

示例 1：

输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
输出：1
示例 2：

输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
输出：2
示例 3：

输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
输出：3
 

提示：

start.length == 8
end.length == 8
0 <= bank.length <= 10
bank[i].length == 8
start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成

链接：https://leetcode.cn/problems/minimum-genetic-mutation

    Solution temp;
    string start = "AAAAACCC", end = "AACCCCCC";
    vector<string> bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
    int ret = temp.minMutation(start, end, bank);
    cout << ret << endl;

*/

#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end)
            return 0;
        int len = bank.size();
        int ret = 1;
        int index = -1;
        vector<unordered_set<int>> visited(len + 1);
        unordered_set<int> memory;
        queue<int> que;
        for (int i = 0; i < len; ++i) {
            if (bank[i] == end)
                index = i;
            for (int j = 0; j < len; j++) {
                if (judgeVaild(bank[i], bank[j]))
                    visited[i].emplace(j);
            }
            if (judgeVaild(start, bank[i]))
                visited[i].emplace(len);
        }
        if (index == -1)
            return -1;
        que.emplace(index);
        memory.emplace(index);
        int now_size = 1;
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            now_size--;
            for (auto num : visited[front]) {
                if (num == len)
                    return ret;
                if (!memory.count(num)) {
                    memory.emplace(num);
                    que.emplace(num);
                }
            }
            if (now_size == 0) {
                now_size = que.size();
                ++ret;
            }
        }
        return -1;
    }
    bool judgeVaild(string a, string b) {
        int num = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i]) {
                if (++num > 1)
                    return false;
            }
        }
        if (num == 0)
            return false;
        return true;
    }
};