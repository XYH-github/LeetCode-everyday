/*

国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如:

'a' 对应 ".-" ，
'b' 对应 "-..." ，
'c' 对应 "-.-." ，以此类推。
为了方便，所有 26 个英文字母的摩尔斯密码表如下：

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
给你一个字符串数组 words ，每个单词可以写成每个字母对应摩尔斯密码的组合。

例如，"cab" 可以写成 "-.-..--..." ，(即 "-.-." + ".-" + "-..." 字符串的结合)。我们将这样一个连接过程称作 单词翻译 。
对 words 中所有单词进行单词翻译，返回不同 单词翻译 的数量。

链接：https://leetcode-cn.com/problems/unique-morse-code-words

    vector<string> words = { "gin", "zen", "gig", "msg" };
    Solution temp;
    int ret = temp.uniqueMorseRepresentations(words);
    cout << ret << endl;

*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//class Solution {
//    const vector<string> dict = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
//
//public:
//    int uniqueMorseRepresentations(vector<string>& words) {
//        unordered_set<string> str_set;
//        for (string word : words) {
//            string mos_pass;
//            for (char ch : word) {
//                mos_pass += dict[ch - 'a'];
//            }
//            str_set.emplace(mos_pass);
//        }
//        return str_set.size();
//    }
//};

pair<uint64_t, int> encode[] = {
    { 0b01, 2 }, { 0b1000, 4 }, { 0b1010, 4 }, { 0b100, 3 },
    { 0b0, 1 }, { 0b0010, 4 }, { 0b110, 3 }, { 0b0000, 4 },
    { 0b00, 2 }, { 0b0111, 4 }, { 0b101, 3 }, { 0b0100, 4 },
    { 0b11, 2 }, { 0b10, 2 }, { 0b111, 3 }, { 0b0110, 4 },
    { 0b1101, 4 }, { 0b010, 3 }, { 0b000, 3 }, { 0b1, 1 },
    { 0b001, 3 }, { 0b0001, 4 }, { 0b011, 3 }, { 0b1001, 4 },
    { 0b1011, 4 }, { 0b1100, 4 }
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<uint64_t> hash;
        for (auto&& word : words) {
            uint64_t mask = 0;
            int len = 0;
            for (auto ch : word) {
                len += encode[ch - 'a'].second;
                mask = (mask << encode[ch - 'a'].second) | encode[ch - 'a'].first;
            }
            hash.emplace(mask | ((uint64_t)len << (64 - 8)));   // 根据评论提醒，之前没有考虑到总长度，这里用最高的 8bit 储存总长度
        }
        return hash.size();
    }
};