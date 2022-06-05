/*

有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1
提示：

words.length <= 100000

链接：https://leetcode.cn/problems/find-closest-lcci

    vector<string> words = { "I", "am", "a", "student", "from", "a", "university", "in", "a", "city" };
    string word1 = "a", word2 = "student";
    Solution temp;
    int ret = temp.findClosest(words, word1, word2);
    cout << ret << endl;

*/

#include <vector>
#include <string>
using namespace std;

//class Solution {
//public:
//    int findClosest(vector<string>& words, string word1, string word2) {
//        int len = words.size();
//        string now_word;
//        int ret = INT_MAX;
//        int pos_word = 0;
//        for (int i = 0; i < len; ++i) {
//            if (words[i] == word1 && now_word != word2) {
//                now_word = word1;
//                pos_word = i;
//            }
//            else if (words[i] == word2 && now_word != word1) {
//                now_word = word2;
//                pos_word = i;
//            }
//            else if (words[i] == word1 && now_word == word2) {
//                now_word = word1;
//                ret = min(ret, i - pos_word);
//                pos_word = i;
//            }
//            else if (words[i] == word2 && now_word == word1) {
//                now_word = word2;
//                ret = min(ret, i - pos_word);
//                pos_word = i;
//            }
//        }
//        return ret;
//    }
//};


class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int length = words.size();
        int ans = length;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < length; i++) {
            string word = words[i];
            if (words[i] == word1) {
                index1 = i;
            }
            else if (words[i] == word2) {
                index2 = i;
            }
            if (index1 >= 0 && index2 >= 0) {
                ans = min(ans, abs(index1 - index2));
            }
        }
        return ans;
    }
};