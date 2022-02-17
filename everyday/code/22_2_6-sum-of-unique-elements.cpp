/*

给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。

请你返回 nums 中唯一元素的 和 。

 

示例 1：

输入：nums = [1,2,3,2]
输出：4
解释：唯一元素为 [1,3] ，和为 4 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：0
解释：没有唯一元素，和为 0 。
示例 3 ：

输入：nums = [1,2,3,4,5]
输出：15
解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

链接：https://leetcode-cn.com/problems/sum-of-unique-elements

    vector<int> nums = { 1, 2, 3, 2 };
    Solution temp;
    int ret = temp.sumOfUnique(nums);
    cout << ret << endl;

*/
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> vector_count(this->count_, 0);
        int ret = 0;
        for (int index : nums)
            vector_count[index - 1]++;
        for (int i = 0; i < this->count_; ++i)
            if (vector_count[i] == 1)
                ret += i + 1;
        return ret;
    }

private:
    int count_ = 100;
};