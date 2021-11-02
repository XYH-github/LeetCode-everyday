/*

给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。


 

示例 1：

输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]
示例 2：

输入：words = ["omk"]
输出：[]
示例 3：

输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]

*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int temp[26];
        getArray(temp);

        for (auto iter = words.begin(); iter != words.end(); ) {
            bool iter_flag = 1;
            int flag = temp[Chartochar((*iter)[0]) - 'a'];
            for (char index : *iter)
                if (flag != temp[Chartochar(index) - 'a']) {
                    iter = words.erase(iter);
                    iter_flag = 0;
                    break;
                }
            if (iter_flag == 1)
                ++iter;
        }
        return words;
    }

    void getArray(int* temp) {
        string str[] = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        for (int i = 0; i < 3; ++i)
            for (char index : str[i])
                temp[index - 'a'] = i;
    }

    char Chartochar(char temp) {
        if (temp <= 'Z' && temp >= 'A')
            return temp + 'a' - 'A';
        else
            return temp;
    }

};