/*

给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标：

i + 1 满足：i + 1 < arr.length
i - 1 满足：i - 1 >= 0
j 满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。

 

示例 1：

输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
输出：3
解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
示例 2：

输入：arr = [7]
输出：0
解释：一开始就在最后一个元素处，所以你不需要跳跃。
示例 3：

输入：arr = [7,6,9,6,9,6,9,7]
输出：1
解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
示例 4：

输入：arr = [6,1,9]
输出：2
示例 5：

输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
输出：3
 

提示：

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

链接：https://leetcode-cn.com/problems/jump-game-iv

    vector<int> arr = { 100, -23, -23, 404, 100, 23, 23, 23, 3, 404 };
    Solution temp;
    int ret = temp.minJumps(arr);
    cout << ret << endl;

*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> pos_map;
        queue<pair<int, int>> way_queue;
        unordered_set<int> visited_set;
        int len = arr.size();
        for (int i = 0; i < len; ++i)
            pos_map[arr[i]].emplace_back(i);
        way_queue.emplace(0, 0);
        visited_set.emplace(0);
        while (!way_queue.empty()) {
            auto queue_front = way_queue.front();
            way_queue.pop();
            if (queue_front.first == len - 1)
                return queue_front.second;
            int step = queue_front.second + 1;
            if (pos_map.count(arr[queue_front.first])) {
                for (auto index : pos_map[arr[queue_front.first]])
                    if (!visited_set.count(index)) {
                        way_queue.emplace(index, step);
                        visited_set.emplace(index);
                    }
                pos_map.erase(arr[queue_front.first]);
            }

            if (queue_front.first + 1 < len && !visited_set.count(queue_front.first + 1)) {
                way_queue.emplace(queue_front.first + 1, step);
                visited_set.emplace(queue_front.first + 1);
            }
            if (queue_front.first - 1 > 0 && !visited_set.count(queue_front.first - 1)) {
                way_queue.emplace(queue_front.first - 1, step);
                visited_set.emplace(queue_front.first - 1);
            }
        }
        return -1;
    }
};