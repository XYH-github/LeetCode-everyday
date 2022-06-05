/*

�и��ں����ʵĳ����ı��ļ�����������������ͬ�ĵ��ʣ��ҳ�������ļ������������ʵ���̾���(���������)�����Ѱ�ҹ���������ļ��л��ظ���Σ���ÿ��Ѱ�ҵĵ��ʲ�ͬ�����ܶԴ��Ż���?

ʾ����

���룺words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
�����1
��ʾ��

words.length <= 100000

���ӣ�https://leetcode.cn/problems/find-closest-lcci

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