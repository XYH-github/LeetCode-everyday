/*

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如 "USA" 。
单词中所有字母都不是大写，比如 "leetcode" 。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

 

示例 1：

输入：word = "USA"
输出：true
示例 2：

输入：word = "FlaG"
输出：false
 

提示：

1 <= word.length <= 100
word 由小写和大写英文字母组成

链接：https://leetcode-cn.com/problems/detect-capital


string word = "Flag";
    Solution temp;
    bool result = temp.detectCapitalUse(word);
    cout << result << endl;

*/
#include <string>
using namespace std;

//class Solution {
//public:
//    bool detectCapitalUse(string word) {
//        bool bigflag = 1;
//        bool smallflag = 1;
//        for (int i = 1; i < word.length(); ++i)
//            if (word[i] >= 'A' && word[i] <= 'Z')
//                smallflag = 0;
//            else
//                bigflag = 0;
//        if (smallflag || (bigflag && word[0] >= 'A' && word[0] <= 'Z'))
//            return true;
//        else
//            return false;
//    }
//};

class Solution {
public:
    bool detectCapitalUse(string word) {
        // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }

        // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
        for (int i = 2; i < word.size(); ++i) {
            if (islower(word[i]) ^ islower(word[1])) {
                return false;
            }
        }
        return true;
    }
};


