/*

句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。

给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。

 

示例 1：

输入：s1 = "this apple is sweet", s2 = "this apple is sour"
输出：["sweet","sour"]
示例 2：

输入：s1 = "apple apple", s2 = "banana"
输出：["banana"]
 

提示：

1 <= s1.length, s2.length <= 200
s1 和 s2 由小写英文字母和空格组成
s1 和 s2 都不含前导或尾随空格
s1 和 s2 中的所有单词间均由单个空格分隔

链接：https://leetcode-cn.com/problems/uncommon-words-from-two-sentences

    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    Solution temp;
    vector<string> result = temp.uncommonFromSentences(s1, s2);
    Print<string>::PrintOneDemionVector(result);

*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    vector<string> uncommonFromSentences(string s1, string s2) {
//        unordered_map<string, int> hash_map;
//        vector<string> result;
//        int temp = 0;
//        for (int i = 0; i < s1.size(); ++i) 
//            if (s1[i] == ' ') {
//                hash_map[s1.substr(temp, i - temp)]++;
//                temp = i + 1;
//            }
//        hash_map[s1.substr(temp, s1.size() - temp)]++;
//        temp = 0;
//        for (int i = 0; i < s2.size(); ++i)
//            if (s2[i] == ' ') {
//                hash_map[s2.substr(temp, i - temp)]++;
//                temp = i + 1;
//            }
//        hash_map[s2.substr(temp, s2.size() - temp)]++;
//        for (auto iter = hash_map.begin(); iter != hash_map.end(); ++iter)
//            if ((*iter).second == 1)
//                result.push_back((*iter).first);
//        return result;
//    }
//};

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hash_map;
        vector<string> result;
        auto insert = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word)
                ++hash_map[move(word)];
        };
        insert(s1);
        insert(s2);
        for (auto iter = hash_map.begin(); iter != hash_map.end(); ++iter)
            if ((*iter).second == 1)
                result.push_back((*iter).first);
        return result;
    }
};