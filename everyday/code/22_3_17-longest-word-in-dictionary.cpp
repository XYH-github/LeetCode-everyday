/*

给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

 

示例 1：

输入：words = ["w","wo","wor","worl", "world"]
输出："world"
解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
示例 2：

输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
输出："apple"
解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply"
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 30
所有输入的字符串 words[i] 都只包含小写字母。

链接：https://leetcode-cn.com/problems/longest-word-in-dictionary

    vector<string> words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    Solution temp;
    string ret = temp.longestWord(words);
    cout << ret << endl;

*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        //unordered_set<string> str_set(words.begin(), words.end());
        string ret;
        unordered_set<string> str_set = { "" };;
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs) {
            if (lhs.size() != rhs.size())
                return lhs.size() < rhs.size();
            else
                return lhs > rhs;
            });
        for (string word : words) {
            if (str_set.count(word.substr(0, word.size() - 1))) {
                str_set.emplace(word);
                ret = word;
            }
        }
        return ret;
    }
};