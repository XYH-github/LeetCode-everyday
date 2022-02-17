/*

给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。

 

示例 1：

输入：s = "aaabb", k = 3
输出：3
解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2：

输入：s = "ababbc", k = 2
输出：5
解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters

    string s = "ababbc";
    int k = 2;
    Solution temp;
    int result = temp.longestSubstring(s, k);
    cout << result << endl;

*/
#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int longestSubstring(string s, int k) {
//        int n = s.length();
//        return dfs(s, 0, n - 1, k);
//    }
//
//    int dfs(const string& s, int l, int r, int k) {
//        vector<int> cnt(26, 0);
//        for (int i = l; i <= r; ++i)
//            cnt[s[i] - 'a']++;
//        char split = 0;
//        for (int i = 0; i < 26; ++i) {
//            if (cnt[i] > 0 && cnt[i] < k) {
//                split = i + 'a';
//                break;
//            }
//        }
//        if (split == 0)
//            return r - l + 1;
//
//        int i = l;
//        int ret = 0;
//        while (i <= r) {
//            while (i <= r && s[i] == split)
//                i++;
//            if (i > r)
//                break;
//            int start = i;
//            while (i <= r && s[i] != split)
//                i++;
//            int length = dfs(s, start, i - 1, k);
//            ret = max(ret, length);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int longestSubstring(string s, int k) {
//        int ret = 0;
//        int n = s.length();
//        for (int i = 1; i <= 26; ++i) {
//            int l = 0, r = 0;
//            vector<int> cnt(26, 0);
//            int tot = 0;
//            int less = 0;
//            while (r < n) {
//                cnt[s[r] - 'a']++;
//                if (cnt[s[r] - 'a'] == 1) {
//                    tot++;
//                    less++;
//                }
//                if (cnt[s[r] - 'a'] == k)
//                    less--;
//                while (tot > i) {
//                    cnt[s[l] - 'a']--;
//                    if (cnt[s[l] - 'a'] == k - 1)
//                        less++;
//                    if (cnt[s[l] - 'a'] == 0) {
//                        tot--;
//                        less--;
//                    }
//                    l++;
//                }
//                if (less == 0)
//                    ret = max(ret, r - l + 1);
//                r++;
//            }
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (ret >= s.size() - i)
                break;
            vector<int> cnt(26, 0);
            int tot = 0;
            int less = 0;
            for (int j = i; j < s.size(); ++j) {
                cnt[s[j] - 'a']++;
                if (cnt[s[j] - 'a'] == 1) {
                    tot++;
                    less++;
                }
                if (cnt[s[j] - 'a'] == k)
                    less--;
                if (less == 0)
                    ret = max(ret, j - i + 1);
            }
        }
        return ret;
    }
};