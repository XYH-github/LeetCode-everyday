/*

你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。

 

示例：

输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
输出：["mee","aqq"]
解释：
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。
 

提示：

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20

链接：https://leetcode.cn/problems/find-and-replace-pattern

    vector<string> words = { "abc", "deq", "mee", "aqq", "dkd", "ccc" };
    string pattern = "abb";
    Solution temp;
    vector<string> ret = temp.findAndReplacePattern(words, pattern);
    Print<string>::PrintOneDemionVector(ret);

*/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    bool isVaild(string word, string pattern) {
//        int len = pattern.size();
//        if (word.size() != len)
//            return false;
//        vector<bool> cnt(26);
//        unordered_map<char, char> f_map;
//        for (int i = 0; i < len; ++i) {
//            if (f_map.count(pattern[i])) {
//                if (f_map[pattern[i]] != word[i])
//                    return false;
//            }
//            else {
//                if (!cnt[word[i] - 'a']) {
//                    f_map[pattern[i]] = word[i];
//                    cnt[word[i] - 'a'] = true;
//                }
//                else
//                    return false;
//            }
//        }
//        return true;
//    }
//
//    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//        vector<string> ret;
//        for (string word : words) {
//            if (isVaild(word, pattern)) {
//                ret.emplace_back(word);
//            }
//        }
//        return ret;
//    }
//};


class Solution {
public:
    unordered_map<char, vector<int>> map;
    bool isVaild(string word) {
        vector<bool> visit(26);
        for (auto iter = map.begin(); iter != map.end(); ++iter) {
            vector<int> vec = iter->second;
            int l = vec.size();
            char temp = word[vec[0]];
            if (visit[temp - 'a'])
                return false;
            visit[temp - 'a'] = true;
            for (int i = 1; i < l; ++i) {
                if (word[vec[i]] != temp) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        int len = pattern.size();
        for (int i = 0; i < len; ++i)
            map[pattern[i]].emplace_back(i);
        for (string word : words) {
            if (isVaild(word))
                ret.emplace_back(word);
        }
        return ret;
    }
};