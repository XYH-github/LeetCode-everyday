/*

给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0
 

提示：

2 <= timePoints.length <= 2 * 104
timePoints[i] 格式为 "HH:MM"

链接：https://leetcode-cn.com/problems/minimum-time-difference

    vector<string> timePoints = {"00:00", "23:59", "00:00"};
    Solution temp;
    int result = temp.findMinDifference(timePoints);
    cout << result << endl;

*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440)
            return 0;
        vector<int> time_minute(timePoints.size());
        for (int i = 0; i < timePoints.size(); ++i)
            time_minute[i] = ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60 +
            (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
        sort(time_minute.begin(), time_minute.end());
        int result = time_minute[0] - time_minute[time_minute.size() - 1] + 1440;
        for (int i = 1; i < time_minute.size(); ++i)
            result = min(result, time_minute[i] - time_minute[i - 1]);
        return result;
    }
};