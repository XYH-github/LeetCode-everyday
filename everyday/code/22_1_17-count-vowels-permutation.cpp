/*

给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
每个元音 'a' 后面都只能跟着 'e'
每个元音 'e' 后面只能跟着 'a' 或者是 'i'
每个元音 'i' 后面 不能 再跟着另一个 'i'
每个元音 'o' 后面只能跟着 'i' 或者是 'u'
每个元音 'u' 后面只能跟着 'a'
由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

 

示例 1：

输入：n = 1
输出：5
解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
示例 2：

输入：n = 2
输出：10
解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
示例 3：

输入：n = 5
输出：68
 

提示：

1 <= n <= 2 * 10^4

链接：https://leetcode-cn.com/problems/count-vowels-permutation

    int n = 144;
    Solution temp;
    long long result = temp.countVowelPermutation(n);
    cout << result << endl;

*/
#include <vector>
#include <numeric>
using namespace std;

//class Solution {
//public:
//    int countVowelPermutation(int n) {
//        vector<vector<long long>> dp(2, vector<long long>(5, 1));
//        long long mod = 1e9 + 7;
//        int poi = 0;
//        int last = 0;
//        for (int i = 1; i < n; ++i) {
//            poi = i % 2;
//            dp[poi][0] = (dp[last][1] + dp[last][2] + dp[last][4]) % mod;
//            dp[poi][1] = (dp[last][0] + dp[last][2]) % mod;
//            dp[poi][2] = (dp[last][1] + dp[last][3]) % mod;
//            dp[poi][3] = dp[last][2] % mod;
//            dp[poi][4] = (dp[last][2] + dp[last][3]) % mod;
//            last = poi;
//        }
//        return accumulate(dp[last].begin(), dp[last].end(), 0LL) % mod;
//    }
//};

using LL = long long;
using Mat = vector<vector<LL>>;
class Solution {
public:
    Mat multiply(const Mat & matrixa, const Mat & matrixb, LL mod) {
        int m = matrixa.size();
        int n = matrixb[0].size();
        Mat res(m, vector<LL>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < matrixa[i].size(); ++k)
                    res[i][j] = (res[i][j] + matrixa[i][k] * matrixb[k][j]) % mod;
        return res;
    }

    Mat fastPow(const Mat& matrix, LL n, LL mod) {
        int m = matrix.size();
        Mat res(m, vector<LL>(m, 0));
        Mat curr = matrix;

        for (int i = 0; i < m; ++i)
            res[i][i] = 1;
        for (int i = n; i != 0; i >>= 1) {
            if (i & 1)
                res = multiply(curr, res, mod);
            curr = multiply(curr, curr, mod);
        }
        return res;
    }

    int countVowelPermutation(int n) {
        LL mod = 1e9 + 7;
        Mat factor = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0}
        };
        Mat res = fastPow(factor, n - 1, mod);
        LL result = 0;
        for (int i = 0; i < 5; ++i)
            result = (result + accumulate(res[i].begin(), res[i].end(), 0LL)) % mod;
        return result;
    }
};