/*

给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

 

示例 1:

输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:

输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
示例 3:

输入: nums1 = [1,2], nums2 = [3], k = 3
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
 

提示:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 和 nums2 均为升序排列
1 <= k <= 1000

链接：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums

参考：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/

    vector<int> nums1 = { 1, 2 }, nums2 = { 3 };
    int k = 3;
    Solution temp;
    vector<vector<int>> ret = temp.kSmallestPairs(nums1, nums2, k);
    Print<int>::PrintTwoDemionVector(ret);

*/

#include <vector>
#include <queue>
using namespace std;

//class Solution {
//public:
//    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//        int len_m = nums1.size();
//        int len_n = nums2.size();
//        if (len_m < 1 || len_n < 1)
//            return { };
//        vector<vector<int>> ret;
//        vector<int> pos_vec(len_m, 0);
//        int max_now;
//        while (k--) {
//            int max_temp = INT_MAX;
//            int pos = 0;
//            for (int i = 0; i < len_m; ++i) {
//                if (pos_vec[i] == len_n)
//                    continue;
//                if (max_temp > nums1[i] + nums2[pos_vec[i]]) {
//                    pos = i;
//                    max_temp = nums1[i] + nums2[pos_vec[i]];
//                } 
//                if (pos_vec[i] == 0) 
//                    break;
//            }
//            if (max_temp == INT_MAX)
//                break;
//            max_now = max_temp;
//            ret.push_back({ nums1[pos], nums2[pos_vec[pos]] });
//            pos_vec[pos]++;
//        }
//        return ret;
//    }
//};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue(cmp);
        int len_m = nums1.size();
        int len_n = nums2.size();
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size(); ++i)
            queue.emplace(i, 0);
        while (k-- && !queue.empty()) {
            pair<int, int> min_now = queue.top();
            queue.pop();
            ans.emplace_back(initializer_list<int>{nums1[min_now.first], nums2[min_now.second]});
            if (min_now.second < len_n - 1)
                queue.emplace(min_now.first, min_now.second + 1);
        }
        return ans;
    }
};