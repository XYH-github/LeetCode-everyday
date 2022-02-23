/*

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

链接：https://leetcode-cn.com/problems/trapping-rain-water

    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    Solution temp;
    int ret = temp.trap(height);
    cout << ret << endl;

*/

#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int len = height.size();
//        vector<int> left_max(len);
//        vector<int> right_max(len);
//        left_max[0] = height[0];
//        for (int i = 1; i < len - 1; ++i) 
//            left_max[i] = max(left_max[i - 1], height[i]);;
//        right_max[len - 1] = height[len - 1];
//        for (int i = len - 2; i > 0; --i) 
//            right_max[i] = max(right_max[i + 1], height[i]);
//        int ret = 0;
//        for (int i = 1; i < len - 1; ++i)
//            ret += min(left_max[i], right_max[i]) > height[i] ? min(left_max[i], right_max[i]) - height[i] : 0;
//        return ret;
//    }
//};

//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int ret = 0;
//        stack<int> stk;
//        int n = height.size();
//        for (int i = 0; i < n; ++i) {
//            while (!stk.empty() && height[stk.top()] < height[i]) {
//                int top = stk.top();
//                stk.pop();
//                if (stk.empty())
//                    break;
//                int left = stk.top();
//                int cur_width = i - left - 1;
//                int cur_height = min(height[left], height[i]) - height[top];
//                ret += cur_height * cur_width;
//            }
//            stk.emplace(i);
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int left_max = height[0];
        int right_max = height[len - 1];
        int left = 0;
        int right = len - 1;
        int ret = 0;
        while (left < right) {
            if (left_max > right_max) {
                ret += right_max - height[right];
                right--;
                right_max = max(right_max, height[right]);
            }
            else {
                ret += left_max - height[left];
                left++;
                left_max = max(left_max, height[left]);
            }
        }
        return ret;
    }
};