/*

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

链接：https://leetcode-cn.com/problems/minimum-window-substring

    string s = "cabwefgewcwaefgcf", t = "cae";
    Solution temp;
    string ret = temp.minWindow(s, t);
    cout << ret << endl;

*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.size();
        int ret_len = INT_MAX;
        int start = 0;
        unordered_map<char, int> char_map;
        for (char ch : t)
            char_map[ch]++;
        unordered_map<char, int> temp_map;
        int index = 0;
        while (index < len && !char_map.count(s[index]))
            index++;
        if (len == index)
            return "";
        int back = index;
        while (index < len) {
            bool flag = false;
            while (index < len) {
                
                if (char_map.count(s[index])) {
                    flag = true;
                    temp_map[s[index]]++;
                    for (auto iter = char_map.begin(); iter != char_map.end(); ++iter) {
                        if (iter->second > temp_map[iter->first]) {
                            flag = false;
                            break;
                        }
                    }
               
                }
                index++;
                if (flag)
                    break;
            }
            if (!flag)
                break;
            if (ret_len > index - back) {
                ret_len = index - back;
                start = back;
            }
            //ret_len = min(ret_len, index - back);            
            //start = back;
            temp_map[s[back]]--;
            back++;
            while (back < len) {
                bool flag = false;
                if (char_map.count(s[back])) {
                    for (auto iter = char_map.begin(); iter != char_map.end(); ++iter) {
                        if (iter->second > temp_map[iter->first]) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                        break;
                    
                    temp_map[s[back]]--;
                    if (ret_len > index - back) {
                        ret_len = index - back;
                        start = back;
                    }
                    //ret_len = min(ret_len, index - back);
                    //start = back;
                }
                back++;
            }
        }
        return ret_len == INT_MAX ? "" : s.substr(start, ret_len);
    }
};