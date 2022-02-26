/*

在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

ages[y] <= 0.5 * ages[x] + 7
ages[y] > ages[x]
ages[y] > 100 && ages[x] < 100
否则，x 将会向 y 发送一条好友请求。

注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。

 

示例 1：

输入：ages = [16,16]
输出：2
解释：2 人互发好友请求。
示例 2：

输入：ages = [16,17,18]
输出：2
解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
示例 3：

输入：ages = [20,30,100,110,120]
输出：3
解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
 

提示：

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120

链接：https://leetcode-cn.com/problems/friends-of-appropriate-ages

    vector<int> ages = {16, 16};
    Solution temp;
    int ret = temp.numFriendRequests(ages);
    cout << ret << endl;

*/

#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int numFriendRequests(vector<int>& ages) {
//        int len = ages.size();
//        int ret = 0;
//        sort(ages.begin(), ages.end());
//        int age_index = 0;
//        while (age_index < len && ages[age_index] < 15)
//            age_index++;
//        if (age_index == len)
//            return 0;
//        int left = 0, right = len - 1;
//        while (left < right) {
//            int mid = left + ((right - left) >> 1);
//            if (ages[mid] > 0.5 * ages[age_index] + 7)
//                right = mid;
//            else
//                left = mid + 1;
//        }
//        int first = left;
//        left = 0, right = len - 1;
//        while (left < right) {
//            int mid = left + ((right - left + 1) >> 1);
//            if (ages[mid] <= ages[age_index])
//                left = mid;
//            else
//                right = mid - 1;
//        }
//        int second = left;
//        ret += second - first;
//        while (++age_index < len) {
//            while (ages[first] <= 0.5 * ages[age_index] + 7)
//                ++first;
//            while (second + 1 < len && ages[second + 1] <= ages[age_index])
//                ++second;
//            ret += second - first;
//        }
//        return ret;
//    }
//};


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121);
        for (int age : ages)
            ++cnt[age];
        vector<int> pre(121);
        for (int i = 1; i <= 120; ++i)
            pre[i] = pre[i - 1] + cnt[i];
        int ret = 0;
        for (int i = 15; i <= 120; ++i) {
            if (cnt[i]) {
                int bound = i * 0.5 + 8;
                ret += cnt[i] * (pre[i] - pre[bound - 1] - 1);
            }
        }
        return ret;
    }
};