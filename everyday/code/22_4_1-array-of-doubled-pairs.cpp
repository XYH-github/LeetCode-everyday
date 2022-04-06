/*

给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。

 

示例 1：

输入：arr = [3,1,3,6]
输出：false
示例 2：

输入：arr = [2,1,2,6]
输出：false
示例 3：

输入：arr = [4,-2,2,-4]
输出：true
解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
 

提示：

0 <= arr.length <= 3 * 104
arr.length 是偶数
-105 <= arr[i] <= 105

链接：https://leetcode-cn.com/problems/array-of-doubled-pairs

    vector<int> arr = { 4, -2, 2, -4 };
    Solution temp;
    bool ret = temp.canReorderDoubled(arr);
    cout << ret << endl;

*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> hash_map;
        for (int a : arr) {
            hash_map[a]++;
        }
        if (hash_map[0] % 2)
            return false;
        vector<int> vev;
        for (auto iter = hash_map.begin(); iter != hash_map.end(); ++iter) {
            vev.emplace_back(iter->first);
        }
        sort(vev.begin(), vev.end(), [](const int& lhs, const int& rhs) {
            return abs(lhs) < abs(rhs);
            });
        int len = vev.size();
        for (int i = 0; i < len; ++i) {
            if (hash_map[vev[i]] > hash_map[vev[i] * 2])
                return false;
            hash_map[vev[i] * 2] -= hash_map[vev[i]];
        }
        return true;
    }
};