/*

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
 

提示：

0 <= n <= 100

链接：https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof

    int n = 100;
    Solution temp;
    int ret = temp.fib(n);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

//class Solution {
//public:
//    const int MOD = 1e9 + 7;
//    int fib(int n) {
//        if (n < 2)
//            return n;
//        int p = 0, q = 0, r = 1;
//        for (int i = 2; i <= n; ++i) {
//            p = q;
//            q = r;
//            r = (p + q) % MOD;
//        }
//        return r;
//    }
//};



class Solution {
public:
    const int MOD = 1e9 + 7;
    int fib(int n) {
        if (n < 2)
            return n;
        vector<vector<long long>> fib_vec{ {1, 1}, {1, 0} };
        vector<vector<long long>> ret = powForVec(fib_vec, n - 1);
        return ret[0][0];
    }

    vector<vector<long long>> powForVec(vector<vector<long long>> a, int n) {
        vector<vector<long long>> ret{ {1, 0}, {0, 1} };
        while (n) {
            if (n & 1)
                ret = mutiForVec(ret, a);
            n >>= 1;
            a = mutiForVec(a, a);
        }
        return ret;
    }

    vector<vector<long long>> mutiForVec(vector<vector<long long>> a, vector<vector<long long>> b) {
        int len_m = a.size();
        int len_n = b[0].size();
        int len = b.size();
        vector<vector<long long>> ret(len_m, vector<long long>(len_n));
        for (int i = 0; i < len_m; ++i) {
            for (int j = 0; j < len_n; ++j) {
                for (int k = 0; k < len; ++k)
                    ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
        return ret;
    }
};

