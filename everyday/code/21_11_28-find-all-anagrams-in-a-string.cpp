/*

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母

链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string

string s = "cbaebabacd", p = "abc";
    Solution temp;
    vector<int> result = temp.findAnagrams(s, p);
    Print<int>::PrintOneDemionVector(result);

*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> ret;
//        vector<int> s_cnt(26);
//        vector<int> p_cnt(26);
//        int len_s = s.size(), len_p = p.size();
//        if (len_s < len_p)
//            return ret;
//        for (int i = 0; i < len_p; ++i) {
//            s_cnt[s[i] - 'a']++;
//            p_cnt[p[i] - 'a']++;
//        }
//        if (s_cnt == p_cnt)
//            ret.emplace_back(0);
//        for (int i = len_p; i < len_s; ++i) {
//            s_cnt[s[i - len_p] - 'a']--;
//            s_cnt[s[i] - 'a']++;
//            if (s_cnt == p_cnt)
//                ret.emplace_back(i - len_p + 1);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        int sLen = s.size(), pLen = p.size();
//
//        if (sLen < pLen) {
//            return vector<int>();
//        }
//
//        vector<int> ans;
//        vector<int> count(26);
//        for (int i = 0; i < pLen; ++i) {
//            ++count[s[i] - 'a'];
//            --count[p[i] - 'a'];
//        }
//
//        int differ = 0;
//        for (int j = 0; j < 26; ++j) {
//            if (count[j] != 0) {
//                ++differ;
//            }
//        }
//
//        if (differ == 0) {
//            ans.emplace_back(0);
//        }
//
//        for (int i = 0; i < sLen - pLen; ++i) {
//            if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
//                --differ;
//            }
//            else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
//                ++differ;
//            }
//            --count[s[i] - 'a'];
//
//            if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
//                --differ;
//            }
//            else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
//                ++differ;
//            }
//            ++count[s[i + pLen] - 'a'];
//
//            if (differ == 0) {
//                ans.emplace_back(i + 1);
//            }
//        }
//
//        return ans;
//    }
//};



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_length = p.size();
        if (s.size() < p.size())
            return {};
        unordered_map<char, int> hash_map;
        
        vector<int> result;
        for (int i = 0; i < p_length; ++i) {
            hash_map[p[i]] += 1;
            hash_map[s[i]] -= 1;
        }
        bool flag = true;
        for (auto index : hash_map)
            if (index.second != 0){
                flag = false;
                break;
            }
        if (flag)
            result.push_back(0);
        for (int i = 1; i < s.size() - p_length + 1; ++i){
            hash_map[s[i - 1]] += 1;
            hash_map[s[i + p_length - 1]] -= 1;
            flag = true;
            for (auto index : hash_map)
                if (index.second != 0) {
                    flag = false;
                    break;
                }
            if (flag)
                result.push_back(i);
        }
        return result;
    }
};