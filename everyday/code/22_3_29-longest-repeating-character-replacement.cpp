/*

给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。

在执行上述操作后，返回包含相同字母的最长子字符串的长度。

 

示例 1：

输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
示例 2：

输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
 

提示：

1 <= s.length <= 105
s 仅由大写英文字母组成
0 <= k <= s.length

链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement

    string s = "AABABBA";
    int k = 1;
    Solution temp;
    int ret = temp.characterReplacement(s, 1);
    cout << ret << endl;

*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        vector<int> char_cnt(26);
        int right = 0;
        int left = 0;
        int ret = 0;
        while (right < len) {
            char_cnt[s[right] - 'A']++;
            ret = max(ret, char_cnt[s[right] - 'A']);
            if (right - left + 1 - ret > k) {
                char_cnt[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};