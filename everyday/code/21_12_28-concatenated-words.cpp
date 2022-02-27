/*

给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。

连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。

 

示例 1：

输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成;
     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成;
     "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
示例 2：

输入：words = ["cat","dog","catdog"]
输出：["catdog"]
 

提示：

1 <= words.length <= 104
0 <= words[i].length <= 1000
words[i] 仅由小写字母组成
0 <= sum(words[i].length) <= 105

链接：https://leetcode-cn.com/problems/concatenated-words

    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    Solution temp;
    vector<string> ret = temp.findAllConcatenatedWordsInADict(words);
    Print<string>::PrintOneDemionVector(ret);

*/

#include <time.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
            });
        vector<string> ret;
        unsigned int prime = 131, offset = 128;
        unordered_set<unsigned long long> hash_set;
        for (string word : words) {
            int len = word.size();
            unsigned long long hash = 0;
            function<bool(string)> dfs = [&](string str) {
                int len = str.size();
                unsigned long long word_hash = 0;
                for (int i = 0; i < len; ++i) {
                    word_hash = word_hash * prime + str[i] - 'a' + offset;
                    if (hash_set.count(word_hash))
                        if (i == len - 1 || dfs(str.substr(i + 1, len - i - 1)))
                            return true;
                }
                hash = word_hash;
                return false;
            };
            if (dfs(word))
                ret.emplace_back(word);
            else
                hash_set.emplace(hash);
        }
        return ret;
    }
};

//class Solution {
//public:
//    int p = 131, offset = 128;
//    unordered_set<unsigned long long> hash_set;
//    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//        /*sort(words.begin(), words.end(), [](const string& a, const string& b) {
//            return a.size() < b.size();
//            });*/
//        vector<string> ret;
//        
//        for (string word : words) {
//            unsigned long long hash = 0;
//            for (char ch : word)
//                hash = hash * p + (ch - 'a') + offset;
//            hash_set.emplace(hash);
//        }
//        for (string word : words)
//            if (check(word))
//                ret.emplace_back(word);
//        return ret;
//    }
//
//    bool check(string str) {
//        int len = str.size();
//        vector<int> visited(len + 1, -1);
//        visited[0] = 0;
//        for (int i = 0; i <= len; ++i) {
//            if (visited[i] == -1)
//                continue;
//            unsigned long long cur = 0;
//            for (int j = i + 1; j <= len; ++j) {
//                cur = cur * p + (str[j - 1] - 'a') + offset;
//                if (hash_set.count(cur))
//                    visited[j] = max(visited[j], visited[i] + 1);
//            }
//            if (visited[len] > 1)
//                return true;
//        }
//        return false;
//    }
//};


//class Solution {
//public:
//    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//        sort(words.begin(), words.end(), [](const string& a, const string& b) {
//            return a.size() < b.size();
//            });
//        vector<string> ret;
//
//
//        unordered_set<string> str_set;
//        for (string word : words) {
//            /*function<bool(string)> dfs = [&](string str) {
//                int len = str.size();
//                for (int i = 0; i < len; ++i) {
//                    if (str_set.count(str.substr(0, i + 1)))
//                        if (i == len - 1 || dfs(str.substr(i + 1, len - i - 1)))
//                            return true;
//                }
//                return false;
//            };
//            if (dfs(word))
//                ret.emplace_back(word);
//            else
//                str_set.emplace(word);*/
//            int len = word.size();
//            if (len == 0)
//                continue;
//            vector<bool> visited(len);
//            function<bool(int)> dfs = [&](int start) {
//                if (visited[start])
//                    return false;
//                visited[start] = true;
//                for (int i = start; i < len; ++i)
//                    if (str_set.count(word.substr(start, i - start + 1)))
//                        if (i == len - 1 || dfs(i + 1))
//                            return true;
//                return false;
//            };
//            if (dfs(0))
//                ret.emplace_back(word);
//            else
//                str_set.emplace(word);
//        }
//        return ret;
//    }
//};




//struct Trie {
//    bool isEnd;
//    vector<Trie*> children;
//    Trie() {
//        this->children = vector<Trie*>(26, nullptr);
//        this->isEnd = false;
//    }
//};
//
//class Solution {
//public:
//    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//        sort(words.begin(), words.end(), [](const string& a, const string& b) {
//            return a.size() < b.size();
//            });
//        vector<string> ret;
//        
//        for (string word : words) {
//            if (word.size() == 0)
//                continue;
//            vector<int> visited(word.size(), 0);
//            if (dfs(word, 0, visited))
//                ret.emplace_back(word);
//            else
//                insert(word);
//        }
//        return ret;
//    }
//
//    bool dfs(const string & word, int start, vector<int> & visited) {
//        int len = word.size();
//        if (len == start)
//            return true;
//        if (visited[start])
//            return false;
//        visited[start] = true;
//        Trie* node = trie;
//        for (int i = start; i < len; ++i) {
//            char ch = word[i] - 'a';
//            node = node->children[ch];
//            if (node == nullptr)
//                return false;
//            if (node->isEnd)
//                if (dfs(word, i + 1, visited))
//                    return true;
//        }
//        return false;
//    }
//
//    void insert(const string& word) {
//        Trie* node = trie;
//        for (char ch : word) {
//            ch -= 'a';
//            if (node->children[ch] == nullptr)
//                node->children[ch] = new Trie();
//            node = node->children[ch];
//        }
//        node->isEnd = true;
//    }
//
//private:
//    Trie* trie = new Trie();
//};