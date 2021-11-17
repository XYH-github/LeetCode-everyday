/*

给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

 

示例 1:

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16
解释: 这两个单词为 "abcw", "xtfn"。
示例 2:

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: ["a","aa","aaa","aaaa"]
输出: 0
解释: 不存在这样的两个单词。
 

提示：

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 仅包含小写字母

链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths

*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        int result = 0;
//        if (words.size() < 2)
//            return result;
//        int n = words.size();
//        for (int i = 0; i < n; ++i)
//            for (int j = i + 1; j < n; ++j)
//                    result = max(getCompare(words[i], words[j]), result);
//        return result;
//    }
//
//    int getCompare(string word_a, string word_b) {
//        for (char index : word_a)
//            for (char index2 : word_b)
//                if (index == index2)
//                    return 0;
//        return word_a.length() * word_b.length();
//    }
//
//};

//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        int result = 0;
//        int n = words.size();
//        if (n < 2)
//            return result;
//        vector<int> mask(n);
//        for (int i = 0; i < n; ++i)
//            for (char index : words[i])
//                mask[i] |= 1 << (index - 'a');
//        for (int i = 0; i < n; ++i)
//            for (int j = i + 1; j < n; ++j)
//                if ((mask[i] & mask[j]) == 0)
//                    result = max(result, int(words[i].length() * words[j].length()));
//        return result;
//    }
//};


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        int n = words.size();
        if (n < 2)
            return result;
        
        unordered_map<int, int> hasmap;
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char index : words[i])
                mask |= 1 << (index - 'a');
            hasmap[mask] = max(hasmap[mask], int(words[i].length()));  
        }
        for (auto index : hasmap)
            for (auto index2 : hasmap)
                if ((index.first & index2.first) == 0)
                    result = max(result, index.second * index2.second);
        return result;
    }
};