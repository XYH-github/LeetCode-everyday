/*

给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

 

示例 1：

输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]
示例 2：

输入：text = "we will we will rock you", first = "we", second = "will"
输出：["we","rock"]
 

提示：

1 <= text.length <= 1000
text 由小写英文字母和空格组成
text 中的所有单词之间都由 单个空格字符 分隔
1 <= first.length, second.length <= 10
first 和 second 由小写英文字母组成

链接：https://leetcode-cn.com/problems/occurrences-after-bigram

    string text = "alice is a good girl she is a good student", first = "a", second = "good";
    Solution temp;
    vector<string> ret = temp.findOcurrences(text, first, second);
    Print<string>::PrintOneDemionVector(ret);

*/

#include <string>
#include <vector>
#include <sstream>
using namespace std;

//class Solution {
//public:
//    vector<string> findOcurrences(string text, string first, string second) {
//        istringstream record(text);
//        string one, two, three;
//        record >> one;
//        record >> two;
//        vector<string> ans;
//        while (record >> three) {
//            if (one == first && two == second)
//                ans.emplace_back(three);
//            one = two;
//            two = three;
//        }
//        return ans;
//    }
//};

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        vector<string> ret;
        auto split = [&](char spl) {
            char* text_p = &text[0];
            while (*text_p != '\0') {
                while (*text_p != '\0' && *text_p == spl)
                    text_p++;
                if (*text_p == '\0')
                    break;
                char* temp = text_p;
                while (*text_p != '\0' && *text_p != spl)
                    text_p++;
                words.emplace_back(temp, text_p);
                if (*text_p == '\0')
                    break;
            }
        };
        split(' ');
        for (int i = 1; i < words.size() - 1; ++i)
            if (words[i] == second && words[i - 1] == first)
                ret.emplace_back(words[i + 1]);
        return ret;
    }
};