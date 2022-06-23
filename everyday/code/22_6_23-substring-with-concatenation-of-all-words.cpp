/*

给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] 由小写英文字母组成

链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words

    string s = "barfoofoobarthefoobarman";
    vector<string> words = { "bar", "foo", "the" };
    Solution temp;
    vector<int> ret = temp.findSubstring(s, words);
    Print<int>::PrintOneDemionVector(ret);

*/

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int len = s.size();
        int len_words = words[0].size();
        int words_cnt = words.size();
        unordered_map<string, int> words_map;
        for (string word : words)
            words_map[word]++;
        for (int i = 0; i < len_words && i < len - len_words * words_cnt + 1; ++i) {
            unordered_map<string, int> diff = words_map;
            for (int j = i; j < i + len_words * words_cnt; j += len_words) {
                string now = s.substr(j, len_words);
                if (--diff[now] == 0)
                    diff.erase(now);
            }
            if (diff.empty())
                ret.emplace_back(i);
            for (int j = i + len_words; j < len - len_words * words_cnt + 1; j += len_words) {
                string pre = s.substr(j - len_words, len_words);
                if (++diff[pre] == 0)
                    diff.erase(pre);
                string now = s.substr(j + (len_words * (words_cnt - 1)), len_words);
                if (--diff[now] == 0)
                    diff.erase(now);
                if (diff.empty())
                    ret.emplace_back(j);
            }
        }
        return ret;
    }
};