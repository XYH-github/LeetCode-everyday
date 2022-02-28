/*

给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。

但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。

示例：

输入: [1000,100,10,2]
输出: "1000/(100/10/2)"
解释:
1000/(100/10/2) = 1000/((100/10)/2) = 200
但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

其他用例:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
说明:

输入数组的长度在 [1, 10] 之间。
数组中每个元素的大小都在 [2, 1000] 之间。
每个测试用例只有一个最优除法解。

链接：https://leetcode-cn.com/problems/optimal-division

    vector<int> matrix = {1000, 100, 10, 2};
    Solution temp;
    string ret = temp.optimalDivision(matrix);
    cout << ret << endl;

*/

#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    string optimalDivision(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) {
//            return to_string(nums[0]);
//        }
//        if (n == 2) {
//            return to_string(nums[0]) + "/" + to_string(nums[1]);
//        }
//        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
//        for (int i = 2; i < n; i++) {
//            res.append("/" + to_string(nums[i]));
//        }
//        res.append(")");
//        return res;
//    }
//};


//class Solution {
//public:
//    string optimalDivision(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) {
//            return to_string(nums[0]);
//        }
//        if (n == 2) {
//            return to_string(nums[0]) + "/" + to_string(nums[1]);
//        }
//        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
//        for (int i = 2; i < n; i++) {
//            res.append("/" + to_string(nums[i]));
//        }
//        res.append(")");
//        return res;
//    }
//};


class Solution {
public:
    struct Node {
        double max_val, min_val;
        string min_str, max_str;
        Node() {
            this->min_val = 10000.0;
            this->max_val = 0.0;
        }
    };

    string optimalDivision(vector<int>& nums) {
        int len = nums.size();
        vector<vector<Node>> dp(len, vector<Node>(len));

        for (int i = 0; i < len; ++i) {
            dp[i][i].min_val = nums[i];
            dp[i][i].max_val = nums[i];
            dp[i][i].min_str = to_string(nums[i]);
            dp[i][i].max_str = to_string(nums[i]);
        }

        for(int i = 1; i < len; ++i)
            for(int j = 0; j + i < len; ++j)
                for (int k = j; k < j + i; ++k) {
                    if (dp[j][j + i].max_val < dp[j][k].max_val / dp[k + 1][j + i].min_val) {
                        dp[j][j + i].max_val = dp[j][k].max_val / dp[k + 1][j + i].min_val;
                        if (k + 1 == j + i)
                            dp[j][j + i].max_str = dp[j][k].max_str + '/' + dp[k + 1][j + i].min_str;
                        else
                            dp[j][j + i].max_str = dp[j][k].max_str + "/(" + dp[k + 1][j + i].min_str + ")";
                    }
                    if (dp[j][j + i].min_val > dp[j][k].min_val / dp[k + 1][j + i].max_val) {
                        dp[j][j + i].min_val = dp[j][k].min_val / dp[k + 1][j + i].max_val;
                        if (k + 1 == j + i) 
                            dp[j][j + i].min_str = dp[j][k].min_str + "/" + dp[k + 1][j + i].max_str;
                        else 
                            dp[j][j + i].min_str = dp[j][k].min_str + "/(" + dp[k + 1][j + i].max_str + ")";
                    }
                }
        return dp[0][len - 1].max_str;
    }
};