/*

你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。

如果你能使这个正方形，则返回 true ，否则返回 false 。

 

示例 1:



输入: matchsticks = [1,1,2,2,2]
输出: true
解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: matchsticks = [3,3,3,3,4]
输出: false
解释: 不能用所有火柴拼成一个正方形。
 

提示:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

链接：https://leetcode.cn/problems/matchsticks-to-square

    vector<int> matchsticks = { 3, 3, 3, 3, 4 };
    Solution temp;
    bool ret = temp.makesquare(matchsticks);
    cout << ret << endl;

*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

//class Solution {
//public:
//    bool makesquare(vector<int>& matchsticks) {
//        int len = matchsticks.size();
//        int num = accumulate(matchsticks.begin(), matchsticks.end(), 0);
//        if (num % 4 != 0)
//            return false;
//        num /= 4;
//        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
//        vector<int> _sum_vec(4);
//        function<bool(int)> dfs = [&](int pos) {
//            if (pos >= len)
//                return true;
//            for (int i = 0; i < 4; ++i) {
//                if (matchsticks[pos] + _sum_vec[i] <= num) {
//                    _sum_vec[i] += matchsticks[pos];
//                    if (dfs(pos + 1))
//                        return true;
//                    _sum_vec[i] -= matchsticks[pos];
//                }
//            }
//            return false;
//        };
//        return dfs(0);
//    }
//};


class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int len = matchsticks.size();
        int num = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (num % 4 != 0)
            return false;
        num /= 4;
        vector<int> dp(1 << len, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << len); ++s) {
            for (int k = 0; k < len; ++k) {
                if ((s & (1 << k)) == 0)
                    continue;
                int s1 = s & ~(1 << k);
                if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= num) {
                    dp[s] = (dp[s1] + matchsticks[k]) % num;
                    break;
                }
            }
        }
        return dp[(1 << len) - 1] == 0;
    }
};