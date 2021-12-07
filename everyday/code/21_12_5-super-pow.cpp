/*

你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

 

示例 1：

输入：a = 2, b = [3]
输出：8
示例 2：

输入：a = 2, b = [1,0]
输出：1024
示例 3：

输入：a = 1, b = [4,3,3,8,5,2]
输出：1
示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198
 

提示：

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b 不含前导 0

链接：https://leetcode-cn.com/problems/super-pow

int a = 2147483647;
    vector<int> b = {2, 0, 0 };
    Solution temp;
    int result = temp.superPow(a, b);
    cout << result << endl;

*/
#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1337;
    int powandmod(int d, int t) {
        if (d >= MOD)
            d %= MOD;
        int res = 1;
        while (t) {
            if (t % 2)
                res = res * d % MOD;
            t /= 2;
            d = d * d % MOD;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            ans = ans * powandmod(a, b[i]) % MOD;
            a = powandmod(a, 10);
        }
        return ans;
    }
};