/*

给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

链接：https://leetcode.cn/problems/edit-distance

    string word1 = "intention", word2 = "execution";
    Solution temp;
    int ret = temp.minDistance(word1, word2);
    cout << ret << endl;

*/

#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        int m = word1.size();
//        int n = word2.size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//        for (int i = 0; i < m + 1; ++i)
//            dp[i][0] = i;
//        for (int i = 0; i < n + 1; ++i)
//            dp[0][i] = i;
//        for (int i = 1; i < m + 1; ++i) {
//            for (int j = 1; j < n + 1; ++j) {
//                if (word1[i - 1] == word2[j - 1])
//                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
//                else
//                    dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });
//            }
//        }
//        return dp[m][n];
//    }
//};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        vector<vector<int>> D(n + 1, vector<int>(m + 1));

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};
