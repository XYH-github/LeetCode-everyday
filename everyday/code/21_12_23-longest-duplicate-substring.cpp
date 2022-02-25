/*

给你一个字符串 s ，考虑其所有 重复子串 ：即 s 的（连续）子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。

返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。

 

示例 1：

输入：s = "banana"
输出："ana"
示例 2：

输入：s = "abcd"
输出：""
 

提示：

2 <= s.length <= 3 * 104
s 由小写英文字母组成

链接：https://leetcode-cn.com/problems/longest-duplicate-substring

    string s = "banana";
    Solution temp;
    string ret = temp.longestDupSubstring(s);
    cout << ret << endl;

*/

#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <time.h>
using namespace std;

//typedef pair<long long, long long> pll;
//class Solution {
//public:
//    long long pow(int a, int m, int mod) {
//        long long ans = 1;
//        long long contribute = a;
//        while (m > 0) {
//            if (m % 2 == 1) {
//                ans = ans * contribute % mod;
//                if (ans < 0)
//                    ans += mod;
//            }
//            contribute = contribute * contribute % mod;
//            if (contribute < 0)
//                contribute += mod;
//            m /= 2;
//        }
//        return ans;
//    }
//
//    int check(const vector<int>& arr, int m, int a1, int a2, int mod1, int mod2) {
//        int n = arr.size();
//        long long al1 = pow(a1, m, mod1);
//        long long al2 = pow(a2, m, mod2);
//        long long h1 = 0, h2 = 0;
//        for (int i = 0; i < m; ++i) {
//            h1 = (h1 * a1 % mod1 + arr[i]) % mod1;
//            h2 = (h2 * a2 % mod2 + arr[i]) % mod2;
//            if (h1 < 0)
//                h1 += mod1;
//            if (h2 < 0)
//                h2 += mod2;
//        }
//        set<pll> seen;
//        seen.emplace(h1, h2);
//        for (int start = 1; start <= n - m; ++start) {
//            h1 = (h1 * a1 % mod1 - arr[start - 1] * al1 % mod1 + arr[start + m - 1]) % mod1;
//            h2 = (h2 * a2 % mod2 - arr[start - 1] * al2 % mod2 + arr[start + m - 1]) % mod2;
//            if (h1 < 0)
//                h1 += mod1;
//            if (h2 < 0)
//                h2 += mod2;
//            if (seen.count(make_pair(h1, h2)))
//                return start;
//            seen.emplace(h1, h2);
//        }
//        return -1;
//    }
//
//    string longestDupSubstring(string s) {
//        srand((unsigned)time(NULL));
//        int a1 = rand() % 75 + 26;
//        int a2 = rand() % 75 + 26;
//
//        int mod1 = rand() % (INT_MAX - 1000000006) + 1000000006;
//        int mod2 = rand() % (INT_MAX - 1000000006) + 1000000006;
//        int n = s.size();
//        vector<int> arr(n);
//        for (int i = 0; i < n; ++i)
//            arr[i] = s[i] - 'a';
//        int left = 1, right = n - 1;
//        while (left < right) {
//            int mid = left + (right - left + 1) / 2;
//            int idx = check(arr, mid, a1, a2, mod1, mod2);
//            if (idx == -1)
//                right = mid - 1;
//            else {
//                left = mid;
//            }
//        }
//        int idx = check(arr, left, a1, a2, mod1, mod2);
//        return idx != -1 ? s.substr(idx, left) : "";
//    }
//};




class Solution {
public:
    string longestDupSubstring(string s) {
        srand((unsigned) time(NULL));
        int len = s.size();
        unsigned long long prime = rand() % 75 + 26;
        auto pow = [](unsigned long long a, int pow){
            unsigned long long ret = 1;
            unsigned long long con = a;
            while (pow) {
                if (pow % 2)
                    ret *= con;
                con *= con;
                pow >>= 1;
            }
            return ret;
        };
        auto check = [&](int length) {
            unsigned long long hash = 0;
            unsigned long long temp = 0;
            for (int i = 0; i < length; ++i)
                hash = hash * prime + s[i] - 'a';
            unordered_set<unsigned long long> hash_set;
            hash_set.emplace(hash);
            for (int i = length; i < len; ++i) {
                hash = hash * prime - pow(prime, length) * (s[i - length] - 'a') + s[i] - 'a';
                if (hash_set.count(hash))
                    return i - length + 1;
                hash_set.emplace(hash);
            }
            return -1; 
        };

        int left = 1, right = len - 1;
        while (left < right) {
            int mid = left + ((right - left + 1) >> 1);
            if (check(mid) == -1)
                right = mid - 1;
            else
                left = mid;
        }
        int idx = check(left);
        return idx == -1 ? "" : s.substr(idx, left);
    }
};