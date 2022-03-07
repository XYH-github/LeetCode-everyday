/*

给你一个下标从 0 开始的二维整数数组 tires ，其中 tires[i] = [fi, ri] 表示第 i 种轮胎如果连续使用，第 x 圈需要耗时 fi * ri(x-1) 秒。

比方说，如果 fi = 3 且 ri = 2 ，且一直使用这种类型的同一条轮胎，那么该轮胎完成第 1 圈赛道耗时 3 秒，完成第 2 圈耗时 3 * 2 = 6 秒，完成第 3 圈耗时 3 * 22 = 12 秒，依次类推。
同时给你一个整数 changeTime 和一个整数 numLaps 。

比赛总共包含 numLaps 圈，你可以选择 任意 一种轮胎开始比赛。每一种轮胎都有 无数条 。每一圈后，你可以选择耗费 changeTime 秒 换成 任意一种轮胎（也可以换成当前种类的新轮胎）。

请你返回完成比赛需要耗费的 最少 时间。

 

示例 1：

输入：tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
输出：21
解释：
第 1 圈：使用轮胎 0 ，耗时 2 秒。
第 2 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
第 3 圈：耗费 5 秒换一条新的轮胎 0 ，然后耗时 2 秒完成这一圈。
第 4 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
总耗时 = 2 + 6 + 5 + 2 + 6 = 21 秒。
完成比赛的最少时间为 21 秒。
示例 2：

输入：tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
输出：25
解释：
第 1 圈：使用轮胎 1 ，耗时 2 秒。
第 2 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
第 3 圈：耗时 6 秒换一条新的轮胎 1 ，然后耗时 2 秒完成这一圈。
第 4 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
第 5 圈：耗时 6 秒换成轮胎 0 ，然后耗时 1 秒完成这一圈。
总耗时 = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 秒。
完成比赛的最少时间为 25 秒。

链接：https://leetcode-cn.com/problems/minimum-time-to-finish-the-race

    vector<vector<int>> tires = { {1,10},{2,2},{3,4} };
    int changeTime = 6;
    int	numLaps = 5;
    Solution temp;
    int ret = temp.minimumFinishTime(tires, changeTime, numLaps);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int len = tires.size();
        vector<long long> cout;
        vector<long long> temp(len);
        vector<long long> temp_all(len);
        long long cmp_temp = LLONG_MAX;
        for (int i = 0; i < len; ++i) {
            temp[i] = tires[i][0];
            cmp_temp = min(cmp_temp, temp[i]);
            temp_all[i] += temp[i];
        }
        cout.push_back(cmp_temp);
        while (true) {
            cmp_temp = LLONG_MAX;
            for (int i = 0; i < len; ++i) {
                if (temp[i] != LLONG_MAX && temp[i] * tires[i][1] < changeTime + tires[i][0]) {
                    temp[i] *= tires[i][1];
                    temp_all[i] += temp[i];
                    cmp_temp = min(cmp_temp, temp_all[i]);
                }
                else
                    temp[i] = LLONG_MAX;
            }
            if (cmp_temp != LLONG_MAX)
                cout.push_back(cmp_temp);
            else
                break;
        }
        len = cout.size();
        vector<long long> ret(numLaps + 1, LLONG_MAX);
        for (int i = 1; i <= numLaps; ++i)
            for (int j = 0; j < i && j < len; ++j)
                ret[i] = min(ret[i], j == i - 1 ? cout[j] : cout[j] + ret[i - j - 1] + changeTime);
        return ret[numLaps];
    }
};