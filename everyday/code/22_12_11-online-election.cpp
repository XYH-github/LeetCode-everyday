/*

给你两个整数数组 persons 和 times 。在选举中，第 i 张票是在时刻为 times[i] 时投给候选人 persons[i] 的。

对于发生在时刻 t 的每个查询，需要找出在 t 时刻在选举中领先的候选人的编号。

在 t 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

实现 TopVotedCandidate 类：

TopVotedCandidate(int[] persons, int[] times) 使用 persons 和 times 数组初始化对象。
int q(int t) 根据前面描述的规则，返回在时刻 t 在选举中领先的候选人的编号。
 
示例：

输入：
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
输出：
[null, 0, 1, 1, 0, 0, 1]

解释：
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
topVotedCandidate.q(15); // 返回 0
topVotedCandidate.q(24); // 返回 0
topVotedCandidate.q(8); // 返回 1
 

提示：

1 <= persons.length <= 5000
times.length == persons.length
0 <= persons[i] < persons.length
0 <= times[i] <= 109
times 是一个严格递增的有序数组
times[0] <= t <= 109
每个测试用例最多调用 104 次 q

链接：https://leetcode-cn.com/problems/online-election

    vector<int> persons = { 0, 1, 2, 2, 1}, times = { 20, 28, 29, 54, 56 };
    TopVotedCandidate temp(persons, times);
    int ret = temp.q(57);
    cout << ret << endl;

*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int len = times.size();
        int priority = persons[0];
        time_ = times;
        priority_vec_.resize(len);
        for (int i = 0; i < len; ++i) {
            vite_count_[persons[i]]++;
            if (vite_count_[persons[i]] >= vite_count_[priority])
                priority = persons[i];
            priority_vec_[i] = priority;
        }
    }

    int q(int t) {
        /*int left = 0;
        int right = time_.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (time_[mid] > t)
                right = mid - 1;
            else
                left = mid;
        }
        return priority_vec_[left];*/

        int left = 0;
        int right = time_.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (time_[mid] > t)
                right = mid;
            else
                left = mid + 1;
        }
        return time_[left] > t ? priority_vec_[left - 1] : priority_vec_[left];

        //int left = upper_bound(time_.begin(), time_.end(), t) - time_.begin() - 1;
        //return priority_vec_[left];
    }
private:
    unordered_map<int, int> vite_count_;
    vector<int> priority_vec_;
    vector<int> time_;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */